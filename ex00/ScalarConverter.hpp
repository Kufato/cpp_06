/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:51 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/22 14:30:07 by axcallet         ###   ########.fr       */
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

#include <limits>
#include <cstdlib>
#include <iostream>

class	ScalarConverter {
	
	private:
	// Constructors
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &toCopy);

	public:
	// Destructor
		~ScalarConverter(void);

	// Overload operator
		ScalarConverter &operator=(const ScalarConverter &toCopy);

	// Public method
		static void	convert(const std::string &arg);
};
