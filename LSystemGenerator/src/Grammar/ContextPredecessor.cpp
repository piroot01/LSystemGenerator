#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>


namespace ls
{


ContextPredecessor::ContextPredecessor() = default;


[[nodiscard]] bool ContextPredecessor::add(const Predecessor* predecessor, const ContextPredecessor::Context context)
{
    if (this->contains(context))
        return false;

    m_predecessors.emplace(context, predecessor);
    return true;
};


[[nodiscard]] bool ContextPredecessor::contains(const ContextPredecessor::Context context) const
{
    return m_predecessors.find(context) != m_predecessors.end();
}


} // namespace ls

