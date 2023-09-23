#ifndef Grammar_SimplePredecessor_INCLUDED
#define Grammar_SimplePredecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>
#include <LSystemGenerator/Grammar/Predecessor.hpp>


namespace ls
{


class LSystemAPI SimplePredecessor : public Predecessor
{
public:
    constexpr SimplePredecessor() noexcept;

    constexpr SimplePredecessor(const char letter) noexcept;

    // For now it will be public
    char letter{};

};


constexpr inline SimplePredecessor::SimplePredecessor() noexcept = default;


constexpr inline SimplePredecessor::SimplePredecessor(const char letter) noexcept :
    letter(letter)
{
}


} // namespace ls


#endif
