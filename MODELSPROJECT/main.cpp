#include <iostream>
#include "models/user.h"

int main() {
    model::user user("login", "password");
    std::cout << user.getLogin();
}