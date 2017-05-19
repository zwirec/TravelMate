//
// Created by root on 12.05.17.
//

#ifndef MANAGERS_USERMODEL_H
#define MANAGERS_USERMODEL_H

#include "userPrototype.h"

namespace model {
    class UserModel : public user {
    public:
        UserModel();

        UserModel(const mysqlpp::Null<mysqlpp::sql_int> &_username, const mysqlpp::sql_char &_password);

        UserModel(const mysqlpp::Null<mysqlpp::sql_int> &_id, const mysqlpp::sql_char &_username,
                  const mysqlpp::sql_char &_password,
                  const mysqlpp::Null<mysqlpp::sql_char> &_avatar_path);

        UserModel(const mysqlpp::Row &row);

    private:
        void cypherPassword();
    };
}

#endif //MANAGERS_USERMODEL_H
