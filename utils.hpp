#ifndef __UTILS__
#define __UTILS__
//#include "Vector.hpp"

namespace ft{

	template<bool B, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };
	/*----------------------------------------------*/
	template<class T, class U=void>
	struct is_integral
	{
		static const bool value = false;
	};

	template<class T>
	struct is_integral<int, T>
	{
		static const bool value = true;
	};

	template<class T>
	struct is_integral<long long, T>
	{
		static const bool value = true;
	};

	template<class T>
	struct is_integral<short, T>
	{
		static const bool value = true;
	};


	template<class T>
	struct is_integral<long, T>
	{
		static const bool value = true;
	};

	template<class T>
	struct is_integral<char, T>
	{
		static const bool value = true;
	};

	template<class T>
	struct is_integral<unsigned long, T>
	{
		static const bool value = true;
	};
	/********************************************/
	template <class T1, class T2> 
	struct pair{
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		pair(): first(first_type()), second(second_type()){
			// std::cout << "pair used\n";
			// fflush(stdout);
		}
		
		template<class U, class V> pair (const pair<U,V>& pr): first(pr.first), second(pr.second){
		}

		pair (const first_type& a, const second_type& b){
			this->first = a;
			this->second = b;
		}
		pair& operator= (const pair& pr){
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}

	};
	/*************************************************/

	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y){
    	return ( pair<T1,T2>(x,y) );
  	}

	/*************************************************/
	template <class T1, class T2>
  	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
  	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs == rhs); 
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){ 
		return !(rhs<lhs); 
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (rhs<lhs);
	}

	template <class T1, class T2>
  	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs<rhs); 
	}


	template <class Iterator> 
	struct iterator_traits{
		typedef typename  Iterator::difference_type		difference_type;
		typedef typename  Iterator::value_type			value_type;
		typedef typename  Iterator::pointer				pointer;
		typedef typename  Iterator::reference			reference;
		typedef typename  Iterator::iterator_category	iterator_category;
	};

	template <class T> 
	struct iterator_traits<T*>{
		typedef ptrdiff_t	difference_type;	
		typedef T			value_type	;		
		typedef T*			pointer		;		
		typedef T&			reference	;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T> 
	struct iterator_traits<const T*>{
		typedef ptrdiff_t	difference_type;	
		typedef T			value_type	;		
		typedef const T*			pointer		;		
		typedef const T&			reference	;
		typedef std::random_access_iterator_tag iterator_category;
	};
};
#endif
