#include <boost/ptr_container/ptr_vector.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <boost/ptr_container/indirect_fun.hpp>
#include <boost/ptr_container/ptr_inserter.hpp>
#include <string>
#include <array>
#include <algorithm>
#include <set>
#include <memory>
#include <functional>
#include <iostream>
#include <sstream>

using namespace std;
using std::cout;
using std::endl;
/*int main()
{
	boost::ptr_vector<int> v;
	v.push_back({ new int {1} });
	v.push_back({ new int {2} });
	cout << v.back() << endl;
	return 0;
}*/
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	boost::ptr_multiset<int> s;
	s.insert({ new int{2}});
	s.insert({ new int{1}});
	cout << *s.begin() << endl;

	std::set<std::unique_ptr<int>, boost::indirect_fun<std::less<int>>> v;
	v.insert(std::unique_ptr<int>(new int{ 2 }));
	v.insert(std::unique_ptr<int>(new int{ 1 }));
	cout << **v.begin() << endl;
	return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////
/*int main()
{
	boost::ptr_vector<int> v;
	std::array<int, 3> a{ {0,1,2} };
	std::copy(a.begin(), a.end(), boost::ptr_container::ptr_back_inserter(v));
	cout << v.size() << '\n';
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////
class animal
{
public:
	animal() :legs(0), has_tail(0), name("")
	{
		ostringstream stream;
		stream << legs << ", " << has_tail << ", ";
		outstring = stream.str();
		outstring += name;
	}
	animal(int leg, int tail, std::string n):legs(leg), has_tail(tail), name(n)
	{
		ostringstream stream;
		stream << legs << ", " << has_tail << ", ";
		outstring = stream.str();
		outstring += name;
	}
	operator const char*()const {return outstring.c_str();}
	int legs;
	int has_tail;
	std::string name;
	string outstring;
};

bool sort_pri(const animal & rleg, const animal & lleg)
{
	return (lleg.legs > rleg.legs);
}
template<typename T>
struct mysort
{
	bool operator()(const T&a1, const T&a2) { return (a1.legs < a2.legs); }
};

int main()
{
	//boost::ptr_vector<animal, boost::inderect_fun<std::less<animal>> v;
	boost::ptr_vector<animal> v;
	v.push_back({ new animal(2,1,"b") });
	v.push_back({ new animal(5,1,"f") });
	v.push_back({ new animal(3,1,"c") });
	v.push_back({ new animal(1,1,"A") });
	v.push_back({ new animal(4,1,"d") });
	sort(v.begin(), v.end(), mysort<animal>());//[](const animal & a1, const animal & a2)->bool {return (a1.legs < a2.legs); });
	
	for (auto elem = v.cbegin(); elem != v.cend(); ++elem)
		cout << elem->outstring << endl;
	return 0;
}