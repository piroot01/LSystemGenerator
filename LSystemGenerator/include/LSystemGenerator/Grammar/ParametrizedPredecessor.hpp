#ifndef Grammar_ParametrizedPredecessor_INCLUDED
#define Grammar_ParametrizedPredecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Grammar/SimplePredecessor.hpp>
#include <LSystemGenerator/Grammar/ParameterMap.hpp>
#include <exprtk.hpp>
#include <string>


namespace ls
{


template <class T>
class LSystemAPI ParametrizedPredecessor : public SimplePredecessor
{
public:
    ParametrizedPredecessor() = default;

    ParametrizedPredecessor(const char letter) :
        SimplePredecessor(letter)
    {
    }

    void registerSymbols(exprtk::symbol_table<T>& symbolTable)
    {
        for (auto iterator = this->parameters.begin(); iterator != this->parameters.end(); ++iterator)
            symbolTable.add_variable(std::string(1, iterator->first), iterator->second);
    }

public:
    detail::ParameterMap<T> parameters;

};


};


#endif
