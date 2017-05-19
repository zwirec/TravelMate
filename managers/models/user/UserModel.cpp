//
// Created by root on 12.05.17.
//
#define EXPAND_MY_SSQLS_STATICS

#include "UserModel.h"
#include "cypher/sha256.h"

#define PASSWORD_LENGTH 73
#define PASSWORD_PREFIX ":sha256::"

namespace model {
    UserModel::UserModel() : user() {
    }

    UserModel::UserModel(const mysqlpp::Null<mysqlpp::sql_int> &_username, const mysqlpp::sql_char &_password) : user(_username, _password) {
        if (password.find("PASSWORD_PREFIX") == password.npos && password.size() != PASSWORD_LENGTH)
            cypherPassword();
    }

    UserModel::UserModel(const mysqlpp::Null<mysqlpp::sql_int> &_id, const mysqlpp::sql_char &_username,
                         const mysqlpp::sql_char &_password, const mysqlpp::Null<mysqlpp::sql_char> &_avatar_path) : user(_id, _username, _password, _avatar_path) {
        if (password.find("PASSWORD_PREFIX") == password.npos && password.size() != PASSWORD_LENGTH)
            cypherPassword();
    }

    UserModel::UserModel(const mysqlpp::Row &row) : user(row) {
        if (password.find("PASSWORD_PREFIX") == password.npos && password.size() != PASSWORD_LENGTH)
            cypherPassword();
    }

    void UserModel::cypherPassword() {
        std::string temp(std::string("PASSWORD_PREFIX") + sha256(password));
        password = temp;
    }
}

#undef EXPAND_MY_SSQLS_STATICS
