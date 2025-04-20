cmake_minimum_required(VERSION 3.10)
project(test_kafka)

# Ищем librdkafka
find_package(RdKafka CONFIG REQUIRED)  

# Создаём исполняемый файл
add_executable(test_kafka src/main.cpp)

# Линкуем librdkafka
target_link_libraries(test_kafka PRIVATE 
    RdKafka::rdkafka 
    RdKafka::rdkafka++ 
)