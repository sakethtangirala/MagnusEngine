cmake_minimum_required(VERSION 3.31)
cmake_policy(VERSION 3.31)

project(OpenGLProject VERSION 1.0)

include(FetchContent)

# Fetch and include GLFW
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw
  GIT_TAG        3.3.8
)
FetchContent_MakeAvailable(glfw)

# Fetch and include GLAD
FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad
  GIT_TAG        v2.0.0
)
FetchContent_MakeAvailable(glad)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

# Fetch and include GLM
FetchContent_Declare(
  glm
  GIT_REPOSITORY https://github.com/g-truc/glm.git
  GIT_TAG        0.9.9.8
)
FetchContent_MakeAvailable(glm)

# Fetch and include Bullet Physics
FetchContent_Declare(
  bullet
  GIT_REPOSITORY https://github.com/bulletphysics/bullet3.git
  GIT_TAG        3.25
)
FetchContent_MakeAvailable(bullet)

# Fetch Assimp
FetchContent_Declare(
  assimp
  GIT_REPOSITORY https://github.com/assimp/assimp.git
  GIT_TAG        v5.2.5
)
FetchContent_MakeAvailable(assimp)

# Fetch and include STB
FetchContent_Declare(
  stb
  GIT_REPOSITORY https://github.com/nothings/stb.git
  GIT_TAG        master
)
FetchContent_MakeAvailable(stb)

# Include necessary directories
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${glad_SOURCE_DIR}/include)
include_directories(${glfw_SOURCE_DIR}/include)
include_directories(${glm_SOURCE_DIR})
include_directories(${bullet_SOURCE_DIR}/src)
include_directories(${assimp_SOURCE_DIR}/include)
include_directories(${stb_SOURCE_DIR})

# Find OpenGL
find_package(OpenGL REQUIRED)

# Add executable
add_executable(main src/main.c src/glad.c)

# Link necessary libraries
target_link_libraries(main PRIVATE glfw OpenGL::GL glm BulletDynamics BulletCollision LinearMath assimp)
