/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:30:07 by kmaeda            #+#    #+#             */
/*   Updated: 2026/01/31 12:41:39 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}*/

#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(void)
{
    const std::string tests[] = {
        "a",
        "\n",
        "42",
        "7",
        "42.5f",
        "42.5",
        "42.0f",
        "42.0",
        "nan",
        "nanf",
        "+inf",
        "-inff",
        "2147483648",
        "hello",
        "9"
    };

    const int testCount = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < testCount; i++)
    {
        std::cout << "==============================" << std::endl;
        std::cout << "Input: " << tests[i] << std::endl;
        std::cout << std::endl;

        ScalarConverter::convert(tests[i]);

        std::cout << "==============================" << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
