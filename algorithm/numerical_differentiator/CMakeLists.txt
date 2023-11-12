#####################################
# Define Target Information
#####################################
set(TARGET_NAME numerical_differentiator)

set(TARGET_INCLUDE_DIR include)
set(TARGET_SOURCE_DIR src)

set(SRC_FILES
        ${TARGET_SOURCE_DIR}/NumericalDifferentiator.cpp
        )

#####################################
# Define Target
#####################################
add_library(${TARGET_NAME} ${SRC_FILES})

set_property(TARGET ${TARGET_NAME} PROPERTY CXX_STANDARD 17)
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    target_compile_options(${TARGET_NAME} PRIVATE -stdlib=libc++)
endif ()

target_include_directories(
        ${TARGET_NAME}
        SYSTEM
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(${TARGET_NAME} PUBLIC interpolation)

set_target_properties(${TARGET_NAME} PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${METHODS_OF_COMPUTATION_LIB_DIR}")
