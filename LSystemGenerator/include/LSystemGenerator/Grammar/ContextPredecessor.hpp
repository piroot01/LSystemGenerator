#ifndef Grammar_ContextPredecessor_INCLUDED
#define Grammar_ContextPredecessor_INCLUDED


#include "LSystemGenerator/Foundation/Foundation.hpp"
#include "LSystemGenerator/Grammar/Predecessor.hpp"
#include <map>


namespace ls
{


class LSystemAPI ContextPredecessor : private Predecessor
{
public:
    enum class Context
    {
        NONE,
        RIGHT,
        LEFT,

    };

    ContextPredecessor();

    [[nodiscard]] bool add(const Predecessor* predecessor, const ContextPredecessor::Context context);

    [[nodiscard]] bool contains(const ContextPredecessor::Context constext) const;

private:
    std::map<Context, const Predecessor*> m_predecessors;

};


} // namespace ls


#endif
