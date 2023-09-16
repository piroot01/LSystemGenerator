# Grep all sources
file(GLOB SOURCES
    "Grammar/*.cpp"
)

# Create local library
add_library(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
)


target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include)
