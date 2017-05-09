//
// Created by root on 07.05.17.
//

#ifndef BASICMODEL_BASEMANAGER_H
#define BASICMODEL_BASEMANAGER_H


#include <mysql++.h>
#include <vector>
#include "dbConfig.h"

namespace model {
    namespace manager {

        template<class ModelName>
        class baseManager {
        public:
            baseManager() {
                try {
                    _con.connect(db_name, db_ip, db_user, db_password);
                }
                catch (...) {
                    return;
                }
            }

            baseManager(const std::string &table) : _tableName(table) {
                try {
                    _con.connect(db_name, db_ip, db_user, db_password);
                }
                catch (...) {
                    return;
                }
            }

            baseManager(const baseManager &rhs) : _con(rhs._con), _query(rhs._query),
                                                  _tableName(rhs._tableName) {}

            virtual ~baseManager() {
                _con.disconnect();
            }

            virtual void update(ModelName &model) = 0;

            virtual void get(const std::string &filter) = 0;

            virtual void get() = 0;

            virtual void all() = 0;

            virtual void filter(const std::string &filter) = 0;

            virtual void execute() = 0;

            virtual void execute(ModelName &result) = 0;

            virtual void execute(std::vector<ModelName> &result) = 0;

        protected:
            mysqlpp::Connection _con;
            std::string _query;

            std::string _tableName;
        };
    }
}
#endif //BASICMODEL_BASEMANAGER_H
