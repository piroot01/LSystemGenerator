#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::ParametrizedPredecessor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK_FALSE(std::is_copy_constructible_v<ls::ParametrizedPredecessor>);
        STATIC_CHECK_FALSE(std::is_copy_assignable_v<ls::ParametrizedPredecessor>);
        STATIC_CHECK_FALSE(std::is_nothrow_move_constructible_v<ls::ParametrizedPredecessor>);
        STATIC_CHECK_FALSE(std::is_nothrow_move_assignable_v<ls::ParametrizedPredecessor>);
    }

    SECTION("Construction")
    {
        SECTION("Default constructor")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::ParametrizedPredecessor>);
            const ls::ParametrizedPredecessor parametrizedPredecessor;
            CHECK(parametrizedPredecessor.getParameterCount() == 0);
        }

        SECTION("Letter construction")
        {
            const ls::ParametrizedPredecessor parametrizedPredecessor('A');
            CHECK(parametrizedPredecessor.letter == 'A');
        }
    }

    SECTION("operator[]")
    {
        ls::ParametrizedPredecessor parametrizedPredecessor;
        for (std::size_t i = 0; i < 26; ++i)
        {
            parametrizedPredecessor.append(static_cast<char>(65 + i));
            CHECK(parametrizedPredecessor[i] == static_cast<char>(65 + i));
        }
        CHECK(parametrizedPredecessor[25] == 'Z');
    }

    SECTION("clear()")
    {
        ls::ParametrizedPredecessor parametrizedPredecessor;
        for (std::size_t i = 0; i < 26; ++i)
            parametrizedPredecessor.append(static_cast<char>(65 + i));
        parametrizedPredecessor.clear();
        CHECK(parametrizedPredecessor.getParameterCount() == 0);
    }

    SECTION("resize()")
    {
        ls::ParametrizedPredecessor parametrizedPredecessor;
        parametrizedPredecessor.resize(26);
        for (std::size_t i = 0; i < parametrizedPredecessor.getParameterCount(); ++i)
            CHECK(parametrizedPredecessor[i] == ls::Parameter());
    }

    SECTION("append()")
    {
        ls::ParametrizedPredecessor parametrizedPredecessor;
        ls::Parameter p = 'A';
        parametrizedPredecessor.append(p);
        CHECK(parametrizedPredecessor.getParameterCount() == 1);
        CHECK(parametrizedPredecessor[0] == p);
    }

}
