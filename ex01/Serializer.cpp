/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:15:15 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/14 11:47:48 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// Constructor
Serializer::Serializer(void) {
	std::cout << "Serializer constructor called" << std::endl;
	return ;
}

Serializer::Serializer(const Serializer &toCopy) {
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
Serializer::~Serializer(void) {
	std::cout << "Serializer destructor called" << std::endl;
	return ;
}

// Overload operator
Serializer	&Serializer::operator=(const Serializer &toCopy) {
	if (this == &toCopy)
		return (*this);

	return (*this);
}

// Public methods
uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}