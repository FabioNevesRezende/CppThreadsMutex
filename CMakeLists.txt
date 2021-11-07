cmake_minimum_required(VERSION 3.13)
project(Threader VERSION 1.0.0) 

set (CMAKE_CXX_STANDARD 17)


# baixar libboost, compilar usando ./bootstrap e b2
include_directories(/home/fabio/src/boost_1_71_0)
link_directories(/home/fabio/src/boost_1_71_0/stage/lib)


add_executable(Threader 
comum.h
fila_msg.h fila_msg.cpp
gerencia_threads.h gerencia_threads.cpp
main.cpp
)

target_link_libraries(Threader PRIVATE -lpthread )
target_link_libraries(Threader LINK_PUBLIC ${Boost_LIBRARIES} )