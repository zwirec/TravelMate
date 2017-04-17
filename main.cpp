#include <cppcms/applications_pool.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/http_response.h>
#include <cppcms/url_mapper.h>
#include <cppcms/service.h>
#include "data/tmpl_master.h"
#include "data/tmpl_news.h"

//-------------------------------------------------------------------------------------
// Dsc: Наш класс отрисовки страниц, при запросе некоторого адреса пользователем
//      В первую очередь он попадет сюда
//-------------------------------------------------------------------------------------
class WebSite : public cppcms::application {
public:
    //-------------------------------------------------------------------------------------
    // Dsc: Конструктор, который будет запушен во время старта программы
    //-------------------------------------------------------------------------------------
    WebSite(cppcms::service &s) : cppcms::application(s) {
        dispatcher().assign("/news(.*)", &WebSite::news, this, 1);
        mapper().assign("news", "/news");

        dispatcher().assign("(/?)", &WebSite::master, this, 1);
        mapper().assign("master", "/");
    }

    //-------------------------------------------------------------------------------------
    // Dsc: Функция в которую мы попадем, если иного не указано в конструкторе
    //      ( об этом позже )
    //-------------------------------------------------------------------------------------
    virtual void main(std::string path) {
        cppcms::application::main(path);
    };

    virtual void master(std::string path);

    virtual void news(std::string path);

    void print() {
        std::cout << "Hello" << std::endl;
    }
};


void WebSite::master(std::string path) {
    Data::Master tmpl;
    tmpl.page.title = path;
    tmpl.page.description = "description";
    tmpl.page.keywords = "keywords";
    tmpl.page.menuList["/news"] = std::string("NEWS");
    tmpl.page.menuList["/else"] = std::string("ELSE");
    render("Master", tmpl);
}

void WebSite::news(std::string path) {
    Data::News tmpl;
    tmpl.page.title = path;
    tmpl.page.description = "description";
    tmpl.page.keywords = "keywords";
    tmpl.page.menuList["/"] = std::string("MASTER");
    tmpl.page.menuList["/news"] = std::string("NEWS");
    tmpl.mainNews = "Сенсация! У нас на сайте ничего не произошло!";
    render("News", tmpl);
}



//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------
int main(int argc, char **argv) {
    try {
        // создаем сервис
        cppcms::service srv(argc, argv);
        // задаем корень
        srv.applications_pool().mount(cppcms::applications_factory<WebSite>());
        // запускаем
        srv.run();

    }
    catch (std::exception const &e) {
        std::cerr << "Failed: " << e.what() << std::endl;
        std::cerr << booster::trace(e) << std::endl;
        return 1;
    }
    return 0;
}