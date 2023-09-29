#ifndef Grammar_ParameterMap_INCLUDED
#define Grammar_ParameterMap_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <unordered_map>
#include <cassert>
#include <cstdint>


namespace ls
{


namespace detail
{


template <class T>
class LSystemAPI ParameterMap
{
public:
    using __parameter = char;

public:
    ParameterMap() = default;

    inline std::size_t getParameterCount() const noexcept
    {
        return m_parameterMap.size();
    }

    T& operator[](const __parameter index)
    {
        assert(m_parameterMap.contains(index));
        return m_parameterMap[index];
    }

    const T& operator[](const __parameter index) const
    {
        assert(m_parameterMap.contains(index));
        return m_parameterMap[index];
    }

    T& at(const __parameter index)
    {
        return (*this)[index];
    }

    const T& at(const __parameter index) const
    {
        return (*this)[index];
    }

    inline void clear() noexcept
    {
        m_parameterMap.clear();
    }

    inline void insertOrAssignParameter(const __parameter parameter, T&& value = T{})
    {
        m_parameterMap.insert_or_assign(parameter, std::forward<T>(value));
    }

    inline bool insertParameter(const __parameter parameter, T&& value = T{})
    {
        return m_parameterMap.insert(std::make_pair(parameter, std::forward<T>(value))).second;
    }

    inline auto begin()
    {
        return m_parameterMap.begin();
    }

    inline auto end()
    {
        return m_parameterMap.end();
    }

    inline auto cbegin()
    {
        return m_parameterMap.cbegin();
    }

    inline auto cend()
    {
        return m_parameterMap.cend();
    }

private:
    std::unordered_map<__parameter, T> m_parameterMap;

};


} // namespace detail


} // namespace ls


#endif

