#line 1 "./templates/master.tmpl"
#include "data/tmpl_master.h" 
#line 2 "./templates/master.tmpl"
namespace defskin {
	#line 3 "./templates/master.tmpl"
	struct Master :public cppcms::base_view
	#line 3 "./templates/master.tmpl"
	{
	#line 3 "./templates/master.tmpl"
		Data::Master &content;
	#line 3 "./templates/master.tmpl"
		Master(std::ostream &_s,Data::Master &_content): cppcms::base_view(_s),content(_content)
	#line 3 "./templates/master.tmpl"
		{
	#line 3 "./templates/master.tmpl"
		}
		#line 4 "./templates/master.tmpl"
		virtual void page_main() {
			#line 4 "./templates/master.tmpl"
			out()<<"MAIN TEMPLATE";
		#line 4 "./templates/master.tmpl"
		} // end of template page_main
		#line 5 "./templates/master.tmpl"
		virtual void page_footer() {
			#line 5 "./templates/master.tmpl"
			out()<<"Все права защищены";
		#line 5 "./templates/master.tmpl"
		} // end of template page_footer
		#line 6 "./templates/master.tmpl"
		virtual void page_left_sidebar() {
			#line 6 "./templates/master.tmpl"
			out()<<"Левая панелька";
		#line 6 "./templates/master.tmpl"
		} // end of template page_left_sidebar
		#line 7 "./templates/master.tmpl"
		virtual void render() {
			#line 110 "./templates/master.tmpl"
			out()<<"\n"
				"<!DOCTYPE html>\n"
				"<html lang=\"en\">\n"
				"\n"
				"<head>\n"
				"\n"
				"    <meta charset=\"utf-8\">\n"
				"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
				"    <meta name=\"description\" content=\"\">\n"
				"    <meta name=\"author\" content=\"\">\n"
				"\n"
				"    <title>TravelMate</title>\n"
				"\n"
				"    <link href=\"/static/css/bootstrap.css\" rel=\"stylesheet\">\n"
				"    <script src=\"http://code.jquery.com/jquery-3.2.1.js\"></script>\n"
				"    <script src=\"../static/js/myjs.js\"></script>\n"
				"    <script src=\"../static/js/bootstrap.min.js\"></script>\n"
				"\n"
				"    <link href=\"/static/css/style1.css?v=3\" rel=\"stylesheet\">\n"
				"    <link href=\"/static/css/loginform.css\" rel=\"stylesheet\">\n"
				"\n"
				"    <link href=\"https://fonts.googleapis.com/css?family=Lato:300,400,700,300italic,400italic,700italic\" rel=\"stylesheet\"\n"
				"          type=\"text/css\">\n"
				"\n"
				"</head>\n"
				"\n"
				"<body>\n"
				"\n"
				"<nav class=\"navbar navbar-default navbar-fixed-top topnav\" role=\"navigation\">\n"
				"    <div class=\"container topnav\">\n"
				"        <div class=\"navbar-header\">\n"
				"            <button type=\"button\" class=\"navbar-toggle\" data-toggle=\"collapse\"\n"
				"                    data-target=\"#bs-example-navbar-collapse-1\">\n"
				"                <span class=\"sr-only\">Toggle navigation</span>\n"
				"                <span class=\"icon-bar\"></span>\n"
				"                <span class=\"icon-bar\"></span>\n"
				"                <span class=\"icon-bar\"></span>\n"
				"            </button>\n"
				"            <a class=\"navbar-brand topnav\" href=\"#\">TravelMate</a>\n"
				"        </div>\n"
				"        <div class=\"collapse navbar-collapse\" id=\"bs-example-navbar-collapse-1\">\n"
				"            <ul class=\"nav navbar-nav navbar-right\">\n"
				"                <li>\n"
				"                    <a href=\"#about\">About</a>\n"
				"                </li>\n"
				"                <li>\n"
				"                    <a href=\"#services\">Services</a>\n"
				"                </li>\n"
				"                <li>\n"
				"                    <a href=\"#contact\">Contact</a>\n"
				"                </li>\n"
				"            </ul>\n"
				"        </div>\n"
				"    </div>\n"
				"</nav>\n"
				"\n"
				"\n"
				"<div class=\"modal fade\" id=\"login\" tabindex=\"-1\" role=\"dialog\" aria-labelledby=\"myModalLabel\" aria-hidden=\"true\"\n"
				"     style=\"display: none;\">\n"
				"    <div class=\"modal-dialog\">\n"
				"        <div class=\"loginmodal-container\">\n"
				"            <h1>Login to Your Account</h1><br>\n"
				"            <form>\n"
				"                <input type=\"text\" name=\"user\" placeholder=\"Username\">\n"
				"                <input type=\"password\" name=\"pass\" placeholder=\"Password\">\n"
				"                <input type=\"submit\" name=\"login\" class=\"login loginmodal-submit\" value=\"Login\">\n"
				"            </form>\n"
				"\n"
				"            <div class=\"login-help\">\n"
				"                <a href=\"#\">Register</a> - <a href=\"#\">Forgot Password</a>\n"
				"            </div>\n"
				"        </div>\n"
				"    </div>\n"
				"</div>\n"
				"\n"
				"<a name=\"about\"></a>\n"
				"<div class=\"intro-header\">\n"
				"    <div class=\"container\">\n"
				"\n"
				"        <div class=\"row\">\n"
				"            <div class=\"col-lg-12\">\n"
				"                <div class=\"intro-message\">\n"
				"                    <h1>TravelMate</h1>\n"
				"                    <h3>Your personal Travel Mate</h3>\n"
				"                    <hr class=\"intro-divider\">\n"
				"                    <ul class=\"list-inline intro-social-buttons\">\n"
				"                        <li>\n"
				"                            <a href=\"#\" id=\"btn-login\" class=\"btn btn-default btn-lg\"><i\n"
				"                                    class=\"fa fa-twitter fa-fw\"></i> <span class=\"network-name\">LOGIN</span></a>\n"
				"                        </li>\n"
				"                        <li>\n"
				"                            <a href=\"#\"\n"
				"                               class=\"btn btn-default btn-lg\"><i class=\"fa fa-github fa-fw\"></i> <span\n"
				"                                    class=\"network-name\">LETS GO!</span></a>\n"
				"                        </li>\n"
				"                    </ul>\n"
				"                </div>\n"
				"            </div>\n"
				"        </div>\n"
				"    </div>\n"
				"</div>\n"
				"</body>\n"
				"</html>\n"
				"";
		#line 110 "./templates/master.tmpl"
		} // end of template render
	#line 111 "./templates/master.tmpl"
	}; // end of class Master
#line 112 "./templates/master.tmpl"
} // end of namespace defskin
#line 1 "./templates/news.tmpl"
#include "data/tmpl_news.h" 
#line 2 "./templates/news.tmpl"
namespace defskin {
	#line 3 "./templates/news.tmpl"
	struct News :public Master
	#line 3 "./templates/news.tmpl"
	{
	#line 3 "./templates/news.tmpl"
		Data::News &content;
	#line 3 "./templates/news.tmpl"
		News(std::ostream &_s,Data::News &_content): Master(_s,_content),content(_content)
	#line 3 "./templates/news.tmpl"
		{
	#line 3 "./templates/news.tmpl"
		}
		#line 4 "./templates/news.tmpl"
		virtual void page_main() {
			#line 4 "./templates/news.tmpl"
			out()<<cppcms::filters::escape(content.mainNews);
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
   my_generator.add_view<defskin::Master,Data::Master>("Master",true);
#line 6 "./templates/news.tmpl"
   my_generator.add_view<defskin::News,Data::News>("News",true);
#line 6 "./templates/news.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 6 "./templates/news.tmpl"
 }
#line 6 "./templates/news.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 6 "./templates/news.tmpl"
} a_loader;
#line 6 "./templates/news.tmpl"
} // anon 
