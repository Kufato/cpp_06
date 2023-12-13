/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:54:42 by axcallet          #+#    #+#             */
/*   Updated: 2023/11/27 11:20:27 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructor
ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter constructor called" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &toCopy) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = toCopy;
	return ;
}

// Destructor
ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter destructor called" << std::endl;
	return ;
}

// Overload operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &toCopy) {
	if (this == &toCopy)
		return (*this);
	// nothing to copy
	return (*this);
}

// Util
bool	checkFloat(const std::string arg) {
	int	i = 0;
	while (arg[i] != 'f')
		i++;
	if (arg[i + 1] != '\0') {
		std::cout << _RED << "Bad format for float" << _END << std::endl;
		return (false);
	}
	i--;
	if (arg[i] == '.') {
		std::cout << _RED << "Bad format for float" << _END << std::endl;
		return (false);
	}
	while (arg[i] != '.' && i >= 0) {
		if (!std::isdigit(arg[i])) {
			std::cout << _RED << "Bad format for float" << _END << std::endl;
			return (false);
		}
		i--;
	}
	if (arg[i] != '.') {
		std::cout << _RED << "Bad format for float" << _END << std::endl;
		return (false);
	}
	return (true);
}

// ############################################ Converters from int ############################################
static void	intToChar(long long intResult) {
	if (intResult < 0 || intResult > 127) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (intResult < 32 || intResult > 126) {
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(intResult) << "'" << std::endl;
	return ;
}

static void	intToInt(long long intResult) {
	if (intResult < -2147483648 || intResult > 2147483647)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intResult << std::endl;
	return ;
}

static void	intToFloat(long long intResult) {
	if ((float)intResult < -std::numeric_limits<float>::max() || (float)intResult > std::numeric_limits<float>::max()) {
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (intResult - intResult != 0 || intResult >= 1000000 || intResult <= -1000000)
		std::cout << "float: " << static_cast<float>(intResult) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(intResult) << ".0f" << std::endl;
	return ;
}

static void	intToDouble(long long intResult) {
	if ((double)intResult < -std::numeric_limits<double>::max() || (double)intResult > std::numeric_limits<double>::max()) {
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (intResult - intResult != 0 || intResult >= 1000000 || intResult <= -1000000)
		std::cout << "double: " << static_cast<double>(intResult) << std::endl;
	else
		std::cout << "double: " << static_cast<double>(intResult) << ".0" << std::endl;
	return ;
}

// ############################################ Converters from double ############################################
static void	doubleToChar(double doubleResult) {
	if (doubleResult < 0.0 || doubleResult > 127.0) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (doubleResult < 32.0 || doubleResult > 126.0) {
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(doubleResult) << "'" << std::endl;
	return ;
}

static void	doubleToInt(double doubleResult) {
	if (doubleResult < -2147483648.0 || doubleResult > 2147483647.0) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(doubleResult) << std::endl;
	return ;
}

static void	doubleToFloat(double doubleResult) {
	if ((float)doubleResult == 0.0f || ((float)doubleResult < -std::numeric_limits<float>::min() || (float)doubleResult > std::numeric_limits<float>::max())) {
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	if (doubleResult - (int)doubleResult != 0)
		std::cout << "float: " << static_cast<float>(doubleResult) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(doubleResult) << ".0f" << std::endl;
	return ;
}

static void	doubleToDouble(double doubleResult) {
	if (doubleResult <= 1e-309 && doubleResult > 0) {	
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (doubleResult - (int)doubleResult != 0)
		std::cout << "double: " << doubleResult << std::endl;
	else
		std::cout << "double: " << doubleResult << ".0" << std::endl;
	return ;
}

// ############################################ Converters from float ############################################
static void	floatToChar(float floatResult) {
	if (floatResult < 0.0f || floatResult > 127.0f) {
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (floatResult < 32.0f || floatResult > 126.0f) {
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(floatResult) << "'" << std::endl;
	return ;
}

static void	floatToInt(float floatResult) {
	if (floatResult < -2147483648.0f || floatResult > 2147483647.0f) {
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(floatResult) << std::endl;
	return ;
}

static void	floatToFloat(float floatResult) {
	if (floatResult <= 1e-39f && floatResult > 0) {
		std::cout << "float: impossible" << std::endl;
		return ;
	}
	std::cout << "float: " << floatResult << std::flush;
	if (floatResult - (int)floatResult != 0)
		std::cout << "f" << std::endl;
	else
		std::cout << ".0f" << std::endl;
	return ;
}

static void	floatToDouble(float floatResult) {
	if ((double)floatResult < -std::numeric_limits<double>::max() || (double)floatResult > std::numeric_limits<double>::max()) {
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (floatResult - (int)floatResult != 0)
		std::cout << "double: " << static_cast<double>(floatResult) << std::endl;
	else
		std::cout << "double: " << static_cast<double>(floatResult) << ".0" << std::endl;
	return ;
}

// ############################################ Converter function ############################################
void	ScalarConverter::convert(const std::string &arg) {
	char *endPtr;

	if (arg == "+inff" || arg == "+inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	if (arg == "-inff" || arg == "-inf") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return ;
	}
	if (arg == "nanf" || arg == "nan") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	if (arg.size() == 1 && !std::isdigit(arg[0])) {
		if (arg[0] < 0 || arg[0] > 127)
			std::cout << "char: impossible" << std::endl;
		else if (arg[0] < 32 || arg[0] > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << arg[0] << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(arg[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<float>(arg[0]) << ".0" << std::endl;
		return ;
	}
	long long intResult = std::strtoll(arg.c_str(), &endPtr, 10);
	if (*endPtr == '\0') {
		intToChar(intResult);
		intToInt(intResult);
		intToFloat(intResult);
		intToDouble(intResult);
		return ;
	}
	double doubleResult = std::strtod(arg.c_str(), &endPtr);
	if (*endPtr == '\0') {
		if (arg[arg.size() - 1] == '.') {
			std::cout << _RED << "Bad format" << _END << std::endl;
			return ;
		}
		doubleToChar(doubleResult);
		doubleToInt(doubleResult);
		doubleToFloat(doubleResult);
		doubleToDouble(doubleResult);
		return ;
	}
	float floatResult = static_cast<float>(std::strtod(arg.c_str(), &endPtr));
	if (*endPtr == 'f' && arg[0] != 'f') {
		if (!checkFloat(arg))
			return ;
		floatToChar(floatResult);
		floatToInt(floatResult);
		floatToFloat(floatResult);
		floatToDouble(floatResult);
		return ;
	}
	std::cerr << _RED << "Sorry but I can't convert this" << _END << std::endl;
	return ;
}