#include <LSystemGenerator/Grammar/Successor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::Successor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::Successor>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::Successor>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<ls::Successor>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<ls::Successor>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::Successor>);
        }

    }

}
