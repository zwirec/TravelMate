#ifndef TRAVELMATE_TMPL_MASTER_H
#define TRAVELMATE_TMPL_MASTER_H

#include <cppcms/view.h>
#include <map>

namespace Data {
    //-------------------------------------------------------------------------------------
    // Dsc: Структура основной информации о странице
    //-------------------------------------------------------------------------------------
    struct infoPage {
        std::string title;                         // титул страницы
        std::string description;                   // описание страницы
        std::string keywords;                      // ключевые слова страницы
        std::map<std::string, std::string> menuList;   // список выводимых пунктов меню (url,desc)
        //-------------------------------------------------------------------------------------
        // Dsc: Конструктор, инициализирующий переменные
        //-------------------------------------------------------------------------------------
        infoPage() :
                title(""),
                description(""),
                keywords(""),
                menuList() {}

        //-------------------------------------------------------------------------------------
        // Dsc: Деструктор, ничего не делающий
        //-------------------------------------------------------------------------------------
        ~infoPage() {}
    };

    //-------------------------------------------------------------------------------------
    // Dsc: Базовый контент который есть на каждой странице
    //-------------------------------------------------------------------------------------
    struct Master : public cppcms::base_content {
        infoPage page;

        //-------------------------------------------------------------------------------------
        // Dsc: Конструктор страницы
        //-------------------------------------------------------------------------------------
        Master() :
                page() {}

        //-------------------------------------------------------------------------------------
        // Dsc: Ленивый деструктор
        //-------------------------------------------------------------------------------------
        ~Master() {}
    };
}
#endif //TRAVELMATE_TMPL_MASTER_H