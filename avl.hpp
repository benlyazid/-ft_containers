#ifndef AVL_H
#define AVL_H
namespace ft{

	template <class KEY, class T, class Compare = std::less<KEY>, class Allocator = std::allocator<std::pair<const KEY, T> > >
    class Avl{
		public:
			struct NODE
			{
				KEY  	key;
				T		value;
				NODE	*left;
				NODE 	*right;
				NODE 	*parent;
				int		left_h;
				int		right_h;
				int		diff;
				bool	is_the_last_node;

				void insert(KEY key, T value, NODE* parent){
					this->key = key;
					this->value = value;
					this->left = NULL;
					this->parent = parent;
					this->right = NULL;
					this->right_h = 0;
					this->left_h = 0;
					this->is_the_last_node = false;
				}
				NODE(const NODE* &origen){
					key = origen->key;
					value = origen->value;
					left = origen->left;
					parent = origen->parent;
					right = origen->right;
					right_h = origen->right_h;
					left_h = origen->left_h;
				}
				NODE *next_node(NODE *head){
					NODE *temp = head;
					if(head->right == NULL){
						if (head->parent){
							if (head->key > head->parent->key){
								if (head->parent->parent){
									while (head->parent->parent && head->parent->parent->key < temp->key){
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
					NODE *ret = NULL;
					if (head->key == key_to_find )
						return head;
					if (head->right)
						ret = find_node(head->right, key_to_find);
					if (ret && ret->key == key_to_find)
						return (ret);
					if (head->left)
						ret = find_node(head->left, key_to_find);
					if (ret && ret->key == key_to_find)
						return (ret);
					return NULL;
					
				}
				NODE *back_node(NODE *head){
					NODE *temp = head;
					if(head->left == NULL){
						if (head->parent){
							if (head->key < head->parent->key){
								if (head->parent->parent){
									while (head->parent->parent && head->parent->parent->key > temp->key){
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

				NODE(){}
			};
	
        public:
			typename Allocator::template rebind<NODE>::other node_allocator;
			Compare compare;
			NODE *node;
			//NODE *head;
			public:
			// Avl(): node(NULL){
			// }
		
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
				std::cout << "insert in right of : " << head->key << "  key : " << new_key << std::endl;
				head->right = node_allocator.allocate(1);
				head->right_h++;
				head->right->insert(new_key, new_value, head);
			}

			void	add_node_in_left(NODE* &head, const KEY new_key, const T new_value){
				head->left = node_allocator.allocate(1);
				head->left_h++;
				std::cout << "insert in left of : "  << head->key << "  key : " << new_key << std::endl;
				head->left->insert(new_key, new_value, head);
			}

			void	add_node_in_root(NODE* &head, const KEY new_key, const T new_value){
				std::cout << "insert in root key : " << new_key << std::endl;
				head = node_allocator.allocate(1);
				head->left_h = 0;
				head->right_h = 0;
				head->insert(new_key, new_value, NULL);
			}

			void	add_node(const KEY new_key, const T new_value, NODE* &head, const Compare comp = std::less<KEY>()){

				
				if (!head)
					add_node_in_root(head, new_key, new_value);
			    else if(comp(head->key, new_key)){
			        if(!head->right){
						add_node_in_right(head, new_key, new_value);
			        }
				 	else{
						add_node(new_key, new_value, head->right, comp);
					}
				}
				else if (comp(new_key, head->key)){
					if(!head->left)
						add_node_in_left(head, new_key, new_value);
				 	else{
						add_node(new_key, new_value, head->left, comp);
					}
				}
				else{
					return ;
				}
				head->right_h = max_hight(head->right);
				head->left_h = max_hight(head->left);
				check_balance(head);
			}
			
			void	check_balance(NODE* &head){
				if (abs(head->right_h - head->left_h) > 1){
					std::cout << "node with key " << head->key << " is not balanced With " << head->right_h << " in right and " << head->left_h << " in left ."  << std::endl;
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
				std::cout << "type of rotation is " << type << std::endl;
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
				NODE *temp_head = head;
				head = head->left;
				KEY temp_successor_key;
				while (head->right){
					head = head->right;
				}
				temp_successor_key = head->key;
				head->key = temp_head->key;
				temp_head->key = temp_successor_key;
				head = temp_head;
				std::cout << "check done " << std::endl;
				std::cout << " head key : " << head->key << " head left key : " << head->left->key << " head right key : " << head->right->key << std::endl;
			}
			
			void remove_node(NODE* &node, KEY key){
				if (node == NULL)
					return;
				std::cout << "enter with key " << node->key << "left_h : "<< node->left_h << "right_h : " << node->right_h<< std::endl;
				if (node->key < key)
					remove_node(node->right, key);
				else if (node->key > key)
					remove_node(node->left, key);
				else{
					if (node->left_h == 0 && node->right_h == 0){
						node_allocator.destroy(node);
						node_allocator.deallocate(node, 1);
						node = NULL;
					}
					else if (node->left_h == 0 || node->right_h == 0){
						NODE *temp = node->left ? node->left : node->right;
						temp->parent = node->parent;
						node_allocator.destroy(node);
						node_allocator.deallocate(node, 1);
						if (node->parent && node->parent->key < node->key){
							node->parent->right = temp;
						}
						else if (node->parent && node->parent->key > node->key){
							node->parent->left = temp;
						}
					}
					else if (node->left_h && node->right_h){
						swap_node_with_in_order_successor(node);
						remove_node(node->left, key);
					}
				}
				if (!node)
					return ;
				node->right_h = max_hight(node->right);
				node->left_h = max_hight(node->left);
				check_balance(node);
			}
			
			void print_node_info(NODE *head){
				if (!head){
					std::cout << "THIS NODE IS NULL " << std::endl;
					return ;
				}
				std::cout << "THE NODE HAS THE KEY " << head->key << " AND LEFT HIGHT " << head->left_h << " AND RIGHT HEIGHT " << head->right_h << std::endl;
				if (head->left)
					std::cout << "					THE LEFT KEY IS " << head->left->key;
				else
					std::cout << "					THE LEFT KEY IS NULL ";
				if (head->right)
					std::cout << "	THE RIGHT KEY IS " << head->right->key;
				else
					std::cout << "	THE RIGHT KEY IS NULL ";
				if (head->parent)
					std::cout << "		THE PARENT KEY IS " << head->parent->key << std::endl;
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
