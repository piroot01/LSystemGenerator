#include <LSystemGenerator/Grammar/Condition.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::Condition")
{
    typedef float TestType;

    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::Condition>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::Condition>);
        STATIC_CHECK(std::is_move_constructible_v<ls::Condition>);
        STATIC_CHECK(std::is_move_assignable_v<ls::Condition>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::Condition>);
        }

        // Does not test anything.
        SECTION("Expression construction")
        {
            ls::Condition("a + b < 10");
        }
    }

    // Does not test anything.
    SECTION("setExpression()")
    {
        ls::Condition condition;
        condition.setExpression("a + b < 10");
    }

    SECTION("evaluate()")
    {
        ls::ParametrizedPredecessor<TestType> predecessor;
        predecessor.parameters.insertParameter('a', 10);
        predecessor.parameters.insertParameter('b');
        predecessor.parameters['b'] = 20;
        ls::SymbolRegistry<TestType> symbolRegistry;
        symbolRegistry.registerSymbols(predecessor);
        symbolRegistry.registerConstant("C", 30);
        ls::Condition condition("a + b - C >= 0 & a > 5");
        exprtk::parser<TestType> parser;
        CHECK(condition.evaluate(parser, symbolRegistry));
    }

}
