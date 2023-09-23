#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::ParametrizedPredecessor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::ParametrizedPredecessor_int>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::ParametrizedPredecessor_int>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<ls::ParametrizedPredecessor_int>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<ls::ParametrizedPredecessor_int>);
    }

    SECTION("Construction")
    {
        SECTION("Default constructor")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::ParametrizedPredecessor_int>);
            const ls::ParametrizedPredecessor_int parametrizedPredecessor;
            CHECK(parametrizedPredecessor.getParameterCount() == 0);
        }

        SECTION("Letter construction")
        {
            const ls::ParametrizedPredecessor_int parametrizedPredecessor('A');
            CHECK(parametrizedPredecessor.letter == 'A');
        }
    }

    SECTION("getParameterCount()")
    {
        ls::ParametrizedPredecessor_int parametrizedPredecessor;
        for (std::size_t i = 0; i < 26; ++i)
        {
            parametrizedPredecessor.insertParameter(static_cast<char>(65 + i), i);
        }
        CHECK(parametrizedPredecessor.getParameterCount() == 26);
    }

    SECTION("[]operator")
    {
        ls::ParametrizedPredecessor_int parametrizedPredecessor;
        for (std::size_t i = 0; i < 26; ++i)
        {
            CHECK(parametrizedPredecessor.insertParameter(static_cast<char>(65 + i), i));
            CHECK(std::size_t(parametrizedPredecessor[static_cast<char>(65 + i)]) == i);
        }
        CHECK_FALSE(parametrizedPredecessor.insertParameter('A', 10));
        CHECK(parametrizedPredecessor['Z'] == 25);
    }

    SECTION("clear()")
    {
        ls::ParametrizedPredecessor_int parametrizedPredecessor;
        for (std::size_t i = 0; i < 26; ++i)
            parametrizedPredecessor.insertParameter(static_cast<char>(65 + i), i);
        parametrizedPredecessor.clear();
        CHECK(parametrizedPredecessor.getParameterCount() == 0);
    }

    SECTION("insertOrAssignParameter()")
    {
        ls::ParametrizedPredecessor_int parametrizedPredecessor;
        ls::Parameter p = 'A';
        parametrizedPredecessor.insertOrAssignParameter(p, 0);
        parametrizedPredecessor.insertOrAssignParameter(p, 1);
        CHECK(parametrizedPredecessor.getParameterCount() == 1);
        CHECK(parametrizedPredecessor[p] == 1);
    }

    SECTION("insertParameter()")
    {
        ls::ParametrizedPredecessor_int parametrizedPredecessor;
        ls::Parameter p = 'A';
        CHECK(parametrizedPredecessor.insertParameter(p, 0));
        CHECK_FALSE(parametrizedPredecessor.insertParameter(p, 1));
        CHECK(parametrizedPredecessor.getParameterCount() == 1);
        CHECK(parametrizedPredecessor[p] == 0);
    }

}
