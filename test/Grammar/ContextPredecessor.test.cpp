#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>
#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <LSystemGenerator/Grammar/Predecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <type_traits>
#include <memory>


TEST_CASE("[Grammar] ContextPredecessor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK_FALSE(std::is_copy_constructible_v<ls::ContextPredecessor>);
        STATIC_CHECK_FALSE(std::is_copy_assignable_v<ls::ContextPredecessor>);
        STATIC_CHECK(std::is_nothrow_move_constructible_v<ls::ContextPredecessor>);
        STATIC_CHECK(std::is_nothrow_move_assignable_v<ls::ContextPredecessor>);
    }

    SECTION("Construction")
    {
        SECTION("Default constructor")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::ContextPredecessor>);
        }

        SECTION("Base predecessor (SimplePredecessor) construction")
        {
            ls::ContextPredecessor contextPredecessor;
            CHECK(std::is_same_v<decltype(contextPredecessor.get<ls::SimplePredecessor>()), const foundation::ObserverPointer<ls::SimplePredecessor>>);
            auto simpleContextPredecessor = ls::ContextPredecessor::create<ls::SimplePredecessor>('A');
            CHECK(std::is_same_v<decltype(simpleContextPredecessor.get<ls::SimplePredecessor>()), decltype(contextPredecessor.get<ls::SimplePredecessor>())>);
        }

        SECTION("Base predecessor (ParametrizedPredecessor) construction")
        {
            ls::ContextPredecessor contextParametrizedPredecessor = ls::ContextPredecessor::create<ls::ParametrizedPredecessor<int>>();
            CHECK(std::is_same_v<decltype(contextParametrizedPredecessor.get<ls::ParametrizedPredecessor<int>>()), const foundation::ObserverPointer<ls::ParametrizedPredecessor<int>>>);
            
        }

    }

    SECTION("insertOrAssignPredecessor()")
    {
        ls::ContextPredecessor contextPredecessor;
        auto simpleContext = ls::SimplePredecessor('A');
        contextPredecessor.addOrAssignContext(ls::ContextPredecessor::Part::RIGHT, simpleContext);
        contextPredecessor.addOrAssignContext(ls::ContextPredecessor::Part::RIGHT, simpleContext);
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::RIGHT));
        CHECK_FALSE(contextPredecessor.contains(ls::ContextPredecessor::Part::LEFT));
    }

    SECTION("insertPredecessor()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto simpleLeftContext = ls::SimplePredecessor('L');
        const auto simpleRightContext = ls::SimplePredecessor('R');
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::RIGHT, simpleRightContext));
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::LEFT, simpleLeftContext));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::RIGHT));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::LEFT));
    }

    SECTION("insertPredecessor() false insertion")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto simpleLeftContext = ls::SimplePredecessor('L');
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::RIGHT, simpleLeftContext));
        CHECK_FALSE(contextPredecessor.addContext(ls::ContextPredecessor::Part::RIGHT, simpleLeftContext));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::RIGHT));
        CHECK_FALSE(contextPredecessor.contains(ls::ContextPredecessor::Part::LEFT));
    }

    SECTION("contains()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = ls::SimplePredecessor('L');
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::LEFT, leftContext));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Part::LEFT));
        CHECK_FALSE(contextPredecessor.contains(ls::ContextPredecessor::Part::RIGHT));
    }

    SECTION("get()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = ls::SimplePredecessor('L');
        auto rightContext = ls::ParametrizedPredecessor<int>('R');
        rightContext.parameters.insertParameter('x', 100);
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::LEFT, leftContext));
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::RIGHT, rightContext));
        auto pLeftContext = contextPredecessor.get<ls::SimplePredecessor>(ls::ContextPredecessor::Part::LEFT);
        CHECK(pLeftContext->letter == 'L');
        auto pRightContext = contextPredecessor.get<ls::ParametrizedPredecessor<int>>(ls::ContextPredecessor::Part::RIGHT);
        CHECK(pRightContext->parameters.at('x') == 100);
    }

    SECTION("get() 'Context not found' exception")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = std::make_unique<ls::SimplePredecessor>();
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::LEFT, *leftContext));
        CHECK_THROWS_MATCHES(contextPredecessor.get<ls::SimplePredecessor>(ls::ContextPredecessor::Part::RIGHT), std::runtime_error, Catch::Matchers::Message("Context not found."));
    }

    SECTION("get() 'Invalid type for dynamic_cast'")
    {
        ls::ContextPredecessor contextPredecessor = ls::ContextPredecessor::create<ls::SimplePredecessor>();
        const auto leftContext = ls::SimplePredecessor('L');
        CHECK(contextPredecessor.addContext(ls::ContextPredecessor::Part::LEFT, leftContext));
        CHECK_THROWS_MATCHES(contextPredecessor.get<ls::ParametrizedPredecessor<int>>(ls::ContextPredecessor::Part::LEFT), std::runtime_error, Catch::Matchers::Message("Invalid type for dynamic_cast."));
    }

}
