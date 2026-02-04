/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:53:32 by kmaeda            #+#    #+#             */
/*   Updated: 2026/02/04 20:30:57 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"
#include "../include/Data.hpp"

int main() {
    Data d;
    d.value = 42;

    uintptr_t raw = Serializer::serialize(&d);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << &d << std::endl;
    std::cout << "Serialized: " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;
    std::cout << "Match: " << (ptr == &d ? "YES" : "NO") << std::endl;
}
