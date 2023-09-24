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

    Predecessor& operator=(const Predecessor&) noexcept;

    Predecessor& operator=(Predecessor&&) noexcept;

    virtual ~Predecessor();

};


constexpr inline Predecessor::Predecessor() noexcept = default;


constexpr inline Predecessor::Predecessor(const Predecessor&) noexcept = default;


constexpr inline Predecessor::Predecessor(Predecessor&&) noexcept = default;


inline Predecessor& Predecessor::operator=(const Predecessor&) noexcept = default;


inline Predecessor& Predecessor::operator=(Predecessor&&) noexcept = default;


} // namespace ls


#endif
