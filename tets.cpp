#include "Vector.hpp"
#include <iostream>
int 	main()
{
	ft::Vector<int>  a(4,55);
	ft::Vector<int>::iterator it;
	it = a.begin();
	std::cout << a.end() - a.begin() << std::endl;
}
