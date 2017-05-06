//
// Created by root on 04.05.17.
//

#ifndef BASICMODEL_INTEGERFIELD_H
#define BASICMODEL_INTEGERFIELD_H


#include "baseField.h"
#include <string>

class integerField : public model::baseField {
public:
    integerField();

    integerField(const int value);

    integerField(const int value, const unsigned flags);

    integerField(const int value, const unsigned flags, const int defaultValue);

    integerField(const integerField &rhs);

    ~integerField() noexcept override = default;

    const int &value() const noexcept;

    void setValue(const int value);

    integerField &operator=(const integerField &rhs);

    bool operator<(const integerField &rhs);

    bool empty() override;

private:
    int _value;
    int _defaultValue;
};


#endif //BASICMODEL_INTEGERFIELD_H
