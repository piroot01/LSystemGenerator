#include <LSystemGenerator/Grammar/SimpleSuccessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::SimpleSuccessor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::SimpleSuccessor>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::SimpleSuccessor>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<ls::SimpleSuccessor>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<ls::SimpleSuccessor>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::SimpleSuccessor>);
            const ls::SimpleSuccessor simpleSuccessor;
            CHECK(simpleSuccessor.successor == "");
        }

        SECTION("Successor (std::string) construction")
        {
            const ls::SimpleSuccessor simpleSuccessor("aabb");
            CHECK(simpleSuccessor.successor == "aabb");
        }

    }

}
