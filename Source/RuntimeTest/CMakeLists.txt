cmake_minimum_required(VERSION 3.26)

# ---------------------- CMAKE INCLUDES ----------------------
include(${CMAKE_SOURCE_DIR}/Scripts/CMake/FetchLibraries.cmake)
# ------------------------------------------------------------

# ---------------------- FILE ADDITION -----------------------
file(GLOB_RECURSE SUBDIRECTORIES "${CMAKE_SOURCE_DIR}/Source/RuntimeTest/*.cpp" "${CMAKE_SOURCE_DIR}/Source/RuntimeTest/*.h")
source_group(TREE "${CMAKE_SOURCE_DIR}/Source/RuntimeTest" FILES ${SUBDIRECTORIES})
add_executable(RuntimeTest main.cpp ${SUBDIRECTORIES})
# ------------------------------------------------------------

# -------------------- INCLUDE LIBRARIES ---------------------
target_include_directories(RuntimeTest PRIVATE "${CMAKE_SOURCE_DIR}/Source")
# ------------------------------------------------------------

# --------------------- LINK LIBRARIES -----------------------
target_link_libraries(RuntimeTest PRIVATE Runtime)
# ------------------------------------------------------------

# -------------------- MACRO DEFINITIONS ---------------------
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_definitions(RuntimeTest PUBLIC RUNTIME_TEST_API=__declspec\(dllexport\))
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_definitions(RuntimeTest PUBLIC RUNTIME_TEST_API=__attribute__\(\(visibility\(\"default\"\)\)\))
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_definitions(RuntimeTest PUBLIC RUNTIME_TEST_API=__attribute__\(\(visibility\(\"default\"\)\)\))
else()
	pMessage(FATAL_ERROR "[CMAKE ERROR] -- UNSUPPORTED COMPILER. PLEASE CHECK YOUR COMPILER AND PLATFORM.")
endif()
# ------------------------------------------------------------