cmake_minimum_required(VERSION 3.10)
project(test_kafka)

# Указываем vcpkg как инструмент для поиска библиотек
#set(CMAKE_TOOLCHAIN_FILE "C:/Users/den24/source/repos/kafka-project/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Ищем librdkafka
find_package(RdKafka CONFIG REQUIRED)  

# Создаём исполняемый файл
add_executable(test_kafka src/main.cpp)

# Линкуем librdkafka
target_link_libraries(test_kafka PRIVATE 
    RdKafka::rdkafka 
    RdKafka::rdkafka++ 
)