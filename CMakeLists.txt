cmake_minimum_required(VERSION 3.13)

project(MacroBot)

find_package(Geode REQUIRED)

add_geode_mod(
    MacroBot
    SOURCES src/main.cpp
)