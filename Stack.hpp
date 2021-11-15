#ifndef __STACK__
#define __STACK__
#include <Vector.hpp>
namespace ft
{
    template <class T, class Container = ft::Vector<T> > class stack;
    class  Stack
    {
        typedef T value_type;
        typedef Container container_type;
        typedef size_type size_t;
        explicit stack (const container_type& ctnr = container_type())
        {  
        } 
    }
}
#endif