//
// Created by root on 07.05.17.
//

#ifndef BASICMODEL_USERMANAGER_H
#define BASICMODEL_USERMANAGER_H


#include <connection.h>
#include <vector>
#include "user.h"
#include "../baseManager.h"

namespace model {
    namespace manager {
        class UserManager : baseManager<model::user> {
        public:
            UserManager();

            UserManager(const UserManager &rhs) = default;

            ~UserManager() = default;

            void update()

            bool authenticate(model::user& user);

            void all();

            void get();

            void get(const std::string &filter);

            void filter(const std::string &filter);

            void execute();

            void execute(model::user &result);

            void execute(std::vector<model::user> &result) override;

        };
    }
}

#endif //BASICMODEL_USERMANAGER_H
