//
// Created by root on 06.05.17.
//

#include "baseQuerySet.h"
#include "../dbConfig.h"

namespace model {
    namespace dbManager {
        template<class Model, class CustomQuerySet>
        baseQuerySet<Model,CustomQuerySet>::baseQuerySet(const std::string &tableName)
                : _tableName(tableName) {
            try {
                _con.connect(db_name, db_ip, db_user, db_password);
            }
            catch (...) {
                exit(10);
            }
        }

        template<class Model, class CustomQuerySet>
        baseQuerySet<Model,CustomQuerySet>::~baseQuerySet() {
            _con.disconnect();
        }

        template<class Model, class CustomQuerySet>
        baseQuerySet<Model,CustomQuerySet>::baseQuerySet(const baseQuerySet &rhs) : _con(rhs._con),
                                                              _query(rhs._query),
                                                              _tableName(rhs._tableName) {

        }
    }
}