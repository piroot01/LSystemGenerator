#include <LSystemGenerator/Foundation/ObserverPointer.hpp>
#include <LSystemGenerator/Grammar/SimplePredecessor.hpp>
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <type_traits>
#include <string>


TEST_CASE("[Foundation] foundation::ObserverPointer")
{
    typedef std::string TestType;
    SECTION("Type traits")
    {
        STATIC_CHECK(std::is_copy_constructible_v<foundation::ObserverPointer<TestType>>);
        STATIC_CHECK(std::is_copy_assignable_v<foundation::ObserverPointer<TestType>>);
        STATIC_CHECK(std::is_nothrow_copy_constructible_v<foundation::ObserverPointer<TestType>>);
        STATIC_CHECK(std::is_nothrow_copy_assignable_v<foundation::ObserverPointer<TestType>>);
    }

    SECTION("Construction")
    {
        SECTION("Default construction")
        {
            STATIC_CHECK(std::is_default_constructible_v<foundation::ObserverPointer<TestType>>);
        }

        SECTION("New pointer construction")
        {
            foundation::ObserverPointer<TestType> ptr(new TestType);
            CHECK(ptr.getRaw()->length() == 0);
        }

        SECTION("Existing pointer construction")
        {
            auto object = new TestType;
            foundation::ObserverPointer<TestType> ptr(object);
            CHECK(&(*object) == &(*ptr));
        }

        SECTION("Copy construction")
        {
            foundation::ObserverPointer<TestType> ptr1(new TestType);
            foundation::ObserverPointer<TestType> ptr2(ptr1);
            CHECK(ptr1.getRaw() == ptr2.getRaw());
        }
    }

    SECTION("getRaw()")
    {
        foundation::ObserverPointer<TestType> ptr(new TestType("string"));
        CHECK(ptr.getRaw()->length() == std::string("string").length());
    }

    SECTION("*operator")
    {
        foundation::ObserverPointer<TestType> ptr(new TestType("string"));
        CHECK((*ptr).length() == std::string("string").length());
    }

    SECTION("*operator Null pointer exception")
    {
        foundation::ObserverPointer<TestType> ptr(new TestType("string"));
        ptr.release();
        CHECK_THROWS_MATCHES(ptr->append("string"), std::runtime_error, Catch::Matchers::Message("Null pointer exception."));
    }

    SECTION("->operator")
    {
        foundation::ObserverPointer<TestType> ptr(new TestType("string"));
        CHECK(ptr->length() == std::string("string").length());
    }

    SECTION("*operator Null pointer exception")
    {
        foundation::ObserverPointer<TestType> ptr(new TestType("string"));
        ptr.release();
        CHECK_THROWS_MATCHES(ptr->append("string"), std::runtime_error, Catch::Matchers::Message("Null pointer exception."));
    }

    SECTION("Bool conversion operator")
    {
        foundation::ObserverPointer<TestType> ptr1(new TestType);
        CHECK(ptr1);
        foundation::ObserverPointer<TestType> ptr2;
        CHECK_FALSE(ptr2);
    }

    SECTION("release()")
    {
        foundation::ObserverPointer<TestType> ptr(new TestType("string"));
        ptr.release();
        CHECK_FALSE(ptr);
    }

    SECTION("reset()")
    {
        foundation::ObserverPointer<TestType> ptr(new TestType("string"));
        ptr.reset(new TestType);
        CHECK(ptr->length() == 0);
        ptr.reset();
        CHECK_FALSE(ptr);
    }

    SECTION("swap()")
    {
        foundation::ObserverPointer<TestType> ptr1(new TestType("string1"));
        foundation::ObserverPointer<TestType> ptr2(new TestType("string2"));
        CHECK(*ptr1 == std::string("string1"));
        CHECK(*ptr2 == std::string("string2"));
        ptr1.swap(ptr2);
        CHECK(*ptr1 == std::string("string2"));
        CHECK(*ptr2 == std::string("string1"));
    }

}
