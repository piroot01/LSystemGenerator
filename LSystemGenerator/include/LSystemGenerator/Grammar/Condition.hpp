#ifndef Grammar_Conditions_INCLUDED
#define Grammar_Conditions_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Foundation/ObserverPointer.hpp>
#include <LSystemGenerator/Grammar/Predecessor.hpp>
#include <LSystemGenerator/Grammar/SymbolRegistry.hpp>
#include <exprtk.hpp>


namespace ls
{


class LSystemAPI Condition
{
public:
    Condition();

    Condition(const std::string& expression);

    void setExpression(const std::string& expression);

    template <class T>
    [[nodiscard]] bool evaluate(exprtk::parser<T>& parser, const SymbolRegistry<T>& symbolRegistry) const
    {
        auto symbolTable = symbolRegistry.get();
        exprtk::expression<T> expression;
        expression.register_symbol_table(symbolTable);
        parser.compile(m_expression, expression);
        return expression.value();
    }

private:
    std::string m_expression;

};



} // namespace ls


#endif
