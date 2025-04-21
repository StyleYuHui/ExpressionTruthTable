cmake_minimum_required(VERSION 3.26)
project(ExpressionTruthTable)


set(CMAKE_EXE_LINKER_FLAGS "-static")

set(CMAKE_CXX_STANDARD 17)



# 声明inc头文件路径
set(INC_DIR ./inc)

# 引入inc头文件
include_directories(${INC_DIR})

# 声明src源代码路径
set(SOURCE_DIR ./src)

# 声明源文件
set(Sources
        ${SOURCE_DIR}/arrayList.cpp
        ${SOURCE_DIR}/expressionTruthTable.cpp
        ${SOURCE_DIR}/stack.cpp
#        ${SOURCE_DIR}/test.cpp
)

# 创建可执行文件
add_executable(ExpressionTruthTable main.cpp ${Sources})