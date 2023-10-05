#include <LSystemGenerator/Grammar/ParametrizedSuccessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::ParametrizedSuccessor")
{
    typedef float TestType;

    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::ParametrizedSuccessor>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::ParametrizedSuccessor>);
        STATIC_CHECK(std::is_move_constructible_v<ls::ParametrizedSuccessor>);
        STATIC_CHECK(std::is_move_assignable_v<ls::ParametrizedSuccessor>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::ParametrizedSuccessor>);
            const ls::ParametrizedSuccessor parametrizedSuccessor;
            CHECK(parametrizedSuccessor.letter == 0);
        }

        // Does not test anything.
        SECTION("Letter construction")
        {
            const ls::ParametrizedSuccessor parametrizedSuccessor('F');
            CHECK(parametrizedSuccessor.letter == 'F');
        }

    }

    SECTION("addExpression()")
    {
        // have no simple method of testing
        ls::ParametrizedSuccessor parametrizedSuccessor('F');
        parametrizedSuccessor.addExpression("a + b");
        parametrizedSuccessor.addExpression("a");
    }

    SECTION("evaluate()")
    {
        ls::ParametrizedPredecessor<TestType> parametrizedPredecessor('F');
        parametrizedPredecessor.parameters.insertParameter('a');
        parametrizedPredecessor.parameters.insertParameter('b');
        ls::ParametrizedSuccessor parametrizedSuccessor(parametrizedPredecessor.letter);
        parametrizedSuccessor.addExpression("a + b");
        parametrizedSuccessor.addExpression("2a");
        parametrizedPredecessor.parameters['a'] = 10;
        parametrizedPredecessor.parameters['b'] = 20;
        ls::SymbolRegistry<TestType> symbolRegistry;
        symbolRegistry.registerSymbols(parametrizedPredecessor);
        exprtk::parser<TestType> parser;
        std::string successorString = "";
        parametrizedSuccessor.evaluate(parser, symbolRegistry, successorString);
        CHECK(successorString == "F(30, 20)");
    }

}
