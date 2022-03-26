cmake_minimum_required(VERSION 3.2)

project(hl_mai_02 C CXX)


find_package(GTest REQUIRED)
find_package(Threads)
find_package(Poco REQUIRED COMPONENTS Foundation Util Net XML JSON Crypto NetSSL)

if(NOT ${Poco_FOUND})
    message(FATAL_ERROR "Poco C++ Libraries not found.")
endif()

include_directories(${Poco_INCLUDE_DIRS})



add_executable(poco_thread poco_thread.cpp)
add_executable(poco_socket poco_socket.cpp)
add_executable(poco_socket_https poco_socket_https.cpp)
add_executable(poco_server poco_server.cpp)



target_compile_options(poco_thread PRIVATE -Wall -Wextra -pedantic -Werror )
target_compile_options(poco_socket PRIVATE -Wall -Wextra -pedantic -Werror )
target_compile_options(poco_socket_https PRIVATE -Wall -Wextra -pedantic -Werror )
target_compile_options(poco_server PRIVATE -Wall -Wextra -pedantic -Werror )


target_link_libraries(poco_thread PRIVATE ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES})
target_link_libraries(poco_socket PRIVATE ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES})
target_link_libraries(poco_socket_https PRIVATE ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES})
target_link_libraries(poco_server PRIVATE ${CMAKE_THREAD_LIBS_INIT} ${Poco_LIBRARIES})


set_target_properties(poco_thread 
                      poco_socket
                      poco_socket_https 
                      poco_server
                     PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)



