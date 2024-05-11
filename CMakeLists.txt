cmake_minimum_required(VERSION 3.5)
project(API)

add_executable(API
    src/main.c
    src/server.c
    src/handler.c
    #src/database.c
)
target_link_libraries(API -lmicrohttpd)

install(TARGETS API DESTINATION bin)
