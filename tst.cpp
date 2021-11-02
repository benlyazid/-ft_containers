
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
	{

		std::vector<int>std_vector(10, 0);
		for (size_t i = 0; i < 10; i++)
		{
			std_vector[i] = i + 1;
		}
		ft::Vector<int> v(4,5);
		std::vector<int>::reverse_iterator my_rit1(std_vector.begin()), my_rit2(std_vector.end());
		std::cout << *my_rit1.base() << "     " << *my_rit2.base() << std::endl;
		std::cout << *my_rit1 << "     " << *my_rit2 << std::endl;

		std::cout << "**************************************" << std::endl;
		my_rit1--;
		my_rit2++;
		std::cout << *my_rit1.base() << "     " << *my_rit2.base() << std::endl;
		std::cout << *my_rit1 << "     " << *my_rit2 << std::endl;
		
		std::cout << "**************************************" << std::endl;
		my_rit1--;
		my_rit2++;
		std::cout << *my_rit1.base() << "     " << *my_rit2.base() << std::endl;
		std::cout << *my_rit1 << "     " << *my_rit2 << std::endl;
		//std::cout << *std_vector.begin() << "     " << *std_vector.end() << std::endl;



	}
}