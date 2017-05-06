//
// Created by root on 04.05.17.
//

#include "integerField.h"

void integerField::setValue(const int value) {
    _value = value;
}

integerField &integerField::operator=(const integerField &rhs) {
    _flags = rhs._flags;
    _value = rhs._value;

    return *this;
}

const int &integerField::value() const noexcept {
    return _value;
}

integerField::integerField(const integerField &rhs) : baseField("integerField", rhs._flags, rhs._isNull),
                                                      _value(rhs._value) {}

integerField::integerField()
        : baseField("integerField", 0, true) {}

integerField::integerField(const int value)
        : baseField("integerField", 0, false), _value(value) {}

integerField::integerField(const int value, const unsigned flags)
        : baseField("integerField", flags, false), _value(value) {}

integerField::integerField(const int value, const unsigned flags, const int defaultValue)
        : baseField("integerField", flags, false), _value(value), _defaultValue(defaultValue) {}

bool integerField::operator<(const integerField &rhs) {
    return _value < rhs._value;
}

bool integerField::empty() {

    return _isNull || hasDefault();
}
