cmake_minimum_required(VERSION 3.26)

include(FetchContent)

# STB_IMAGE library
FetchContent_Declare(
    stbi
    GIT_REPOSITORY https://github.com/nothings/stb.git
)

# ASSIMP library
FetchContent_Declare(
    assimp
    GIT_REPOSITORY https://github.com/assimp/assimp.git
)

# IMGUI library
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG docking
)

# IMGUIZMO library
FetchContent_Declare(
	imguizmo
	GIT_REPOSITORY https://github.com/CedricGuillemet/ImGuizmo.git
    GIT_TAG "1.83"
)

# YAML-CPP library
FetchContent_Declare(
	yaml-cpp
	GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
)

# FREE-TYPE library
FetchContent_Declare(
    freetype
    GIT_REPOSITORY https://gitlab.freedesktop.org/freetype/freetype.git
    GIT_TAG       master
)

# If assimp declared successfully, set installation options
if(assimp_ADDED)
    set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build shared libraries" FORCE)
    set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "Assimp build tests" FORCE)
    set(ASSIMP_INSTALL OFF CACHE BOOL "Assimp install" FORCE)
    set(ASSIMP_INSTALL_PDB OFF CACHE BOOL "Assimp install PDB" FORCE)
endif()
