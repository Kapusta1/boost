#include <boost/spirit/include/qi.hpp>
#include <boost/variant.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <string>
#include <vector>
#include <iostream>

using namespace boost::spirit;
using std::cout;
using std::endl;
typedef boost::variant<int, bool> int_or_bool;

/*
template <typename Iterator, typename Skipper>
struct my_grammer :qi::grammar<Iterator, std::vector<boost::variant<int, bool>>(), Skipper>
{
	my_grammer() :my_grammer::base_type{ values }
	{
		value = qi::int_ | qi::bool_;
		values = value % ',';
	}
	qi::rule<Iterator, boost::variant<int, bool>(), Skipper> value;
	qi::rule<Iterator, std::vector<boost::variant<int, bool>>(), Skipper> values;
};

struct print :public boost::static_visitor<>
{
	template<typename T>
	void operator()(T t)const
	{
		cout << std::boolalpha << t << ';';
	}
};
int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	my_grammer<std::string::iterator, ascii::space_type> g;
	std::vector<boost::variant<int, bool>> v;

	if(qi::phrase_parse(it, s.end(), g, ascii::space, v))
		for(const auto &elem:v)
			boost::apply_visitor(print{}, elem);
	return 0;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct int_or_bool_values
{
	int_or_bool first;
	std::vector<int_or_bool> others;
};

BOOST_FUSION_ADAPT_STRUCT(
	int_or_bool_values,
	(int_or_bool, first)
	(std::vector<int_or_bool>, others)
)

template <typename Iterator, typename Skipper>
struct my_grammar : qi::grammar<Iterator, int_or_bool_values(), Skipper>
{
	my_grammar() : my_grammar::base_type{ values }
	{
		value = qi::int_ | qi::bool_;
		values = value >> ',' >> value % ',';
	}

	qi::rule<Iterator, int_or_bool(), Skipper> value;
	qi::rule<Iterator, int_or_bool_values(), Skipper> values;
};

struct print : public boost::static_visitor<>
{
	template <typename T>
	void operator()(T t) const
	{
		std::cout << std::boolalpha << t << ';';
	}
};

int main()
{
	std::string s;
	std::getline(std::cin, s);
	auto it = s.begin();
	my_grammar<std::string::iterator, ascii::space_type> g;
	int_or_bool_values v;

	if (qi::phrase_parse(it, s.end(), g, ascii::space, v))
	{
		print p;
		boost::apply_visitor(p, v.first);
		for (const auto &elem : v.others)
			boost::apply_visitor(p,elem);
	}
	return 0;
}

