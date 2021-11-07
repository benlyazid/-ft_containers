
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

# define TIME_FAC 3 

# define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return(msecs_time);
}


void    iterator_tests(void)
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Vector iterator tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    /*------------ std::vector ---------*/
    std::vector<int> v(3,4);
    std::vector<int>::iterator it,it1;
    it = v.begin();
    it1 = v.begin() + 1;
    /*----------------------------------*/
    /*------------ ft::Vector ---------*/
    ft::Vector<int>    my_v(3,4);
    ft::Vector<int>::iterator my_it,my_it1, tmp;
    my_it = my_v.begin();
    my_it1 = my_v.begin() + 1;
    /*----------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor " << "] --------------------]\t\t\033[0m";
    {
        ft::Vector<int>::iterator ob(my_it);
        EQUAL(&(*my_it) == &(*ob));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " iterator to const_iterator " << "] --------------------]\t\t\033[0m";
    {
        ft::Vector<int>::const_iterator c_it, c_ob(my_it);
        c_it = my_it;
        EQUAL(&(*my_it) == &(*c_it) && (&(*my_it) == &(*c_ob)));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it == it1) == (my_it == my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it != it1) == (my_it != my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " > operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it > it1) == (my_it > my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " >= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it >= it1) == (my_it >= my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " < operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it < it1) == (my_it < my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " <= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it <= it1) == (my_it <= my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator " << "] --------------------]\t\t\033[0m";
    EQUAL(((*my_it = 6) == 6) && (*my_it == *(my_v.begin())));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator " << "] --------------------]\t\t\033[0m";
    {
        /*--------------- std::vector-------------------- */
        std::vector<std::string>    v(3, "hello");
        std::vector<std::string>::iterator it = v.begin();
        /*---------------------------------------------- */
        /*--------------- ft::vector-------------------- */
        ft::Vector<std::string>    my_v(3, "hello");
        ft::Vector<std::string>::iterator my_it = my_v.begin();
        /*---------------------------------------------- */
        EQUAL(it->length() == my_it->length());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator " << "] --------------------]\t\t\033[0m";
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " += operator " << "] --------------------]\t\t\033[0m";
	my_it += 1;
	EQUAL(&(*my_it) == &(*my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -= operator " << "] --------------------]\t\t\033[0m";
	my_it -= 1;
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " [] operator " << "] --------------------]\t\t\033[0m";
	EQUAL(((my_it[0] = 5) == 5) && (*my_it == 5));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator " << "] --------------------]\t\t\033[0m";
    ++my_it; // I incremented here to make sure that the object changes
	EQUAL(&(*my_it) == &(*my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator " << "] --------------------]\t\t\033[0m";
    --my_it; // I decremented here to make sure that the object changes
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator (n + it) " << "] --------------------]\t\t\033[0m";
	EQUAL(&(*(1 + my_it)) == &(*(my_it1)) && (&(*my_it) == &(*(my_v.begin()))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator (it1 - it) " << "] --------------------]\t\t\033[0m";
	EQUAL(((my_it1 - my_it == 1)) && ((my_it - my_it1) == -1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator " << "] --------------------]\t\t\033[0m";
    tmp = my_it++;
    EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*my_it1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator " << "] --------------------]\t\t\033[0m";
    tmp = my_it--;
	EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*(my_v.begin()))));
    std::cout << "\033[1;36m\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
}


void    const_iterator_tests(void)
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Vector const_iterator tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    /*------------ std::vector ---------*/
    std::vector<int> v(3,4);
    std::vector<int>::const_iterator it,it1;
    it = v.begin();
    it1 = v.begin() + 1;
    /*----------------------------------*/
    /*------------ ft::Vector ---------*/
    ft::Vector<int>    my_v(3,4);
    ft::Vector<int>::const_iterator my_it,my_it1, tmp;
    my_it = my_v.begin();
    my_it1 = my_v.begin() + 1;
    /*----------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor " << "] --------------------]\t\t\033[0m";
    {
        ft::Vector<int>::const_iterator ob(my_it);
        EQUAL(&(*my_it) == &(*ob));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it == it1) == (my_it == my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it != it1) == (my_it != my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " > operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it > it1) == (my_it > my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " >= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it >= it1) == (my_it >= my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " < operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it < it1) == (my_it < my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " <= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((it <= it1) == (my_it <= my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator " << "] --------------------]\t\t\033[0m";
    EQUAL(*my_it == *(my_v.begin()) && (&(*my_it) == &(*(my_v.begin()))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator " << "] --------------------]\t\t\033[0m";
    {
        /*--------------- std::vector-------------------- */
        std::vector<std::string>    v(3, "hello");
        std::vector<std::string>::const_iterator it = v.begin();
        /*---------------------------------------------- */
        /*--------------- ft::vector-------------------- */
        ft::Vector<std::string>    my_v(3, "hello");
        ft::Vector<std::string>::const_iterator my_it = my_v.begin();
        /*---------------------------------------------- */
        EQUAL(it->length() == my_it->length());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator " << "] --------------------]\t\t\033[0m";
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " += operator " << "] --------------------]\t\t\033[0m";
	my_it += 1;
	EQUAL(&(*my_it) == &(*my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -= operator " << "] --------------------]\t\t\033[0m";
	my_it -= 1;
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " [] operator " << "] --------------------]\t\t\033[0m";
	EQUAL((my_it[0] == *(my_v.begin())) && (&(my_it[0]) == &(*(my_v.begin()))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++it operator " << "] --------------------]\t\t\033[0m";
    ++my_it; // I incremented here to make sure that the object changes
	EQUAL(&(*my_it) == &(*my_it1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --it operator " << "] --------------------]\t\t\033[0m";
    --my_it; // I decremented here to make sure that the object changes
	EQUAL(&(*my_it) == &(*(my_it1 - 1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator (n + it) " << "] --------------------]\t\t\033[0m";
	EQUAL(&(*(1 + my_it)) == &(*(my_it1)) && (&(*my_it) == &(*(my_v.begin()))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator (it1 - it) " << "] --------------------]\t\t\033[0m";
	EQUAL(((my_it1 - my_it == 1)) && ((my_it - my_it1) == -1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it++ operator " << "] --------------------]\t\t\033[0m";
    tmp = my_it++;
    EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*my_it1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " it-- operator " << "] --------------------]\t\t\033[0m";
    tmp = my_it--;
	EQUAL(&(*my_it) != &(*tmp) && (&(*my_it) == &(*(my_v.begin()))));
    std::cout << "\033[1;36m\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
}


void    reverse_iterator_tests(void)
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< reverse_iterator tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    /*------------ std::reverse_iterator ---------*/
    std::vector<int> v(3,4);
    std::reverse_iterator<std::vector<int>::iterator> rit(v.end()), rit_1(v.end() - 1);
    /*----------------------------------*/
    /*------------ ft::reverse_iterator ---------*/
    ft::reverse_iterator<std::vector<int>::iterator> my_rit(v.end()), my_rit1(v.end() - 1);
    /*----------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor " << "] --------------------]\t\t\033[0m";
    {
        ft::reverse_iterator<std::vector<int>::iterator> ob(my_rit);
        EQUAL(&(*my_rit) == &(*ob));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " riterator to const_riterator " << "] --------------------]\t\t\033[0m";
    {
		ft::Vector<int> v(4,5);
		ft::Vector<int>::reverse_iterator 		my_rit2(v.end());
        ft::Vector<int>::const_reverse_iterator c_it, c_ob(v.end());
        c_it = my_rit2;
        EQUAL(&(*my_rit2) == &(*c_it) && (&(*my_rit2) == &(*c_ob)));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " base function " << "] --------------------]\t\t\033[0m";
    EQUAL((&(*rit) == &(*rit_1.base())) && (&(*my_rit) == &(*my_rit1.base())));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit == rit_1) == (my_rit == my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit != rit_1) == (my_rit != my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " > operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit > rit_1) == (my_rit > my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " >= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit >= rit_1) == (my_rit >= my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " < operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit < rit_1) == (my_rit < my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " <= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit <= rit_1) == (my_rit <= my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator " << "] --------------------]\t\t\033[0m";
    EQUAL(((*my_rit == *(v.end() - 1)) && (&(*my_rit) == &(*(v.end() - 1))))
    && ((*rit == *(v.end() - 1)) && (&(*rit) == &(*(v.end() - 1)))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator " << "] --------------------]\t\t\033[0m";
    {
        std::vector<std::string> v(3, "hello");
        std::reverse_iterator<std::vector<std::string>::iterator> rit(v.end());
        ft::reverse_iterator<std::vector<std::string>::iterator> my_rit(v.end());
        EQUAL(rit->length() == my_rit->length());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*(my_rit + 1)) == &(*my_rit1)) && (&(*(rit + 1)) == &(*rit_1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " += operator " << "] --------------------]\t\t\033[0m";
	my_rit += 1;
	rit += 1;
	EQUAL((&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -= operator " << "] --------------------]\t\t\033[0m";
	my_rit -= 1;
	rit -= 1;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " [] operator " << "] --------------------]\t\t\033[0m";
	EQUAL(((my_rit[0] = 5) == 5) && (rit[0] == 5));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++rit operator " << "] --------------------]\t\t\033[0m";
    ++my_rit; // I incremented here to make sure that the object changes
    ++rit;
	EQUAL(&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --rit operator " << "] --------------------]\t\t\033[0m";
    --my_rit; // I incremented here to make sure that the object changes
    --rit;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator (n + rit) " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*(2 + my_rit)) == &(*(1 + my_rit1))) && (&(*(2 + rit)) == &(*(1 + rit_1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator (rit1 - rit) " << "] --------------------]\t\t\033[0m";
    EQUAL(((my_rit - my_rit1) == (rit - rit_1)) && ((my_rit1 - my_rit) == (rit_1 - rit)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit++ operator " << "] --------------------]\t\t\033[0m";
    {
        std::reverse_iterator<std::vector<int>::iterator>   tmp(rit++);
        ft::reverse_iterator<std::vector<int>::iterator>    my_tmp(my_rit++);
        EQUAL((&(*tmp) == &(*(--rit))) && (&(*my_tmp) == &(*(--my_rit))));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit-- operator " << "] --------------------]\t\t\033[0m";
    {
        std::reverse_iterator<std::vector<int>::iterator>   tmp(rit--);
        ft::reverse_iterator<std::vector<int>::iterator>    my_tmp(my_rit--);
        EQUAL((&(*tmp) == &(*(++rit))) && (&(*my_tmp) == &(*(++my_rit))));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " *rit++ test " << "] --------------------]\t\t\033[0m";
    {
        std::vector<char> v(10);
        std::string res, my_res;
        std::reverse_iterator<std::vector<char>::iterator> start(v.end()), end(v.begin());
        ft::reverse_iterator<std::vector<char>::iterator> my_start(v.end()), my_end(v.begin());

        for(size_t i = 0; i < 10; ++i)
            v[i] = '0' + i;
        while (start != end)
            res.push_back(*start++);
        while (my_start != my_end)
            my_res.push_back(*my_start++);
        EQUAL(res == my_res);
    }
    std::cout << "\033[1;36m\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
}

void    reverse_iterator_with_ft_vector(void)
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< reverse_iterator with ft::vector >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    /*------------ std::reverse_iterator ---------*/
    std::vector<int> v(3,4);
    std::vector<int>::reverse_iterator rit(v.end()), rit_1(v.end() - 1);
    /*----------------------------------*/
    /*------------ ft::reverse_iterator ---------*/
    ft::Vector<int> my_v(3,4);
    ft::Vector<int>::reverse_iterator my_rit(my_v.end()), my_rit1(my_v.end() - 1);
    /*----------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor " << "] --------------------]\t\t\033[0m";
    {
        ft::Vector<int>::reverse_iterator ob(my_rit);
        EQUAL(&(*my_rit) == &(*ob));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " base function " << "] --------------------]\t\t\033[0m";
    EQUAL((&(*rit) == &(*rit_1.base())) && (&(*my_rit) == &(*my_rit1.base())));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " == operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit == rit_1) == (my_rit == my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " != operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit != rit_1) == (my_rit != my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " > operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit > rit_1) == (my_rit > my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " >= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit >= rit_1) == (my_rit >= my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " < operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit < rit_1) == (my_rit < my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " <= operator " << "] --------------------]\t\t\033[0m";
    EQUAL((rit <= rit_1) == (my_rit <= my_rit1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " * operator " << "] --------------------]\t\t\033[0m";
    EQUAL(((*my_rit == *(my_v.end() - 1)) && (&(*my_rit) == &(*(my_v.end() - 1))))
    && ((*rit == *(v.end() - 1)) && (&(*rit) == &(*(v.end() - 1)))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -> operator " << "] --------------------]\t\t\033[0m";
    {
        std::vector<std::string> v(3, "hello");
        ft::Vector<std::string> my_v(3, "hello");
        std::vector<std::string>::reverse_iterator rit(v.end());
        ft::Vector<std::string>::reverse_iterator   my_rit(my_v.end());
        EQUAL(rit->length() == my_rit->length());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*(my_rit + 1)) == &(*my_rit1)) && (&(*(rit + 1)) == &(*rit_1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " += operator " << "] --------------------]\t\t\033[0m";
	my_rit += 1;
	rit += 1;
	EQUAL((&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " -= operator " << "] --------------------]\t\t\033[0m";
	my_rit -= 1;
	rit -= 1;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " [] operator " << "] --------------------]\t\t\033[0m";
	EQUAL((my_rit[0] = 5) == 5);
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " ++rit operator " << "] --------------------]\t\t\033[0m";
    ++my_rit; // I incremented here to make sure that the object changes
    ++rit;
	EQUAL(&(*my_rit) == &(*my_rit1)) && (&(*rit) == &(*rit_1));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " --rit operator " << "] --------------------]\t\t\033[0m";
    --my_rit; // I incremented here to make sure that the object changes
    --rit;
	EQUAL((&(*my_rit) == &(*(my_rit1 - 1))) && (&(*rit) == &(*(rit_1 - 1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " + operator (n + rit) " << "] --------------------]\t\t\033[0m";
	EQUAL((&(*(2 + my_rit)) == &(*(1 + my_rit1))) && (&(*(2 + rit)) == &(*(1 + rit_1))));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " - operator (rit1 - rit) " << "] --------------------]\t\t\033[0m";
    EQUAL(((my_rit - my_rit1) == (rit - rit_1)) && ((my_rit1 - my_rit) == (rit_1 - rit)));
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit++ operator " << "] --------------------]\t\t\033[0m";
    {
        std::vector<int>::reverse_iterator   tmp(rit++);
        ft::Vector<int>::reverse_iterator    my_tmp(my_rit++);
        EQUAL((&(*tmp) == &(*(--rit))) && (&(*my_tmp) == &(*(--my_rit))));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rit-- operator " << "] --------------------]\t\t\033[0m";
    {
        std::vector<int>::reverse_iterator   tmp(rit--);
        ft::Vector<int>::reverse_iterator    my_tmp(my_rit--);
        EQUAL((&(*tmp) == &(*(++rit))) && (&(*my_tmp) == &(*(++my_rit))));
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " *rit++ test " << "] --------------------]\t\t\033[0m";
    {
        std::vector<char> v(10);
        ft::Vector<char> my_v(10);
        std::string res, my_res;
        std::vector<char>::reverse_iterator start(v.end()), end(v.begin());
        ft::Vector<char>::reverse_iterator 	my_start(my_v.end()), my_end(my_v.begin());
        for(size_t i = 0; i < 10; ++i)
            v[i] = '0' + i;
		size_t i = 0;
		for(ft::Vector<char>::iterator it = my_v.begin(); it != my_v.end(); ++it)
			*it = '0' + i++;
        while (start != end)
            res.push_back(*start++);
        while (my_start != my_end)
            my_res.push_back(*my_start++);
        EQUAL(res == my_res);
    }
    std::cout << "\033[1;36m\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
}

void vector_tests(void)
{
    std::cout << "\033[1;36m<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< vector tests >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\033[0m\n\n";
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " fill constructor " << "] --------------------]\t\t\033[0m";
	{
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;

            start = get_time();
            std::vector<std::string>    v(1e5, "fill constructor test");
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            ualarm(diff * 1e3, 0);
            ft::Vector<std::string>    my_v(1e5, "fill constructor test");
            ualarm(0, 0);
        }
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- fill tow vectors with a 10 strings ------*/
        ft::Vector<std::string>		my_v(10, "fill constructor test");
        std::vector<std::string>	v(10, "fill constructor test");
        /*---------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res;
        /*---------------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
            res += *it;
        
        for(ft::Vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
            my_res += *it;
        EQUAL(res == my_res);
	}
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " range constructor " << "] --------------------]\t\t\033[0m";
	{
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            std::vector<std::string>    v(1e5, "range constructor test");
            start = get_time();
            std::vector<std::string>	v1(v.begin(), v.end());
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;

            ualarm(diff * 1e3, 0);
            ft::Vector<std::string>		my_v(v.begin(), v.end());
            ualarm(0, 0);
        }
        /*-----------------------------------------------------------------------------------------------*/
        /*--------------- fill std::vector with 10 strings and ft::vector with range of iterators ------*/
        std::cout << "return 0___!!!!!!!\n";
        std::vector<std::string>    v(10, "range constructor test");
        // return ;
        ft::Vector<std::string>     my_v(10, "range constructor test");
        std::cout << "return !!!!!!!\n";

        return ;
        ft::Vector<std::string>		my_v1(my_v.begin(), my_v.end()); // this one is to check if the range works with ft::vector
        /*----------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, my_res, my_res1;
        /*--------------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) // fill res from std::vector
            res += *it;
        int index = 0;
        for(ft::Vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it) // fill my_res from ft::vector
        {
            my_res += *it;
        }
        index = 0;
        for(ft::Vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it) // fill my_res1 from ft::vector
        {
            my_res1 += *it;

        }
        EQUAL(res == my_res && my_res == my_res1);
        // return ;
	}
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " copy constructor " << "] --------------------]\t\t\033[0m";
    {
        /*---------------------------------- time limit test --------------------------------------------*/
        {
            time_t start, end, diff;
            std::vector<char>    v(1e7, 'a');
            start = get_time();
            std::vector<char>	copy_v(v);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  20)  :  20;

            ft::Vector<char>    my_v(1e7, 'a');
            alarm(diff);
            ft::Vector<char>	my_copy_v(my_v);
            alarm(0);
        }
        /*---------------------------------------------------------------------------------------------*/
        /*---------------------------- declare a vector and fill with 'a', and create a copy of it ------------------*/
        ft::Vector<char>    v1(10, 'a');
        ft::Vector<char>    copy_v(v1);
        /*-----------------------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, res1;
        /*--------------------------------------------------------*/
        for(ft::Vector<char>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::Vector<char>::iterator it = copy_v.begin(); it != copy_v.end(); ++it) // fill res from copy_v
            res1 += *it;
        EQUAL(res == res1);
    }
    /*------------------------------------------ = operator tests --------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 1 : test with equale size vecotrs ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size = rhs.size) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string1");
            std::vector<std::string>    v2(1e6, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string1");
            ft::Vector<std::string>    ft_v2(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string1");
        std::vector<std::string>    v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string1");
        ft::Vector<std::string>    ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 2 : test with diff size vecotrs ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size < rhs.size) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e4, "string1");
            std::vector<std::string>    v2(1e6, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e4, "string1");
            ft::Vector<std::string>    ft_v2(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string1");
        std::vector<std::string>    v2(20, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string1");
        ft::Vector<std::string>    ft_v2(20, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 3 : test with diff size vecotrs ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size > rhs.size) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string1");
            std::vector<std::string>    v2(1e4, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string1");
            ft::Vector<std::string>    ft_v2(1e4, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(20, "string1");
        std::vector<std::string>    v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(20, "string1");
        ft::Vector<std::string>    ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 4 : test with one empty vector ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (lhs.size = 0) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1;
            std::vector<std::string>    v2(1e6, "string2");
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1;
            ft::Vector<std::string>    ft_v2(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1;
        std::vector<std::string>    v2(10, "string2");
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1;
        ft::Vector<std::string>    ft_v2(10, "string2");
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

        EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    /*------------------------------------------ test 5 : test with one empty vector ----------------------------------------------------------------------*/ 
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " = operator (rhs.size = 0) " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            std::vector<std::string>    v2;
            start = get_time();
            v1 = v2;
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string2");
            ft::Vector<std::string>    ft_v2;
            ualarm(diff * 1e3, 0);
            ft_v1 = ft_v2;
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<std::string>    v2;
        v1 = v2;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string2");
        ft::Vector<std::string>    ft_v2;
        ft_v1 = ft_v2;
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;

        for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;

            EQUAL(res == ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " begin and end methods " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.begin();
            v1.end();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.begin();
            ft_v1.end();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<std::string>    const v2(10, "string2");
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string2");
        ft::Vector<std::string>    const ft_v2(10, "string2");
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it) // fill res from v1
            res += *it;
        for(std::vector<std::string>::const_iterator rit = v2.begin(); rit != v2.end(); ++rit) // fill c_res from const v1
            c_res += *rit;

        for(ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it) // fill ft_res from ft_v1
            ft_res += *it;
        for(ft::Vector<std::string>::const_iterator rit = ft_v2.begin(); rit != ft_v2.end(); ++rit) // fill c_ft_res from const ft_v1
            c_ft_res += *rit;

        EQUAL(res == ft_res && c_res == c_ft_res);
	}
    /*-------------------------------------------------------------------------------------------------------------------------------------------------------*/
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " rbegin and rend methods " << "] --------------------]\t\t\033[0m";
	{
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.rbegin();
            v1.rend();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.rbegin();
            ft_v1.rend();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<std::string>    const v2(10, "string2");
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string2");
        ft::Vector<std::string>    const ft_v2(10, "string2");
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for(std::vector<std::string>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit) // fill res from v1
            res += *rit;
        for(std::vector<std::string>::const_reverse_iterator rit = v2.rbegin(); rit != v2.rend(); ++rit) // fill c_res from const v1
            c_res += *rit;

        for(ft::Vector<std::string>::reverse_iterator rit = ft_v1.rbegin(); rit != ft_v1.rend(); ++rit) // fill ft_res from ft_v1
            ft_res += *rit;
        //return; // error in rbegin and rend
        for(ft::Vector<std::string>::const_reverse_iterator rit = ft_v2.rbegin(); rit != ft_v2.rend(); ++rit) // fill c_ft_res from const ft_v1
            c_ft_res += *rit;

        EQUAL(res == ft_res && c_ft_res == c_res);
	}
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " size method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.size();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");          // fill constructor
        std::vector<std::string>    v2;                         // empty constructor
        std::vector<std::string>    v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string>    v4(v3);                     // copy constructor
        std::vector<std::string>    v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string2");
        ft::Vector<std::string>    ft_v2;
        ft::Vector<std::string>    ft_v3(ft_v1.begin(), ft_v1.end());
        ft::Vector<std::string>    ft_v4(ft_v1);
        ft::Vector<std::string>    ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        EQUAL(v1.size() == ft_v1.size() && v2.size() == ft_v2.size() 
        && v3.size() == ft_v3.size() && v4.size() == ft_v4.size() && v5.size() == ft_v5.size());
    }
     std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " capacity method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.capacity();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------------------------------------f-----*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.capacity();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");          // fill constructor
        std::vector<std::string>    v2;                         // empty constructor
        std::vector<std::string>    v3(v1.begin(), v1.end());   // range constructor with normal iterators
        std::vector<std::string>    v4(v3);                     // copy constructor
        std::vector<std::string>    v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string2");
        ft::Vector<std::string>    ft_v2;
        ft::Vector<std::string>    ft_v3(ft_v1.begin(), ft_v1.end());
        ft::Vector<std::string>    ft_v4(ft_v1);
        ft::Vector<std::string>    ft_v5(ft_v1.rbegin(), ft_v1.rend());
        /*----------------------------------------------------*/
        EQUAL(v1.capacity() == ft_v1.capacity() && v2.capacity() == ft_v2.capacity() 
        && v3.capacity() == ft_v3.capacity() && v4.capacity() == ft_v4.capacity() && v5.capacity() == ft_v5.capacity());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " max_size method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;

            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(1e6, "string2");
            start = get_time();
            v1.max_size();
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*-----------------------------------------------------*/
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(1e6, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.max_size();
            ualarm(0, 0);
            /*----------------------------------------------------*/
        }
        /*------------------------------------------------------------------------------------------*/
        /*------------------ std::vectors ---------------------*/

        std::vector<std::string>    v1(10, "string");
        std::vector<int>            v2;
        std::vector<double>         v4;
        /*-----------------------------------------------------*/
        /*------------------ ft::vectors ---------------------*/
        ft::Vector<std::string>     ft_v1(10, "string2");
        ft::Vector<int>             ft_v2;
        ft::Vector<double>          ft_v4;
        /*----------------------------------------------------*/
        EQUAL(v1.max_size() == ft_v1.max_size() && v2.max_size() == ft_v2.max_size() 
        && v4.max_size() == ft_v4.max_size());
    }
    std::cout << "\033[1;37m[-------------------- [" << std::setw(40) << std::left << " reserve method " << "] --------------------]\t\t\033[0m";
    {
        /*-------------------------------------- time limit test -----------------------------------*/
        {
            time_t      start, end, diff;
            /*------------------ std::vectors ---------------------*/
            std::vector<std::string>    v1(10, "string2");
            start = get_time();
            v1.reserve(1e6);
            end = get_time();
            diff = end - start;
            diff  =  (diff)  ? (diff  *  TIME_FAC)  :  TIME_FAC;
            /*------------------ ft::vectors ---------------------*/
            ft::Vector<std::string>    ft_v1(10, "string2");
            ualarm(diff * 1e3, 0);
            ft_v1.reserve(1e6);
            ualarm(0, 0);
        }
		/*
		 * Strings to store the results
		 */
		std::string	s1, s2, s3, ft_s1, ft_s2, ft_s3;
        std::string sit1, ft_sit1; // strings to store the result by iterators
		/*
		 * Var to store the size and the capacity
		 */
		size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
		size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
        /*
         * iterators to check the iterator validity
         *  it : iterator, eit : iterator to the end
         */
        std::vector<std::string>::iterator valid_it, valid_eit;
        ft::Vector<std::string>::iterator ft_valid_it, ft_valid_eit;
        // bool to check if the function throw or not
        bool exec_throwed = false;
        /*------------------ std::vectors ---------------------*/
        std::vector<std::string>    v1(10, "string2");
        std::vector<char>            v2;
        /*------------------ std::vectors ---------------------*/
        ft::Vector<std::string>    ft_v1(10, "string2");
        ft::Vector<char>            ft_v2;
        try
        {
            ft_v1.reserve(ft_v1.max_size() + 1);
        }
        catch(std::length_error const& e)
        {
            (void)e;
            exec_throwed = true;
        }
        v1.reserve(100);
        ft_v1.reserve(100);

		z1 = v1.size();
		ft_z1 = ft_v1.size();
        c1 = v1.capacity();
        ft_c1 = ft_v1.capacity();

        for (size_t i = 0; i < v1.size(); ++i)
            s1 += v1[i];
            
        ft_valid_it = ft_v1.begin();
        for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
            ft_s1 += *ft_valid_it;

        valid_it = v1.begin();
        valid_eit = v1.end();
        ft_valid_it = ft_v1.begin();
        ft_valid_eit = ft_v1.end();
        v1.reserve(50);
        ft_v1.reserve(50);

		z2 = v1.size();
		ft_z2 = ft_v1.size();
        c2 = v1.capacity();
        ft_c2 = ft_v1.capacity();

        for (size_t i = 0; i < v1.size(); ++i)
            s2 += v1[i];

        for (; valid_it != valid_eit; ++valid_it)
            sit1 += *valid_it;
            
        for (ft::Vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
            ft_s2 += *it;

        for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
            ft_sit1 += *ft_valid_it;

        v2.reserve(200);
        ft_v2.reserve(200);
		z3 = v2.size();
		ft_z3 = ft_v2.size();
        c3 = v2.capacity();
        ft_c3 = ft_v2.capacity();

        for (size_t i = 0; i < v2.size(); ++i)
            s3 += v2[i];
            
        for (ft::Vector<char>::iterator it = ft_v2.begin(); it != ft_v2.end(); ++it)
            ft_s3 += *it;
        
		EQUAL((s1 == ft_s1 && z1 == ft_z1 && c1 == ft_c1 && sit1 == ft_sit1) && (s2 == ft_s2 &&  z2 == ft_z2 && c2 == ft_c2)
        && (s3 == ft_s3 && z3 == ft_z3 && c3 == ft_c3) && exec_throwed);
    }
}


int main()
{
	std::vector<int> std_vector(10, -1);
	ft::Vector<int> ft_vector(10, -1);
	std::vector<int>::reverse_iterator r_it(std_vector.begin());
	for(int i =0; i < 10; i++)
	{
		std_vector[i] =  i + 1; 
		ft_vector[i] =  i + 1; 
	}

	// iterator_tests();
    // const_iterator_tests();
    // reverse_iterator_tests();
    // reverse_iterator_with_ft_vector();
    vector_tests();

   // while (1);
}