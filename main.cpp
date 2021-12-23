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

        std::map<std::string, std::string, std::greater<std::string> > m1, m2;
        ft::map<std::string, std::string, std::greater<std::string> > ft_m1, ft_m2;

        m1["γ"] = "gamma";
        m1["β"] = "beta";
        m1["α"] = "alpha";
        m1["γ"] = "gamma";

      

        ft_m1["γ"] = "gamma";
        ft_m1["β"] = "beta";
        ft_m1["α"] = "alpha";
        ft_m1["γ"] = "gamma";

        //const std::map<std::string, std::string, std::greater<std::string> >::iterator iter = std::next(m1.begin());
        //onst ft::map<std::string, std::string, std::greater<std::string> >::iterator ft_iter = std::next(ft_m1.begin());
// THE PROBLEM IS IN INSERT WITH SPESCPHEC SORT FUNCTION
  
        // cond = cond && ref.first == ft_ref.first && ref.second == ft_ref.second && iter->second == ft_iter->second && iter->first == ft_iter->first && m1.size() == ft_m1.size() && m2.size() && ft_m2.size();
        std::cout << "\n" << m1.begin()->first << "    "   << ft_m1.begin()->first;
        cond = ref.first == ft_ref.first;
        
    
	return 0;
};




