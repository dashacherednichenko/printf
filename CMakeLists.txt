cmake_minimum_required(VERSION 3.13)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
AUX_SOURCE_DIRECTORY(libft LIB)
add_executable(ft_printf ${LIB} main.c ft_printf.c libftprintf.h ft_putnbrf.c ft_putnbrll.c ft_putnbrlln.c ft_putnbrn.c ft_putstrn.c)
link_libraries(libft/libft.a)