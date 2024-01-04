cmake_minimum_required(VERSION 3.26)

# ---------------------- CMAKE INCLUDES ----------------------
include(${CMAKE_SOURCE_DIR}/Scripts/CMake/FetchLibraries.cmake)
# ------------------------------------------------------------

# ------------------- AVAILABLE LIBRARIES --------------------
FetchContent_MakeAvailable(imgui)
# ------------------------------------------------------------

# ---------------------- IMGUI FILES -------------------------
file(GLOB IMGUI_FILES "${imgui_SOURCE_DIR}/*.cpp" "${imgui_SOURCE_DIR}/*.h")
source_group(TREE "${imgui_SOURCE_DIR}" FILES ${IMGUI_FILES})
add_library(imgui STATIC ${IMGUI_FILES})
# ------------------------------------------------------------

# ---------------------- FILE ADDITION -----------------------
file(GLOB_RECURSE SUBDIRECTORIES "${CMAKE_SOURCE_DIR}/Source/Editor/*.cpp" "${CMAKE_SOURCE_DIR}/Source/Editor/*.h")
source_group(TREE "${CMAKE_SOURCE_DIR}/Source/Editor" FILES ${SUBDIRECTORIES})
add_library(Editor STATIC main.cpp ${SUBDIRECTORIES} )
# ------------------------------------------------------------

# ---------------------- INCLUDE DIRECTORIES -----------------
target_include_directories(Editor PRIVATE "${CMAKE_SOURCE_DIR}/Source")
target_include_directories(Editor PRIVATE "${CMAKE_SOURCE_DIR}/External")
target_include_directories(Editor PUBLIC "${imgui_SOURCE_DIR}")

target_link_libraries(Editor PRIVATE Runtime)
target_link_libraries(Editor PUBLIC imgui)
# ------------------------------------------------------------

# ---------------------- EXECUTES ----------------------------
execute_process(COMMAND "${CMAKE_SOURCE_DIR}/Tools/ReflectionParser/bin/Debug/net8.0/ReflectionParser.exe" ${PROJECT_SOURCE_DIR}/Source/Editor)
# ------------------------------------------------------------

# -------------------- MACRO DEFINITIONS ---------------------
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_definitions(Editor PUBLIC EDITOR_API=__declspec\(dllexport\))
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_definitions(Editor PUBLIC EDITOR_API=__attribute__\(\(visibility\(\"default\"\)\)\))
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_definitions(Editor PUBLIC EDITOR_API=__attribute__\(\(visibility\(\"default\"\)\)\))
else()
	message(FATAL_ERROR "[CMAKE ERROR] -- UNSUPPORTED COMPILER. PLEASE CHECK YOUR COMPILER AND PLATFORM.")
endif()
# ------------------------------------------------------------