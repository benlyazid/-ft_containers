#ifndef AVL_H
#define AVL_H
#include "./utils.hpp"
#include <algorithm>
#include <iostream>
namespace ft{

	template <class KEY, class T, class CMPR, class Allocator = std::allocator<ft::pair<const KEY, T> > >
    class Avl{
		public:
			typedef KEY key_t;
			typedef T 	mapped_t;
			typedef	CMPR Compare;
			Compare 	compare;
			struct NODE
			{
				Allocator  pair_allocator;
				NODE() : node_pair() {}
				NODE(const pair <const key_t, mapped_t> p) {
					pair_allocator.construct(&node_pair, p);
				}

				ft::pair<const key_t, mapped_t> node_pair;
				NODE							*left;
				NODE 							*right;
				NODE 							*parent;
				int								left_h;
				int								right_h;
				Compare 						compare;

				void insert(KEY key, T value, NODE* parent){
					node_pair.first = key;
					node_pair.second = value;
					this->left = NULL;
					this->parent = parent;
					this->right = NULL;
					this->right_h = 0;
					this->left_h = 0;
				}
				
				NODE *next_node(NODE *head){
					NODE *temp = head;
					if(head && head->right == NULL){
						if (head->parent){
							if (this->compare(head->parent->node_pair.first, head->node_pair.first)){
								if (head->parent->parent){
									while (head->parent->parent && this->compare(head->parent->parent->node_pair.first, temp->node_pair.first)){
										head = head->parent;
									}
									return (head->parent->parent);								
								}
							}
							else{
								return (head->parent);
							}
						}
					}
					else{
						temp = temp->right;
						while(temp && temp->left){
							temp = temp->left;
						}
						return temp;
					}
					return NULL;
				}

				NODE *find_node(NODE *head, KEY key_to_find){
					if(!head)
						return (NULL);
					if (!this->compare(head->node_pair.first, key_to_find) && !this->compare(key_to_find, head->node_pair.first))
						return head;
					if (head->right && this->compare(head->node_pair.first, key_to_find))
						return find_node(head->right, key_to_find);
					if (head->left && this->compare(key_to_find, head->node_pair.first))
						return find_node(head->left, key_to_find);
					return NULL;					
				}

				NODE *back_node(NODE *head){
					NODE *temp = head;
					if(head->left == NULL){
						if (head->parent){
							if (this->compare(head->node_pair.first, head->parent->node_pair.first)){
								if (head->parent->parent){
									while (head->parent->parent && this->compare( temp->node_pair.first, head->parent->parent->node_pair.first)){
										head = head->parent;
									}
									return (head->parent->parent);								
								}
							}
							else{
								return (head->parent);
							}
						}
					}
					else{
						temp = temp->left;
						while(temp && temp->right){
							temp = temp->right;
						}
						return temp;
					}
					return NULL;
				}
				
				NODE *get_the_smallest_one(NODE *head) const {
					NODE *temp = head;
					while(temp && temp->left)
						temp = temp->left;
					return temp;
				}
				
				NODE *get_the_beggist_one(NODE *head){
					NODE *temp = head;
					while(temp && temp->right)
						temp = temp->right;
					return temp;
				}
			};
	
        public:
			typedef NODE node_t;
			typename Allocator::template rebind<NODE>::other node_allocator;
			NODE *node;
			Allocator pair_allocator;
			NODE *the_last_node;
			size_t avl_size;

		public:
			Avl(){
				avl_size = 0;
				the_last_node = node_allocator.allocate(1);
			}
			~Avl(){
				node_allocator.deallocate(the_last_node, 1);
			}

			int max_hight(NODE *node){
				int m1 = 0;
				int m2 = 0;
				if (node){
					m1 = node->left_h + 1;
					m2 = node->right_h + 1;
				}
				return (std::max(m1, m2));
			}

			void	add_node_in_right(NODE* &head, const KEY new_key, const T new_value){
				avl_size++;
				head->right = node_allocator.allocate(1);
				node_allocator.construct(head->right, ft::make_pair(new_key, new_value));
				head->right_h++;
				head->right->left = NULL;
				head->right->parent = head;
				head->right->right = NULL;
				head->right->right_h = 0;
				head->right->left_h = 0;
			}

			void	add_node_in_left(NODE* &head, const KEY new_key, const T new_value){
				avl_size++;
				head->left = node_allocator.allocate(1);
				node_allocator.construct(head->left, ft::make_pair(new_key, new_value));
				head->left_h++;
				head->left->left = NULL;
				head->left->parent = head;
				head->left->right = NULL;
				head->left->right_h = 0;
				head->left->left_h = 0;
			}

			void	add_node_in_root(NODE* &head, const KEY new_key, const T new_value){
				avl_size++;
				head = node_allocator.allocate(1);
				node_allocator.construct(head, ft::make_pair(new_key, new_value));
				head->left_h = 0;
				head->right_h = 0;
				head->left = NULL;
				head->parent = NULL;
				head->right = NULL;
				head->right_h = 0;
				head->left_h = 0;
			}

			pair<NODE*, bool> add_node(const KEY new_key, const T new_value, NODE* &head){
				pair<NODE*, bool> pait_to_return;
				if (!head){
					add_node_in_root(head, new_key, new_value);
					pait_to_return = (make_pair(head, true));
				}
			    else if(compare(head->node_pair.first, new_key)){
			        if(!head->right){
						add_node_in_right(head, new_key, new_value);
						pait_to_return = (make_pair(head->right, true));
			        }
				 	else{
						pait_to_return = (add_node(new_key, new_value, head->right));
					}
				}
				else if (compare(new_key, head->node_pair.first)){
					if(!head->left){
						add_node_in_left(head, new_key, new_value);
						pait_to_return = (make_pair(head->left, true));
					}
				 	else{
						pait_to_return = (add_node(new_key, new_value, head->left));
					}
				}
				else{
					pait_to_return = (make_pair(head, false));
				}
				head->right_h = max_hight(head->right);
				head->left_h = max_hight(head->left);
				check_balance(head);
				return (pait_to_return);
			}
			
			void	check_balance(NODE* &head){
				if (abs(head->right_h - head->left_h) > 1){
					std::string type = type_of_rotation(head);
					balance(head, type);
				}
			}
			
			std::string	type_of_rotation(NODE *head){
				std::string type = "";
				if (head->right_h > head->left_h){
					type = "R";
					if (head->right && head->right->right_h < head->right->left_h)
						type = "RL";
				}
				else{
					type = "L";
					if (head->left && head->left->right_h > head->left->left_h)
						type = "LR";
				}
				return (type);
			}
			
			void	balance(NODE* &head, std::string type){
				if (type == "L")
					right_rotation(head);
				else if  (type == "R")
					left_rotation(head);
				else if (type == "RL"){
					right_rotation(head->right);
					left_rotation(head);
				}
				else if (type == "LR"){
					left_rotation(head->left);
					right_rotation(head);
				}
			}
		
			void	right_rotation(NODE* &head){
				NODE *temp_head_left = head->left;
				NODE *temp_head_parent = head->parent;
				NODE *temp_head_left_right = temp_head_left->right;

				temp_head_left->right = head;
				head->left = temp_head_left_right;
				if (head->left)
					head->left->parent = head;
				
				head->parent = temp_head_left;
				head = temp_head_left;
				head->parent = temp_head_parent;

				head->right->left_h = max_hight(head->right->left);
				head->right_h = max_hight(head->right);
			}
			
			void	left_rotation(NODE* &head){

				NODE *temp_head_right = head->right;
				NODE *temp_head_parent = head->parent;
				NODE *temp_head_right_left = temp_head_right->left;
				
				temp_head_right->left = head;
				head->right = temp_head_right_left;
				if (head->right)
					head->right->parent = head;

				head->parent = temp_head_right;
				head = temp_head_right;
				head->parent = temp_head_parent;

				head->left->right_h =  max_hight(head->left->right);
				head->left_h = max_hight(head->left);
			}
			
			void	swap_node_with_in_order_successor(NODE* &head){
				NODE *temp_head = head->left;
				while (temp_head->right){
					temp_head = temp_head->right;
				}
				ft::pair <const key_t, mapped_t> temp_pair(temp_head->node_pair);
				pair_allocator.construct(&temp_head->node_pair, head->node_pair);
				pair_allocator.construct(&head->node_pair, temp_pair);
			}
			
			void remove_node(NODE* &node, KEY key){
				if (node == NULL){
					return;
				}
				else if (compare(node->node_pair.first, key))
					remove_node(node->right, key);
				else if (compare(key, node->node_pair.first))
					remove_node(node->left, key);
				else{
					if (node->left_h == 0 && node->right_h == 0){
						node_allocator.destroy(node);
						node_allocator.deallocate(node, 1);
						node = NULL;
						avl_size--;
					}
					else if (node->left_h == 0 || node->right_h == 0){
						NODE *temp = node->left ? node->left : node->right;
						NODE *temp_prt = node->parent;
						temp->parent = node->parent;
						node_allocator.destroy(node);
						node_allocator.deallocate(node, 1);
						node = NULL;
						if (temp_prt && compare(temp_prt->node_pair.first, temp->node_pair.first)){
							temp_prt->right = temp;
						}
						else if (temp_prt && compare(temp->node_pair.first, temp_prt->node_pair.first)){
							temp_prt->left = temp;
						}
						else{
							node = temp;
						}
						avl_size--;
					}
					else if (node->left_h && node->right_h){
						swap_node_with_in_order_successor(node);
						remove_node(node->left, key);
					}
				}
				if (!node){
					return ;
				}
				node->right_h = max_hight(node->right);
				node->left_h = max_hight(node->left);
				check_balance(node);
			}
			
			NODE* lower_bound (NODE *first, KEY key) const{
				while (first){
					if (compare(first->node_pair.first, key))
						first = first->next_node(first);
					else
						break ;
				}
				return first;
			}

			NODE* upper_bound (NODE *first, KEY key) const{
				while (first){
					if (compare(key,first->node_pair.first))
						break ;
					first = first->next_node(first);
				}
				return first;
			}
    };
}
#endif