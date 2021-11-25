#ifndef AVL_H
#define AVL_H
namespace ft{

	template <class KEY, class T, class Compare = std::less<KEY>, class Allocator = std::allocator<std::pair<const KEY, T> > >
    class Avl{
		private:
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
				void insert(KEY key, T value, NODE* parent){
					this->key = key;
					this->value = value;
					this->left = NULL;
					this->parent = parent;
					this->right = NULL;
					this->right_h = 0;
					this->left_h = 0;
				}
			};
	
        public:
			typename Allocator::template rebind<NODE>::other node_allocator;
			Compare compare;
			NODE *node;
        public:
			Avl(KEY key, T value){
			}

			Avl(): node(NULL){}

			int	add_node(const KEY new_key, const T new_value, NODE* &head, const Compare comp = std::less<KEY>()){
				int update_height = 0;
				if (!head){
					std::cout << "insert in root key : " << new_key << std::endl;
					head = node_allocator.allocate(1);
					head->left_h = 0;
					head->right_h = 0;
					head->insert(new_key, new_value, NULL);
				}
			    else if(comp(head->key, new_key)){
			        if(!head->right){
						head->right_h++;
						std::cout << "insert in right of : " << head->key << "  key : " << new_key << std::endl;
						head->right = node_allocator.allocate(1);
						head->right_h = 1;
						head->right->insert(new_key, new_value, node);
						if (head->left_h == 0)
							update_height = 1;
			        }
				 	else{
						update_height = add_node(new_key, new_value, head->right, comp);
						head->right_h += update_height;
					}
			    }
				else{
					if(!head->left){
						head->left_h++;
						std::cout << "insert in left of : "  << head->key << "  key : " << new_key << std::endl;
						head->left = node_allocator.allocate(1);
						head->left->insert(new_key, new_value, head);
						if (head->right_h == 0)
							update_height = 1;
					}
				 	else{
						update_height = add_node(new_key, new_value, head->left, comp);
						head->left_h += update_height;
					}
				}
				if (abs(head->right_h - head->left_h) > 1){
					std::cout << "node with key " << head->key << " is not balanced With " << head->right_h << " in right and " << head->left_h << " in left ."  << std::endl;
					std::string type = type_of_rotation(head);
					// std::cout << "before balancing check for head with value " << head->key << " and right " << head->right->key << " and left " << head->left->key << std::endl;
					head = balance(head, type);
					std::cout << "after balncing check for head with value " << head->key << " and right " << head->right->key << " and left " << head->left->key << std::endl;
				}
				return update_height;
			}
			
			std::string	type_of_rotation(NODE *head){
				std::string type = "";
				if (head->right_h > head->left_h){
					type += "R";
					// if (head->right && head->right->right_h > head->right->left_h)
					if (head->right && head->right->right_h <= head->right->left_h)
						//type += "R";
					// else
						type += "L";
				}
				else{
					type += "L";
					if (head->left && head->left->right_h > head->left->left_h)
						type += "R";
					else
						type += "L";
				}
				std::cout << "type of rotation is " << type << std::endl;
				return (type);
			}
			
			NODE *balance(NODE *head, std::string type){
				NODE *new_node;
				if (type.length() == 1 && type == "L")
					new_node = right_rotation(head);
				else if  (type.length() == 1 && type == "R")
					new_node = left_rotation(head);
				else if (type.length() == 2 && type == "RL"){
					new_node = left_rotation(head->right);
					head->right = new_node;
					new_node = right_rotation(head);
				}
				else if (type.length() == 2 && type == "LR"){
					new_node = right_rotation(head->right);
					head->right = new_node;
					new_node = right_rotation(head);
				}
				return (new_node);

			}
			
			NODE *right_rotation(NODE *head){
				NODE *new_head;
				new_head = node_allocator.allocate(1);
				new_head->insert(head->left->key, head->left->value, head->parent);
				new_head->left = head->left->left;
				new_head->right = head;
				new_head->right->left = head->left->right;
				return (new_head);
			}
			NODE *left_rotation(NODE *head){
				
				NODE *new_head;
				new_head = node_allocator.allocate(1);
				new_head->insert(head->right->key, head->right->value, head->parent);
				new_head->right =  head->right->right;
				new_head->left = head;
				new_head->left->right = head->right->left;
				return (new_head);
			}
			void print_map(NODE *head)
			{
				if (!head)
					return;
				std::cout << " node with key " << head->key ;
				print_map(head->right);	
				print_map(head->left);
			}
    };
}
#endif