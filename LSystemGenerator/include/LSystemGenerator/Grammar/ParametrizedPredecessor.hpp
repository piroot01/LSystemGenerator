#ifndef Grammar_ParametrizedPredecessor_INCLUDED
#define Grammar_ParametrizedPredecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Grammar/SimplePredecessor.hpp>
#include <LSystemGenerator/Grammar/ParameterArray.hpp>
#include <cassert>


namespace ls
{


class LSystemAPI ParametrizedPredecessor : public SimplePredecessor
{
public:
    constexpr ParametrizedPredecessor() noexcept;

    constexpr ParametrizedPredecessor(const char letter) noexcept;

    constexpr ParametrizedPredecessor(const char letter, const std::size_t size) noexcept;

    constexpr std::size_t getParameterCount() const noexcept;

    constexpr Parameter& operator[](const std::size_t index);

    constexpr const Parameter& operator[](const std::size_t index) const;

    constexpr void clear() noexcept;

    constexpr void resize(const std::size_t parameterCount);

    constexpr void appendParameter(const Parameter& parameter);

private:
    ParameterArray m_parameters;

};


constexpr ParametrizedPredecessor::ParametrizedPredecessor() noexcept = default;


constexpr ParametrizedPredecessor::ParametrizedPredecessor(const char letter) noexcept :
    SimplePredecessor(letter)
{
}


constexpr ParametrizedPredecessor::ParametrizedPredecessor(const char letter, const std::size_t size) noexcept :
    SimplePredecessor(letter), m_parameters(size)
{
}


constexpr inline std::size_t ParametrizedPredecessor::getParameterCount() const noexcept
{
    return m_parameters.size();
}


constexpr inline Parameter& ParametrizedPredecessor::operator[](const std::size_t index)
{
    assert(index < m_parameters.size());
    return m_parameters[index];
}


constexpr inline const Parameter& ParametrizedPredecessor::operator[](const std::size_t index) const
{
    assert(index < m_parameters.size());
    return m_parameters[index];
}


constexpr inline void ParametrizedPredecessor::clear() noexcept
{
    m_parameters.clear();
}


constexpr inline void ParametrizedPredecessor::resize(const std::size_t parameterCount)
{
    m_parameters.resize(parameterCount);
}


constexpr inline void ParametrizedPredecessor::appendParameter(const Parameter& parameter)
{
    m_parameters.push_back(parameter);
}


} // namespace ls


#endif

