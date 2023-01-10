#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

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
					reverse_iterator(): current(){}
		explicit		reverse_iterator( iterator_type x ): current(x){}
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ): current(other.base()){}
					~reverse_iterator(){}
		iterator_type 		base() const {

			return (current);
		}
		template< class U >
		reverse_iterator& 	operator=( const reverse_iterator<U>& other ) {
			current = other.base();
			return (*this);
		}
		reference 		operator*() const {

			Iter	tmp;

			tmp = current;
			return (*--tmp);
		}
		pointer 		operator->() const {
			return (std::addressof(operator*()));
		}
		reference		operator[]( difference_type n ) const {
			return (base()[-n - 1]);
		}
		reverse_iterator&	operator++() {
			--current;
			return (*this);
		}
		reverse_iterator&	operator--() {
			++current;
			return (*this);
		}
		reverse_iterator	operator++( int ){
			reverse_iterator	tmp(*this);

			current--;
			return (tmp);
		}
		reverse_iterator	operator--( int ){
			reverse_iterator	tmp(*this);

			current++;
			return (tmp);
		}
		reverse_iterator	operator+( difference_type n ) const {
			return (current - n);
		}
		reverse_iterator	operator-( difference_type n ) const {
			return (current + n);
		}
		reverse_iterator&	operator+=( difference_type n ) {
			current-= n;
			return (*this);
		}
		reverse_iterator&	operator-=( difference_type n ) {
			current+= n;
			return (*this);
		}
	};

//                    NON-MEMBER FUNCTIONS                   //

	template< class Iterator1, class Iterator2 >
	bool 	operator==( const ft::reverse_iterator<Iterator1>& lhs,
                 	const ft::reverse_iterator<Iterator2>& rhs ){
		return (lhs.base() == rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() != rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() > rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() >= rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
                const ft::reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() < rhs.base());
	}
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
                 const ft::reverse_iterator<Iterator2>& rhs ) {
		return (lhs.base() <= rhs.base());
	}
	template< class Iter >
	reverse_iterator<Iter>
    		operator+( typename reverse_iterator<Iter>::difference_type n,
               		const reverse_iterator<Iter>& it ) {
			return (reverse_iterator<Iter>(it.base() - n));
		}
	template< class Iterator1, class Iterator2 >
	typename reverse_iterator<Iterator1>::difference_type
    		operator-( const reverse_iterator<Iterator1>& lhs,
               		const reverse_iterator<Iterator2>& rhs ) {
			return (rhs.base() - lhs.base());
	}
}

/* # include "reverse_iterator.tpp" */
#endif
