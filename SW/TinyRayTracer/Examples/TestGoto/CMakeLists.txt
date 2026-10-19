project(TestGoto)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
		  ${CMAKE_CURRENT_SOURCE_DIR}/*.c                  
		  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
		  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(TestGoto
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(TestGoto
    ${ALL_LIBS}
)

target_compile_features(TestGoto PRIVATE cxx_std_17)

# 设置输出目录
set_target_properties(TestGoto
    PROPERTIES
    FOLDER "Examples"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>
)

# 添加依赖
add_dependencies(TestGoto CLibs) 

