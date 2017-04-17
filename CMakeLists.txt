cmake_minimum_required(VERSION 3.6)
project(TravelMateProject)

set(CMAKE_CXX_STANDARD 11)

find_library(Booster Boster)
find_library(cppcms CPPCMS)
set(SOURCE_FILES main.cpp )

add_executable(TravelMateProject ${SOURCE_FILES})
target_link_libraries(TravelMateProject ${Booster_LIBRARY} ${CPPCMS_LIBRARY})
