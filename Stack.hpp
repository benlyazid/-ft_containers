#ifndef __STACK__
#define __STACK__
#include "Vector.hpp"
namespace ft
{
    template <class T_CLASS, class Container_class = ft::Vector<T_CLASS> >
    class  Stack{
        public:
            typedef T_CLASS value_type;
            typedef Container_class container_type;
            typedef size_t size_type;
        protected:
            container_type c;
        public:
            explicit Stack (const container_type& ctnr = container_type()){
                c = ctnr;
            }
            size_type size() const{
                return (c.size());
            }
            void push (const value_type& val){
                c.push_back(val);
            }
            bool empty() const{
                return (c.empty());
            }
            value_type& top(){
                return (c.back());
            }
            const value_type& top() const{
                return (c.back());
            }
            void pop(){
                c.pop_back();
            }
            template <class T, class Container>
            friend bool operator== (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
                return (lhs.c == rhs.c); 
            }
            template <class T, class Container>
            friend bool operator!= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
                return (lhs.c != rhs.c); 
            }
            template <class T, class Container>
            friend bool operator< (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
                return (lhs.c < rhs.c); 
            }
            template <class T, class Container>
            friend bool operator<= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
                return (lhs.c <= rhs.c); 
            }
            template <class T, class Container>
            friend bool operator> (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
                return (lhs.c > rhs.c); 
            }
            template <class T, class Container>
            friend bool operator>= (const Stack<T,Container>& lhs, const Stack<T,Container>& rhs){
                return (lhs.c >= rhs.c); 
            }
    };
}
#endif