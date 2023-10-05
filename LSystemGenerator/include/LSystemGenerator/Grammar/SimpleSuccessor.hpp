#ifndef Grammar_SimpleSuccessor_INCLUDED
#define Grammar_SimpleSuccessor_INCLUDED


#include <LSystemGenerator/Grammar/Successor.hpp>


namespace ls
{


class LSystemAPI SimpleSuccessor : public Successor
{
public:
    constexpr SimpleSuccessor() noexcept;

    constexpr SimpleSuccessor(const std::string& successor) noexcept;

    // for now it will be public
    std::string successor;

};


inline constexpr SimpleSuccessor::SimpleSuccessor() noexcept = default;


inline constexpr SimpleSuccessor::SimpleSuccessor(const std::string& successor) noexcept :
    successor(successor)
{
}


} // namespace ls


#endif
