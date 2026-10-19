cmake_minimum_required(VERSION 3.8)
project(TinyRayTracer)

# 包含辅助函数
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(SetSourceGroup)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
				    )
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
                  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
               	  ${CMAKE_CURRENT_SOURCE_DIR}/*.c
		  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
		  )

# set_source_group_for_files("${SOURCES}")
# set_source_group_for_files("${HEADERS}")

# 为源文件和头文件设置 source_group
set_source_group_for_files("${SOURCES}")
set_source_group_for_files("${HEADERS}")

#添加依赖的头文件
# include_directories(
#	${GLFW_GLAD_INCLUDE_DIR}
#	${VULKAN_INCLUDE_DIR}
#	${CMAKE_CURRENT_SOURCE_DIR}/GTVulkan/include
#	${CMAKE_CURRENT_SOURCE_DIR}/include
#	${CMAKE_BINARY_DIR}/configuration
#	${THIRD_PARTY_INCLUDE_DIR})

add_library(TinyRayTracer STATIC 
			${HEADERS}
			${SOURCES})  ## lib

target_include_directories(TinyRayTracer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(TinyRayTracer PUBLIC cxx_std_17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set_target_properties(TinyRayTracer
    PROPERTIES
	FOLDER "Libraries"
  #  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/#$<CONFIGURATION>/
)

set(ALL_LIBS
	# ${GLFW_LIB}
	# ${VULKAN_LIB}
	# ${THIRD_PARTY_LIB}
	TinyRayTracer
)

# 源资源目录：项目根目录下的 resources/
set(RESOURCE_DIR ${CMAKE_SOURCE_DIR}/resources)
# 拷贝目标：与可执行文件相同的 build/bin/<Config>/resources
# Visual Studio 是多配置生成器，必须用 $<CONFIG>，不能在配置阶段写死 Debug/Release
set(RESOURCE_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin/$<CONFIG>/resources)
# 定义宏将资源路径传递给代码
target_compile_definitions(TinyRayTracer PUBLIC 
    RESOURCE_PATH="${RESOURCE_OUTPUT_DIR}/"
)

#生成可执行程序
# add_subdirectory(Examples/TestGoto)
add_subdirectory(Examples/inOneWeekend)

add_custom_command(TARGET TinyRayTracer POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "${RESOURCE_OUTPUT_DIR}"
  COMMENT "Creating resources directory for current config"
)

# 源目录不存在时 copy_directory 会失败；有 resources/ 后再重新配置即可拷贝
if(EXISTS "${RESOURCE_DIR}")
    add_custom_command(TARGET TinyRayTracer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${RESOURCE_DIR}"
            "${RESOURCE_OUTPUT_DIR}"
        COMMENT "Copying resources to build directory"
    )
endif()

