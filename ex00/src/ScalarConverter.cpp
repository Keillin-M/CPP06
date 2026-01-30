/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:55 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/30 19:45:41 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <string>
#include <sstream>
#include <cctype>

ScalarConverter::ScalarConverter() {}
	
ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}
	
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	(void)other;
	return *this;
}
	
ScalarConverter::~ScalarConverter() {}

bool isInt(const std::string& s) {
	std::istringstream iss(s);
	int i;
	char c;
	if (!(iss >> i))
		return false;
	if (iss >> c)
		return false;
	return true;
}

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
	if (string.length() == 3)
		return CHAR;
	if (string == "nanf" || string == "+inff" || string == "-inff")
		return FLOAT_PSEUDO;
	if (string == "nan" || string == "+inf" || string == "-inf")
		return DOUBLE_PSEUDO;
	char lastChar = string[string.length() - 1];
	if (lastChar == 'f' && isDouble(string.substr(0, string.length() - 1)))
		return FLOAT;
	if (isInt(string))
		return INT;
	if (isDouble(string))
		return DOUBLE;
	return UNKNOWN;
}

void ScalarConverter::printResult(type type, char c, int i, float f, double d, const std::string& s) {
	switch (type) {
		case CHAR:
			std::cout << "char: ";
			if (std::isprint(c))
				std::cout << "'" << c << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
    		std::cout << "int: " << i << std::endl;
    		std::cout << "float: " << f << ".0f" << std::endl;
    		std::cout << "double: " << d << ".0" << std::endl;
			break;
		case INT:
			i = std::atoi(string.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case FLOAT:
			f = static_cast<float>(std::atof(string.c_str()));
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = std::atof(string.c_str());
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		case FLOAT_PSEUDO:
			std::cout << "char: impossible" << std::endl;
	    	std::cout << "int: impossible" << std::endl;
    		std::cout << "float: " << string << std::endl;
    		std::cout << "double: " << string.substr(0, string.length() - 1) << std::endl;
    		break;
		case DOUBLE_PSEUDO:
			std::cout << "char: impossible" << std::endl;
    		std::cout << "int: impossible" << std::endl;
    		std::cout << "float: " << string << "f" << std::endl;
    		std::cout << "double: " << string << std::endl;
			break;
		default:
			break;
}

void ScalarConverter::convert(const std::string& string) {
	type detectedType = checkType(string);
	
	char c;
	int i;
	float f;
	double d;
	
	switch (detectedType) {
		case CHAR:
			c = string[1];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			std::cout << "char: ";
			if (std::isprint(c))
				std::cout << "'" << c << "'" << std::endl;
			else
				std::cout << "Non displayable" << std::endl;
    		std::cout << "int: " << i << std::endl;
    		std::cout << "float: " << f << ".0f" << std::endl;
    		std::cout << "double: " << d << ".0" << std::endl;
			break;
		case INT:
			i = std::atoi(string.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case FLOAT:
			f = static_cast<float>(std::atof(string.c_str()));
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = std::atof(string.c_str());
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		case FLOAT_PSEUDO:
			std::cout << "char: impossible" << std::endl;
	    	std::cout << "int: impossible" << std::endl;
    		std::cout << "float: " << string << std::endl;
    		std::cout << "double: " << string.substr(0, string.length() - 1) << std::endl;
    		break;
		case DOUBLE_PSEUDO:
			std::cout << "char: impossible" << std::endl;
    		std::cout << "int: impossible" << std::endl;
    		std::cout << "float: " << string << "f" << std::endl;
    		std::cout << "double: " << string << std::endl;
			break;
		default:
			break;
		printResult(detectedType, c, i, f, d, string);
	}
}
