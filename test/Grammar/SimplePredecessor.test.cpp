#include <LSystemGenerator/Grammar/SimplePredecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::SimplePredecessor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::Predecessor>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::Predecessor>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<ls::Predecessor>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<ls::Predecessor>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::Predecessor>);
            constexpr ls::SimplePredecessor simplePredecessor;
            STATIC_CHECK(simplePredecessor.letter == 0);
        }

        SECTION("Letter construction")
        {
            constexpr ls::SimplePredecessor simplePredecessor('A');
            STATIC_CHECK(simplePredecessor.letter == 'A');
        }

    }

}
