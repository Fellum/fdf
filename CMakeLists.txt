cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework AppKit")
set(CMAKE_C_FRA)

add_subdirectory(libft)

include_directories(include)
include_directories(libft/include)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)
aux_source_directory(src srcs)

add_executable(fdf ${srcs})
target_link_libraries(fdf "-framework AppKit")
target_link_libraries(fdf "-framework OpenGL")
target_link_libraries(fdf libft)