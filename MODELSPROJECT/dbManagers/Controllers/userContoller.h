//
// Created by root on 06.05.17.
//

#ifndef BASICMODEL_USERCONTOLLER_H
#define BASICMODEL_USERCONTOLLER_H

#include "baseController.h"
#include "../../models/user.h"
#include "../querySets/userQuerySet.h"

namespace model{
    namespace dbManager{
        class userContoller: public baseController<user, userQuerySet> {

        };
    }
}



#endif //BASICMODEL_USERCONTOLLER_H
