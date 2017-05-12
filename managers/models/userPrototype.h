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


namespace model {
    sql_create_3(users, 2, 3,
                 mysqlpp::Null<mysqlpp::sql_int>, id,
                 mysqlpp::sql_char, login,
                 mysqlpp::sql_char, password)

}


#endif //MANAGERS_USERPROTOTYPE_H
