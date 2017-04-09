cmake_minimum_required(VERSION 3.6)
project(TravelMate)

set(CMAKE_CXX_STANDARD 11)

find_library(Booster Boster)
find_library(cppcms CPPCMS)
set(SOURCE_FILES main.cpp data/tmpl_master.h data/tmpl_news.h)

add_executable(TravelMate ${SOURCE_FILES})
target_link_libraries(TravelMate ${Booster_LIBRARY} ${CPPCMS_LIBRARY})
