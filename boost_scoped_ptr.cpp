#include <boost\scoped_ptr.hpp>
#include <boost/scoped_array.hpp>
#include <iostream>
using namespace std;

int main()
{
	boost::scoped_ptr<int> p{ new int{1} };
	cout << *p << '\n';
	p.reset(new int{ 2 });
	cout << *p.get() << '\n';
	p.reset();
	cout << std::boolalpha << static_cast<bool>(p) << '\n';
	boost::scoped_array<int> b{ new int[2] };
	*b.get() = 1;
	b[1] = 2;
	cout << b[0] << endl << b[1] << endl;
	b.reset(new int[3]);
	b[2] = 3;
	cout << b[2] << endl;
	cout << std::boolalpha << static_cast<bool>(b) << '\n';
	return 0;
}