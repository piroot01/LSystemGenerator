#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>
#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <utility>


namespace ls
{


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
