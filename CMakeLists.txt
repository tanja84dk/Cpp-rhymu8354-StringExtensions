# CMakeLists.txt for StringExtensions
#
# © 2018-2019 by Richard Walters

cmake_minimum_required(VERSION 3.8)
project(StringExtensions)

set(Headers
    include/StringExtensions/StringExtensions.hpp
)

set(Sources
    src/StringExtensions.cpp
)

add_library(${PROJECT_NAME} STATIC ${Sources} ${Headers})

add_library(libs::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
add_library(rhymu8354::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(${PROJECT_NAME}
	PRIVATE
		cxx_std_14
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
	VERSION ${PROJECT_VERSION}
	SOVERSION ${PROJECT_VERSION_MAJOR}
    FOLDER Libraries
)

if(BUILD_TESTING)
	add_subdirectory(test)
endif()

