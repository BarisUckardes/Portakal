cmake_minimum_required(VERSION 3.26)

# ------------------ PROJECT NAME ------------------
project("Portakal")
# --------------------------------------------------

# ------------------ CXX FLAGS ---------------------
set(CMAKE_CXX_STANDARD 20)
# --------------------------------------------------

# --------------- COMPILER VERSIONS ----------------
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Platform is Windows, Using MSVC Compiler Version ${MSVC_VERSION}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Platform is Unix, Using Clang Compiler Version ${CMAKE_CXX_COMPILER_VERSION}")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Platform is Unix, Using GCC Compiler Version ${CMAKE_CXX_COMPILER_VERSION}")
else()
    message(FATAL_ERROR "[CMAKE ERROR] -- UNSUPPORTED COMPILER. PLEASE CHANGE YOUR COMPILER.")
endif ()
# --------------------------------------------------

# ------------------ SUBDIRECTORIES ----------------
add_subdirectory("Source/RuntimeTest")
add_subdirectory("Source/Runtime")