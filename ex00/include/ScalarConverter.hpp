/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:43 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/30 19:44:53 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter &other);
		~ScalarConverter();
		
		enum type {
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			FLOAT_PSEUDO,
			DOUBLE_PSEUDO,
			UNKNOWN
		};
		
		static type checkType(const std::string& string);
		static void printResult(type type, char c, int i, float f, double d, const std::string& s);

	public:
		static void convert(const std::string& string);
};

#endif
