#include <boost/spirit/include/qi.hpp>
#include <string>
#include <iostream>

using namespace boost::spirit;
using std::cout;
using std::cin;
using std::endl;
/*
int main()
{
	std::string s;
	std::getline(cin, s);
	auto it = s.begin();
	bool match = qi::phrase_parse(it, s.end(), ascii::digit >> ascii::digit, ascii::space);
	cout << std::boolalpha << match << endl;
	if (it != s.end())
		cout << std::string{ it, s.end() };

	return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	bool match = qi::phrase_parse(it, s.end(), qi::lexeme[ascii::digit >> ascii::digit], ascii::space);
	cout << std::boolalpha << match << endl;
	if (it != s.end())
		cout << std::string{ it, s.end() } << endl;
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s;
	std::getline(cin, s);
	auto it = s.begin();
	bool match = qi::phrase_parse(it, s.end(), +ascii::digit , ascii::space);
	cout << std::boolalpha << match << endl;
	if (it != s.end())
		cout << std::string{ it, s.end() };
    return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	std::string s;
	std::getline(cin, s);
	auto it = s.begin();
	bool match = qi::phrase_parse(it, s.end(), qi::byte_, ascii::space);
	cout << std::boolalpha << match << endl;
	if (it != s.end())
		cout << std::string{ it, s.end() };
	return 0;
}