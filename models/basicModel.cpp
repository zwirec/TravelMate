//
// Created by root on 03.05.17.
//

#include "basicModel.h"

model::basicModel::basicModel(const std::string &modelName) : _modelName(modelName) {

}

model::basicModel::basicModel(const int id, const std::string &modelName) : _modelName(modelName),
                                                                            _id(id, Flags::primaryKeyBit) {

}

model::basicModel::basicModel(const model::basicModel &rhs) : _modelName(rhs._modelName), _id(rhs._id) {

}

void model::basicModel::setId(const int id) {
    _id = id;
}
