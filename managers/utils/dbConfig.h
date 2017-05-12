#ifndef MANAGERS_DBCONFIG_H
#define MANAGERS_DBCONFIG_H

#include <string>

namespace config {
    struct dbConfig {
        dbConfig() = default;

        dbConfig(const dbConfig& rhs) = default;

        ~dbConfig() = default;

        std::string databaseName = "travelmate";
        std::string databaseHost = "192.168.1.105";
        std::string databaseUser = "tm_connect";
        std::string userPassword = "$5E0sA%ra5t*0R92";
    };
}

#endif //MANAGERS_DBCONFIG_H
