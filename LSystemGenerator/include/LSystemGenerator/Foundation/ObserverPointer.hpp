#ifndef Foundation_ObserverPointer_INCLUDED
#define Foundation_ObserverPointer_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>

namespace foundation
{


template <typename T>
class ObserverPointer
{
public:
    using __pointer = std::add_pointer_t<T>;

    using __reference = std::add_lvalue_reference_t<T>; 

public:
    constexpr ObserverPointer() noexcept = default;

    constexpr explicit ObserverPointer(__pointer pointer) noexcept :
        m_pointer(pointer)
    {
    }

    template <typename U, typename = typename 
        std::enable_if_t<
            std::is_convertible_v<
                typename std::add_pointer_t<U>, __pointer
            >
        >
    >
    constexpr ObserverPointer(ObserverPointer<U> pointer) noexcept :
        m_pointer(pointer.get())
    {
    }

    constexpr __pointer get() const noexcept
    {
        return m_pointer;
    }
    
    constexpr __reference operator*() const noexcept
    {
        return *m_pointer;
    }

    constexpr __pointer operator->() const noexcept
    {
        return m_pointer;
    }

    constexpr explicit operator bool() const noexcept
    {
        return m_pointer != nullptr;
    }

    constexpr explicit operator __pointer() const noexcept
    {
        return m_pointer;
    }

    constexpr __pointer release() noexcept
    {
        __pointer pointer = this->get();
        this->reset();
        return pointer;
    }
    
    constexpr void reset(__pointer pointer = nullptr) noexcept
    {
        m_pointer = pointer;
    }

    constexpr void swap(ObserverPointer& pointer) noexcept
    {
        std::swap(m_pointer, pointer.m_pointer);
    }
    
private:
    __pointer m_pointer{};

};


} // namespace foundation


#endif
