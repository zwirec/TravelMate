//
// Created by root on 11.05.17.
//

#include "managers.h"

namespace model {
    managers::managers() : _con(_conf.databaseName.c_str(), _conf.databaseHost.c_str(), _conf.databaseUser.c_str(),
                                _conf.userPassword.c_str()) {}

    managers::managers(const managers &rhs) : _con(rhs._con) {}

    managers::~managers() {
        _con.disconnect();
    }


}
