#ifndef MAP_H
#define MAP_H
#include "avl.hpp"
#include "./Vector.hpp"
#include "bidirectional_iterator.hpp"

namespace ft{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > > 
	class map{
		public:
			typedef				Key 																								key_type;
			typedef				T																									mapped_type;
			typedef				pair<const key_type, mapped_type>																	value_type;
			typedef				Compare																								key_compare;
			typedef				Alloc																								allocator_type;
			typedef				size_t																								size_type;
			typedef				ptrdiff_t																							difference_type;
			typedef typename 	allocator_type::reference																			reference;
			typedef typename 	allocator_type::const_reference																		const_reference;
			typedef typename 	allocator_type::pointer																				pointer;
			typedef typename 	allocator_type::const_pointer																		const_pointer;
			typedef 			bidirectional_iterator< ft::Avl<key_type, mapped_type, key_compare>, pair< key_type, mapped_type> >				iterator;
			typedef 			bidirectional_iterator< const ft::Avl<key_type, mapped_type, key_compare>, const pair< key_type, mapped_type> >	const_iterator;
			typedef 			ft::reverse_iterator<iterator>																		reverse_iterator;
			typedef 			ft::reverse_iterator<const_iterator>																const_reverse_iterator;
			// 	typedef	**********															value_compare;
		private:
			typedef typename 	Avl<key_type, mapped_type, key_compare>::NODE													nood_t;
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
					_my_tree.add_node(first->first, first->second, _my_tree.node);
					first++;
				}
				_exist = 0;
			}
			map (const map& map_x){
				_exist = 1;
				*this = map_x;
			}
			~map(){
				// std::cout << "Destructor " << std::endl;
				if (this->_my_tree.node)
					this->clear();
			}
			map& operator= (const map& x_map){
				if (!_exist && this == &x_map)
					return *this ;
				if (!_exist && _my_tree.avl_size){
					this->clear();
				}
				else
					this->_my_tree.node = NULL;

				this->_key_compare = x_map._key_compare;
				this->_allocator = x_map._allocator;
				if (x_map._my_tree.node)
					this->insert(x_map.begin(), x_map.end());
				return *this;
			}

 			/*********************************Iterators:*******************************/
			
			iterator begin(){
				typename ft::Avl<key_type, mapped_type, key_compare>::NODE *temp;
				if (_my_tree.avl_size == 0)
					temp = _my_tree.the_last_node;
				else
					temp = _my_tree.node->get_the_smallest_one(_my_tree.node);
				return iterator(&_my_tree, temp);
			}

			const_iterator begin() const{
				typename ft::Avl<key_type, mapped_type, key_compare>::NODE *temp;
				if (_my_tree.avl_size == 0)
					temp = _my_tree.the_last_node;
				else
					temp = _my_tree.node->get_the_smallest_one(_my_tree.node);
				return const_iterator(&_my_tree, temp);
			}

			iterator end(){
					typename ft::Avl<key_type, mapped_type, key_compare>::NODE *temp = _my_tree.the_last_node;
				return iterator(&_my_tree, temp);
			}

			const_iterator end() const{
					typename ft::Avl<key_type, mapped_type, key_compare>::NODE *temp = _my_tree.the_last_node;
				return const_iterator(&_my_tree, temp);
			}

			reverse_iterator rbegin(){
				return reverse_iterator(this->end());
			}

			const_reverse_iterator rbegin() const {

				return const_reverse_iterator(this->end());		
			}
			reverse_iterator rend(){
				return reverse_iterator(this->begin());

			}
			const_reverse_iterator rend() const{
				return const_reverse_iterator(this->begin());
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
				if (node_finded)
					return node_finded->node_pair.second;
				pair<nood_t*, bool> pair_to_return = _my_tree.add_node(k, mapped_type(), _my_tree.node);
				return (pair_to_return.first->node_pair.second);
			}
		
			/********************************* Modifiers:**********************************/

			pair<iterator,bool> insert (const value_type& val){
				pair<nood_t*, bool> pair_to_return = _my_tree.add_node(val.first, val.second, _my_tree.node);
				return (ft::make_pair(iterator(&_my_tree, pair_to_return.first), pair_to_return.second));
			}

			iterator insert (iterator position, const value_type& val){
				(void)(position);
				pair<nood_t*, bool> pair_to_return = _my_tree.add_node(val.first, val.second, _my_tree.node);
				return iterator(&_my_tree, pair_to_return.first);
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
				std::swap(x_map._exist, this->_exist);
			}

			void clear(){
				erase(this->begin(), this->end());
			}
			/*********************************  Observers:**********************************/
			/*********************************  Operations:**********************************/
			iterator lower_bound (const key_type& k){
				nood_t *temp =  _my_tree.lower_bound(_my_tree.node->get_the_smallest_one(_my_tree.node), k);
				if (!temp)
					return (end());
				return iterator(&_my_tree, temp);
			}

			const_iterator lower_bound (const key_type& k) const{
				// nood_t	*node_finded = _my_tree.node->find_node(_my_tree.node, k);

				nood_t 	*node_finded =  _my_tree.lower_bound(_my_tree.node->get_the_smallest_one(_my_tree.node), k);
				if (!node_finded)
					return (this->end());
				//you should correct this function
				return const_iterator(&_my_tree, node_finded);
			}

			//corect the return that should be the last node if we didnt find nothing
			iterator find (const key_type& k){
				nood_t	*node_finded = _my_tree.node->find_node(_my_tree.node, k);
				if (node_finded == NULL)
					node_finded = _my_tree.the_last_node;
				return(iterator(&_my_tree, node_finded));
			}

			const_iterator find (const key_type& k) const{
				nood_t	*node_finded = _my_tree.node->find_node(_my_tree.node, k);
				if (node_finded == NULL)
					node_finded = _my_tree.the_last_node;
				return(const_iterator(&_my_tree, node_finded));
			}

			size_type count (const key_type& k) const{
				nood_t	*node_finded = _my_tree.node->find_node(_my_tree.node, k);
				if (!node_finded)
					return (0);
				return (1);
			}
			/*********************************  Allocator::**********************************/
			void printing(){
				_my_tree.print_node_info(_my_tree.node);
			}


		private:
			key_compare		_key_compare;
			allocator_type	_allocator;
			bool			_exist;
			Avl<key_type, mapped_type, key_compare> _my_tree;
	};

};
#endif