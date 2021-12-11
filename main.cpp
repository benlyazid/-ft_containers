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

	// std::cout << tst.ptr1 << "    " << tst.ptr2 << "     " << tst.ptr3 << std::endl;
	// swap_all(&tst);
	// std::cout << tst.ptr1 << "    " << tst.ptr2 << "     " << tst.ptr3 << std::endl;

	// allocator.construct(my_tree, 2, 2);
	// tree.add_node(100, 100, (tree.node));
	//std::cout << "key is " << tree.node->key << std::endl;
	//std::cout << "key is " << tree.node->key << std::endl;
	//tree.add_node(100, 120, (tree.node));
	//tree.add_node(120, 120, (tree.node));
	//tree.add_node(80, 120, (tree.node));
	//tree.add_node(110, 120, (tree.node));
	// tree.add_node(110, 120, (tree.node));
	// tree.add_node(60, 120, (tree.node));
	// tree.add_node(90, 120, (tree.node));
	// 	tree.remove_node(tree.node, 80);
	// tree.add_node(160, 120, (tree.node));
	//tree.add_node(180, 120, (tree.node));
	// tree.add_node(110, 90, (tree.node));
	// tree.add_node(60, 90, (tree.node));
	// tree.add_node(90, 90, (tree.node));
	// tree.add_node(180, 90, (tree.node));
	// tree.add_node(140, 90, (tree.node));
	// tree.add_node(115, 60, (tree.node));
	// tree.add_node(105, 60, (tree.node));
	// tree.add_node(95, 60, (tree.node));
	// tree.add_node(70, 60, (tree.node));
	// tree.add_node(50, 60, (tree.node));
	// tree.add_node(85, 60, (tree.node));
	// tree.add_node(200, 60, (tree.node));
	// tree.add_node(220, 60, (tree.node));
	// // tree.add_node(115, 40, (tree.node));

	//tree.add_node(100, 100, tree.node);
	//tree.add_node(120, 100, tree.node);
	//tree.add_node(60, 100, tree.node);
	//tree.add_node(140, 100, tree.node);
	//tree.add_node(110, 100, tree.node);
	//tree.add_node(160, 100, tree.node);


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
	std::map<int, int>::iterator it_end (std__map.end());
	it_end--;
	int t = 15;
	while (it_end !=  std__map.begin()){
		std::cout << (it_end)->first << std::endl;
		it_end--;
	}
	Avl<int, int> tree;
	tree.node = NULL;
	tree.add_node(100, 100, tree.node);
	tree.add_node(80, 100, tree.node);
	tree.add_node(120, 100, tree.node);
	tree.add_node(60, 100, tree.node);
	tree.add_node(140, 100, tree.node);
	tree.add_node(110, 100, tree.node);
	tree.add_node(90, 100, tree.node);
	tree.add_node(150, 100, tree.node);
	tree.add_node(130, 100, tree.node);
	tree.add_node(115, 100, tree.node);
	tree.add_node(105, 100, tree.node);
	tree.add_node(95, 100, tree.node);
	tree.add_node(85, 100, tree.node);
	tree.add_node(70, 100, tree.node);
	tree.add_node(40, 100, tree.node);
	std::cout << "*********************" << std::endl;
	ft::Avl<int, int >::NODE *temp	= tree.node->get_the_beggist_one(tree.node);
	

	while(temp){

		std::cout << temp->key << std::endl;
		temp = temp->back_node(temp);

	}



	return 0;
}
