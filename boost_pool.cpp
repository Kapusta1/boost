#define BOOST_POOL_NO_MT
#include <boost/pool/simple_segregated_storage.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/singleton_pool.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <vector>
#include <cstddef>
#include <iostream>
#include <list>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	boost::simple_segregated_storage<std::size_t> storage;
	std::vector<char> v(1024);
	storage.add_block(&v.front(), v.size(), 256);
	int *i = static_cast<int *>(storage.malloc());
	*i = 1;
	int *j = static_cast<int*>(storage.malloc_n(1, 512));
	j[10] = 2;
	storage.free(i);
	storage.free_n(j, 1, 512);
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	boost::object_pool<int> pool;
	int *i = pool.malloc();
	*i = 1;
	int *j = pool.construct(2);

	pool.destroy(i);
	pool.destroy(j);
	return 0;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	boost::object_pool<int> pool{ 32,1 };
	pool.construct();
	cout << pool.get_next_size() << '\n';
	pool.set_next_size(8);
	cout << pool.get_next_size() << '\n';
	return 0;
}
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct int_pool{};
typedef boost::singleton_pool<int_pool, sizeof(int)> singlenton_int_pool;
int main()
{
	int *i = static_cast<int*>(singlenton_int_pool::malloc());
	*i = 1;
	int *j = static_cast<int*>(singlenton_int_pool::ordered_malloc(10));
	j[9] = 2;
	singlenton_int_pool::release_memory();
	singlenton_int_pool::purge_memory();
	return 0;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
int main()
{
	vector<int, boost::pool_allocator<int>> v;
	for (int i = 0; i < 1000; ++i)
		v.push_back(i);
	v.clear();
	boost::singleton_pool<boost::pool_allocator_tag, sizeof(int)>::purge_memory();
	return 0;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	typedef boost::fast_pool_allocator<int,
		boost::default_user_allocator_new_delete,
		boost::details::pool::default_mutex, 64, 128> allocator;
	list <int, allocator> l;
	for (int i = 0; i < 1000; ++i)
		l.push_back(i);
	l.clear();
	boost::singleton_pool<boost::fast_pool_allocator_tag, sizeof(int)>::purge_memory();
	return 0;
}
