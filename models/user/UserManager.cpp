//
// Created by root on 07.05.17.
//

#include "UserManager.h"

model::manager::UserManager::UserManager() : baseManager<user>("users") {

}

bool model::manager::UserManager::authenticate(model::user &user) {
    _query = std::string("SELECT * FROM ") + _tableName + std::string(" WHERE login='") + user.getLogin() + std::string("'");
    mysqlpp::Query q = _con.query(_query);

    auto res = q.store();
    if (!res.empty()) {
        return strcmp(res[0]["password"].c_str(), user.getPassword().c_str()) == 0;
    }
    throw 1;
}

void model::manager::UserManager::all() {
    _query = std::string("SELECT * FROM ") + _tableName;
}

void model::manager::UserManager::get() {

}

void model::manager::UserManager::get(const std::string &filter) {

}

void model::manager::UserManager::filter(const std::string &filter) {

}

void model::manager::UserManager::execute() {

}

void model::manager::UserManager::execute(model::user &result) {

}

void model::manager::UserManager::execute(std::vector<model::user> &result) {

}
