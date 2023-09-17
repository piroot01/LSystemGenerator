#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>
#include <LSystemGenerator/Grammar/ParametrizedPredecessor.hpp>
#include <LSystemGenerator/Grammar/Predecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <memory>


TEST_CASE("[Grammar] ContextPredecessor")
{
    SECTION("Type traits")
    {
        STATIC_CHECK_FALSE(std::is_copy_constructible_v<ls::ContextPredecessor>);
        STATIC_CHECK_FALSE(std::is_copy_assignable_v<ls::ContextPredecessor>);
        STATIC_CHECK_FALSE(std::is_move_constructible_v<ls::ContextPredecessor>);
        STATIC_CHECK_FALSE(std::is_move_assignable_v<ls::ContextPredecessor>);
    }

    SECTION("Construction")
    {
        SECTION("Default constructor")
        {
            STATIC_CHECK(std::is_default_constructible_v<ls::ContextPredecessor>);
        }

        SECTION("Letter construction")
        {
            const ls::ContextPredecessor contextPredecessor('A');
            CHECK(contextPredecessor.letter == 'A');
        }
    }

    SECTION("add()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = std::make_unique<ls::Predecessor>('L');
        const auto rightContext = std::make_unique<ls::Predecessor>('R');
        CHECK(contextPredecessor.add(leftContext.get(), ls::ContextPredecessor::Context::LEFT));
        CHECK(contextPredecessor.add(rightContext.get(), ls::ContextPredecessor::Context::RIGHT));
        CHECK_FALSE(contextPredecessor.add(rightContext.get(), ls::ContextPredecessor::Context::RIGHT));
    }

    SECTION("add() different Predecessor types")
    {
        ls::ContextPredecessor contextPredecessor;
        auto leftContext = std::make_unique<ls::ParametrizedPredecessor>();
        leftContext->append('A');
        // Also possible, but not recommended
        auto rightContext = std::make_unique<ls::ContextPredecessor>();
        CHECK(contextPredecessor.add(leftContext.get(), ls::ContextPredecessor::Context::LEFT));
        CHECK(contextPredecessor.add(rightContext.get(), ls::ContextPredecessor::Context::RIGHT));
    }

    SECTION("contains()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = std::make_unique<ls::Predecessor>('L');
        CHECK(contextPredecessor.add(leftContext.get(), ls::ContextPredecessor::Context::LEFT));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Context::LEFT));
        CHECK_FALSE(contextPredecessor.contains(ls::ContextPredecessor::Context::RIGHT));
    }

    SECTION("getPredecessor()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = std::make_unique<ls::Predecessor>('L');
        auto rightContext = std::make_unique<ls::ParametrizedPredecessor>();
        rightContext->append('R');
        CHECK(contextPredecessor.add(leftContext.get(), ls::ContextPredecessor::Context::LEFT));
        CHECK(contextPredecessor.add(rightContext.get(), ls::ContextPredecessor::Context::RIGHT));
        CHECK(contextPredecessor.getPredecessor(ls::ContextPredecessor::Context::LEFT)->letter == 'L');
        CHECK((*static_cast<const ls::ParametrizedPredecessor*>(contextPredecessor.getPredecessor(ls::ContextPredecessor::Context::RIGHT)))[0] == 'R');
    }

    SECTION("getPredecessor() exception")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = std::make_unique<ls::Predecessor>();
        CHECK(contextPredecessor.add(leftContext.get(), ls::ContextPredecessor::Context::LEFT));
        CHECK_THROWS_AS(contextPredecessor.getPredecessor(ls::ContextPredecessor::Context::RIGHT), std::runtime_error);
    }

}
