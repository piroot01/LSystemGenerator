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

    [[nodiscard]] constexpr char get() const; 


private:
    char m_letter{};

};


constexpr inline Predecessor::Predecessor() = default;


constexpr inline Predecessor::Predecessor(const char letter) :
    m_letter(letter)
{
}


constexpr inline char Predecessor::get() const
{
    return m_letter;
}


} // namespace ls


#endif
