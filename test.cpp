#include "inspect"

class foo
{};

class bar
{
	public:
		std::string
		inspect (void)
		{
			return "#<bar: dabbah>";
		}

		std::string
		to_string (void)
		{
			return "fo real";
		}
};

class wat
{
	public:
		std::string
		to_string (void)
		{
			return "I like trains";
		}
};

union omg
{};

enum class derp
{
	lol, wut, omg
};

std::ostream& operator << (std::ostream& on, derp v)
{
	switch (v) {
		case derp::lol:
			on << "lol";
			break;

		case derp::wut:
			on << "wut";
			break;

		case derp::omg:
			on << "omg";
			break;
	}

	return on;
}

void
func (float a)
{
	(void) a;
}

int
main (int argc, char* argv[])
{
	std::string str = "34";
	std::cout << inspect::value(str) << std::endl;

	foo a;
	std::cout << inspect::value(a) << std::endl;

	bar b;
	std::cout << inspect::value(b) << std::endl;

	wat c;
	std::cout << inspect::value(c) << std::endl;

	omg d;
	std::cout << inspect::value(d) << std::endl;

	std::cout << inspect::value(23) << std::endl;
	std::cout << inspect::value(derp::omg) << std::endl;
	std::cout << inspect::value(1.04719755) << std::endl;

	int lol[][2] = { { 1, 2 }, { 3, 4 } };
	std::cout << inspect::value(lol) << std::endl;

	float* duh = (float*) 342;
	std::cout << inspect::value(duh) << std::endl;

	std::cout << inspect::value("\tlol\n\x01\"ß") << std::endl;
	std::wcout << inspect::value(L"\tlol\n\x01\"ß") << std::endl;

	std::cout << inspect::value(true) << std::endl;

#	ifndef _MSC_VER
		std::function<void(int)> f = [](int a) { (void) a; };
		std::cout << inspect::value(f) << std::endl;

		std::cout << inspect::value(func) << std::endl;

		std::cout << inspect::value(&bar::inspect) << std::endl;

		auto l = []{};
		std::cout << inspect::value(l) << std::endl;
#	endif

	return 0;
}

