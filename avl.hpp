#ifndef AVL_H
#define AVL_H
#include "./utils.hpp"
namespace ft{

	template <class KEY, class T, class Compare = std::less<KEY>, class Allocator = std::allocator<std::pair<const KEY, T> > >
    class Avl{
		public:
			typedef KEY key_t;
			typedef T 	mapped_t;
			Compare 	compare;

			struct NODE
			{
				NODE() : node_pair() {}
				// KEY  	key;
				// T		value;
				ft::pair<key_t, mapped_t> node_pair;
				NODE	*left;
				NODE 	*right;
				NODE 	*parent;
				int		left_h;
				int		right_h;
				int		diff;
				Compare 	compare;

				void insert(KEY key, T value, NODE* parent){
					// this->key = key;
					// this->value = value;

					// std::cout << "INSERT 0 " << std::endl;
					node_pair.first = key;
					// std::cout << "INSERT 0_0 " << "|" << key << "|" << std::endl;
					node_pair.second = value;
					// std::cout << "INSERT 0_1 " << std::endl;
					this->left = NULL;
					// std::cout << "INSERT 1 " << std::endl;
					this->parent = parent;
					this->right = NULL;
					// std::cout << "INSERT 2 " << std::endl;
					this->right_h = 0;
					this->left_h = 0;
				}
				
				NODE(const NODE* &origen){
					// key = origen->key;
					// value = origen->value;
					node_pair = origen->node_pair;
					left = origen->left;
					parent = origen->parent;
					right = origen->right;
					right_h = origen->right_h;
					left_h = origen->left_h;
				}
	
				NODE *next_node(NODE *head){
					NODE *temp = head;
					if(head && head->right == NULL){
						if (head->parent){
							// if (head->key > head->parent->key){
							if (this->compare(head->parent->node_pair.first, head->node_pair.first)){
								if (head->parent->parent){
									// while (head->parent->parent && (head->parent->parent->key < temp->key)){
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

				// NODE *find_node(NODE *head, KEY key_to_find){
				// 	NODE *ret = NULL;
				// 	if (head->key == key_to_find )
				// 		return head;
				// 	if (head->right)
				// 		ret = find_node(head->right, key_to_find);
				// 	if (ret && ret->key == key_to_find)
				// 		return (ret);
				// 	if (head->left)
				// 		ret = find_node(head->left, key_to_find);
				// 	if (ret && ret->key == key_to_find)
				// 		return (ret);
				// 	return NULL;					
				// }
	
				NODE *find_node(NODE *head, KEY key_to_find){
					NODE *ret = NULL;
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
							// if (head->key < head->parent->key){
							if (this->compare(head->node_pair.first, head->parent->node_pair.first)){
								if (head->parent->parent){
									// while (head->parent->parent && head->parent->parent->key > temp->key){
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
				
				NODE *get_the_smallest_one(NODE *head){
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
			NODE *the_last_node;
			size_t avl_size;
			// ft::pair<int, int> *__pair;
			ft::pair<const key_t, mapped_t> _pair_for_iterator;

			public:
			Avl(){
				avl_size = 0;
				the_last_node = node_allocator.allocate(1);
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
				// std::cout << "ADDING NODE IN RIGHT" << std::endl;
				avl_size++;
				head->right = node_allocator.allocate(1);
				node_allocator.construct(head->right);
				head->right_h++;
				// head->right->insert(new_key, new_value, head);
				/*********/
				// std::cout << "ADDING NODE IN RIGHT_1" << std::endl;
				head->right->node_pair.first = new_key;
				// std::cout << "ADDING NODE IN RIGHT_1_1   "  << head->right->node_pair.second << std::endl;
				// std::cout << "HERE WE GO\n";
				// std::cout << head->right->node_pair.second.c_str() << std::endl;
				head->right->node_pair.second = new_value;
				// std::cout << "ADDING NODE IN RIGHT_1_2" << std::endl;
				head->right->left = NULL;
				head->right->parent = head;
				head->right->right = NULL;
				head->right->right_h = 0;
				head->right->left_h = 0;
				// std::cout << "ADDING NODE IN RIGHT_2" << std::endl;
				/**********/

			}

			void	add_node_in_left(NODE* &head, const KEY new_key, const T new_value){
				avl_size++;
				head->left = node_allocator.allocate(1);
				node_allocator.construct(head->left);
				head->left_h++;

				/*********/
				head->left->node_pair.first = new_key;
				head->left->node_pair.second = new_value;
				head->left->left = NULL;
				head->left->parent = NULL;
				head->left->right = NULL;
				head->left->right_h = 0;
				head->left->left_h = 0;
				/**********/
				//head->left->insert(new_key, new_value, head);
			}

			void	add_node_in_root(NODE* &head, const KEY new_key, const T new_value){
				avl_size++;
				// std::cout << "add node value " << new_key << std::endl;
				head = node_allocator.allocate(1);
				node_allocator.construct(head);
				head->left_h = 0;
				head->right_h = 0;
				// std::cout << "add node value__0 " << new_key << std::endl;
				//head->insert(new_key, new_value, NULL);

				/*********/
				head->node_pair.first = new_key;
				// std::cout << "add node value__10 " << new_key << std::endl;
				head->node_pair.second = new_value;
				// std::cout << "add node value__20 " << new_key << std::endl;
				head->left = NULL;
				head->parent = NULL;
				head->right = NULL;
				head->right_h = 0;
				head->left_h = 0;
				/**********/
				// std::cout << "add node value__1 " << new_key << std::endl;
			}

			pair<NODE*, bool> add_node(const KEY new_key, const T new_value, NODE* &head){

				// std::cout << "START INSERTING KEY " << new_key << std::endl;
				pair<NODE*, bool> pait_to_return;
				if (!head){
					// std::cout << "Insert in head vlaue " << new_key << std::endl;
					add_node_in_root(head, new_key, new_value);
					// std::cout << "Insert in head vlaue 1" << new_key << std::endl;
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
				// std::cout << "end_0 of inserting " << new_key << std::endl;
				head->right_h = max_hight(head->right);
				head->left_h = max_hight(head->left);
				check_balance(head);
				// std::cout << "end of inserting " << new_key << std::endl;
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
				//std::cout << "type of rotation is " << type << std::endl;
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
				//temp_head->node_pair = head->node_pair;
				std::swap(temp_head->node_pair, head->node_pair);
				// head = temp_head;
				// head->left = temp_head->left;
				// head->right = temp_head->right;


				// temp_successor_key = head->node_pair.first;
				// std::cout << " swap with " << temp_successor_key << std::endl;
				// //head->node_pair.first = temp_head->node_pair.first;
				// temp_head->node_pair.first = temp_successor_key;
				// head = temp_head;
				// std::cout << "check done " << std::endl;

			}
			
			void remove_node(NODE* &node, KEY key){
				// std::cout << "REMOVE NODE " << key << " WITH SIZE " << avl_size << std::endl;
				if (node == NULL){
					
					// std::cout << "EXIT  " << key << " WITH SIZE " << avl_size << std::endl;
					return;

				}
				else if (compare(node->node_pair.first, key))
					remove_node(node->right, key);
				else if (compare(key, node->node_pair.first))
					remove_node(node->left, key);
				else{
					if (node->left_h == 0 && node->right_h == 0){
						// std::cout << "REMOVING NODE " << key << " WITH SIZE " << avl_size << std::endl;
						node_allocator.destroy(node);
						node_allocator.deallocate(node, 1);
						node = NULL;
						avl_size--;
					}
					else if (node->left_h == 0 || node->right_h == 0){
						NODE *temp = node->left ? node->left : node->right;
						NODE *temp_prt = node->parent;
						temp->parent = node->parent;

						// std::cout << "REMOVING NODE " << key << " WITH SIZE " << avl_size << std::endl;
						node_allocator.destroy(node);
						node_allocator.deallocate(node, 1);
						node = NULL;
						if (temp_prt && compare(temp_prt->node_pair.first, temp->node_pair.first)){
							// std::cout << " set in right" << std::endl;
							temp_prt->right = temp;
						}
						else if (temp_prt && compare(temp->node_pair.first, temp_prt->node_pair.first)){
							// std::cout << " set in left" << std::endl;
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
				// std::cout << "AFTER REMOVE NODE " << key << " WITH SIZE " << avl_size << std::endl;

				if (!node){
					return ;
				}
				node->right_h = max_hight(node->right);
				node->left_h = max_hight(node->left);
				check_balance(node);
			}
			
			static void print_node_info(NODE *head){
				if (!head){
					std::cout << "THIS NODE IS NULL " << std::endl;
					return ;
				}
				std::cout << "THE NODE HAS THE KEY " << head->node_pair.first << " AND LEFT HIGHT " << head->left_h << " AND RIGHT HEIGHT " << head->right_h << std::endl;
				if (head->left)
					std::cout << "					THE LEFT KEY IS " << head->left->node_pair.first;
				else
					std::cout << "					THE LEFT KEY IS NULL ";
				if (head->right)
					std::cout << "	THE RIGHT KEY IS " << head->right->node_pair.first;
				else
					std::cout << "	THE RIGHT KEY IS NULL ";
				if (head->parent)
					std::cout << "		THE PARENT KEY IS " << head->parent->node_pair.first << std::endl;
				else
					std::cout << "		THE PARENT KEY IS NULL "<< std::endl;
				std::cout << std::endl;
				if (head->right)
					print_node_info(head->right);
				if (head->left)
					print_node_info(head->left);
			}
    };
}
#endif
