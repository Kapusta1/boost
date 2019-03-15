#include <boost/scope_exit.hpp>
#include <utility>
#include <iostream>
/*
int *foo()
{
	int *i = new int{ 10 };
	BOOST_SCOPE_EXIT(&i)
	{
		delete i;
		i = 0;
	}BOOST_SCOPE_EXIT_END
		std::cout << *i << '\n';
	return i;
}

int main()
{
	int *j = foo();
	std::cout << j << '/n';
	return 0;
}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
template <typename T>
struct scope_exit
{
	scope_exit(T&&t):t_{std::move(t)}{}
	~scope_exit() { t_(); }
	T t_;
};
template <typename T>
scope_exit<T> make_scope_exit(T&&t)
{
	return scope_exit<T>{std::move(t)};
}
int *foo()
{
	int *i = new int{ 10 };
	auto cleanup = make_scope_exit([&i]() mutable { delete i; i = 0; });
	std::cout << *i << '\n';
	return i;
}
int main()
{
	int *j = foo();
	std::cout << j << '\n';
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
struct x
{
	int i;
	void foo()
	{
		i = 10;
		BOOST_SCOPE_EXIT(void)
		{
			std::cout << "last\n";
		}BOOST_SCOPE_EXIT_END
			BOOST_SCOPE_EXIT(this_)
		{
			this_->i = 20;
			std::cout << "first\n";
		}BOOST_SCOPE_EXIT_END
	}
};
int main()
{
	x obj;
	obj.foo();
	std::cout << obj.i << '\n';
	return 0;
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <memory>
#include <cstdio>

struct CloseFile
{
	void operator()(std::FILE *file)
	{
		std::fclose(file);
	}
};

void write_to_file(const std::string &s)
{
	FILE *f;
	std::cout << "open file" << '\n';
	fopen_s(&f, "hello-world.txt", "a");
	BOOST_SCOPE_EXIT(&f)
	{
		if (std::fclose(f) == 0)
			std::cout << "close file" << '\n';
	}BOOST_SCOPE_EXIT_END
//	std::unique_ptr<std::FILE, CloseFile> file{f };
	fputs(const_cast<char*>(s.c_str()), f);
	std::cout << "write file" << '\n';
	//std::fprintf(file.get(), s.c_str());
}

int main()
{
	write_to_file("Hello, ");
	write_to_file("world!");
}