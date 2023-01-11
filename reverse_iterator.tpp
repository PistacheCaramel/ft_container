#ifndef REVERSE_ITERATOR_TPP
# define REVERSE_ITERATOR_TPP

# include "reverse_iterator.hpp"
# include "iterator_traits.hpp"

namespace ft {

//				MEMBER FUNCTIONS			//
	
//	CONSTRUCTOR && DESTRUCTOR	//
template< class Iter >
						reverse_iterator<Iter>::reverse_iterator(): current()
						{

						}


template< class Iter >
						reverse_iterator<Iter>::reverse_iterator( iterator_type x ): current(x)
						{

						}

template< class Iter >
template< class U >
						reverse_iterator<Iter>::reverse_iterator( const reverse_iterator<U>& other ): current(other.base())
						{

						}

template< class Iter >
						reverse_iterator<Iter>::~reverse_iterator()
						{

						}

//	BASE GETTER	//
template< class Iter >
Iter						reverse_iterator<Iter>::base() const
						{
							return (current);
						}

//	OPERATOR OVERLOAD	//

template< class Iter >
typename ft::iterator_traits<Iter>::pointer	reverse_iterator<Iter>::operator->() const
						{
							return (addressof(operator*()));
						}

template< class Iter >
typename ft::iterator_traits<Iter>::reference	reverse_iterator<Iter>::operator[]( difference_type n ) const
						{
							return (base()[-n - 1]);
						}

template< class Iter >
reverse_iterator<Iter>&				reverse_iterator<Iter>::operator++()
						{
							--current;
							return (*this);
						}

template< class Iter >
reverse_iterator<Iter>&				reverse_iterator<Iter>::operator--()
						{
							++current;
							return (*this);
						}

template< class Iter >
reverse_iterator<Iter>				reverse_iterator<Iter>::operator++( int )
						{
							reverse_iterator	tmp(*this);

							current--;
							return (tmp);
						}

template< class Iter >
reverse_iterator<Iter>				reverse_iterator<Iter>::operator--( int )
						{
							reverse_iterator	tmp(*this);

							current++;
							return (tmp);
						}

template< class Iter >
reverse_iterator<Iter>				reverse_iterator<Iter>::operator+( difference_type n ) const
						{
							return (current - n);
						}

template< class Iter >
reverse_iterator<Iter>				reverse_iterator<Iter>::operator-( difference_type n) const
						{
							return (current + n);
						}

template< class Iter >
reverse_iterator<Iter>&				reverse_iterator<Iter>::operator+=( difference_type n )
						{
							current -= n;
							return (*this);
						}

template< class Iter >
reverse_iterator<Iter>&				reverse_iterator<Iter>::operator-=( difference_type n)
						{
							current += n;
							return (*this);
						}

//			NON-MEMBER FUNCTIONS 			//

template< class Iterator1, class Iterator2 >
bool 						operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 						const ft::reverse_iterator<Iterator2>& rhs )
						{
							return (lhs.base() == rhs.base());
						}

template< class Iterator1, class Iterator2 >
bool						operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 						const ft::reverse_iterator<Iterator2>& rhs )
						{
							return (lhs.base() != rhs.base());
						}

template< class Iterator1, class Iterator2 >
bool						operator<( const ft::reverse_iterator<Iterator1>& lhs,
                						const ft::reverse_iterator<Iterator2>& rhs )
						{
							return (lhs.base() > rhs.base());
						}

template< class Iterator1, class Iterator2 >
bool						operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 					const ft::reverse_iterator<Iterator2>& rhs )
						{
							return (lhs.base() >= rhs.base());
						}

template< class Iterator1, class Iterator2 >
bool						operator>( const ft::reverse_iterator<Iterator1>& lhs,
                					const ft::reverse_iterator<Iterator2>& rhs )
						{
							return (lhs.base() < rhs.base());
						}

template< class Iterator1, class Iterator2 >
bool						operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 						const ft::reverse_iterator<Iterator2>& rhs )
						{
							return (lhs.base() <= rhs.base());
						}

template< class Iter >
reverse_iterator<Iter>				operator+( typename reverse_iterator<Iter>::difference_type n,
               							const reverse_iterator<Iter>& it )
						{
							return (reverse_iterator<Iter>(it.base() - n));
						}

template< class Iterator1, class Iterator2 >
typename reverse_iterator<Iterator1>::difference_type	operator-( const reverse_iterator<Iterator1>& lhs,
               								const reverse_iterator<Iterator2>& rhs )
							{
								return (rhs.base() - lhs.base());
							}
}
#endif
