cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE on)

file(GLOB rtn_centered_text_SRC CONFIGURE_DEPENDS *.cpp)
add_library(rtn_centered_text SHARED ${rtn_centered_text_SRC})
target_include_directories(rtn_centered_text PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rtn_centered_text PUBLIC rnoh)