#include <boost/format.hpp>
#include <iostream>
using std::cout;
using std::endl;
/*
int main()
{
	cout << boost::format{ "%1%.%2%.%3%" } % 12 % 5 % 2014 << endl;
	cout<<boost::format{"%2%/%1%/%3%"} % 12 % 5 % 2014 << endl;
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	std::cout << boost::format{ "%1% %2% %1%" }%boost::io::group(std::showpos, 1) % 5 << endl;
	cout << boost::format{ "%|1$+| %2% %1%" } % 1 % 2 << endl;
	try
	{
		std::cout << boost::format{ "%|1$+| %2% %1%" } % 1 % 2 << '\n';
	}
	catch (boost::io::format_error &ex)
	{
		std::cout << ex.what() << '\n';
	}
	std::cout << boost::format{ "%|+| %|| %||" } % 1 % 2 % 1 << '\n';
	std::cout << boost::format{ "%+d %d %d" } % 1 % 2 % 1 << '\n';
	std::cout << boost::format{ "%+s %s %s" } % 1 % 2 % 1 << '\n';
	return 0;
}
*/

struct animal
{
	std::string name;
	int legs;
};

std::ostream &operator<<(std::ostream &os, const animal &a)
{
	return os << a.name << ',' << a.legs;
}

int main()
{
	animal a{ "cat", 4 };
	std::cout << boost::format{ "%1%" } % a << '\n';
}