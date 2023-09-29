#include <LSystemGenerator/Grammar/SymbolRegister.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>


TEST_CASE("[Grammar] ls::SymbolRegister")
{
    typedef double TestType;

    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<ls::SymbolRegistry<TestType>>);
        STATIC_CHECK(std::is_copy_assignable_v<ls::SymbolRegistry<TestType>>);
        STATIC_CHECK(std::is_move_constructible_v<ls::SymbolRegistry<TestType>>);
        STATIC_CHECK(std::is_move_assignable_v<ls::SymbolRegistry<TestType>>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::SymbolRegistry<TestType>>);
        }

    }

    SECTION("registerSymbols() ParameterizedPredecessor")
    {
        ls::ParametrizedPredecessor<TestType> parameterizedPredecessor('P');
        ls::SymbolRegistry<TestType> symbolRegistry;
        symbolRegistry.registerSymbols(parameterizedPredecessor);
        auto symbolTable = symbolRegistry.get();
        CHECK(symbolTable.variable_count() == 0);
        parameterizedPredecessor.parameters.insertParameter('x');
        parameterizedPredecessor.parameters.insertParameter('y');
        parameterizedPredecessor.parameters.insertParameter('z');
        symbolRegistry.registerSymbols(parameterizedPredecessor);
        CHECK(symbolTable.variable_count() == 3);
    }

    SECTION("registerSymbols() ContextPredecessor")
    {
        ls::ParametrizedPredecessor<TestType> middlePart('M');
        middlePart.parameters.insertParameter('x');
        middlePart.parameters.insertParameter('y');
        ls::ContextPredecessor contextPredecessor = ls::ContextPredecessor::create(middlePart);
        ls::SymbolRegistry<TestType> symbolTable;
        ls::ParametrizedPredecessor<TestType> leftContext;
        leftContext.parameters.insertOrAssignParameter('a');
        leftContext.parameters.insertOrAssignParameter('b');
        contextPredecessor.addOrAssignContext(ls::ContextPredecessor::Part::LEFT, leftContext);
        contextPredecessor.addOrAssignContext(ls::ContextPredecessor::Part::RIGHT, ls::SimplePredecessor('S'));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::MIDDLE));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::LEFT));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::RIGHT));
        symbolTable.registerSymbols(contextPredecessor);
        CHECK(symbolTable.get().variable_count() == 4);
    }

    SECTION("registerConstant()")
    {
        ls::SymbolRegistry<TestType> symbolRegistry;
        const TestType pi = 3.1415;
        symbolRegistry.registerConstant("PI", pi);
        CHECK(symbolRegistry.get().variable_count());
    }

    SECTION("get()")
    {
        ls::SymbolRegistry<TestType> symbolRegistry;
        const TestType pi = 3.1415;
        symbolRegistry.registerConstant("PI", pi);
        CHECK(symbolRegistry.get().variable_count());
        const auto symbolTable = symbolRegistry.get();
        CHECK(std::is_same_v<exprtk::symbol_table<TestType>, std::decay_t<decltype(symbolTable)>>);
    }

}
