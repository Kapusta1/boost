#include <boost/spirit/include/qi.hpp>
#include <boost/variant.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>

using namespace boost::spirit;
using std::cout;
 
typedef  qi::rule<std::string::iterator, std::vector<float>(), ascii::space_type> v_int;

struct number
{
	float first;
	float second;
};

int main()
{
	std::string s = { "1.2+6/5-0.9" };
	//std::getline(std::cin, s);
	std::string::iterator it = s.begin();
	qi::rule<std::string::iterator, std::vector<float>(), ascii::space_type> value_f =  qi::float_;
	qi::rule<std::string::iterator, std::vector<float>(), ascii::space_type> value_i = qi::int_;
	qi::rule<std::string::iterator, std::vector<float>(), ascii::space_type> value_sub = value_f % '-';
	qi::rule<std::string::iterator, std::vector<float>(), ascii::space_type> value_sum = value_f % '+';
	qi::rule<std::string::iterator, std::vector<float>(), ascii::space_type> value_div = value_f % '/';

   // v_int value_sub = qi::float_ % '-';
   //v_int value_sum = qi::float_ % '+';
   //v_int value_div = qi::int_  % '/';
		
	std::vector<float> v;
	float  result = 0, i=0;
	number div, sum, sub;

		if (qi::phrase_parse(it, s.end(), value_sum, ascii::space, v))
			for (const auto &elem : v)
			{
				if (i == 0)
					sum.first = elem;
				else
					sum.second = elem;
				++i;
			}
		v.clear();
		--it;
		i = 0;
		if (qi::phrase_parse(it, s.end(), value_div, ascii::space, v))
			for (const auto &elem : v)
			{
				if (i == 0)
					div.first = elem;
				else
					div.second = elem;
				++i;
			}
		v.clear();
		i = 0;
		if (qi::phrase_parse(it, s.end(), value_sub, ascii::space, v))
			for (const auto &elem : v)
			{
				if (i == 0)
					sub.first = std::abs( elem);
				else
					sub.second = std::abs(elem);
				++i;
			}
				
		v.clear();

		result = div.first / div.second;
		result += sum.first;
		result -= sub.first;
	cout << "result : " << result << '\n';
	return 0;
}
