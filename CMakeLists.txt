cmake_minimum_required(VERSION 3.10)

# Set project name and version
project(OpenGLProject VERSION 1.0)

# Specify the C standard
set(CMAKE_C_STANDARD 11)

# Add glad and GLFW header paths
include_directories(include)
include_directories(${CMAKE_SOURCE_DIR}/include/glad)

# Find OpenGL package
find_package(OpenGL REQUIRED)

# Fetch and make GLFW available
include(FetchContent)
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw
  GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw)

# Fetch and make GLAD available
FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad
  GIT_TAG        v2.0.0
)
FetchContent_MakeAvailable(glad)

# Add the source files
add_executable(main src/main.c src/glad.c)

# Include the necessary directories for GLAD and GLFW
include_directories(${glad_SOURCE_DIR}/include)
include_directories(${glfw_SOURCE_DIR}/include)

# Link the libraries (no need for glad.lib, only glfw and OpenGL)
target_link_libraries(main PRIVATE glfw OpenGL::GL)
