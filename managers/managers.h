//
// Created by root on 11.05.17.
//

#ifndef MANAGERS_MANAGERS_H
#define MANAGERS_MANAGERS_H


#include <connection.h>
#include "utils/dbConfig.h"
#include "managers/manager.h"
#include "managers/userManager.h"


namespace model {
    class managers {
    public:
        managers();

        managers(const managers &rhs);

        ~managers();

        template<class ModelName>
        manager<ModelName> getManager() const {
            return manager<ModelName>(_con);
        }

    private:
        config::dbConfig _conf;
        mysqlpp::Connection _con;
    };
}


#endif //MANAGERS_MANAGERS_H
