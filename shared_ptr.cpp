#define BOOST_SP_USE_QUICK_ALLOCATOR

#include <boost/shared_ptr.hpp>
#include <iostream>
#include <Windows.h>
#include <boost/make_shared.hpp>
#include <typeinfo>
#include <boost/shared_array.hpp>
#include <ctime>

using std::cout;
using std::endl;
using boost::shared_ptr;

int main()
{
	shared_ptr<int> p1{ new int{1} };
	cout << *p1 << '\n';
	shared_ptr<int> p2{p1};
	p1.reset(new int{ 2 });
	cout << *p1.get() << endl;
	p1.reset();
	cout << std::boolalpha << static_cast<bool>(p1) << endl;
	cout << std::boolalpha << static_cast<bool>(p2) << endl;
	/////////////////////////////////////////////////////////////////////////////////////////
	DWORD id = GetCurrentProcessId();
	shared_ptr<void> handle(OpenProcess(PROCESS_SET_INFORMATION, FALSE,id ), CloseHandle);
	cout << handle.get() << endl;
	cout << "Current Process Id : " << id << endl;
	/////////////////////////////////////////////////////////////////////////////////////////
	auto r1 = boost::make_shared<int>(1);
	cout << typeid(r1).name() << '\n';
	auto r2 = boost::make_shared<int[]>(10);
	cout << typeid(r2).name() << '\n';
	cout << typeid(p2).name() << endl;
	///////////////////////////////////////////////////////////////////////////////////////////
	boost::shared_array<int> a{ new int[10] };
	boost::shared_array<int> a2{ a };
	a2[0] = 1;
	cout << a[0] << '\n';
	/////////////////////////////////////////////////////////////////////////////////////////////
	boost::shared_ptr<int> p;
	std::time_t then = std::time(nullptr);
	for (int i = 0; i < 1000000; ++i)
		p.reset(new int{ i });
	std::time_t now = std::time(nullptr);
	std::cout << now - then << '\n';
	return 0;
}