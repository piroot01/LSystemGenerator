# Find the Catch2 testing framework
find_package(Catch2 CONFIG REQUIRED)

# Grammar tests
set(GRAMMAR_TESTS
    Grammar/Predecessor.test.cpp
    Grammar/ParametrizedPredecessor.test.cpp
    Grammar/ContextPredecessor.test.cpp
)


set(GRAMMAR_TESTS_DIR ${TESTS_DIR}/Grammar)


foreach(target ${GRAMMAR_TESTS})
    get_filename_component(name ${target} NAME_WE)
    add_executable(${name} ${GRAMMAR_TESTS_DIR}/${name}.test.cpp)
    target_link_libraries(${name} Catch2::Catch2WithMain ${PROJECT_NAME})
endforeach()
