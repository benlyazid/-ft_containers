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
using namespace ft;


int main()
{
	Avl<int, int> tree;
	// Avl<int, int> *my_tree = allocator.allocate(1);

	// allocator.construct(my_tree, 2, 2);
	tree.add_node(100, 100, (tree.node));
	//std::cout << "key is " << tree.node->key << std::endl;
	tree.add_node(110, 80, (tree.node));
	//std::cout << "key is " << tree.node->key << std::endl;
	tree.add_node(105, 120, (tree.node));
	// tree.add_node(90, 90, (tree.node));
	// tree.add_node(60, 60, (tree.node));
	// tree.add_node(95, 95, (tree.node));
	// tree.check_balnce(tree.node);
	//std::cout << "key is " << tree.node->key << std::endl;


	return 0;
}
