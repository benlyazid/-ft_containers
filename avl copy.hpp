#ifndef AVL_H
#define AVL_H
namespace ft{
	template <class KEY, class T, class Compare = std::less<KEY>, class Allocator = std::allocator<std::pair<const KEY, T> > >
    class Avl{
        private:
			Compare compare_function;
			Avl <KEY, T> *_left_child;
			Avl <KEY, T> *_right_child;
			Avl <KEY, T>	*_parent;
			Allocator alloc;
			std::allocator<Avl<KEY, T> > my_allocator;
			std::pair<KEY, T> pair;
        public:
			Avl(KEY key, T value){
				std::cout << "done\n";
				_left_child = NULL;
				_right_child = NULL;
				_parent = NULL;
				pair.first = key;
				pair.second = value;
			}
			Avl(){
				std::cout << "done0\n";

			}
			void add_node(KEY new_key, T new_value, const Compare& comp = Compare()){
			    if(comp(new_key, pair.first)){
			        if(!_left_child){
						_left_child = my_allocator.allocate(1);
						_left_child->_left_child = NULL;
						_left_child->_right_child = NULL;
						_left_child->_parent = this;
						_left_child->pair.first = new_key;
						_left_child->pair.second = new_value;
						std::cout << "parent value is "  << "for key " << _left_child->pair.first << std::endl;
						std::cout << "parent value is " << _parent->pair.first  << "for key " << _left_child->pair.first << std::endl;

			        }
					else
						_left_child->add_node(new_key, new_value, comp);
			    }
				else{
			        if(!_right_child){

						_right_child = my_allocator.allocate(1);
						_right_child->_left_child = NULL;
						_right_child->_right_child = NULL;
						_right_child->_parent = this;
						_right_child->pair.first = new_key;
						_right_child->pair.second = new_value;
						std::cout << "parent value is " << "for key " << _right_child->pair.first << std::endl;
						// std::cout << "parent value is " << _parent->pair.first  << "for key " << _right_child->pair.first << std::endl;
			        }
					else
						_right_child->add_node(new_key, new_value, comp);
				}
			}
			void print_node(){
				std::cout << "parent node >> " << pair.first << " left child >> " << _left_child->pair.first << " right child >> " << _right_child->pair.first << std::endl;
			}
    };
}
#endif