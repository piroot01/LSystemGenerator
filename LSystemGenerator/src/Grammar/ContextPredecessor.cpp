#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>
#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <utility>


namespace ls
{


ContextPredecessor::ContextPredecessor()
{
    m_predecessors.insert(std::make_pair(Part::MIDDLE, std::make_unique<SimplePredecessor>()));
}


ContextPredecessor::ContextPredecessor(std::unique_ptr<SimplePredecessor> pPredecessor)
{
    m_predecessors.insert(std::make_pair(Part::MIDDLE, std::move(pPredecessor)));
}


[[nodiscard]] bool ContextPredecessor::contains(const Part part) const
{
    return m_predecessors.find(part) != m_predecessors.end();
}

/*
const std::shared_ptr<SimplePredecessor> ContextPredecessor::get(const Part context)
{
    auto iterator = m_predecessors.find(context);
    if (iterator != m_predecessors.end())
    {
        auto pPredecessor = std::make_shared<ls::SimplePredecessor>(*(iterator->second));
        std::cout << std::static_pointer_cast<ls::ParametrizedPredecessor<int>>(pPredecessor)->getParameterCount() << '\n';
        return pPredecessor;
    }
    else
    {
        throw std::runtime_error("Context not found.");
    }
}
*/

} // namespace ls
