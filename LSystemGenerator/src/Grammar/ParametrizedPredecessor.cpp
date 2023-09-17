#include "LSystemGenerator/Grammar/ParametrizedPredecessor.hpp"
#include <cassert>


namespace ls
{


ParametrizedPredecessor::ParametrizedPredecessor() = default;


ParametrizedPredecessor::ParametrizedPredecessor(const char letter) :
    Predecessor(letter)
{
}


std::size_t ParametrizedPredecessor::getParameterCount() const
{
    return m_parameters.size();
}


Parameter& ParametrizedPredecessor::operator[](const std::size_t index)
{
    assert(index < m_parameters.size());
    return m_parameters[index];
}


const Parameter& ParametrizedPredecessor::operator[](const std::size_t index) const
{
    assert(index < m_parameters.size());
    return m_parameters[index];
}


void ParametrizedPredecessor::clear()
{
    m_parameters.clear();
}


void ParametrizedPredecessor::resize(const std::size_t parameterCount)
{
    m_parameters.resize(parameterCount);
}


void ParametrizedPredecessor::append(const Parameter& parameter)
{
    m_parameters.push_back(parameter);
}


} // namespace ls
