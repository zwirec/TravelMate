//
// Created by root on 12.05.17.
//
#define EXPAND_MY_SSQLS_STATICS

#include "UserModel.h"
#include "cypher/sha256.h"

namespace model {
    UserModel::UserModel() : user() {
    }

    UserModel::UserModel(const mysqlpp::Null<mysqlpp::sql_int> &_a, const mysqlpp::sql_char &_b) : user(_a, _b) {
        if (password.find(":sha256::") == password.npos && password.size() != 64 + 9)
            cypherPassword();
    }

    UserModel::UserModel(const mysqlpp::Null<mysqlpp::sql_int> &_a, const mysqlpp::sql_char &_b,
                         const mysqlpp::sql_char &_c, const mysqlpp::Null<mysqlpp::sql_char> &_d) : user(_a, _b, _c, _d) {
        if (password.find(":sha256::") == password.npos && password.size() != 64 + 9)
            cypherPassword();
    }

    UserModel::UserModel(const mysqlpp::Row &row) : user(row) {
        if (password.find(":sha256::") == password.npos && password.size() != 64 + 9)
            cypherPassword();
    }

    void UserModel::cypherPassword() {
        std::string temp(std::string(":sha256::") + sha256(password));
        password = temp;
    }
}

#undef EXPAND_MY_SSQLS_STATICS
