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
FetchContent_Declare(
  cglm
  GIT_REPOSITORY https://github.com/recp/cglm.git
  GIT_TAG        v0.9.2
)
FetchContent_MakeAvailable(cglm)

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

include_directories(${CMAKE_SOURCE_DIR}/include)  # For your custom include folder
include_directories(${glad_SOURCE_DIR}/include)   # glad includes
include_directories(${glfw_SOURCE_DIR}/include)   # glfw includes
include_directories(${glm_SOURCE_DIR})            # glm (header-only)
include_directories(${bullet_SOURCE_DIR}/src)    # Bullet physics includes
include_directories(${assimp_SOURCE_DIR}/include) # Assimp includes
include_directories(${stb_SOURCE_DIR})            # stb includes



# Find OpenGL
find_package(OpenGL REQUIRED)

# Add executable
add_executable(main src/main.cpp src/glad.c src/Camera.c)

# Link necessary libraries
target_link_libraries(main PRIVATE glfw OpenGL::GL cglm BulletDynamics BulletCollision LinearMath assimp)
