cmake_minimum_required(VERSION 3.10)
project(AF_Math)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)


# Explicitly list ImGui source files
list(APPEND SOURCE_FILES
    #SDK/imgui/backends/imgui_impl_sdl2.cpp
    #SDK/imgui/backends/imgui_impl_opengl3.cpp
)

# Add include directories
include_directories(${CMAKE_SOURCE_DIR}/include)


# Add the header-only library (interface library)
add_library(AF_Math INTERFACE)

# Link include directory to the interface library
target_include_directories(AF_Math INTERFACE ${CMAKE_SOURCE_DIR}/include)


# Define the executable or library target
#add_executable(${PROJECT_NAME} ${SOURCE_FILES})
add_executable(AF_Math_test src/main.cpp)


# Link against libraries
target_link_libraries(AF_Math_test PRIVATE AF_Math)

#

# Set compiler flags
target_compile_options(AF_Math_test PRIVATE
    #-mwindows
    #-time
    -Wall
    -Wextra
    -Werror
    -pedantic
    -Wformat-security
    -Wnull-dereference
    -Wshadow
    -fstack-protector-strong
    #-D_FORTIFY_SOURCE=2
    -fsanitize=address
    -fno-omit-frame-pointer
    #-g
    -O3
    #-v
    #-shared
    #-o
)

# Linker flags
target_link_options(AF_Math_test PRIVATE
    -fsanitize=address
)

# Set output directory
set_target_properties(AF_Math_test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
    OUTPUT_NAME AF_Math_test
    PREFIX ""
)

# Copy the executable to the "bin" directory after building
add_custom_command(TARGET AF_Math_test POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:AF_Math_test> ${CMAKE_SOURCE_DIR}/bin
)

