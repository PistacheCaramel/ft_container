#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {
	
	template< class Iter >
	class reverse_iterator {

	public:
		typedef typename Iter						iterator_type;		
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type		value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type	difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer		pointer;
		typedef typename ft::iterator_traits<Iter>::reference		reference;

	private:
		iterator_type	_x;

	public:
					reverse_iterator(): _x(){}
		explicit		reverse_iterator( iterator_type x ): _x(x){}
		template< class U >
					reverse_iterator( const reverse_iterator<U>& other ): _x(other.base()){}
		iterator_type 		base() const {
			return (_x);
		}
		reverse_iterator& 	operator=( const reverse_iterator<U>& other ) {
			return (*this);
		}
		reference 		operator*() const {

			Iter	tmp;

			tmp = this;
			return (*--tmp);
		}
		pointer 		operator->() const {
			return (std::addressof(operator*()));
		}
		reference		operator[]( difference_type n ) const {
			return (base()[-n - 1]);
		}
		reverse_iterator&	operator++(){
			;
		reverse_iterator&	operator--();
		reverse_iterator	operator++( int );
		reverse_iterator	operator--( int );
		reverse_iterator	operator+( difference_type n ) const;
		reverse_iterator	operator-( difference_type n ) const;
		reverse_iterator&	operator+=( difference_type n );
		reverse_iterator&	operator-=( difference_type n );
	}
}

# include "reverse_iterator.tpp"
#endif
