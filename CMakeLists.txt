cmake_minimum_required(VERSION 3.5)
project(API)

add_executable(API
    src/main.c
    src/server.c
    src/handler.c
    src/routes/not_found.c
    src/routes/ping.c
)
target_link_libraries(API -lmicrohttpd)
target_link_libraries(API -lcjson)

install(TARGETS API DESTINATION bin)
