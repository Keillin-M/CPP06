/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:43 by kmaeda            #+#    #+#             */
/*   Updated: 2026/03/26 13:31:13 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <iomanip>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();
		
		enum type {
			CHAR,
			FLOAT,
			DOUBLE,
			FLOAT_PSEUDO,
			DOUBLE_PSEUDO,
			UNKNOWN
		};
		
		static type checkType(const std::string& string);
		static void printPseudo(type type, const std::string& s);
		static void printResult(type type, char c, float f, double d);

	public:
		static void convert(const std::string& string);
};

#endif
