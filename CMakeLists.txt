cmake_minimum_required(VERSION 3.5.2)
project(TravelMateProject)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -I/usr/local/include/mysql -I/usr/local/include/mysql++ -L../build ")

set(SOURCE_FILES 
main.cpp
        all_tmpl.cpp
data/tmpl_master.h 
data/tmpl_news.h 
managers/managers.cpp 
managers/managers.h 
managers/utils/dbConfig.cpp 
managers/utils/dbConfig.h 
managers/managers/manager.cpp 
managers/managers/manager.h
        managers/managers/userManager.cpp
managers/managers/userManager.h
        managers/models/user/UserModel.cpp
managers/models/user/UserModel.h 
managers/models/user/userPrototype.h 
managers/models/user/cypher/sha256.cpp 
managers/models/user/cypher/sha256.h)

add_executable(TravelMateProject ${SOURCE_FILES})

target_link_libraries(TravelMateProject mysqlpp)
target_link_libraries(TravelMateProject mysqlclient)
target_link_libraries(TravelMateProject booster)
target_link_libraries(TravelMateProject cppcms)
target_link_libraries(TravelMateProject cpp_defskin)


