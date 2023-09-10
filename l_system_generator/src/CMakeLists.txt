# Grep all sources
file(GLOB SOURCES
    "grammar/*.cpp"
)

# Create local library
add_library(l_system_generator ${SOURCES})

set_target_properties(l_system_generator
    PROPERTIES
    OUTPUT_NAME l_system_generator
)

#target_include_directories(l_system_generator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../../include)

target_include_directories(l_system_generator PUBLIC ${CMAKE_SOURCE_DIR}/l_system_generator/include)
