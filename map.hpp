#ifndef MAP_H
#define MAP_H
#include "avl.hpp"
#include "bidirectional_iterator.hpp"

namespace ft{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
	class map{
		public:
			typedef				Key 																	key_type;
			typedef				T																		mapped_type;
			typedef				pair<const key_type, mapped_type>										value_type;
			typedef				Compare																	key_compare;
			typedef				Alloc																	allocator_type;
			typedef				size_t																	size_type;
			typedef				ptrdiff_t																difference_type;
			typedef typename 	allocator_type::reference												reference;
			typedef typename 	allocator_type::const_reference											const_reference;
			typedef typename 	allocator_type::pointer													pointer;
			typedef typename 	allocator_type::const_pointer											const_pointer;
			typedef 			bidirectional_iterator< ft::Avl<key_type, mapped_type> >				iterator;
			typedef 			bidirectional_iterator< const ft::Avl<key_type, mapped_type> >			const_iterator;
			// 	typedef	**********															value_compare;
			//	typedef ***********															reverse_iterator
			//	typedef ***********															const_reverse_iterator
		private:
			typedef typename 	Avl<key_type, mapped_type>::NODE										nood_t;
		public:
		/******************************CONATRUCTORS**************************************/
			
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				_key_compare = comp;
				_allocator = alloc;
				_my_tree.node = NULL;	
				_exist = 0;
			}

			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()){
				_key_compare = comp;
				_allocator = alloc;
				_my_tree.node = NULL;
				while(first != last){
					_my_tree.add_node(*(first).first, *(first).second, _my_tree.node, comp);
					first++;
				}
				_exist = 0;
			}
			map (const map& map_x){
				*this = map_x;
			}
			~map(){
				this->clear();
			}
			map& operator= (const map& x_map){
				if (!_exist && this == &x_map)
					return *this ;
				if (!_exist){
					this->clear();
					std::cout<< "end of clear " << std::endl;

				}
				else
					this->_my_tree.node = NULL;
				this->_key_compare = x_map._key_compare;
				this->_allocator = x_map._allocator;
				this->insert(x_map.begin(), x_map.end());
				//	this->_the_last_node = 
				return *this;
			}

 			/*********************************Iterators:*******************************/
			
			iterator begin(){
				typename ft::Avl<key_type, mapped_type>::NODE *temp = _my_tree.node->get_the_smallest_one(_my_tree.node);
				return iterator(&_my_tree, temp);
			}

			const_iterator begin() const{
				typename ft::Avl<key_type, mapped_type>::NODE *temp = _my_tree.node->get_the_smallest_one(_my_tree.node);
				return const_iterator(&_my_tree, temp);

			}

			iterator end(){
				return iterator(&_my_tree, _my_tree.the_last_node);
			}

			const_iterator end() const{
				return const_iterator(&_my_tree, _my_tree.the_last_node);
			}
			
 			/*************************************Capacity:******************************/
			 
			bool empty() const{
				return (_my_tree.avl_size == 0);
			}

			size_type size() const{
				return (_my_tree.avl_size);
			}
			size_type max_size() const{
				_allocator.max_size();
			}
		
			/********************************* Element access:****************************/
	
			mapped_type& operator[] (const key_type& k){
				nood_t	*node_finded = _my_tree.node->find_node(_my_tree.node, k);
				return node_finded->value;
			}
		
			/********************************* Modifiers:**********************************/

			pair<iterator,bool> insert (const value_type& val){
				pair<nood_t*, bool> pair_to_return = _my_tree.add_node(val.first, val.second, _my_tree.node);
				return (ft::make_pair(iterator(&_my_tree, pair_to_return.first), pair_to_return.second));
			}

			iterator insert (iterator position, const value_type& val){
				(void)(position);
				pair<nood_t*, bool> pair_to_return = _my_tree.add_node(val.first, val.second, _my_tree.node);
				iterator(&_my_tree, pair_to_return.first);
			}

			template <class InputIterator>
			void insert (InputIterator it_first, InputIterator it_last){
				while(it_first != it_last){
					_my_tree.add_node(it_first->first, it_first->second, _my_tree.node);
					it_first++;
				}
			}

			void erase (iterator position){
				_my_tree.remove_node(_my_tree.node, position->first);
			}

			size_type erase (const key_type& k){
				size_type return_value = 1;
				if (_my_tree.node->find_node(_my_tree.node, k) == NULL)
					return_value = 0;
				_my_tree.remove_node(_my_tree.node, k);
				return (return_value);
			}


			void erase (iterator first_it, iterator last){
				ft::Vector<key_type> key_to_remove;
				while (first_it != last)
				{
					key_to_remove.push_back(first_it->first);
					first_it++;
				}
				for (size_t i = 0; i < key_to_remove.size(); i++)
				{
					_my_tree.remove_node(_my_tree.node, key_to_remove[i]);
				}
			}

			void swap (map& x_map){
				std::swap(x_map._my_tree, this->_my_tree);
				std::swap(x_map._key_compare, this->_key_compare);
				std::swap(x_map._allocator, this->_allocator);
			}

			void clear(){
				erase(this->begin(), this->end());
			}
			/*********************************  Observers:**********************************/
			/*********************************  Operations:**********************************/
			/*********************************  Allocator::**********************************/



		private:
			Avl<key_type, mapped_type> _my_tree;
			key_compare		_key_compare;
			allocator_type	_allocator;
			bool			_exist;
	};

};

#endif