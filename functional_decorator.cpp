#include <functional>
#include <iostream>

namespace Decorator
{
#if __cpp_lib_invoke
	template<typename Function>
	static auto make(Function&& func)
	{
		return [func = std::forward<Function>(func)](auto&&... args)
		{
			return std::invoke(func, std::forward<decltype(args)>(args)...);
		};
	}
#endif
}

struct MyClass
{
	static void func(int a, int b) 
	{
		std::cout << "MyClass::func" << a << " " << b << std::endl;
	}
};

void myFunc(int a, int b)
{
	std::cout << "myFunc" << a << " " << b << std::endl;
}

int main()
{
	std::function<void(int, int)> f = myFunc;
	auto decorated_1 = Decorator::make(myFunc);
	decorated_1(1, 2);

	auto myLambda = [](int a, int b, int g)
	{
		std::cout << a << " " << b << g << std::endl;
	};
	auto decorated_2 = Decorator::make(myLambda);
	decorated_2(3, 4, 8);

	void (*ptr)(int, int) = myFunc;
	auto decorated_3 = Decorator::make(ptr);
	decorated_3(5, 6);

	std::function<void(int, int)> fun = myFunc;
	auto decorated_4 = Decorator::make(fun);
	decorated_4(7, 8);

	auto decorated_5 = Decorator::make(decorated_4);
	decorated_5(9, 10);

	auto decorated_6 = Decorator::make(&MyClass::func);
	decorated_6(11, 12);

	return 0;
}
