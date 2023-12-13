/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:21:07 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/23 14:28:56 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

Base	*generate(void) {
	std::srand(std::time(NULL));
	int	rand = std::rand() % 3;
	
	switch (rand) {
		case 0:
			return (new A);
			break;
		case 1:
			return (new B);
			break;
		case 2:
			return (new C);
			break;
		default:
			break;
	}
	return (NULL);
}

void	identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "The actual type of this object is A" << std::endl; 
	else if (dynamic_cast<B*>(p))
		std::cout << "The actual type of this object is B" << std::endl; 
	else if (dynamic_cast<C*>(p))
		std::cout << "The actual type of this object is C" << std::endl; 
	return ;
}

void	identify(Base &p) {
	try {
		Base	tmp = dynamic_cast<A&>(p);
		std::cout << "The actual type of this object is A" << std::endl; 
		return ;
	}
	catch (std::exception &exep) {}
	try {
		Base	tmp = dynamic_cast<B&>(p);
		std::cout << "The actual type of this object is B" << std::endl; 
		return ;
	}
	catch (std::exception &exep) {}
	try {
		Base	tmp = dynamic_cast<C&>(p);
		std::cout << "The actual type of this object is C" << std::endl; 
		return ;
	}
	catch (std::exception &exep) {}
	return ;
}

int	main(void) {
	Base	*obj = generate();
	
	identify(obj);
	identify(*obj);
	delete obj;
	return (0);
}