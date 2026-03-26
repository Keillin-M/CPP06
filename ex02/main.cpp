/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmaeda <kmaeda@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:21:36 by kmaeda            #+#    #+#             */
/*   Updated: 2026/03/26 14:25:55 by kmaeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Base.hpp"
#include "include/A.hpp"
#include "include/B.hpp"
#include "include/C.hpp"
#include <ctime>

int main() {
	// Seed random number generator
	std::srand(std::time(NULL));
	
	std::cout << "=== Testing Type Identification ===" << std::endl << std::endl;
	
	// Test multiple random generations
	for (int i = 0; i < 6; i++) {
		std::cout << "Test " << i + 1 << ":" << std::endl;
		
		// Generate random object
		Base* ptr = generate();
		
		// Test pointer version
		std::cout << "  identify(Base* p): ";
		identify(ptr);
		
		// Test reference version
		std::cout << "  identify(Base& p): ";
		identify(*ptr);
		
		// Clean up
		delete ptr;
		std::cout << std::endl;
	}
	
	std::cout << "=== Testing Specific Types ===" << std::endl << std::endl;
	
	// Test each type specifically to verify correctness
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();
	
	std::cout << "Known type A:" << std::endl;
	std::cout << "  Pointer: ";
	identify(a);
	std::cout << "  Reference: ";
	identify(*a);
	std::cout << std::endl;
	
	std::cout << "Known type B:" << std::endl;
	std::cout << "  Pointer: ";
	identify(b);
	std::cout << "  Reference: ";
	identify(*b);
	std::cout << std::endl;
	
	std::cout << "Known type C:" << std::endl;
	std::cout << "  Pointer: ";
	identify(c);
	std::cout << "  Reference: ";
	identify(*c);
	std::cout << std::endl;
	
	delete a;
	delete b;
	delete c;
	
	std::cout << "=== Edge Cases ==" << std::endl << std::endl;
	
	std::cout << "NULL pointer test:" << std::endl;
	std::cout << "  Pointer: ";
	identify(NULL);
	std::cout << std::endl;
	
	return 0;
}

