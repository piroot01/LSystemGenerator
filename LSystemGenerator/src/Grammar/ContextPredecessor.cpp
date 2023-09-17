#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>
#include <stdexcept>


namespace ls
{


ContextPredecessor::ContextPredecessor() = default;


ContextPredecessor::ContextPredecessor(const char letter) :
    Predecessor(letter)
{
}


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


const Predecessor* ContextPredecessor::getPredecessor(const ContextPredecessor::Context context) const
{
    auto iterator = m_predecessors.find(context);
    if (iterator != m_predecessors.end())
        return iterator->second;
    else
        throw std::runtime_error("Context not found.");
}

/*
Predecessor* ContextPredecessor::getPredecessor(const ContextPredecessor::Context context)
{
    auto iterator = m_predecessors.find(context);
    if (iterator != m_predecessors.end())
        return const_cast<Predecessor*>(iterator->second);
    else
        throw std::runtime_error("Context not found.");
}
*/

} // namespace ls

