#include <boost/spirit/include/qi.hpp>
#include <boost/variant.hpp>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace boost::spirit;
/*
int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	qi::rule<std::string::iterator, std::vector<int>(), ascii::space_type> values = qi::int_ % ',';
	std::vector<int> v;
	if (qi::phrase_parse(it, s.end(), values, ascii::space, v))
	{
		std::ostream_iterator<int> out{ std::cout, ";" };
		std::copy(v.begin(), v.end(), out);
	}
	return 0;
}*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct print : public boost::static_visitor<>
{
	template<typename T>
	void operator()(T t)const
	{
		std::cout << std::boolalpha << t << ";";
	}
};

int main()
{
	std::string s = { "3442,5324 5345,543" };
	//std::getline(std::cin, s);
	auto it = s.begin();
	qi::rule<std::string::iterator, boost::variant<int, char>(), ascii::space_type> value = qi::int_ | qi::bool_;
	qi::rule<std::string::iterator, std::vector<boost::variant<int, char>>(), ascii::space_type> 
		values = value % ",";
	std::vector<boost::variant<int, char>> v;
	
	if (qi::phrase_parse(it, s.end(), values, ascii::space, v))
		for (const auto &elem : v)
			boost::apply_visitor(print{}, elem);

	return 0;
	
}
