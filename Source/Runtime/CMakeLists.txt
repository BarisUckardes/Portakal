cmake_minimum_required(VERSION 3.26)

# ---------------------- CMAKE INCLUDES ----------------------
include(${CMAKE_SOURCE_DIR}/Scripts/CMake/FetchLibraries.cmake)
# ------------------------------------------------------------

# ---------------------- CMAKE FETCH -------------------------
FetchContent_MakeAvailable(stbi)
FetchContent_MakeAvailable(yaml-cpp)
FetchContent_MakeAvailable(freetype)
# ------------------------------------------------------------

# ---------------------- FILE ADDITION -----------------------
file(GLOB_RECURSE SUBDIRECTORIES "${CMAKE_SOURCE_DIR}/Source/Runtime/*.cpp" "${CMAKE_SOURCE_DIR}/Source/Runtime/*.h")
source_group(TREE "${CMAKE_SOURCE_DIR}/Source/Runtime" FILES ${SUBDIRECTORIES})
add_library(Runtime main.cpp ${SUBDIRECTORIES})
# ------------------------------------------------------------

# ------------------- INCLUDE DIRECTORIES --------------------
target_include_directories(Runtime PRIVATE "${CMAKE_SOURCE_DIR}/Source")
target_include_directories(Runtime PUBLIC "${yaml-cpp_SOURCE_DIR}/include")

target_link_libraries(Runtime PUBLIC yaml-cpp)
# ------------------------------------------------------------

# ------------------ FORCE SHADER DIRECTORY ------------------
target_include_directories(Runtime PRIVATE "${CMAKE_SOURCE_DIR}/External/")

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/dxcompilerd.lib")
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/glslangd.lib")

    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/shaderc_combinedd.lib")

    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/spirv-cross-cored.lib")
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/spirv-cross-glsld.lib")
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/spirv-cross-hlsld.lib")
else()
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/dxcompiler.lib")
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/glslang.lib")

    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/shaderc_combined.lib")

    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/spirv-cross-core.lib")
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/spirv-cross-glsl.lib")
    target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/spirv-cross-hlsl.lib")
endif()
# ------------------------------------------------------------

# ----------------- STB IMAGE IMPLEMENTATION -----------------
if (stbi_POPULATED) 
    target_compile_definitions(Runtime PUBLIC STB_IMAGE_IMPLEMENTATION=1)
    target_include_directories(Runtime PUBLIC ${stbi_SOURCE_DIR})
else ()
    target_compile_definitions(Runtime PUBLIC STB_IMAGE_IMPLEMENTATION=0)
endif ()
# ------------------------------------------------------------

# ----------------- FREETYPE IMPLEMENTATION ------------------
if (freetype_POPULATED) 
	target_link_libraries(Runtime PUBLIC freetype)
endif ()

# ------------------- VULKAN IMPLEMENTATION ------------------
target_include_directories(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Vulkan/Include")

target_link_libraries(Runtime PUBLIC "${CMAKE_SOURCE_DIR}/External/Libs/vulkan-1.lib")
# ------------------------------------------------------------

# ----------------- PREPROCESSOR DEFINITIONS -----------------
if (CMAKE_BUILD_TYPE MATCHES Debug)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_DEBUG)
endif ()

if (CMAKE_BUILD_TYPE MATCHES Release)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_RELEASE)
endif ()
# ------------------------------------------------------------

# ------------------ PLATFORM DEFINITIONS --------------------
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_WINDOWS=1)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_LINUX=0)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_MACOS=0)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND PLATFORM_ID STREQUAL "Linux")
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_WINDOWS=0)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_LINUX=1)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_MACOS=0)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND PLATFORM_ID STREQUAL "Linux")
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_WINDOWS=0)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_LINUX=1)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_MACOS=0)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND PLATFORM_ID STREQUAL "Darwin")
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_WINDOWS=0)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_LINUX=0)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_MACOS=1)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND PLATFORM_ID STREQUAL "Darwin")
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_WINDOWS=0)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_LINUX=0)
    target_compile_definitions(Runtime PUBLIC PORTAKAL_PLATFORM_MACOS=1)
else()
	pMessage(FATAL_ERROR "[CMAKE ERROR] -- UNSUPPORTED PLATFORM. PLEASE CHECK YOUR COMPILER AND PLATFORM.")
endif()
# ------------------------------------------------------------

# -------------------- MACRO DEFINITIONS ---------------------
if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_definitions(Runtime PUBLIC RUNTIME_API=__declspec\(dllexport\))
    target_compile_definitions(Runtime PUBLIC FORCEINLINE=__forceinline)
    target_compile_definitions(Runtime PUBLIC NOINLINE=__declspec\(noinline\))
    target_compile_definitions(Runtime PUBLIC INLINE=__inline)
    target_compile_definitions(Runtime PUBLIC NULLPTR=decltype\(nullptr\)\(\))
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_definitions(Runtime PUBLIC RUNTIME_API=__attribute__\(\(visibility\(\"default\"\)\)\))
    target_compile_definitions(Runtime PUBLIC FORCEINLINE=__attribute__\(\(always_inline\)\))
    target_compile_definitions(Runtime PUBLIC NOINLINE=__attribute__\(\(noinline\)\))
    target_compile_definitions(Runtime PUBLIC INLINE=__attribute__\(\(always_inline\)\))
    target_compile_definitions(Runtime PUBLIC NULLPTR=nullptr)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_definitions(Runtime PUBLIC RUNTIME_API=__attribute__\(\(visibility\(\"default\"\)\)\))
    target_compile_definitions(Runtime PUBLIC FORCEINLINE=__attribute__\(\(always_inline\)\))
    target_compile_definitions(Runtime PUBLIC NOINLINE=__attribute__\(\(noinline\)\))
    target_compile_definitions(Runtime PUBLIC INLINE=__attribute__\(\(always_inline\)\))
    target_compile_definitions(Runtime PUBLIC NULLPTR=nullptr)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GCC")
	target_compile_definitions(Runtime PUBLIC RUNTIME_API=__attribute__\(\(visibility\(\"default\"\)\)\))
	target_compile_definitions(Runtime PUBLIC FORCEINLINE=__attribute__\(\(always_inline\)\))
	target_compile_definitions(Runtime PUBLIC NOINLINE=__attribute__\(\(noinline\)\))
	target_compile_definitions(Runtime PUBLIC INLINE=__attribute__\(\(always_inline\)\))
	target_compile_definitions(Runtime PUBLIC NULLPTR=nullptr)
else()
	pMessage(FATAL_ERROR "[CMAKE ERROR] -- UNSUPPORTED COMPILER. PLEASE CHECK YOUR COMPILER AND PLATFORM.")
endif()
# ------------------------------------------------------------

# ---------------------- EXECUTES ----------------------------
execute_process(COMMAND "${CMAKE_SOURCE_DIR}/Tools/ReflectionParser/bin/Debug/net8.0/ReflectionParser.exe" ${PROJECT_SOURCE_DIR}/Source/Runtime)
# ------------------------------------------------------------

# --------------------- LINK LIBRARIES -----------------------
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_link_libraries(Runtime PRIVATE d3d12.lib)
    target_link_libraries(Runtime PRIVATE d3d11.lib)
    target_link_libraries(Runtime PRIVATE dxgi.lib)
    target_link_libraries(Runtime PRIVATE d3dcompiler.lib)
    target_link_libraries(Runtime PRIVATE Shlwapi.lib)
    target_link_libraries(Runtime PRIVATE Comctl32.lib)
    target_link_libraries(Runtime PRIVATE dinput8.lib)
    target_link_libraries(Runtime PRIVATE XInput.lib)
    target_link_libraries(Runtime PRIVATE dxguid.lib)
    target_link_libraries(Runtime PRIVATE Ws2_32.lib)
endif ()
# ------------------------------------------------------------