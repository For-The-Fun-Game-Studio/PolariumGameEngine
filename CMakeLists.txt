cmake_minimum_required(VERSION 3.29)
project(PolariumGameEngine)

set(CMAKE_CXX_STANDARD 17)


file(GLOB SDLFILES "libraries/SDL2/include/*.h")
file(GLOB LUAFILES "libraries/Lua/include/*.h")
file(GLOB IMGGUIFILES "libraries/imgui/*.h" "libraries/imgui/*.cpp")
file(GLOB SOLFILES "libraries/sol/*.hpp")


include_directories(libraries/glm)
include_directories(libraries/glm/detail)
include_directories(libraries/glm/ext)
include_directories(libraries/glm/gtc)
include_directories(libraries/glm/gtx)
include_directories(libraries/glm/simd)
include_directories(libraries/imgui)
include_directories(libraries/sol)



if(WIN32)
    add_subdirectory(libraries/SDL2)
    include_directories(libraries/Lua/include)
    link_directories(libraries/Lua)
elseif (UNIX)
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})

    find_package(Lua REQUIRED)
    include_directories(${LUA_INCLUDE_DIR})
endif ()



add_executable(PolariumGameEngine
        ${IMGGUIFILES}
        ${SOLFILES}
        ${SDLFILES}
        ${LUAFILES}
        src/Game.cpp
        src/Main.cpp
)
if(WIN32)
target_link_libraries(PolariumGameEngine SDL2main SDL2)
elseif (UNIX)
    target_link_libraries(PolariumGameEngine ${SDL2_LIBRARIES})
endif ()
target_link_libraries(PolariumGameEngine ${LUA_LIBRARIES})