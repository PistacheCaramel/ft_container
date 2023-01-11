#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <memory>
# include "iterator_traits.hpp"

namespace ft {
	
	template< class Iter >
	class reverse_iterator {

	public:
		typedef Iter							iterator_type;		
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type		value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer		pointer;
		typedef typename ft::iterator_traits<Iter>::reference		reference;

	protected:
		Iter	current;

//                 MEMBER FONCTIONS                  //

	public:
					reverse_iterator();
		explicit		reverse_iterator( iterator_type x );
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other );
					~reverse_iterator();

		iterator_type 		base() const;

		template< class U >
		reverse_iterator& 	operator=( const reverse_iterator<U>& other );
		reference 		operator*() const;
		pointer 		operator->() const;
		reference		operator[]( difference_type n ) const;
		reverse_iterator&	operator++();
		reverse_iterator&	operator--();
		reverse_iterator	operator++( int );
		reverse_iterator	operator--( int );
		reverse_iterator	operator+( difference_type n ) const;
		reverse_iterator	operator-( difference_type n ) const;
		reverse_iterator&	operator+=( difference_type n );
		reverse_iterator&	operator-=( difference_type n ); 
	};

//                    NON-MEMBER FUNCTIONS                   //

	template< class Iterator1, class Iterator2 >
	bool 	operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 	const ft::reverse_iterator<Iterator2>& rhs );

	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ); 

	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs ); 

	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ); 

	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs );

	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs );

	template< class Iter >
	reverse_iterator<Iter>
    		operator+( typename reverse_iterator<Iter>::difference_type n,
               		const reverse_iterator<Iter>& it );

	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type
    		operator-( const reverse_iterator<Iterator1>& lhs,
               		const reverse_iterator<Iterator2>& rhs );
}

 # include "reverse_iterator.tpp"
#endif
