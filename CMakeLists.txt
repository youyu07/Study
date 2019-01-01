cmake_minimum_required(VERSION 3.6)

project(Game)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(DEPENDENCY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependency)

file(COPY ${DEPENDENCY_DIR}/sdl/lib/SDL2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/content DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})


set(GAME_SOURCE	src/main.cpp
				src/application.cpp)

add_executable(${PROJECT_NAME} WIN32 ${GAME_SOURCE})

target_include_directories(${PROJECT_NAME}
    PRIVATE ${DEPENDENCY_DIR}/bgfx/include
	PRIVATE ${DEPENDENCY_DIR}/sdl/include)

target_link_libraries(${PROJECT_NAME}
    PRIVATE ${DEPENDENCY_DIR}/sdl/lib/SDL2.lib
	PRIVATE ${DEPENDENCY_DIR}/bgfx/lib/bx.lib
	PRIVATE ${DEPENDENCY_DIR}/bgfx/lib/bimg.lib
	PRIVATE ${DEPENDENCY_DIR}/bgfx/lib/bgfx.lib)