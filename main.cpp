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


int main()
{
	// #if MY
	// 	#define MAP ft::map 
	// #else
	// 	#define MAP std::map 
	// #endif

	// std::map<int, std::string> m;
	ft::map<int, std::string> ft_m;
	int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
	for (size_t i = 0; i < 9; ++i)
	{
		ft_m.insert(ft::make_pair(arr[i], "value"));
	}
	// std::map<int, std::string> const c_m(m.begin(), m.end());
	// ft::map<int, std::string> const c_ft_m(ft_m.begin(), ft_m.end());

	// bool cond = (cond && (m.lower_bound(15)->first == ft_m.lower_bound(15)->first));
	// cond = (cond && (m.lower_bound(65)->first == ft_m.lower_bound(65)->first));
	// std::cout << ft_m.lower_bound(90)->first << std::endl;
      
	// ft_m.printing();

	ft::map<int, std::string>::iterator it_1, it_2;
	it_1 = ft_m.begin();
	it_2 = ft_m.end();
	while (it_1 != it_2)
	{
		std::cout << it_1->first << std::endl;
		it_1++;
		std::cout << "**********************\n";
	}
	
    
	return 0;
};




