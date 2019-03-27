#define BOOST_SPIRIT_USE_PHOENIX_V3
#include <boost/phoenix/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>
#include <string>
#include <iostream>
using namespace boost::spirit;
using boost::phoenix::ref;
using std::cout;
using std::endl;
/*
int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	bool match = qi::phrase_parse(it, s.end(), qi::int_[([](int i) {cout << i << endl; })], ascii::space);
	cout << std::boolalpha << match << '\n';
	if (it != s.end())
		cout << std::string{ it, s.end() } << '\n';
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	int i;
	bool match = qi::phrase_parse(it, s.end(), qi::int_[ref(i) = qi::_1], ascii::space);
	cout << std::boolalpha << match << '\n';
	cout << i << endl;
	if (it != s.end())
		cout << std::string{ it, s.end() } << '\n';
	return 0;
}