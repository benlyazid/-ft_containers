/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbenlyaz <kbenlyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:43:35 by kbenlyaz          #+#    #+#             */
/*   Updated: 2021/10/22 08:55:58 by kbenlyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>
# include <iostream>
# include <iterator>
#include <map>
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
#include "avl.hpp"
#include "random_access_iterator.hpp"
#include "map.hpp"
// #include "bidirectional_iterator.hpp"

std::string s1("hello1");
std::string s2("hello2");

using namespace ft;
typedef std::string key_type_t;


template<typename T> // primary template
struct isFF_void : std::false_type {};
template<>           // explicit specialization for T = void
struct isFF_void<void> : std::true_type {};

int main()
{
	// #if MY
	// 	#define MAP ft::map 
	// #else
	// 	#define MAP std::map 
	// #endif

	// std::map<char,int> mymap;

	// mymap['x'] = 100;
	// mymap['y'] = 200;
	// mymap['z'] = 300;

	// show content:
	// std::map<char,int>::reverse_iterator rit;
	// rit = mymap.rbegin();

	// std::cout <<  rit->first << std::endl;




	// rit_ = mymap_2.rbegin();
	// std::cout <<  rit_->first << std::endl;
	// for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
	// 	std::cout << rit->first << " => " << rit->second << '\n';


	// // show content:
	// ft::map<char,int>::reverse_iterator rit_2;
	// for (rit_2=mymap_2.rbegin(); rit_2!=mymap_2.rend(); ++rit_2)
	// 	std::cout << rit_2->first << " => " << rit_2->second << '\n';



	ft::Vector<int> my_v(10);
	ft::Vector<int>::reverse_iterator r_it;
	ft::Vector<int>::const_reverse_iterator c_r_it;
	c_r_it = r_it;

	return 0;
};








