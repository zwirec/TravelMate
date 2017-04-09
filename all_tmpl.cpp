#line 1 "./templates/master.tmpl"

#include "data/tmpl_master.h"

#line 2 "./templates/master.tmpl"
namespace defskin {
#line 3 "./templates/master.tmpl"

    struct Master : public cppcms::base_view
#line 3 "./templates/master.tmpl"
    {
#line 3 "./templates/master.tmpl"
        Data::Master &content;
#line 3 "./templates/master.tmpl"

        Master(std::ostream &_s, Data::Master &_content) : cppcms::base_view(_s), content(_content)
#line 3 "./templates/master.tmpl"
        {
#line 3 "./templates/master.tmpl"
        }

#line 4 "./templates/master.tmpl"

        virtual void page_main() {
#line 4 "./templates/master.tmpl"
            out() << "MAIN TEMPLATE";
#line 4 "./templates/master.tmpl"
        } // end of template page_main
#line 5 "./templates/master.tmpl"

        virtual void page_footer() {
#line 5 "./templates/master.tmpl"
            out() << "Все права защищены";
#line 5 "./templates/master.tmpl"
        } // end of template page_footer
#line 6 "./templates/master.tmpl"

        virtual void page_left_sidebar() {
#line 6 "./templates/master.tmpl"
            out() << "Левая панелька";
#line 6 "./templates/master.tmpl"
        } // end of template page_left_sidebar
#line 7 "./templates/master.tmpl"

        virtual void render() {
#line 12 "./templates/master.tmpl"
            out() << "\n"
                    "<!DOCTYPE html>\n"
                    "<html>\n"
                    "<head>\n"
                    "    <meta charset=\"utf-8\"/>\n"
                    "    <title>";
#line 12 "./templates/master.tmpl"
            out() << cppcms::filters::escape(content.page.title);
#line 13 "./templates/master.tmpl"
            out() << "</title>\n"
                    "    <meta name=\"keywords\" content=\"";
#line 13 "./templates/master.tmpl"
            out() << cppcms::filters::escape(content.page.keywords);
#line 14 "./templates/master.tmpl"
            out() << "\"/>\n"
                    "    <meta name=\"description\" content=\"";
#line 14 "./templates/master.tmpl"
            out() << cppcms::filters::escape(content.page.description);
#line 21 "./templates/master.tmpl"
            out() << "\"/>\n"
                    "    <link href=\"../static/css/style.css\" rel=\"stylesheet\">\n"
                    "</head>\n"
                    "<body>\n"
                    "<div class=\"wrapper\">\n"
                    "    <header class=\"header\">\n"
                    "        <div class=\"nav\">\n"
                    "            ";
#line 21 "./templates/master.tmpl"
            if ((content.page.menuList).begin() != (content.page.menuList).end()) {
#line 23 "./templates/master.tmpl"
                out() << "\n"
                        "            <ul>\n"
                        "                ";
#line 23 "./templates/master.tmpl"
                for (CPPCMS_TYPEOF(
                             (content.page.menuList).begin()) menuItem_ptr = (content.page.menuList).begin(), menuItem_ptr_end = (content.page.menuList).end();
                     menuItem_ptr != menuItem_ptr_end; ++menuItem_ptr) {
#line 23 "./templates/master.tmpl"
                    CPPCMS_TYPEOF(*menuItem_ptr) &menuItem = *menuItem_ptr;
#line 24 "./templates/master.tmpl"
                    out() << "\n"
                            "                <li><a href=\"";
#line 24 "./templates/master.tmpl"
                    out() << cppcms::filters::escape(menuItem.first);
#line 24 "./templates/master.tmpl"
                    out() << "\">";
#line 24 "./templates/master.tmpl"
                    out() << cppcms::filters::escape(menuItem.second);
#line 25 "./templates/master.tmpl"
                    out() << "</a></li>\n"
                            "                ";
#line 25 "./templates/master.tmpl"
                } // end of item
#line 27 "./templates/master.tmpl"
                out() << "\n"
                        "            </ul>\n"
                        "            ";
#line 27 "./templates/master.tmpl"
            }
#line 32 "./templates/master.tmpl"
            out() << "\n"
                    "        </div>\n"
                    "    </header>\n"
                    "    <div class=\"middle\">\n"
                    "        <div class=\"container\">\n"
                    "            <main class=\"content\">";
#line 32 "./templates/master.tmpl"
            page_main();
#line 36 "./templates/master.tmpl"
            out() << "</main>\n"
                    "        </div>\n"
                    "        <aside class=\"left-sidebar\">\n"
                    "            <div>\n"
                    "                ";
#line 36 "./templates/master.tmpl"
            page_left_sidebar();
#line 41 "./templates/master.tmpl"
            out() << "\n"
                    "            </div>\n"
                    "        </aside>\n"
                    "    </div>\n"
                    "</div>\n"
                    "<footer class=\"footer\">";
#line 41 "./templates/master.tmpl"
            page_footer();
#line 44 "./templates/master.tmpl"
            out() << "</footer>\n"
                    "</body>\n"
                    "</html>\n"
                    "";
#line 44 "./templates/master.tmpl"
        } // end of template render
#line 45 "./templates/master.tmpl"
    }; // end of class Master
#line 46 "./templates/master.tmpl"
} // end of namespace defskin
#line 1 "./templates/news.tmpl"

#include "data/tmpl_news.h"

#line 2 "./templates/news.tmpl"
namespace defskin {
#line 3 "./templates/news.tmpl"

    struct News : public Master
#line 3 "./templates/news.tmpl"
    {
#line 3 "./templates/news.tmpl"
        Data::News &content;
#line 3 "./templates/news.tmpl"

        News(std::ostream &_s, Data::News &_content) : Master(_s, _content), content(_content)
#line 3 "./templates/news.tmpl"
        {
#line 3 "./templates/news.tmpl"
        }

#line 4 "./templates/news.tmpl"

        virtual void page_main() {
#line 4 "./templates/news.tmpl"
            out() << cppcms::filters::escape(content.mainNews);
#line 4 "./templates/news.tmpl"
        } // end of template page_main
#line 5 "./templates/news.tmpl"
    }; // end of class News
#line 6 "./templates/news.tmpl"
} // end of namespace defskin
#line 6 "./templates/news.tmpl"
namespace {
#line 6 "./templates/news.tmpl"
    cppcms::views::generator my_generator;
#line 6 "./templates/news.tmpl"

    struct loader {
#line 6 "./templates/news.tmpl"

        loader() {
#line 6 "./templates/news.tmpl"
            my_generator.name("defskin");
#line 6 "./templates/news.tmpl"
            my_generator.add_view<defskin::Master, Data::Master>("Master", true);
#line 6 "./templates/news.tmpl"
            my_generator.add_view<defskin::News, Data::News>("News", true);
#line 6 "./templates/news.tmpl"
            cppcms::views::pool::instance().add(my_generator);
#line 6 "./templates/news.tmpl"
        }

#line 6 "./templates/news.tmpl"

        ~loader() { cppcms::views::pool::instance().remove(my_generator); }

#line 6 "./templates/news.tmpl"
    } a_loader;

#line 6 "./templates/news.tmpl"
} // anon 
