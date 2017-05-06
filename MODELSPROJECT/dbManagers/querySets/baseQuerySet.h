//
// Created by root on 06.05.17.
//

#ifndef BASICMODEL_QUERYSET_H
#define BASICMODEL_QUERYSET_H

#include <mysql++.h>

namespace model {
    namespace dbManager {

        template<class Model, class customQuerySet>
        class baseQuerySet {
        public:
            baseQuerySet() = default;

            baseQuerySet(const std::string &tableName);

            baseQuerySet(const baseQuerySet &rhs);

            virtual ~baseQuerySet();

            virtual customQuerySet filter(const std::string &filterArgs) = 0;

            virtual void execute() = 0;

            virtual void execute(Model &result) = 0;

            virtual void execute(std::vector<Model> &result) = 0;

        protected:
            mysqlpp::Connection _con;

            std::string _query;
            std::string _tableName;
        };

    }
}
#endif //BASICMODEL_QUERYSET_H
