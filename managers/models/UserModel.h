//
// Created by root on 12.05.17.
//

#ifndef MANAGERS_USERMODEL_H
#define MANAGERS_USERMODEL_H

#include "userPrototype.h"

namespace model {
    class UserModel : public users {
    public:
        UserModel();

        UserModel(const mysqlpp::sql_char& _a);

        UserModel(const mysqlpp::Null<mysqlpp::sql_int>& _a, const mysqlpp::sql_char& _b, const mysqlpp::sql_char& _c);

        UserModel(const mysqlpp::Row& row);
    private:
        void cypherPassword();
    };
}

#endif //MANAGERS_USERMODEL_H
