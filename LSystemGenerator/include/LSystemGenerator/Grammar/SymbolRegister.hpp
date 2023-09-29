#ifndef Grammar_SymbolRegistry_INCLUDED
#define Grammar_SymbolRegistry_INCLUDED


#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>
#include <exprtk.hpp>


namespace ls
{


template <class T>
class LSystemAPI SymbolRegistry
{
public:
    SymbolRegistry() = default;

    inline void registerSymbols(ParametrizedPredecessor<T>& predecessor)
    {
        predecessor.registerSymbols(m_symbolTable);
    }

    void registerSymbols(ContextPredecessor& predecessor)
    {
        for (auto i : {0, 1, 2})
        {
            if (predecessor.contains(static_cast<ContextPredecessor::Part>(i)))
            {
                auto pPredecessor = predecessor.get<ParametrizedPredecessor<T>>(static_cast<ContextPredecessor::Part>(i));
                if (pPredecessor)
                    pPredecessor->registerSymbols(m_symbolTable);
            }
        }
    }

    inline void registerConstant(const std::string& constantName, const T& value)
    {
        m_symbolTable.add_constant(constantName, value);
    }

    constexpr inline const exprtk::symbol_table<T>& get() const
    {
        return m_symbolTable;
    }

private:
    exprtk::symbol_table<T> m_symbolTable;

};


} // namespace ls


#endif
