cmake_minimum_required(VERSION 3.13)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)
SET(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
AUX_SOURCE_DIRECTORY(libft LIB)
add_executable(ft_printf ${LIB} main.c ft_printf.c printf.h ft_putnbrf.c ft_putnbrll.c ft_putnbrlln.c ft_putstrn.c ft_retnbr_float.c ft_putcharn.c ft_obnul_flags.c ft_ptr.c ft_strjoinfree.c ft_octal.c ft_declima.c ft_float.c ft_pars.c ft_flags.c ft_percent.c ft_uitoa_base.c ft_binar.c ft_itoa_baseld.c)
link_libraries(libft/libft.a)