cmake_minimum_required(VERSION 3.7)
project(basicModel)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-long-long -pedantic -I/usr/include/mysql -I/usr/include/mysql++ -L/usr/lib ")

set(SOURCE_FILES main.cpp models/basicModel.cpp models/basicModel.h Fields/charField.cpp Fields/charField.h utils.h Fields/baseField.cpp Fields/baseField.h Fields/integerField.cpp Fields/integerField.h Fields/byteField.cpp Fields/byteField.h models/user.cpp models/user.h dbManagers/Controllers/baseController.cpp dbManagers/Controllers/baseController.h dbManagers/querySets/baseQuerySet.cpp dbManagers/querySets/baseQuerySet.h dbManagers/dbConfig.h dbManagers/Controllers/userContoller.cpp dbManagers/Controllers/userContoller.h dbManagers/querySets/userQuerySet.cpp dbManagers/querySets/userQuerySet.h)
add_executable(basicModel ${SOURCE_FILES})

target_link_libraries(basicModel mysqlpp)
target_link_libraries(basicModel mysqlclient)