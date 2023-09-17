#include <LSystemGenerator/Grammar/Predecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::Predecessor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK_FALSE(std::is_copy_constructible_v<ls::Predecessor>);
        STATIC_CHECK_FALSE(std::is_copy_assignable_v<ls::Predecessor>);
        STATIC_CHECK_FALSE(std::is_nothrow_move_constructible_v<ls::Predecessor>);
        STATIC_CHECK_FALSE(std::is_nothrow_move_assignable_v<ls::Predecessor>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            constexpr ls::Predecessor predecessor;
            STATIC_CHECK(predecessor.get() == static_cast<char>(0));
        }
        
        SECTION("Letter construction")
        {
            constexpr ls::Predecessor predecessor('A');
            STATIC_CHECK(predecessor.get() == 'A');
        }
    }

}
