cmake_minimum_required(VERSION 3.8)

project(Tutorial VERSION 1.0)

# 我们可以搞一个条件，来判断是否要使用我们的lib
option(USE_MYMATH "Use tutorial provided math implementation" ON)
# 有了这个之后我们就可以使用if来决定是否要将lib所在子目录添加到项目中了，以及包含目录
if(USE_MYMATH)
	# 添加子目录MathFunctions
	add_subdirectory(MathFunctions)
	list(APPEND EXTRA_LIBS MathFunctions)
endif()

# 把我们之前的那个配置文件补上
configure_file(TutorialConfig.h.in TutorialConfig.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(Tutorial tutorial.cxx)

# 把lib的源代码添加上来
target_link_libraries(Tutorial PUBLIC ${EXTRA_LIBS})

# 添加包含目录
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
