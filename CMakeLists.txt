cmake_minimum_required(VERSION 3.10)

project(SimpleKit LANGUAGES CXX)

add_subdirectory(libs/infoware)

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SimpleKit main.cpp)

if(WIN32) 
	target_link_libraries(SimpleKit PRIVATE infoware gdi32 version Ole32 OleAut32 wbemuuid ntdll)
else() 
	target_link_libraries(SimpleKit PRIVATE infoware) 
endif()

#set(CMAKE_BUILD_TYPE Debug)
