//
// Created by root on 12.05.17.
//

#ifndef MANAGERS_USERMANAGER_H
#define MANAGERS_USERMANAGER_H

#include "../managers.h"
#include "../models/userPrototype.h"

namespace model {
    template<>
    class manager<users> {
    public:
        manager(mysqlpp::Connection& Con);

        bool authenticate(const std::string &login, const std::string &password);

    private:
        mysqlpp::Connection& _connection;
        mysqlpp::Query _query;
        std::vector<users> _res;
    };
}

#endif //MANAGERS_USERMANAGER_H
