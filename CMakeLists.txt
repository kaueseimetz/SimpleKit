cmake_minimum_required(VERSION 3.10)
project(SimpleKit LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(libs/infoware)
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

add_executable(SimpleKit main.cpp)

if(WIN32) 
	target_link_libraries(SimpleKit PRIVATE infoware gdi32 version Ole32 OleAut32 wbemuuid ntdll SDL2::SDL2 SDL2_ttf::SDL2_ttf)
else() 
	target_link_libraries(SimpleKit PRIVATE infoware SDL2::SDL2 SDL2_ttf::SDL2_ttf)
endif()

#set(CMAKE_BUILD_TYPE Debug)
