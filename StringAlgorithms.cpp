#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/regex.hpp>
#include <string>
#include <iostream>
#include <locale>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using namespace std;
using namespace boost::algorithm;
/*
int main()
{
	std::string s = "Boost C++ Libraries";
	std::cout << to_upper_copy(s) << '\n';
	return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost C++ k\xfct\xfcphaneleri";
	std::string upper_case1 = to_upper_copy(s);
	std::string upper_case2 = to_upper_copy(s, std::locale{ "Russian" });
	std::locale::global(std::locale{ "Russian" });
	cout << upper_case1 << '\n';
	cout << upper_case2 << '\n';
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost C++ Libraries";
	cout << erase_first_copy(s, "s") << '\n';
	cout << erase_nth_copy(s, "s", 0) << '\n';
	cout << erase_last_copy(s, "s") << '\n';
	cout << erase_all_copy(s, "s") << '\n';
	cout << erase_head_copy(s, 5) << '\n';
	cout << erase_tail_copy(s, 9) << '\n';
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost C++ Libraries";
	boost::iterator_range<std::string::iterator> r = find_first(s, "C++");
	cout << r << '\n';
	r = find_first(s, "xyz");
	cout << r << '\n';
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::vector<std::string> v{ "Boost", "C++", "Libraries" };
	cout << join(v, " ") << '\n';
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost C++ Libraries";
	cout << replace_first_copy(s, "+", "-") << '\n';
	cout << replace_nth_copy(s, "+", 0, "-") << '\n';
	cout << replace_last_copy(s, "+", "-") << '\n';
	cout << replace_all_copy(s, "+", "-") << '\n';
	cout << replace_head_copy(s, 5, "BOOST") << '\n';
	cout << replace_tail_copy(s, 9, "LIBRARIES") << '\n';
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "\t Boost C++ Libraries";
	cout << "_" << trim_left_copy(s) << "_\n";
	cout << "_" << trim_right_copy(s) << "_\n";
	cout << "_" << trim_copy(s) << "_\n";
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "--Boost C++ Libraries--";
	cout << trim_left_copy_if(s, is_any_of("-")) << '\n';
	cout << trim_right_copy_if(s, is_any_of("-")) << '\n';
	cout << trim_copy_if(s, is_any_of("-")) << '\n';
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "123456789Boost C++ Libraries123456789";
	cout << trim_left_copy_if(s, is_digit()) << endl;;
	cout << trim_right_copy_if(s, is_digit()) << endl;;
	cout << trim_copy_if(s, is_digit()) << '\n';
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost C++ Libraries";
	cout.setf(std::ios::boolalpha);
	cout << starts_with(s, "Boost") << endl;
	cout << ends_with(s, "Libraries") << endl;
	cout << contains(s, "C++") << endl;
	cout << lexicographical_compare(s, "Boost") << endl;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::string s = "Boost C++ Libraries";
	std::vector<std::string> v;
	split(v, s, is_space());
	cout << v.size() << endl;
	for (std::vector<std::string>::iterator i = v.begin(); i != v.end(); ++i)
		cout << *i << endl;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
		std::string s = "Boost C++ Libraries";
		boost::iterator_range<std::string::iterator> r =find_regex(s, boost::regex{ "\\w\\+\\+" });
		std::cout << r << '\n';
}
*/

int main()
{
	boost::iterator_range<std::string::iterator> iter;
	std::string hello = { "Hello " }, full_name;
	std::vector<std::string>  fname;

	cout << "Enter your first name and last name : " ;
	getline(std::cin, full_name);
	hello += full_name;
	split(fname, hello, is_space());

	for (std::vector<std::string>::iterator iterator = fname.begin(); iterator != fname.end(); ++iterator)
	{
		iter =find_regex(*iterator, boost::regex{ "[[:alpha:]]" });
		to_upper(iter);
	}

	std::vector<std::string>::iterator i = fname.begin();
	++i;
	*i += "!";
	cout<<join(fname, " ");
    return 0;
}