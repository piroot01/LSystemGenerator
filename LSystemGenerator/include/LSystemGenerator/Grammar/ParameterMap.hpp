#ifndef Grammar_ParameterArray_INCLUDED
#define Grammar_ParameterArray_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Grammar/Parameter.hpp>
#include <unordered_map>


namespace ls
{


template <class T>
using ParameterMap = std::unordered_map<Parameter, T>;


} // namespace ls


#endif
