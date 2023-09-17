#include <LSystemGenerator/Grammar/ContextPredecessor.hpp>
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
    }

    SECTION("add()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = std::make_unique<ls::Predecessor>('L');
        const auto noneContext = std::make_unique<ls::Predecessor>('N');
        const auto rightContext = std::make_unique<ls::Predecessor>('R');
        CHECK(contextPredecessor.add(leftContext.get(), ls::ContextPredecessor::Context::LEFT));
        CHECK(contextPredecessor.add(noneContext.get(), ls::ContextPredecessor::Context::NONE));
        CHECK(contextPredecessor.add(rightContext.get(), ls::ContextPredecessor::Context::RIGHT));
        CHECK_FALSE(contextPredecessor.add(noneContext.get(), ls::ContextPredecessor::Context::NONE));
    }

    SECTION("contains()")
    {
        ls::ContextPredecessor contextPredecessor;
        const auto leftContext = std::make_unique<ls::Predecessor>('L');
        const auto noneContext = std::make_unique<ls::Predecessor>('N');
        CHECK(contextPredecessor.add(leftContext.get(), ls::ContextPredecessor::Context::LEFT));
        CHECK(contextPredecessor.add(noneContext.get(), ls::ContextPredecessor::Context::NONE));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Context::LEFT));
        CHECK(contextPredecessor.contains(ls::ContextPredecessor::Context::NONE));
        CHECK_FALSE(contextPredecessor.contains(ls::ContextPredecessor::Context::RIGHT));
    }

}
