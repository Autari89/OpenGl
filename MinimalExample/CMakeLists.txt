cmake_minimum_required(VERSION 3.22)

project(MinimalExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MinimalExample)

target_sources(${PROJECT_NAME}
	PRIVATE
		src/main.cpp
)

target_link_options(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:/SUBSYSTEM:CONSOLE>
)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:setupapi.lib>
		$<$<PLATFORM_ID:Windows>:wtsapi32.lib>
		$<$<PLATFORM_ID:Windows>:opengl32.lib>
		$<$<PLATFORM_ID:Windows>:glu32.lib>
		$<$<PLATFORM_ID:Windows>:freeglut.lib>
)

target_compile_definitions(${PROJECT_NAME}
	PRIVATE
		$<$<PLATFORM_ID:Windows>:_UNICODE>
		$<$<PLATFORM_ID:Windows>:UNICODE>
)