cmake_minimum_required(VERSION 3.29)
project(PolariumGameEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(libraries/glm)
include_directories(libraries/glm/detail)
include_directories(libraries/glm/ext)
include_directories(libraries/glm/gtc)
include_directories(libraries/glm/gtx)
include_directories(libraries/glm/simd)
include_directories(libraries/imgui)
include_directories(libraries/lua)
include_directories(libraries/sol)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIR})

add_executable(PolariumGameEngine
        libraries/imgui/imconfig.h
        libraries/imgui/imgui.cpp
        libraries/imgui/imgui.h
        libraries/imgui/imgui_demo.cpp
        libraries/imgui/imgui_draw.cpp
        libraries/imgui/imgui_internal.h
        libraries/imgui/imgui_sdl.cpp
        libraries/imgui/imgui_sdl.h
        libraries/imgui/imgui_widgets.cpp
        libraries/imgui/imstb_rectpack.h
        libraries/imgui/imstb_textedit.h
        libraries/imgui/imstb_truetype.h
        libraries/sol/sol.hpp
        libraries/sol/config.hpp
        libraries/sol/forward.hpp
        src/Game.cpp
        src/Main.cpp
)


target_link_libraries(PolariumGameEngine ${SDL2_LIBRARIES}
${LUA_LIBRARIES})