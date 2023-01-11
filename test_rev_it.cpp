#include "ft_container.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "reverse_iterator.tpp"
#include <iterator>
#include <list>
#include <iostream>
#include <typeinfo>
#include <vector>

void	reverse_iterator_testing(void)
{
	std::vector<int> vector;
	vector.push_back(1);
	vector.push_back(3);
	vector.push_back(2);
	vector.push_back(7);
	vector.push_back(0);
	vector.push_back(8);

	std::vector<int>::iterator it = vector.end();

	ft::reverse_iterator<std::vector<int>::iterator> rit (it);
	std::reverse_iterator<std::vector<int>::iterator> ritt (it);
	std::cout << *rit << ";" << *ritt << std::endl;
	
	++rit;
	++ritt;
	std::cout << *rit << ";" << *ritt << std::endl;
	rit++;
	ritt++;
	std::cout << *rit << ";" << *ritt << std::endl;
	{
		ft::reverse_iterator<std::vector<int>::iterator> irit (it);
		std::cout << *rit << ";" << *irit << std::endl;
		irit = rit;
		std::cout << *rit << ";" << *irit << std::endl;

	}
	std::cout << *(rit.base()) << ";" << *(ritt.base()) << std::endl;
	std::vector<int>::iterator i = rit.base();
	std::vector<int>::iterator ii = ritt.base();
	std::cout << *i<< ";" << *ii << std::endl;


	--rit;
	--ritt;
	std::cout << *rit << ";" << *ritt << std::endl;
	rit--;
	ritt--;
	std::cout << *rit << ";" << *ritt << std::endl;
	std::cout << rit[4] << ";" << ritt[4] << std::endl;
	
	rit += 2;
	ritt += 2;
	std::cout << *rit - 1 << ";" << *ritt - 1 << std::endl;
	rit -= 1;
	ritt -= 1;
	std::cout << *rit + 1 << ";" << *ritt + 1 << std::endl;
	ft::reverse_iterator<std::vector<int>::iterator> rerit = rit;
	if (rit == rerit)
		std::cout << 0 << std::endl;
	if (rit != rerit)
		std::cout << 1 << std::endl;
	if (rit <= rerit)
	std::cout << 2 << std::endl;
	if (rit >= rerit)
	std::cout << 3 << std::endl;
	if (rit < rerit)
	std::cout << 4 << std::endl;
	if (rit > rerit)
	std::cout << 5 << std::endl;

	std::reverse_iterator<std::vector<int>::iterator> reritt = ritt;
	if (ritt == reritt)
		std::cout << 0 << std::endl;
	if (ritt != reritt)
		std::cout << 1 << std::endl;
	if (ritt <= reritt)
	std::cout << 2 << std::endl;
	if (ritt >= reritt)
	std::cout << 3 << std::endl;
	if (ritt < reritt)
	std::cout << 4 << std::endl;
	if (ritt > reritt)
	std::cout << 5 << std::endl;
}

int	main()
{
	reverse_iterator_testing();
}
