#ifndef Grammar_ParametrizedPredecessor_INCLUDED
#define Grammar_ParametrizedPredecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Grammar/Predecessor.hpp>
#include <LSystemGenerator/Grammar/ParameterArray.hpp>


namespace ls
{


class LSystemAPI ParametrizedPredecessor : private Predecessor
{
public:
    ParametrizedPredecessor();

    std::size_t getParameterCount() const;

    Parameter& operator[](const std::size_t index);

    const Parameter& operator[](const std::size_t index) const;

    void clear();

    void resize(const std::size_t parameterCount);

    void append(const Parameter& parameter);

private:
    ParameterArray m_parameters;

};


} // namespace ls


#endif

