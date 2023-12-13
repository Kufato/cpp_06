/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:15:20 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/23 14:22:13 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define _END		"\033[0m"
#define _BLACK		"\033[0;30m"
#define _RED		"\033[0;31m"
#define _GREEN		"\033[0;32m"
#define _YELLOW		"\033[0;33m"
#define _BLUE		"\033[0;34m"
#define _PURPLE		"\033[0;35m"
#define _CYAN		"\033[0;36m"

#include <iostream>
#include <stdint.h>

struct	Data {
		int	i;
};

class	Serializer {
	
	private:
	// Constructors
		Serializer(void);
		Serializer(const Serializer &toCopy);

	public:
	// Destructor
		~Serializer(void);

	// Overload operator
		Serializer &operator = (const Serializer &toCopy);

	// Public methods
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};
