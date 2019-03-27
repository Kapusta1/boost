#include <iostream>
#include <boost/regex.hpp>
#include <string>
#include <locale>
using std::cout;
using std::endl;
/*
int main()
{
	std::string s = "Boost Libraries";
	boost::regex expr{ "\\w+\\s\\w+" };
	cout << std::boolalpha << boost::regex_match(s, expr) << '\n';
	return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost libraries";
	boost::regex expr{ "(\\w+)\\s(\\w+)" };
	boost::smatch what;
	if (boost::regex_search(s, what, expr))
	{
		cout << what[0] << '\n';
		cout << what[1] << "_" << what[2] << '\n';
	}
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = " Boost Libraires ";
	boost::regex expr{ "\\s" };
	std::string fmt{ "_" };
	cout << boost::regex_replace(s, expr, fmt)<<'\n';
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost Libraries";
	boost::regex expr{ "(\\w+)\\s(\\w+)" };
	std::string fmt{ "\\2 \\1" };
	std::cout << boost::regex_replace(s, expr, fmt) << '\n';
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost Libraries";
	boost::regex expr{ "(\\w+)\\s(\\w+)" };
	std::string fmt{ "\\2 \\1" };
	cout << boost::regex_replace(s, expr, fmt, boost::regex_constants::format_literal) << '\n';
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost libraries";
	boost::regex expr{ "\\w+" };
	boost::regex_token_iterator<std::string::iterator> it{ s.begin(), s.end(), expr };
	boost::regex_token_iterator<std::string::iterator> end;
	while (it != end)
		cout << *it++ << '\n';
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost Libraries";
	boost::regex expr{ "(\\w)\\w+" };
	boost::regex_token_iterator<std::string::iterator> it{ s.begin(), s.end(), expr, 2 };
	boost::regex_token_iterator<std::string::iterator> end;
	while (it != end)
		cout << *it++ << '\n';
	return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	std::string s = "Boost k\xfct\xfcphaneleri";
	boost::basic_regex<char, boost::cpp_regex_traits<char>> expr;
	expr.imbue(std::locale{ "Turkish" });
	expr = "\\w+\\s\\w+";
	cout << std::boolalpha << boost::regex_match(s, expr) << '\n';
}