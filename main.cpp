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
using namespace ft;
int main()
{

	std::map<int, int>std__map;
	std__map[100] = 100;
	std__map[80] = 100;
	std__map[120] = 100;
	std__map[60] = 100;
	std__map[140] = 100;
	std__map[110] = 100;
	std__map[90] = 100;
	std__map[150] = 100;
	std__map[130] = 100;
	std__map[115] = 100;
	std__map[105] = 100;
	std__map[95] = 100;
	std__map[85] = 100;
	std__map[70] = 100;
	std__map[40] = 100;

	std::map<int, int>std__map_2;
	std__map[100] = 100;
	std__map[80] = 100;
	std__map[120] = 100;
	std__map[60] = 100;
	std__map[140] = 100;
	std__map[110] = 100;
	std__map[90] = 100;
	std__map[150] = 100;
	std__map[130] = 100;
	std__map[115] = 100;
	std__map[105] = 100;
	std__map[95] = 100;
	std__map[85] = 100;
	std__map[70] = 100;
	std__map[40] = 100;
	
	std::map<int, int>::iterator std_it(std__map.begin());
	std::map<int, int>::iterator std_it_2(std__map_2.begin());
	std::cout << (std_it == std_it) << std::endl;

	// std::map<int, int>::iterator it_begin (std__map.begin());
	// while (it_begin !=  std__map.end()){
	// 	std::cout << (it_begin)->first << std::endl;
	// 	it_begin++;
	// }
	//return 1;
	ft::map<int, int>my_map;
	pair<int, int>pr(80, 100);
	my_map.insert(make_pair(80, 100));
	my_map.insert(make_pair(120, 100));
	my_map.insert(make_pair(100, 100));
	my_map.insert(make_pair(60, 100));
	my_map.insert(make_pair(140, 100));
	my_map.insert(make_pair(110, 100));
	my_map.insert(make_pair(90, 100));
	my_map.insert(make_pair(150, 100));
	my_map.insert(make_pair(130, 100));
	my_map.insert(make_pair(115, 100));
	my_map.insert(make_pair(105, 100));
	my_map.insert(make_pair(95, 100));
	my_map.insert(make_pair(85, 100));
	my_map.insert(make_pair(70, 100));
	my_map.insert(make_pair(40, 100));

	std::cout << "*********************" << std::endl;
	ft::map<int, int>::iterator it;
	it = my_map.begin();
	//std::cout << "at begin " << it->first << std::endl;
	// while(it != (my_map.end())){
	// 	std::cout << (it)->first << std::endl;
	// 	it++;
	// }

	//std::cout << (it)->first << std::endl;
	return 0;
}
