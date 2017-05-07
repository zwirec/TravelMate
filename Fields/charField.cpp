//
// Created by root on 03.05.17.
//

#include "charField.h"

namespace model {
    charField::charField(const size_t limit) noexcept : _dataLimit(limit) {
        if (_dataLimit > MaxCharFieldLength) {
            _dataLimit = MaxCharFieldLength;
        }
    }

    charField::charField(const charField &rhs) noexcept : baseField("charField", rhs._flags),
                                                          _dataLimit(rhs._dataLimit),
                                                          _data(rhs._data) {}

    charField::charField(const std::string &data, const size_t limit) noexcept : _dataLimit(limit), _data(data) {}

    std::string &charField::value() noexcept {
        return _data;
    }

    charField &charField::operator=(const charField &rhs) {
        setFlags(rhs._flags);
        _dataLimit = rhs._dataLimit;
        _data = rhs._data;

        return *this;
    }

    void charField::setValue(const std::string &newValue) noexcept {
        _data = newValue;

        if (_data.size() > _dataLimit) {
            _data.resize(_dataLimit);
        }
    }

    charField::charField(const std::string &data, const unsigned flags, const std::string &defaultValue)
            : baseField("charField", flags, false), _dataLimit(MaxCharFieldLength), _data(data),
              _defaultValue(defaultValue) {
        if (data.empty() && hasDefault()) {
            _data = _defaultValue;
        }
    }

    bool charField::empty() {
        if (!_isNull || hasDefault()) {
            return false;
        }
        return _data.empty();
    }

    bool charField::operator<(const charField &rhs) {
        return _data < rhs._data;
    }


}