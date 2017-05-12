cmake_minimum_required(VERSION 3.5)
project(managers)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -I/usr/include/mysql -I/usr/include/mysql++ -L/usr/lib ")

set(SOURCE_FILES main.cpp managers.cpp managers.h utils/dbConfig.cpp utils/dbConfig.h managers/manager.cpp managers/manager.h models/tableModels.h managers/userManager.cpp managers/userManager.h models/tableModel.cpp models/UserModel.cpp models/UserModel.h models/userPrototype.h)
add_executable(managers ${SOURCE_FILES})


target_link_libraries(managers mysqlpp)
target_link_libraries(managers mysqlclient)
