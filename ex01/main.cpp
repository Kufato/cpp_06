/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:46:41 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/23 14:26:07 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data		*data = new Data;
	uintptr_t	dataTmp;

	std::cout << "\nRaw :\t\t\t" << data << std::endl;
	dataTmp = Serializer::serialize(data);
	std::cout << "After serializer :\t" << _RED << dataTmp << _END << std::endl;
	std::cout << "After deserialize :\t" << _YELLOW << Serializer::deserialize(dataTmp) << _END << std::endl;
	std::cout << std::endl;
	delete data;
	return (0);
}