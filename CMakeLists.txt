cmake_minimum_required(VERSION 3.10)
project(test_kafka)

# Создаём исполняемый файл
add_executable(test_kafka src/main.cpp)

# Ищем librdkafka
if(WIN32)
    find_package(RdKafka REQUIRED)  
    # Линкуем librdkafka
    target_link_libraries(test_kafka PRIVATE 
        RdKafka::rdkafka 
        RdKafka::rdkafka++ 
    )

else()
    # Используем pkg-config для поиска библиотеки
    find_package(PkgConfig REQUIRED)
    pkg_search_module(RDKAFKA REQUIRED rdkafka)

    target_include_directories(test_kafka PRIVATE ${RDKAFKA_INCLUDE_DIRS})
    target_link_directories(test_kafka PRIVATE ${RDKAFKA_LIBRARY_DIRS})
    target_link_libraries(test_kafka PRIVATE ${RDKAFKA_LIBRARIES})
endif()





