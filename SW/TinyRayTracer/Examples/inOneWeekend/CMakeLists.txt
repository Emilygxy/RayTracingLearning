project(inOneWeekend)

file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
		  ${CMAKE_CURRENT_SOURCE_DIR}/*.c                  
		  ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
		  ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(inOneWeekend
    ${HEADERS}
    ${SOURCES}
)

target_link_libraries(inOneWeekend
    ${ALL_LIBS}
)

target_compile_features(inOneWeekend PRIVATE cxx_std_17)

# 设置输出目录
set_target_properties(inOneWeekend
    PROPERTIES
    FOLDER "Examples"
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIGURATION>
)

# 添加依赖
add_dependencies(inOneWeekend TinyRayTracer) 

