//
// Created by root on 06.05.17.
//

#include "userQuerySet.h"

model::dbManager::userQuerySet::userQuerySet() : baseQuerySet("user") {

}

model::dbManager::userQuerySet::userQuerySet(const model::dbManager::userQuerySet &rhs) : baseQuerySet(rhs) {

}

void model::dbManager::userQuerySet::execute() {
    if (!_query.empty()) {
        mysqlpp::Query Query = _con.query(_query);

        Query.execute();
    }
}

void model::dbManager::userQuerySet::execute(model::user &result) {
    if (!_query.empty()) {
        mysqlpp::Query Query = _con.query(_query);
        mysqlpp::StoreQueryResult res = Query.store();

        result.setLogin(std::string(res[0]["login"].c_str()));
    }
}
