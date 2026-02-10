/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:55 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/10 16:48:54 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
	
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
	
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
	
ScalarConverter::~ScalarConverter() {}

bool isDouble(const std::string& s) {
	std::istringstream iss(s);
	double d;
	char c;
	if (!(iss >> d))
		return false;
	if (iss >> c)
		return false;
	if (!s.empty() && s[s.length() - 1] == 'f')
        return false;
    return true;
}

ScalarConverter::type ScalarConverter::checkType(const std::string& string) {
	if (string.length() == 1 && !std::isdigit(string[0]))
		return CHAR;
	if (string == "nanf" || string == "+inff" || string == "-inff")
		return FLOAT_PSEUDO;
	if (string == "nan" || string == "+inf" || string == "-inf")
		return DOUBLE_PSEUDO;
	char lastChar = string[string.length() - 1];
	if (lastChar == 'f' && isDouble(string.substr(0, string.length() - 1)))
		return FLOAT;
	if (isDouble(string))
		return DOUBLE;
	return UNKNOWN;
}

void ScalarConverter::printResult(type type, char c, float f, double d, const std::string& s) {
	if (type == FLOAT_PSEUDO || type == DOUBLE_PSEUDO) {
		std::cout << "char: impossible" << std::endl;
	    std::cout << "int: impossible" << std::endl;
		if (type == FLOAT_PSEUDO) {
			std::cout << "float: " << s << std::endl;
    		std::cout << "double: " << s.substr(0, s.length() - 1) << std::endl;
		}
		else {
			std::cout << "float: " << s << "f" << std::endl;
    		std::cout << "double: " << s << std::endl;
		}
	}
	else if (type == UNKNOWN) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}	
	else {
		std::cout << "char: ";
		if (d < 0 || d > 127)
			std::cout << "impossible" << std::endl;
		else if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
    	if (d < INT_MIN || d > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;
    	std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
}

void ScalarConverter::convert(const std::string& string) {
	type detectedType = checkType(string);
	
	char c = 0;
	float f = 0.0f;
	double d = 0.0;
	
	switch (detectedType) {
		case CHAR:
			c = string[0];
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case FLOAT:
			f = static_cast<float>(std::atof(string.c_str()));
			c = static_cast<char>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = std::atof(string.c_str());
			c = static_cast<char>(d);
			f = static_cast<float>(d);
			break;
		default:
			break;
	}
	printResult(detectedType, c, f, d, string);
}
