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

    std::size_t getParameterCount() const noexcept
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

    void clear() noexcept
    {
        m_parameterMap.clear();
    }

    void insertOrAssignParameter(const __parameter parameter, T&& value)
    {
        m_parameterMap.insert_or_assign(parameter, std::forward<T>(value));
    }

    bool insertParameter(const __parameter parameter, T&& value)
    {
        return m_parameterMap.insert(std::make_pair(parameter, std::forward<T>(value))).second;
    }

    auto begin()
    {
        return m_parameterMap.begin();
    }

    auto end()
    {
        return m_parameterMap.end();
    }

    auto cbegin()
    {
        return m_parameterMap.cbegin();
    }

    auto cend()
    {
        return m_parameterMap.cend();
    }

private:
    std::unordered_map<__parameter, T> m_parameterMap;

};


} // namespace detail


} // namespace ls


#endif

