//
// Created by root on 03.05.17.
//

#include "baseField.h"


namespace model {
//    baseField::baseField() : _flags(0), _fieldType("") {
//        throw 1;
//    }

    baseField::baseField(const std::string &type, unsigned flags, bool isNull) : _flags(flags), _isNull(isNull),
                                                                                 _fieldType(type) {
        try {
            checkFlags();
        }
        catch (...) {}
    }

    bool baseField::isPrimaryKey() {
        return (_flags & ~Flags::primaryKeyBit) != _flags;
    }

    bool baseField::canBeNull() {
        return (_flags & ~Flags::nullBit) != _flags;
    }

    bool baseField::hasDefault() {
        return (_flags & ~Flags::defaultBit) != _flags;
    }

    bool baseField::canBeBlank() {
        return (_flags & ~Flags::blankBit) != _flags;
    }

    baseField::baseField(const baseField &rhs) noexcept : _flags(rhs._flags) {}

    void baseField::setFlags(const unsigned newFlags) {
        _flags = newFlags;

        try {
            checkFlags();
        }
        catch (...) {}
    }

    void baseField::checkFlags() {
        //Если флагов пришло больше, чем на самом деле есть. 4 пока реализовано.
        if (_flags >= 1 << 5) {
            throw 1;//todo Выкинуть ошибку "нет таких флагов"
        }

        //Проверить на то, что PK и Null или Default не выставлены одновременно
        if (isPrimaryKey()) { //То есть выставлен PK
            if (canBeNull() || canBeBlank() || hasDefault()) {
                throw 2; //todo Выкинуть ошибку "неверные флаги"
            }
        }

        //Проверка на то, что Not Null идет вместе с Blank не имея Default
        if (!canBeNull() && !hasDefault()) {
            if (canBeBlank()) {
                throw 3; //todo Выкинуть ошибку "нельзя без дефолта делать бланк при NotNull"
            }
        }
    }

    baseField::baseField(unsigned flags, bool isNull) : _flags(flags), _isNull(isNull) {}

    const std::string &const baseField::type() const {
        return _fieldType;
    }

}