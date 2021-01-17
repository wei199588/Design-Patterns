# 设置项目名  这里的项目名指的是这个CMakeLists.txt的项目名
PROJECT(WORK)

# 规定cmake最低版本
cmake_minimum_required(VERSION 3.5)

# 设置可执行文件的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

set(THREADS_PREFER_PTHREAD_FLAG ON)

# 找到Pthread包
find_package(Threads REQUIRED) 

# 头文件路径
include_directories(${PROJECT_SOURCE_DIR}/perception)
include_directories(${PROJECT_SOURCE_DIR}/src)

#把一个目录下的所有源文件名存入一个变量
aux_source_directory(${PROJECT_SOURCE_DIR}/perception SRC_PCP)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
# 添加可执行文件
add_executable(main ${SRC_PCP} ${SRC})


target_link_libraries(main PUBLIC Threads::Threads)

