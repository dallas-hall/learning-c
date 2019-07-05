cmake_minimum_required(VERSION 3.13)
project(working C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(working
        bar_list.c
        bar_list.h
        board.c
        board.h
        game.c
        game.h
        helpers.c
        helpers.h
        io.c
        io.h
        main.c
        main.h
        player.c
        player.h
        rules.c
        rules.h
        shared.h)
