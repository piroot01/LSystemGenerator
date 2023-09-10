set(TEST_NAME init)


add_executable(${TEST_NAME} main.cpp)


target_link_libraries(${TEST_NAME} PRIVATE l_system_generator)
