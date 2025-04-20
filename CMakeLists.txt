cmake_minimum_required(VERSION 3.10)
project(test_kafka)

# стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
    pkg_check_modules(RDKAFKA REQUIRED IMPORTED_TARGET rdkafka)
    pkg_check_modules(RDKAFKACPP REQUIRED IMPORTED_TARGET rdkafka++)

    # Автоматически добавляет include dirs и libs
    target_link_libraries(test_kafka PRIVATE 
        PkgConfig::RDKAFKA 
        PkgConfig::RDKAFKACPP
    )

endif()





