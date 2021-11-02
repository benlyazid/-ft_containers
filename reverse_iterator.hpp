#ifndef __R_iter
#define __R_iter
#include "iterator.hpp"
namespace ft
{
	template <class Iterator_>
	class reverse_iterator : public Iterator<typename Iterator_::iterator_category, typename Iterator_::value_type>
	{
		public:
			typedef 			Iterator_ iterator_type;
			typedef typename	Iterator_::iterator_category iterator_category;
			typedef typename 	Iterator_::value_type value_type;
			typedef typename 	Iterator_::difference_type difference_type;
			typedef typename 	Iterator_::pointer pointer;
			typedef typename 	Iterator_::reference reference;
			typedef reverse_iterator <Iterator <typename Iterator_::iterator_category, const typename Iterator_::value_type> > const_reverse_iterator;

			reverse_iterator()
			{

			}

			explicit reverse_iterator (iterator_type it)
			{
				this->ptr = &(*it);
			}

			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it)
			{
				*this = rev_it;
			}

			
			operator const_reverse_iterator()
			{
				return const_reverse_iterator(this->ptr);
			}
	};
};

#endif