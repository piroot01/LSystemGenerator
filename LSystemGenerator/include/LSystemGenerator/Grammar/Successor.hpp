#ifndef Grammar_Successor_INCLUDED
#define Grammar_Successor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>


namespace ls
{


class LSystemAPI Successor
{
public:
    constexpr Successor() noexcept;

    constexpr Successor(const Successor&) noexcept;

    constexpr Successor(Successor&&) noexcept;

    Successor& operator=(const Successor&) noexcept;

    Successor& operator=(Successor&&) noexcept;

    virtual ~Successor();

};


constexpr inline Successor::Successor() noexcept = default;


constexpr inline Successor::Successor(const Successor&) noexcept = default;


constexpr inline Successor::Successor(Successor&&) noexcept = default;


inline Successor& Successor::operator=(const Successor&) noexcept = default;


inline Successor& Successor::operator=(Successor&&) noexcept = default;





} // namespace ls


#endif
