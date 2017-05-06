//
// Created by root on 03.05.17.
//

#ifndef BASICMODEL_BASEFIELD_H
#define BASICMODEL_BASEFIELD_H

#include <string>

namespace model {

    //До 16 битов информации
    enum Flags {
        primaryKeyBit = 1,
        nullBit = 1 << 2,
        defaultBit = 1 << 3,
        blankBit = 1 << 4
        //unique
        //foreign Key
    };


    class baseField {
    public:
        baseField() noexcept = default;

        baseField(const std::string &type, unsigned flags = 0, bool isNull = true); //noexcept?

        baseField(const baseField &rhs) noexcept;

        virtual ~baseField() noexcept = default;

        bool isPrimaryKey() noexcept;

        bool canBeNull() noexcept;

        bool hasDefault() noexcept;

        bool canBeBlank() noexcept;

        virtual bool empty() = 0;

        const std::string & type() const noexcept;

    protected:
        unsigned _flags:16;
        bool _isNull;

        const std::string _fieldType;

        void setFlags(const unsigned); //noexcept?

        void checkFlags();/*throw (...............)*/
    };
}
#endif //BASICMODEL_BASEFIELD_H
