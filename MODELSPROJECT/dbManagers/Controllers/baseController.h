//
// Created by root on 06.05.17.
//

#ifndef BASICMODEL_BASECONTROLLER_H
#define BASICMODEL_BASECONTROLLER_H

#include <vector>
#include <string>
#include "../querySets/baseQuerySet.h"

namespace model {
    namespace dbManager {
        template<class Model, class CustomQuerySet>
        class baseController {
        public:
            baseController() = default;

            baseController(const baseController &rhs) = default;

            ~baseController() = default;



            ///root/CLionProjects/basicModel/dbManagers/Controllers/baseController.h:23:57: error:
            /// invalid abstract return type ‘model::dbManager::baseQuerySet<model::user, model::dbManager::userQuerySet>’

            virtual baseQuerySet<Model, CustomQuerySet> all() = 0;

            //то же самое
            virtual baseQuerySet<Model, CustomQuerySet> get(const std::string &params) = 0;

        protected:

        };
    }
}


#endif //BASICMODEL_BASECONTROLLER_H
