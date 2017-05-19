//
// Created by root on 12.05.17.
//

#include "userManager.h"

struct loginEquality {
    loginEquality(const std::string &Login) : login(Login) {}

    bool operator()(const model::UserModel &user) const {
        return user.login == login;
    }

    const std::string &login;
};

namespace model {
    manager<UserModel>::manager(mysqlpp::Connection &Con) : _connection(Con), _query(_connection.query()) {

    }

    bool
    manager<UserModel>::authenticate(const std::string &login, const std::string &password) throw(std::runtime_error) {
        model::UserModel attempt(mysqlpp::null, login, password, mysqlpp::null_str);

        if (login.empty()) {
            throw std::runtime_error("login field is empty");
        }

        _query.reset();
        _query.store_if(_res, UserModel(), loginEquality(attempt.login));

        if (!_res.empty()) {
            if (_res.size() == 1) {
                return _res[0].password == attempt.password;
            }
        } else {
//            throw std::runtime_error("login not found");
            return false;
        }
    }

    bool manager<UserModel>::authenticate(const UserModel &user)throw(std::runtime_error) {
        if (user.login.empty()) {
            throw std::runtime_error("Login field is empty");
        }

        _query.reset();
        _query.store_if(_res, UserModel(), loginEquality(user.login));

        if (!_res.empty()) {
            if (_res.size() == 1) {
                return _res[0].password == user.password;
            } else {
                throw std::runtime_error("Duplicate login!");
            }
        } else {
//            throw std::runtime_error("login not found");
            return false;
        }
    }

    void manager<UserModel>::create(const std::string &login, const std::string &password) {
        UserModel newUser(mysqlpp::null, login, password, mysqlpp::null_str);

        _query.reset();
        _query.insert(newUser);
        _query.execute();
    }

    void manager<UserModel>::create(const UserModel &user) {
        _query.reset();
        _query.insert(user);
        _query.execute();
    }

    void manager<UserModel>::update(const std::string &login, const std::string &password) {

    }

    void manager<UserModel>::update(const UserModel &user) {

    }

    void
    manager<UserModel>::create(const std::string &login, const std::string &password, const std::string &avatarPath) {
        UserModel newUser(mysqlpp::null, login, password, avatarPath);

        _query.reset();
        _query.insert(newUser);
        _query.execute();
    }
}

