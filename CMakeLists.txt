cmake_minimum_required(VERSION 3.16)

set(This SortsVis)

project(${This} CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(Src
    src/Main.cpp
    src/SortingAlgorithms.cpp
    src/SortingAlgorithms.hpp
    src/DrawVector.hpp
    src/DrawVector.cpp
    src/Application.hpp
    src/Application.cpp
)

add_executable(${This} ${Src})
target_link_libraries(${This} PRIVATE sfml-graphics)
target_compile_features(${This} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET ${This}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${This}>
        VERBATIM)
endif()

install(TARGETS ${This})
