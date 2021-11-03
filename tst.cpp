
#include "Vector.hpp"
#include <vector>
# include <iostream>
# include <iterator>
# include <type_traits>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
// #include "utils.hpp"
using namespace ft;

# define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

class class_a
{
	protected:
		bool class_a_value;
	public:
		class_a(){this->class_a_value = true;}
		~class_a(){}

};

class class_b : public class_a
{
	public:
		bool class_b_value;
		class_b(){ class_a_value = false;}
		~class_b(){}
};

/*
##############################################################
*/
int main()
{
	ft::Vector<int>my_vector(10,0);
	// std::vector<int>::reverse_iterator:
	}