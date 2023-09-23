#ifndef Grammar_Predecessor_INCLUDED
#define Grammar_Predecessor_INCLUDED


#include <LSystemGenerator/Foundation/Foundation.hpp>


namespace ls
{


class LSystemAPI Predecessor
{
public:
    constexpr Predecessor() noexcept;

    constexpr Predecessor(const Predecessor&) noexcept;

    constexpr Predecessor(Predecessor&&) noexcept;

    constexpr Predecessor& operator=(const Predecessor&) noexcept;

    constexpr Predecessor& operator=(Predecessor&&) noexcept;

};


constexpr inline Predecessor::Predecessor() noexcept = default;


constexpr inline Predecessor::Predecessor(const Predecessor&) noexcept = default;


constexpr inline Predecessor::Predecessor(Predecessor&&) noexcept = default;


constexpr inline Predecessor& Predecessor::operator=(const Predecessor&) noexcept = default;


constexpr inline Predecessor& Predecessor::operator=(Predecessor&&) noexcept = default;


} // namespace ls


#endif
