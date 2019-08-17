cmake_minimum_required(VERSION 3.14)

project(fdf)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
include_directories(lib minilibx) # header directories
link_directories(lib minilibx) # library directories
set(SOURCE_FILES draw.c
        draw_line.c
        fdf.h
        ft_check_num_and_color.c
        ft_exit_error.c
        ft_make_op.c
        help_init.c
        init.c
        main.c)
add_executable(fdf ${SOURCE_FILES}) # compilation
target_link_libraries(fdf -lft  -lmlx "-framework OpenGL" "-framework AppKit")