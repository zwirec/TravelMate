//
// Created by root on 03.05.17.
//

#ifndef BASICMODEL_BASICMODEL_H
#define BASICMODEL_BASICMODEL_H

#include <string>
#include "../Fields/integerField.h"

namespace model {
    class basicModel {
    public:
        basicModel() = default;

        basicModel(const std::string& modelName);

        basicModel(const int id, const std::string& modelName);

        basicModel(const basicModel &rhs);

        ~basicModel() = default;

        void setId(const int id);

    protected:
        std::string _modelName;
        integerField _id = integerField(0, Flags::primaryKeyBit);
    };
}

#endif //BASICMODEL_BASICMODEL_H
