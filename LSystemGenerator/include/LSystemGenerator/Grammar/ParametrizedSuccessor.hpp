#ifndef Grammar_ParametrizedSuccessor_INCLUDED
#define Grammar_ParametrizedSuccessor_INCLUDED


#include <LSystemGenerator/Grammar/Successor.hpp>
#include <LSystemGenerator/Grammar/SymbolRegistry.hpp>
#include <exprtk.hpp>
#include <sstream>


namespace ls
{


class LSystemAPI ParametrizedSuccessor : public Successor
{
public:
    ParametrizedSuccessor();

    ParametrizedSuccessor(const char letter);

    void addExpression(const std::string& expression);

    // probably will go to another class
    template <class T>
    void evaluate(exprtk::parser<T>& parser, const SymbolRegistry<T>& symbolRegistry, std::string& successor) const
    {
        exprtk::expression<T> expression;
        std::stringstream stringStream;

        auto symbolTable = symbolRegistry.get();
        expression.register_symbol_table(symbolTable);

        stringStream << letter
                     << '(';

        const auto expressionsSize = m_expressions.size();
        for (std::size_t i = 0; i < expressionsSize; ++i)
        {
            parser.compile(m_expressions[i], expression);
            stringStream << expression.value();
            if (i != expressionsSize - 1)
                stringStream << ", ";
        }

        stringStream << ')';
        successor = stringStream.str();
    }

public:
    char letter{};

private:
    std::vector<std::string> m_expressions;

};


inline ParametrizedSuccessor::ParametrizedSuccessor() = default;


inline ParametrizedSuccessor::ParametrizedSuccessor(const char letter) :
    letter(letter)
{
}


inline void ParametrizedSuccessor::addExpression(const std::string& expression)
{
    m_expressions.emplace_back(expression);
}


} // namespace ls


#endif
