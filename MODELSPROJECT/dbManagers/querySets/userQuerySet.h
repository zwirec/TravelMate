//
// Created by root on 06.05.17.
//

#ifndef BASICMODEL_USERQUERYSET_H
#define BASICMODEL_USERQUERYSET_H

#include "baseQuerySet.h"
#include "../../models/user.h"

namespace model {
    namespace dbManager {
        class userQuerySet : baseQuerySet<user, userQuerySet> {
        public:
            userQuerySet();

            userQuerySet(const userQuerySet &rhs);

            ~userQuerySet() = default;

            userQuerySet filter(const std::string &filterArgs) override;

            void execute() override;

            void execute(user &result) override;

            void execute(std::vector<user> &result) override;

        private:
        };
    }
}


#endif //BASICMODEL_USERQUERYSET_H
