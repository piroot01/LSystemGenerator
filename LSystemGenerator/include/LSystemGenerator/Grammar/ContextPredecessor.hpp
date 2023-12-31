#ifndef Grammar_ContextPredecessor_INCLUDED
#define Grammar_ContextPredecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Foundation/ObserverPointer.hpp>
#include <LSystemGenerator/Grammar/Predecessor.hpp>
#include <LSystemGenerator/Grammar/SimplePredecessor.hpp>
#include <type_traits>
#include <memory>
#include <map>


namespace ls
{


class LSystemAPI ContextPredecessor : public Predecessor
{
public:
    enum class Part
    {
        RIGHT,
        MIDDLE,
        LEFT,

    };

    ContextPredecessor();

    ContextPredecessor(const ContextPredecessor&) = delete;

    ContextPredecessor& operator=(const ContextPredecessor&) = delete;

    ContextPredecessor(ContextPredecessor&&) noexcept = default;

    ContextPredecessor& operator=(ContextPredecessor&&) noexcept = default;

    template <class T, typename = typename std::enable_if_t<!std::is_same_v<std::remove_reference_t<T>, ContextPredecessor> && std::is_base_of_v<SimplePredecessor, std::remove_reference_t<T>>>>
    inline static ContextPredecessor create(T&& predecessor = T())
    {
        return ContextPredecessor(std::make_unique<std::decay_t<T>>(std::forward<T>(predecessor)));
    }

    template <class T, typename = typename std::enable_if_t<!std::is_same_v<std::remove_reference_t<T>, ContextPredecessor> && std::is_base_of_v<SimplePredecessor, std::remove_reference_t<T>>>>
    inline void addOrAssignContext(const ContextPredecessor::Part part, T&& predecessor)
    {
        m_predecessors.insert_or_assign(part, std::make_unique<std::decay_t<T>>(std::forward<T>(predecessor)));
    }

    template <class T, typename = typename std::enable_if_t<!std::is_same_v<std::remove_reference_t<T>, ContextPredecessor> && std::is_base_of_v<SimplePredecessor, std::remove_reference_t<T>>>>
    [[nodiscard]] inline bool addContext(const ContextPredecessor::Part part, T&& predecessor)
    {
        return m_predecessors.insert(std::make_pair(part, std::make_unique<std::decay_t<T>>(std::forward<T>(predecessor)))).second;
    }

    [[nodiscard]] bool contains(const Part part) const;

    template <class T, typename = typename std::enable_if_t<!std::is_same_v<std::remove_reference_t<T>, ContextPredecessor> && std::is_base_of_v<SimplePredecessor, std::remove_reference_t<T>>>>
    const foundation::ObserverPointer<T> get(const Part context = Part::MIDDLE)
    {
        auto iterator = m_predecessors.find(context);
        if (iterator == m_predecessors.end())
            throw std::runtime_error("Context not found.");

        auto predecessor = dynamic_cast<std::add_pointer_t<T>>(iterator->second.get());

        return foundation::ObserverPointer<T>(predecessor);
    }

protected:
    ContextPredecessor(std::unique_ptr<SimplePredecessor> pPredecessor);

private:
    std::map<Part, std::unique_ptr<SimplePredecessor>> m_predecessors;

};


inline ContextPredecessor::ContextPredecessor()
{
    m_predecessors.insert(std::make_pair(Part::MIDDLE, std::make_unique<SimplePredecessor>()));
}


inline ContextPredecessor::ContextPredecessor(std::unique_ptr<SimplePredecessor> pPredecessor)
{
    m_predecessors.insert(std::make_pair(Part::MIDDLE, std::move(pPredecessor)));
}


[[nodiscard]] inline bool ContextPredecessor::contains(const Part part) const
{
    return m_predecessors.find(part) != m_predecessors.end();
}


} // namespace ls


#endif
