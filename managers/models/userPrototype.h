//
// Created by root on 12.05.17.
//

#ifndef MANAGERS_USERPROTOTYPE_H
#define MANAGERS_USERPROTOTYPE_H

#if !defined(EXPAND_MY_SSQLS_STATICS)
#define MYSQLPP_SSQLS_NO_STATICS
#endif

#include <mysql++.h>
#include <ssqls.h>

#define USERS_ROW_COUNT 3
#define USERS_ROW_COUNT_COMP 2;

namespace model {
    sql_create_3(users, USERS_ROW_COUNT_COMP, USERS_ROW_COUNT,
                 mysqlpp::Null<mysqlpp::sql_int>, id,
                 mysqlpp::sql_char, login,
                 mysqlpp::sql_char, password)

}


#endif //MANAGERS_USERPROTOTYPE_H
