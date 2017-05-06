//
// Created by root on 03.05.17.
//

#ifndef BASICMODEL_CHARFIELD_H
#define BASICMODEL_CHARFIELD_H

#include <string>
#include "baseField.h"

#define MaxCharFieldLength 255

namespace model {
    class charField : public model::baseField {
    public:
        charField() = default;

        charField(const std::size_t limit = MaxCharFieldLength) noexcept;

        charField(const std::string &data, const std::size_t limit = MaxCharFieldLength) noexcept;

        charField(const std::string &data, const unsigned flags, const std::string &defaultValue = std::string());

        charField(const charField &rhs) noexcept;

        ~charField() noexcept = default;

        std::string &value() noexcept;

        void setValue(const std::string &newValue) noexcept;

        charField &operator=(const charField &rhs);

        bool operator<(const charField &rhs);

        bool empty() override;

    private:
        std::size_t _dataLimit;
        std::string _data;
        std::string _defaultValue;
    };
}

#endif //BASICMODEL_CHARFIELD_H
