//
// Created by root on 06.05.17.
//

#include "user.h"

#define UserModelName "user"


model::user::user() : basicModel(UserModelName), _login("", 0, ""),
                      _password(255), _email(255) {

}

model::user::user(const std::string &login, const std::string &password)
        : basicModel(UserModelName), _login(login), _password(password), _email(255) {

}

model::user::user(const std::string &login, const std::string &password, const std::string &email)
        : basicModel(UserModelName), _login(login), _password(password), _email(email) {

}

model::user::user(const model::user &rhs) : basicModel(rhs._id.value(), UserModelName), _login(rhs._login),
                                            _password(rhs._password), _email(rhs._email) {

}


std::string &model::user::getLogin(){
    return _login.value();
}

std::string &model::user::getEmail() {
    return _email.value();
}

void model::user::setEmail(const std::string &email) {
    _email.value() = email;
}

void model::user::setEmail(const model::charField &email) {
    _email = email;
}
//
//void model::user::setLogin(const model::charField &login) {
//    _login = login;
//}

void model::user::setLogin(const std::string &login) {
    _login.value() = login;
}

void model::user::setPassword(const std::string &password) {
    _password.value() = password;
}

void model::user::setPassword(const model::charField &password) {
    _password = password;
}

std::string &model::user::getPassword()  {
    return _password.value();
}
