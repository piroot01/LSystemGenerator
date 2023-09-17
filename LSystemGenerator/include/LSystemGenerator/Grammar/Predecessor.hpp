#ifndef Grammar_Predecessor_INCLUDED
#define Grammar_Predecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>


namespace ls
{


class LSystemAPI Predecessor
{
public:
    constexpr Predecessor();

    constexpr Predecessor(const char letter);

    Predecessor(const Predecessor&) = delete;

    Predecessor& operator=(const Predecessor&) = delete;

    // For now it will be visible
    char letter{};

};


constexpr inline Predecessor::Predecessor() = default;


constexpr inline Predecessor::Predecessor(const char letter) :
    letter(letter)
{
}


} // namespace ls


#endif
