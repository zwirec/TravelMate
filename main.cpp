#include <cppcms/applications_pool.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/http_response.h>
#include <cppcms/url_mapper.h>
#include <cppcms/service.h>
#include "data/tmpl_master.h"
#include "data/tmpl_news.h"
#include "models/dbConfig.h"
#include "managers.h"


class WebSite : public cppcms::application {
private:

public:

    WebSite(cppcms::service &s) : cppcms::application(s) {
        dispatcher().assign("/news(.*)", &WebSite::news, this, 1);
        mapper().assign("news", "/news");

        dispatcher().assign("(/?)", &WebSite::master, this, 1);
        mapper().assign("master", "/");


    }

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

    render("Master", tmpl);
}

void WebSite::news(std::string path) {
    Data::Master tmpl;
    std::string username = request().post("username");
    std::string password = request().post("password");
    model::managers dispatcher;
    auto um = dispatcher.getManager<users>();
    um.authenticate("bla", "bla");
    render("News", tmpl);
}




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