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


class my_execption : public std::exception{
	public:
		const char* what() const throw(){
			return "this is error\n";
		}
};
class my_execption2 : public std::exception{
	public:
		const char* what() const throw(){
			return "this is error2\n";
		}
};

class tst_ptr{

	public:

		char *ptr1;
		char *ptr2;
		char *ptr3;
};
void swap_all(tst_ptr*  tst){
	char *ptr_1_tmp = tst->ptr1;
	char *ptr_2_tmp = tst->ptr2;
	char *ptr_3_tmp = tst->ptr3;
	tst->ptr3 = ptr_2_tmp;
	tst->ptr2 = ptr_1_tmp;
	tst->ptr1 = ptr_3_tmp;
}
int main()
{
	tst_ptr tst;
	tst.ptr1 = strdup("1");
	tst.ptr2 = strdup("2");
	tst.ptr3 = strdup("3");
	
	Avl<int, int> tree;
	// std::cout << tst.ptr1 << "    " << tst.ptr2 << "     " << tst.ptr3 << std::endl;
	// swap_all(&tst);
	// std::cout << tst.ptr1 << "    " << tst.ptr2 << "     " << tst.ptr3 << std::endl;

	// allocator.construct(my_tree, 2, 2);
	// tree.add_node(100, 100, (tree.node));
	//std::cout << "key is " << tree.node->key << std::endl;
	//std::cout << "key is " << tree.node->key << std::endl;
	tree.add_node(100, 120, (tree.node));
	tree.add_node(120, 120, (tree.node));
	//tree.add_node(80, 120, (tree.node));
	tree.add_node(110, 120, (tree.node));
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
	std::cout << "------------------------------------------" << std::endl;
	tree.print_node_info(tree.node);


	return 0;
}