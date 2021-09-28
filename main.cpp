// Test1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <functional>


/*


аСИНК fun(listener - В КОНЦЕ РАБОТЫ - ЛИСТЕНЕР МЕТОД ВЫЗЫВАЕТ КОТОРЫЙ МОЖНО ЕМУ УСТАНОВИТЬ) {

	ВЫЗОВ КОЛБЕКА
}*/

struct A {
private:
	std::function<void(int)> func;
public:
	template<class T>
	void set_fun(T ff) {
		func = ff;
	}

	void operator() (int i) {
		func(i);
	}
};

void async_fun(A& a, int i) {
	std::cout << "working" << std::endl;
	a(i);
}

int main()
{
	A a;
	a.set_fun([](int i) {std::cout << i << std::endl; });
	async_fun(a, 10);
	//a.set_fun([](int) {std::cout << "2" << std::endl; });
	async_fun(a, 11);
}
