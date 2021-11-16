/* ************************************************************************************************ */
/*                                                                                                  */
/*                                                        :::   ::::::::   ::::::::  :::::::::::    */
/*   Vector_test.cpp                                   :+:+:  :+:    :+: :+:    :+: :+:     :+:     */
/*                                                      +:+         +:+        +:+        +:+       */
/*   By: mamoussa <mamoussa@student.1337.ma>           +#+      +#++:      +#++:        +#+         */
/*                                                    +#+         +#+        +#+      +#+           */
/*   Created: 2021/07/10 19:43:45 by mamoussa        #+#  #+#    #+# #+#    #+#     #+#             */
/*   Updated: 2021/09/23 12:57:39 by moboustt         ###   ########.fr       */
/*                                                                                                  */
/* ************************************************************************************************ */

#include <vector>
# include <iostream>
# include <iterator>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
# include "Vector.hpp"
# include "Stack.hpp"


#include <vector>
#include <stack>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"


#if MY
#define V_NAME ft::Vector
#define SWP ft::swap
#else
#define  V_NAME std::vector
#define SWP std::swap
#endif


#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 3 // the ft::Map methods can be slower up to std::map methods * TIME_FAC (MAX 20)

bool mypredicate (int i, int j)
	{return (i==j);}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }


void print_vector(V_NAME<int>::iterator ft_it_b, V_NAME<int>::iterator ft_it_e)
{
	std::cout << "ft  :: ";
	for(; ft_it_b != ft_it_e ; ++ft_it_b)
	 {
		std:: cout << *ft_it_b << " ";
	 }
	std::cout << std::endl;
}

int main()
{


	V_NAME<int>vctr;
	for (size_t i = 1; i <= 20; i++)
	{
		vctr.push_back(i * 10);
	}
	V_NAME<int>::reverse_iterator rev(vctr.rbegin());
	std:: cout << " * " << *rev << std::endl;
	std:: cout << " 0 " << rev[0] << std::endl;
	std:: cout << " 1 " << rev[1] << std::endl;
	std:: cout << " 2 " << rev[2] << std::endl;
	std:: cout << " 3 " << rev[3] << std::endl;
	//return 0;

	clock_t start = clock();
    	std::cout << "	======================>\033[1;31m init and iterators tests \033[0m<============================ " << std::endl;
	// Creating vects of diffrent types

	V_NAME<int> ft_vect_int; // call default constructor 
	V_NAME<int> vect_1(1e6, 5); // call fill constructor
	V_NAME<char> ft_vect_char(1e6, 'a');
	V_NAME<float> ft_vect_float;V_NAME<int>::iterator ft_it;
	V_NAME<char>::iterator ft_it_char(ft_vect_char.begin());
	V_NAME<int>::const_iterator ft_itc(vect_1.end());

	(void)ft_it_char;
	// std_it = ft_itc;
	ft_itc = ft_it;

	// *ft_itc = 8;
	// *std_itc = 8;

	std::cout << (ft_itc == ft_it) << std::endl;
	std::cout << (ft_itc != ft_it) << std::endl << std::endl;

	for(int i = 0; i < 10; ++i)
		ft_vect_int.push_back(i);
	V_NAME<int> ft_vect_int1(ft_vect_int.begin(), ft_vect_int.end()); // call range constructor 

	ft_it = ft_vect_int1.begin();
	for(ft_it = ft_vect_int1.begin(); ft_it != ft_vect_int1.end(); ++ft_it)
		std::cout << *ft_it << std::endl;


	std::cout << "	======================>\033[1;31m member functions tests \033[0m<============================ " << std::endl;

	std::cout << ft_vect_int.max_size() << std::endl;

	V_NAME<int> ft_vect_int2; 
	for(int i = 0; i < 100; i += 20)
		ft_vect_int2.push_back(i);
	std::cout << "Capacity: " << ft_vect_int2.capacity() << std::endl;
	
	print_vector(ft_vect_int2.begin(), ft_vect_int2.end());

	ft_vect_int2.reserve(50);

	std::cout << "Capacity: " << ft_vect_int2.capacity() << std::endl;
	
	print_vector(ft_vect_int2.begin(), ft_vect_int2.end());
	try
	{
	// ft_vect_int2.reserve(4611686018427387999);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//checked--------------------
	std::cout << "Capacity:  " << ft_vect_int2.capacity() << std::endl;

	ft_vect_int1[8] = 19;
	std::cout << ft_vect_int1[8] << std::endl;
	
	ft_vect_int1[0] = 100;
	std::cout << ft_vect_int1.back() << std::endl;

	V_NAME<int> ft_new(25, 0);
	
	std::cout << "vect 2 Capacity : " << ft_vect_int2.capacity() << std::endl;

	ft_new.assign(ft_vect_int2.begin(), ft_vect_int2.end());

	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;
	//checked--------------------

	print_vector(ft_new.begin(), ft_new.end());

	ft_new.assign(10, 0);

	print_vector(ft_new.begin(), ft_new.end());
	
	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;
	
	ft_new.assign(20, 1);
	
	print_vector(ft_new.begin(), ft_new.end());
	
	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;

	V_NAME<int> ft_new1(10, 0);

	// ft_new1.reserve(100);
	for (int i = 0; i < 2; ++i)
		ft_new1.push_back(i);
	print_vector(ft_new1.begin(), ft_new1.end());
	std::cout << "Capacity:  : " << ft_new1.capacity() << std::endl;
	std::cout << "Size: " << ft_new1.size() << std::endl;

	//checked---------------------------
	V_NAME<int> ft_new2;
	std::cout << std::endl;
	// ft_new2.reserve(1);
	V_NAME<int>::iterator ft_it2(ft_new2.begin());
	
	// ft_new2.push_back(50);
	// ft_it2 = ft_new2.begin();
	// ft_it2++;
	// std::cout << *ft_it2 << std::endl;

	ft_new2.insert(ft_it2, 900);
	ft_it2++;
	std::cout << std::endl;
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 100);
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 10);
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 20);
	// ft_it2--;
	ft_it2 = ft_new2.end();
	// std_it2++;
	// ft_it2++;
	std::cout << *(ft_new2.insert(ft_it2, 800))<< std::endl;
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout << "ft capacity : " << ft_new2.capacity() << std::endl;
	std::cout << "ft size :" << ft_new2.size() << std::endl << std::endl;
	//checked---------------------------------------------

	print_vector(ft_new2.begin(), ft_new2.end());
	ft_it2 = ft_new2.begin();
	// ft_it2--;

	ft_new2.insert(ft_it2, 1, 55);
	std::cout << "check done  : " << ft_new2.size() << "    " << ft_new2.capacity() << std::endl;
    print_vector(ft_new2.begin(), ft_new2.end());
	ft_it2 = ft_new2.begin();
	ft_it2++;
	ft_new2.insert(ft_it2, 190);
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout << "ft capacity :  " << ft_new2.capacity() << std::endl;
	std::cout << "ft size :      " << ft_new2.size() << std::endl << std::endl;
	

	V_NAME<int> ft_new3(1, 0);
	ft_new3.reserve(10);
	ft_new3.push_back(10);
	ft_new3.push_back(20);
	ft_new3.push_back(30);
	ft_new3.push_back(40);
	std::cout << "new 3 ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "new 3 ft size :" << ft_new3.size() << std::endl << std::endl;
	std::cout << "insert  :" << ft_new2.end() - ft_new2.begin()<< std::endl << std::endl;
	ft_new3.insert(ft_new3.begin(), ft_new2.begin(), ft_new2.end());
	//checked---------------------------------------------


	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "new 3 ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "new 3 ft size :" << ft_new3.size() << std::endl << std::endl;

	// return 22;
	std::cout << *(ft_new3.erase(ft_new3.end()  - 3)) << std::endl;
	std::cout << *(ft_new3.erase(ft_new3.begin() + 3, ft_new3.end())) << std::endl;

	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl << std::endl;

	std::cout << "iter " << ft_new3.end() - ft_new3.begin() << std::endl;

	V_NAME<int> ft_new4(20, 0);
	ft_new4 = ft_new3;
	std::cout << "print new4" << std::endl << std::endl;
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;

	ft_new3.push_back(3333);
	ft_new3.push_back(20);
	ft_new3.push_back(30);
	ft_new3.push_back(3333);
	ft_new3.swap(ft_new4);
	std::cout << std::endl;
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;
	std::cout << "print new3" << std::endl << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl;

	ft_new4.clear();
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;
	
	std::cout << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	print_vector(ft_new2.begin(), ft_new2.end());
	// ft::swap(ft_new3, ft_new2);
		SWP(ft_new3, ft_new3);
	std::cout << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout <<  "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;
	ft_new3.resize(12, 10);
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout <<  "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;
	ft_new3.resize(13, 6);
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;

std::cout << "	======================>\033[1;31m Non-member functions tests \033[0m<============================ " << std::endl << std::endl;
	V_NAME<int> foo (3,200);
	V_NAME<int> bar (3,300);

	if (foo == bar)
		std::cout << "equal\n";
	if (foo != bar)
		std::cout << "not equal \n";
	if (foo < bar)
		std::cout << "foo is less than bar" << std::endl;
	if (foo <= bar)
		std::cout << "foo is less than or equal bar" << std::endl;
	if (bar > foo)
		std::cout << "bar is greater than foo" << std::endl;
	if (foo >= bar)
		std::cout << "foo is greater than or equal bar" << std::endl;

	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	V_NAME<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	// using default comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n"<< std::endl;
  char foo1[]="Apple";
  char bar1[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo1 and bar1 lexicographically (foo1<bar1):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << ft::lexicographical_compare(foo1,foo1+5,bar1,bar1+9);
  std::cout << '\n';

  std::cout << "Using mycomp as comparison object: ";
  std::cout << ft::lexicographical_compare(foo1,foo1+5,bar1,bar1+9,mycomp);
  std::cout << std::endl;

std::cout << "	======================>\033[1;31m iteartors && rev_iterators arithmetic operations tests \033[0m<============================ " << std::endl << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft::size  :" <<ft_new3.size() << " ft::capacity  :" << ft_new3.capacity() << std::endl<< std::endl;

	V_NAME<int>::iterator ft_it3(ft_new3.begin());
	V_NAME<int>::const_iterator ft_it30(ft_new3.begin());
	if (ft_it30 == ft_it3)
		std::cout << "equal \n";

	std::cout << *(4 + ft_it3) << std::endl;
	std::cout << *ft_it3++ << std::endl;
	std::cout << *(ft_it3 + 2) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	std::cout << *(ft_it3 += 1) << std::endl;	
	std::cout << *ft_it3 << std::endl;

	
	std::cout << std::endl;
	ft_it3 = ft_new3.end();
	--ft_it3;
	ft_it3--;
	std::cout << *ft_it3-- << std::endl;
	std::cout << *(ft_it3 - 6) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	std::cout << *(ft_it3 -= 9) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	ft_it3 = ft_new3.begin();
	std::cout << (ft_new3.end() - ft_it3) << std::endl;
	
	std::cout << std::endl;
	std::cout << (ft_it3 < ft_new3.end()) << std::endl;
	std::cout << (ft_it3 > ft_new3.end()) << std::endl;
	std::cout << (ft_it3 <= ft_new3.end()) << std::endl;
	std::cout << (ft_it3 >= ft_new3.end()) << std::endl;
	std::cout << *(ft_it3.base()) << std::endl;
	std::cout << ft_it3[4] << std::endl;


	std::cout << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	V_NAME<int>::reverse_iterator ft_rit3(ft_new3.end() - 1);
	V_NAME<int>::const_reverse_iterator ft_crit13(ft_new3.rend());
	if (ft_crit13 == ft_new3.rend())
		std::cout << "equal \n";
	std::cout << *ft_rit3 << std::endl;
	ft_rit3 = ft_new3.rbegin();
	std::cout << *ft_rit3 << std::endl;	
	std::cout << *(ft_rit3 + 8) << std::endl;
	++ft_rit3;
	ft_rit3++;
	std::cout << *ft_rit3 << std::endl;
	ft_rit3 += 5;
	std::cout << *ft_rit3 << std::endl;
	std::cout << *(ft_rit3 - 1) << std::endl;	
	std::cout << *ft_rit3-- << std::endl;
	std::cout << *--ft_rit3 << std::endl;
	std::cout << *ft_rit3 << std::endl;
	std::cout << *(ft_rit3 -= 5) << std::endl;

	std::cout << std::endl;
	ft_new3[3] = 33;
	ft_new3[4] = 44;
	ft_new3[2] = 22;

	ft_rit3 = ft_new3.rend();
	++ft_rit3;
	std::cout <<  "3 " << ft_rit3[3] << std::endl;
	std::cout <<  "0 " << ft_rit3[0] << std::endl;
	std::cout <<  "* " << *ft_rit3 << std::endl;

	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "chek this line \n";	
	std::cout << *(ft_new3.rend() - 2) << std::endl;
	V_NAME<int>::const_reverse_iterator ft_crit3(ft_new3.end() - 1);

	std::cout << *ft_crit3 << std::endl;

	// *ft_crit3 = 8; // compilation error 

	std::cout << std::endl;
	std::cout << (ft_rit3 < ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 <= ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 > ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 >= ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 != ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 == ft_new3.rend()) << std::endl;

	ft_rit3 = ft_new3.rbegin();
	std::cout << *(8 + ft_rit3) << std::endl;

	std::cout << ft_new3.rbegin() - ft_new3.rend() << std::endl;



	std::cout << "	======================>\033[1;31m STACK tests \033[0m<============================ " << std::endl << std::endl;

	ft::Stack<int> st;
	ft::Stack<int> st2(st);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);

	for(size_t i = 0; i < st.size(); ++i)
	{
		std::cout << st.top() << std::endl;
	}

	std::cout << st2.empty() << std::endl;

	st.pop();
	st.pop();
	st.pop();
	
	st.push(200);
	st.push(300);
	st.push(400);

	for(size_t i = 0; i < st.size(); ++i)
		std::cout << st.top()<< std::endl;

	std::cout << std::endl;

	std::cout << (st2 == st) << std::endl;

	std::cout << (st2 != st) << std::endl;

	std::cout << (st2 > st) << std::endl;
	std::cout << (st2 >= st) << std::endl;
	std::cout << (st2 < st) << std::endl;
	std::cout << (st2 <= st) << std::endl;

	std::cout << (st > st2) << std::endl;
	std::cout << (st >= st2) << std::endl;
	std::cout << (st < st2) << std::endl;
	std::cout << (st <= st2) << std::endl;
    std::cout << "done \n" << std::endl;
}
