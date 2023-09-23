#ifndef Grammar_ParametrizedPredecessor_INCLUDED
#define Grammar_ParametrizedPredecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Grammar/SimplePredecessor.hpp>
#include <LSystemGenerator/Grammar/ParameterMap.hpp>
#include <cassert>
#include <cstdint>


namespace ls
{


template <class T>
class LSystemAPI ParametrizedPredecessor : public SimplePredecessor
{
public:
    ParametrizedPredecessor() = default;

    explicit ParametrizedPredecessor(const char letter) :
        SimplePredecessor(letter)
    {
    }

    std::size_t getParameterCount() const noexcept
    {
        return m_parameters.size();
    }

    T& operator[](const Parameter index)
    {
        assert(m_parameters.contains(index));
        return m_parameters[index];
    }

    const T& operator[](const Parameter index) const
    {
        assert(m_parameters.contains(index));
        return m_parameters[index];
    }

    T& at(const Parameter index)
    {
        return (*this)[index];
    }

    const T& at(const Parameter index) const
    {
        return (*this)[index];
    }

    void clear() noexcept
    {
        m_parameters.clear();
    }

    void insertOrAssignParameter(const Parameter parameter, T&& value)
    {
        m_parameters.insert_or_assign(parameter, std::forward<T>(value));
    }

    bool insertParameter(const Parameter parameter, T&& value)
    {
        return m_parameters.insert(std::make_pair(parameter, std::forward<T>(value))).second;
    }

private:
    ParameterMap<T> m_parameters;

};


using ParametrizedPredecessor_int = ParametrizedPredecessor<std::int32_t>;


} // namespace ls


#endif

