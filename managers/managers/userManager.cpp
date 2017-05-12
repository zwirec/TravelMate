//
// Created by root on 12.05.17.
//

#define EXPAND_MY_SSQLS_STATICS
#include "userManager.h"

struct loginEquality {
    loginEquality(const std::string &Login) : login(Login) {}

    bool operator()(const model::users &user) {
        return user.login == login;
    }

    const std::string &login;
};

namespace model {
    manager<users>::manager(mysqlpp::Connection &Con) : _connection(Con), _query(_connection.query()) {

    }

    bool manager<users>::authenticate(const std::string &login, const std::string &password) {
        model::users attempt(NULL, login, password);

        _query.reset();
        _query.store_if(_res, users(), loginEquality(login));

        if(!_res.empty()) {
            if (_res.size() == 1) {
                if (_res[0].password == password) {
                    return true;
                }
            }
        }

        return false;
    }
}

#undef EXPAND_MY_SSQLS_STATICS