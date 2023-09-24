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
            const ls::SimplePredecessor simplePredecessor;
            CHECK(simplePredecessor.letter == 0);
        }

        SECTION("Letter construction")
        {
            ls::SimplePredecessor simplePredecessor('A');
            CHECK(simplePredecessor.letter == 'A');
        }

    }

}
