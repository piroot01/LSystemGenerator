#include <LSystemGenerator/Grammar/ParameterMap.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::detail::ParameterMap")
{
    typedef int TestType;

    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::detail::ParameterMap<int>>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::detail::ParameterMap<int>>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<ls::detail::ParameterMap<int>>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<ls::detail::ParameterMap<int>>);
    }

    SECTION("Construction")
    {
        SECTION("Default constructor")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::detail::ParameterMap<int>>);
            const ls::detail::ParameterMap<TestType> parameterMap;
            CHECK(parameterMap.getParameterCount() == 0);
        }

    }

    SECTION("getParameterCount()")
    {
        ls::detail::ParameterMap<TestType> parameterMap;
        for (std::size_t i = 0; i < 26; ++i)
        {
            parameterMap.insertParameter(static_cast<char>(65 + i), i);
        }
        CHECK(parameterMap.getParameterCount() == 26);
    }

    SECTION("[]operator")
    {
        ls::detail::ParameterMap<TestType> parameterMap;
        for (std::size_t i = 0; i < 26; ++i)
        {
            CHECK(parameterMap.insertParameter(static_cast<char>(65 + i), i));
            CHECK(std::size_t(parameterMap[static_cast<char>(65 + i)]) == i);
        }
        CHECK_FALSE(parameterMap.insertParameter('A', 10));
        CHECK(parameterMap['Z'] == 25);
    }

    SECTION("clear()")
    {
        ls::detail::ParameterMap<TestType> parameterMap;
        for (std::size_t i = 0; i < 26; ++i)
            parameterMap.insertParameter(static_cast<char>(65 + i), i);
        parameterMap.clear();
        CHECK(parameterMap.getParameterCount() == 0);
    }

    SECTION("insertOrAssignParameter()")
    {
        ls::detail::ParameterMap<TestType> parameterMap;
        char p = 'A';
        parameterMap.insertOrAssignParameter(p, 0);
        parameterMap.insertOrAssignParameter(p, 1);
        CHECK(parameterMap.getParameterCount() == 1);
        CHECK(parameterMap[p] == 1);
    }

    SECTION("insertParameter()")
    {
        ls::detail::ParameterMap<TestType> parameterMap;
        char p = 'A';
        CHECK(parameterMap.insertParameter(p, 0));
        CHECK_FALSE(parameterMap.insertParameter(p, 1));
        CHECK(parameterMap.getParameterCount() == 1);
        CHECK(parameterMap[p] == 0);
    }

    SECTION("iterators")
    {
        ls::detail::ParameterMap<TestType> parameterMap;
        parameterMap.insertParameter('x', 3);
        parameterMap.insertParameter('y', 2);
        parameterMap.insertParameter('z', 1);
        int i = 0;
        for (auto iterator = parameterMap.cbegin(); iterator != parameterMap.cend(); ++iterator)
        {
            i += 1;
            CHECK(iterator->second == i);
        }
    }

}
