#ifndef TRAVELMATE_TMPL_MASTER_H
#define TRAVELMATE_TMPL_MASTER_H


#include <vector>
#include <cppcms/view.h>
#include <map>
#include <string>

namespace Data {

    struct infoPage {
        std::string title;                         // титул страницы
        std::string description;                   // описание страницы
        std::string keywords;                      // ключевые слова страницы
        std::map<std::string, std::string> menuList;   // список выводимых пунктов меню (url,desc)

        infoPage() :
                title(""),
                description(""),
                keywords(""),
                menuList() {}


        ~infoPage() {}
    };


    struct Master : public cppcms::base_content {
        Master()
                {}


        ~Master() {}
    };
}
#endif
