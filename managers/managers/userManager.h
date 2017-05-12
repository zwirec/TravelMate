//
// Created by root on 12.05.17.
//

#ifndef MANAGERS_USERMANAGER_H
#define MANAGERS_USERMANAGER_H

#include "../managers.h"
#include "../models/user/UserModel.h"

namespace model {
    template<>
    class manager<UserModel> {
    public:
        manager(mysqlpp::Connection &Con);

        bool authenticate(const std::string &login, const std::string &password) throw(std::runtime_error);

        bool authenticate(const UserModel &user) throw(std::runtime_error);

        void create(const std::string &login, const std::string &password);
        void create(const std::string &login, const std::string &password, const std::string& avatarPath);

        void create(const UserModel &user);

        void update(const std::string &login, const std::string &password);

        void update(const UserModel &user);

    private:
        mysqlpp::Connection &_connection;
        mysqlpp::Query _query;
        std::vector<UserModel> _res;
    };
}

#endif //MANAGERS_USERMANAGER_H
