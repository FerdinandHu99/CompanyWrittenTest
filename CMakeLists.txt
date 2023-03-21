cmake_minimum_required(VERSION 2.8)

project(CompanyWrittenTest)
# 设置 可执行文件
add_executable(${PROJECT_NAME} "er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof.cpp")

add_library(Main "main.cpp")

# 设置 2023.3.28西山居暑期实习笔试项目
add_library(Xishaju1 "er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof.cpp")
add_library(Xishaju2 "top-k-frequent-words.cpp")
