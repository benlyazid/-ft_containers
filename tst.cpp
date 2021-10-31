
//#include "Vector.hpp"
#include <vector>
# include <iostream>
# include <iterator>
# include <type_traits>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
#include "utils.hpp"
// using namespace ft;

# define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
class class_a
{
	public:
		bool class_a_value;
		class_a(){}
		~class_a(){}
};

template<bool B, class T = void>
struct enable_if{};

template<class T>
struct enable_if<true, T> { typedef T type;};

/*
##############################################################
*/
template<class T, class U=void>
struct is_class_a
{
	static const bool value = false;
};

template<class T>
struct is_class_a<class_a, T>
{
	static const bool value = true;
};

int main()
{
	class_a c_a;
	// class_b c_b;
	// what_is(c_a);
	// what_is(c_b);
	int var = 8;
	std::cout << ft::is_integral<int>::value << std::endl;
	std::cout <<  is_class_a<class_a>::value << std::endl;

}