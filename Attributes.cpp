#include <boost/spirit/include/qi.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace boost::spirit;
/*
int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	int i;
	if (qi::phrase_parse(it, s.end(), qi::int_, ascii::space, i))
		std::cout << i << '\n';
	return 0;
}
*/

int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	std::vector<int> v;
	if (qi::phrase_parse(it, s.end(), qi::int_ % ',', ascii::space, v))
	{
		std::ostream_iterator<int> out{ std::cout, ";" };
		std::copy(v.begin(), v.end(), out);
	}
	return 0;
}