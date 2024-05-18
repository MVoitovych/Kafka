cmake_minimum_required(VERSION 3.28)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

include_directories(/usr/include/librdkafka)

add_executable(lab4 src/main.cpp
        src/KafkaController.cpp
        src/ConsoleSender.cpp
        src/KafkaSender.cpp
        src/ConsoleSender.cpp
        src/CSVReader.cpp
)

target_link_libraries(lab4 /usr/lib/x86_64-linux-gnu/librdkafka++.so /usr/lib/x86_64-linux-gnu/librdkafka.so)