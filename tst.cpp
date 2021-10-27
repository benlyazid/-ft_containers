
#include "Vector.hpp"
#include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
using namespace ft;

# define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))


int main()
{
	{
		ft::Vector<int>::iterator my_it,my_it1, tmp;
		ft::Vector<int>::const_iterator c_it, c_ob(my_it);
		c_it = c_ob;
		//my_it = my_it1;
		EQUAL((&(*c_ob) == &(*my_it)));
		//EQUAL((&(*my_it1) == &(*my_it)));
	}

	std::cout << "########################################\n";
	{
		std::vector<int>::iterator my_it,my_it1, tmp;
		std::vector<int>::const_iterator c_it, c_ob(my_it);
		std::vector<int> vec(10, 100);
		c_it =  vec.cbegin();
		c_ob = vec.cbegin();
		//my_it = my_it1;
		EQUAL((&(*c_ob) == &(*c_it)));
		//EQUAL((&(*my_it1) == &(*my_it)));
	}
}