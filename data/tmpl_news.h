//
// Created by Даниил Котельников on 07.04.17.
//

#ifndef TRAVELMATE_TMPL_NEWS_H
#define TRAVELMATE_TMPL_NEWS_H

#include "tmpl_master.h"

namespace Data {
    //-------------------------------------------------------------------------------------
    // Dsc: Новостной контент
    //-------------------------------------------------------------------------------------
    struct News : public Master {
        //-------------------------------------------------------------------------------------
        // Dsc: Главная новость
        //-------------------------------------------------------------------------------------
        std::string mainNews;

        //-------------------------------------------------------------------------------------
        // Dsc: Конструктор страницы
        //-------------------------------------------------------------------------------------
        News() :
                Master() {}

        //-------------------------------------------------------------------------------------
        // Dsc: Ленивый деструктор
        //-------------------------------------------------------------------------------------
        ~News() {}
    };
}
#endif //TRAVELMATE_TMPL_NEWS_H
