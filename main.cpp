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

// std::string s1("hello1");
// std::string s2("hello2");

// using namespace ft;
// typedef std::string key_type_t;
// int main()
// {
// 	// #if MY
// 	// 	#define MAP ft::map 
// 	// #else
// 	// 	#define MAP std::map 
// 	// #endif

// 		key_type_t key__ = key_type_t();
// 		ft::map<int, key_type_t> ft_m1;
// 		ft::map<int, key_type_t> ft_m2;
// 		for (int i = 0; i < 1e7; ++i)
// 		{
// 			ft_m2.insert(ft::make_pair(i, key__));
// 			// ft_m1.insert(ft::make_pair(i, key__));
// 		}

// 		// std::cout << "CHECK BEFORE OPEARATOR = *****************" << std::endl;

// 		// ft_m1.clear();


// 		// std::cout << "CHECK AFTER ERASING " << std::endl;
// 		// std::cout << "size is " << ft_m1.size() << std::endl;

// 		// int i_i = 0;

// 		// for (ft::map<int, key_type_t>::iterator it_ = ft_m2.begin(); it_ != ft_m2.end(); it_++ , i_i++)
// 		// {
// 		// 	ft::pair<int, key_type_t> p(it_->first, it_->second);
// 		// 	std::cout << "before insert in loop " <<i_i << std::endl;			
// 		// 	ft_m1.insert(p);
// 		// 	std::cout << i_i << std::endl;
// 		// }
	
// 		// std::cout << "CHECK AFTER OPEARATOR = " << std::endl;
// 		//m.printing();
// 	return 0;
// };



int main(){


	std::cout << "check 0" << std::endl;
	ft::Vector<int> v((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());
	std::cout << "check 1" << std::endl;
	//std::cout << v.capacity() << " " << v.size() << "\n" << std::endl;

	int arr[10] = {1,2,3,4,5,6,7,8,9, 10};
	ft::Vector<int> v2(arr, arr + 10);
	// std::vector<int>::iterator b = v.begin();
	//std::cout << v2.capacity() << " " << v2.size() << std::endl;

}








