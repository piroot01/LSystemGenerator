#include <LSystemGenerator/Grammar/Condition.hpp>


namespace ls
{


Condition::Condition() = default;


Condition::Condition(const std::string& expression) :
    m_expression(expression)
{
}


void Condition::setExpression(const std::string& expression)
{
    m_expression = expression;
}


} // namespace ls
