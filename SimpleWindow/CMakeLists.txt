cmake_minimum_required(VERSION 3.22)

project(SimpleWindow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SimpleWindow)

target_sources(${PROJECT_NAME}
	PRIVATE
		src/main.cpp
)

target_link_options(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:/SUBSYSTEM:CONSOLE>
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../ExernalLibraries/GLEW/include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../ExernalLibraries/GLFW/include>
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:opengl32.lib>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../ExernalLibraries/GLEW/lib/Release/x64/glew32.lib>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../ExernalLibraries/GLFW/lib-vc2022/glfw3.lib>
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:_UNICODE>
		$<$<PLATFORM_ID:Windows>:UNICODE>
)