#include <boost/xpressive/xpressive.hpp>
#include <boost/xpressive/regex_actions.hpp>
#include <iterator>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using namespace boost::xpressive;
/*
int main()
{
	std::string s = "Boost Libraries";
	sregex expr = sregex::compile("\\w+\\s\\w+");
	cout << std::boolalpha << regex_match(s, expr) << '\n';
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	const char *c = "Boost libraries";
	cregex expr = cregex::compile("\\w+\\s\\w+");
	cout << std::boolalpha << regex_match(c, expr) << '\n';
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost Libraries";
	sregex expr = +_w >> _s >> +_w;
	cout << std::boolalpha << regex_match(s, expr) << '\n';
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	std::string s = "Boost Libraries";
	std::ostream_iterator<std::string> it{ std::cout, "\n" };
	sregex expr = (+_w)[*boost::xpressive::ref(it) = _] >> _s >> +_w;
	cout << std::boolalpha << regex_match(s, expr) << '\n';
}