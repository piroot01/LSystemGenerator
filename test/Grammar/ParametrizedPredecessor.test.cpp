#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::ParametrizedPredecessor")
{
    typedef double TestType;

    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::ParametrizedPredecessor<TestType>>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::ParametrizedPredecessor<TestType>>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<ls::ParametrizedPredecessor<TestType>>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<ls::ParametrizedPredecessor<TestType>>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::ParametrizedPredecessor<TestType>>);
        }

        SECTION("Letter construction")
        {
            ls::ParametrizedPredecessor<TestType> pararametrizedPredecessor('A');
            CHECK(pararametrizedPredecessor.letter == 'A');
        }

    }

    SECTION("Parameter acces")
    {
        ls::ParametrizedPredecessor<TestType> pararametrizedPredecessor('A');
        pararametrizedPredecessor.parameters.insertOrAssignParameter('x', 1.2);
        CHECK(pararametrizedPredecessor.parameters.insertParameter('y', 1.4));
        CHECK(pararametrizedPredecessor.parameters.at('x') == 1.2);
        CHECK(pararametrizedPredecessor.parameters.getParameterCount() == 2);
    }

    SECTION("addSymbols()")
    {
        ls::ParametrizedPredecessor<TestType> parametrizedPredecessor;
        const std::string expressionString = "x + y < 3";
        parametrizedPredecessor.parameters.insertOrAssignParameter('x', 1.2);
        CHECK(parametrizedPredecessor.parameters.insertParameter('y', 1.4));
        exprtk::symbol_table<TestType> symbolTable;
        parametrizedPredecessor.registerSymbols(symbolTable);
        exprtk::expression<TestType> expression;
        expression.register_symbol_table(symbolTable);
        exprtk::parser<TestType> parser;
        parser.compile(expressionString, expression);
        CHECK(expression.value());
        parametrizedPredecessor.parameters['x'] = 1.99;
        CHECK_FALSE(expression.value());
    }

}
