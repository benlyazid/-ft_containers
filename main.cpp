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
# include <ctime>
# include <iomanip>
# include <unistd.h>
# include <signal.h>
# include <sys/time.h>
#include "avl.hpp"
#include "random_access_iterator.hpp"
using namespace ft;

int main()
{
	Avl<int, int> tree;
	// Avl<int, int> *my_tree = allocator.allocate(1);
	std::vector<int>::iterator c_it;
	std::vector<int>::iterator it;
	bool r = it == c_it;
	return 2;

	// allocator.construct(my_tree, 2, 2);
	// tree.add_node(100, 100, (tree.node));
	//std::cout << "key is " << tree.node->key << std::endl;
	//std::cout << "key is " << tree.node->key << std::endl;
	// tree.add_node(120, 120, (tree.node));
	// tree.add_node(130, 120, (tree.node));
	//tree.add_node(90, 90, (tree.node));
	//tree.add_node(110, 60, (tree.node));
	//tree.add_node(115, 40, (tree.node));
	std::cout << "The head Key is " << tree.node->key << std::endl;
	std::cout << "-------------------------------\n";
	tree.print_map(tree.node);
	// tree.check_balnce(tree.node);
	//std::cout << "key is " << tree.node->key << std::endl;


	return 0;
}
