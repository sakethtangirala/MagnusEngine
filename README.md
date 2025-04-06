# MagnusEngine

3D dynamic simulator and engine for the Magnus effect using OpenGL.

## Dependencies

This project relies on the following libraries:

-   GLFW
-   GLAD
-   cglm
-   Bullet Physics
-   Assimp
-   STB

These dependencies are automatically managed by CMake during the build process.

## Prerequisites

Before building the project, ensure you have the following installed:

1.  **CMake:** Download and install CMake from the official website: [https://cmake.org/download/](https://cmake.org/download/). Make sure to add CMake to your system's PATH environment variable.

2.  **Visual Studio:** This project is built using Visual Studio. If you don't have it already, download and install Visual Studio Community Edition (or a professional version) from the official website: [https://visualstudio.microsoft.com/downloads/](https://visualstudio.microsoft.com/downloads/). During installation, make sure to include the "Desktop development with C++" workload.

## Build Instructions

1.  Clone the repository to your local machine:

    ```bash
    git clone <repository_url>
    ```

2.  Navigate to the project's root directory:

    ```bash
    cd MagnusEngine
    ```

3.  Create a `build` directory:

    ```bash
    mkdir build
    cd build
    ```

4.  Run CMake to configure the project:

    ```bash
    cmake .. -G "Visual Studio 17 2022"

    ```
    (or whatever version of Visual Studio you have installed)

5.  Build the project using CMake:

    ```bash
    cmake --build . --config Debug
    ```

## Usage Instructions

1.  Navigate to the `Debug` directory inside the `build` directory:

    ```bash
    cd Debug
    ```

2.  Run the executable:

    ```bash
    .\\main.exe
    ```

## Additional Notes

-   Ensure you have a compatible OpenGL driver installed.
-   The project is configured to build in Debug mode by default. You can change the build type in CMake if needed.

## Kits/Compilers and Extensions

This project is built using Visual Studio and CMake. It uses the following extensions:

-   GLFW: Window management
-   GLAD: OpenGL function loading
-   cglm: Math
-   Bullet Physics: Physics
-   Assimp: Model loading
-   STB: Image loading
