cmake_minimum_required(VERSION 3.12)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
#AUX_SOURCE_DIRECTORY(libft LIBA)
set(SOURCE_LIB libftprintf.h)

add_library(foo STATIC ${SOURCE_LIB})
add_executable(ft_printf main.c)

target_link_libraries(ft_printf foo)