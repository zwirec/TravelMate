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

    charField::charField(const charField &rhs) noexcept : baseField(rhs._flags), _dataLimit(rhs._dataLimit),
                                                          _data(rhs._data) {}

    charField::charField(const std::string &data, const size_t limit) noexcept : _dataLimit(limit), _data(data) {}

    std::string &charField::value() const noexcept {
        return _data;
    }

    charField::charField(const std::string &data, const bool isPrimaryKey, const size_t limit) : _dataLimit(limit),
                                                                                                 _data(data) {
        if (isPrimaryKey) {
            setFlags(Flags::primaryKeyBit);
        }
    }

    charField &charField::operator=(const charField &rhs) {
        setFlags(rhs._flags);
        _dataLimit = rhs._dataLimit;
        _data = rhs._data;

        return *this;
    }

    bool charField::operator<(const charField &left, const charField& right) {
        return left._data < right._data;
    }

    charField::charField(const bool null, const bool blank) : _dataLimit(MaxCharFieldLength) {
        unsigned flags = 0;
        if (null) {
            flags |= Flags::nullBit;
        }
        if (blank) {
            flags |= Flags::blankBit;
        }
        setFlags(flags);
    }

    void charField::setValue(const std::string &newValue) {
        _data = newValue;

        if(_data.size() > _dataLimit){
            _data.resize(_dataLimit);
        }
    }


}