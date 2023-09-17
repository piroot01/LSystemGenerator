#ifndef Grammar_ContextPredecessor_INCLUDED
#define Grammar_ContextPredecessor_INCLUDED


#include "LSystemGenerator/Foundation/Foundation.hpp"
#include "LSystemGenerator/Grammar/Predecessor.hpp"
#include <map>


namespace ls
{


class LSystemAPI ContextPredecessor : public Predecessor
{
public:
    enum class Context
    {
        RIGHT,
        LEFT,

    };

    ContextPredecessor();

    ContextPredecessor(const char letter);

    [[nodiscard]] bool add(const Predecessor* predecessor, const ContextPredecessor::Context context);

    [[nodiscard]] bool contains(const ContextPredecessor::Context context) const;

    const Predecessor* getPredecessor(const ContextPredecessor::Context context) const;

//    Predecessor* getPredecessor(const ContextPredecessor::Context context);

private:
    std::map<Context, const Predecessor*> m_predecessors;

};


} // namespace ls


#endif
