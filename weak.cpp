#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <atlbase.h>
#include <thread>
#include <functional>
#include <iostream>

using std::cout;
using std::endl;
using boost::shared_ptr;
using boost::weak_ptr;
/////////////////////////////////////////////////////////////////////////////////////////////////
/*
void reset(shared_ptr<int>&sh)
{
	sh.reset();
}
void print(weak_ptr<int> &w)
{
	shared_ptr<int> sh = w.lock();
	if (sh)
		cout << *sh << '\n';
}

int main()
{
	shared_ptr<int> sh{ new int{99} };
	weak_ptr<int> w{ sh };
	std::thread t1{ reset, std::ref(sh) };
	std::thread t2{ print, std::ref(w) };
	t1.join();
	t2.join();
	return 0;
}
*/
///////////////////////////////////////////////////////////////////////////////////////////////////

void intrusive_ptr_add_ref(IDispatch *p) { p->AddRef(); }
void intrusive_ptr_release(IDispatch *p) { p->Release(); }
void check_windows_folder()
{
	CLSID clsid;
	CLSIDFromProgID(CComBSTR{ "Scripting.FileSystemObject" }, &clsid);
	void *p;
	CoCreateInstance(clsid, 0, CLSCTX_INPROC_SERVER, __uuidof(IDispatch), &p);
	boost::intrusive_ptr<IDispatch> disp{ static_cast<IDispatch*>(p), false };
	boost::intrusive_ptr<IDispatch> ddd{ static_cast<IDispatch*>(p), false };
	CComDispatchDriver dd{ disp.get() };
	CComVariant arg{ "C:\\Windows" };
	CComVariant ret{ false };
	dd.Invoke1(CComBSTR{ "FolderExists" }, &arg, &ret);
	cout << std::boolalpha << (ret.boolVal != 0) << '\n';
}

int main()
{
	CoInitialize(0);
	check_windows_folder();
	CoUninitialize();
}