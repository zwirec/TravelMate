//
// Created by root on 06.05.17.
//

#ifndef BASICMODEL_USER_H
#define BASICMODEL_USER_H

#include "../Fields/charField.h"
#include "../Fields/integerField.h"
#include "basicModel.h"

#define SALT "LALALALA"

namespace model {
    class user : public basicModel{
    public:
        user();

        user(const std::string &login, const std::string &password);

        user(const std::string &login, const std::string &password, const std::string &_email);

        user(const user &);

        const std::string &getLogin();

        const std::string &getEmail();

        void setEmail(const std::string &email);

        void setEmail(const charField &email);

        void setLogin(const charField &login);

        void setLogin(const std::string &login);

        void setPassword(const std::string &password);

        void setPassword(const charField &password);

        ~user() = default;

    private:
        std::string _salt = SALT;


        charField _login;
        charField _password;
        charField _email;
    };
}

#endif //BASICMODEL_USER_H
