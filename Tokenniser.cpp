#include <boost/tokenizer.hpp>
#include <string>
#include <iostream>

using std::cout;
using std::endl;
/*
int main()
{
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	std::string s = "Boost C++ Libraries";
	tokenizer tok{ s };
	for (tokenizer::iterator it = tok.begin(); it != tok.end(); ++it)
		cout << *it << '\n';
	return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	typedef boost::tokenizer<boost::char_separator<char>>  tokenizer;
	std::string s = "Boost C++ Libraries";
	boost::char_separator<char> sep{ " " };
	tokenizer tok{ s, sep };
	for (const auto &t : tok)
		cout << t << '\n';
	return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	std::string s = "Boost C++ Libraries";
	boost::char_separator<char> sep{ " ", "a" };
	tokenizer tok{ s, sep };
	for (const auto &t : tok)
		cout << t << endl;
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	std::string s = "Boost C++ Libraries";
	boost::char_separator<char> sep{ " ", "+", boost::keep_empty_tokens };
	tokenizer tok{ s, sep };
	for (const auto &t : tok)
		cout << t << endl;
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
int main()
{
	typedef boost::tokenizer<boost::char_separator<wchar_t>, std::wstring::const_iterator, std::wstring> tokenizer;
	std::wstring s = L"Boost C++ Libraries";
	boost::char_separator<wchar_t> sep{ L" " };
	tokenizer tok{ s, sep };
	for (const auto &t : tok)
		std::wcout << t << endl;
	return 0;
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	typedef boost::tokenizer<boost::escaped_list_separator<char>> tokenizer;
	std::string s = "Boost,\"C++ Libraries\"";
	tokenizer tok{ s };
	for (const auto &t : tok)
		cout << t << '\n';
	return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
