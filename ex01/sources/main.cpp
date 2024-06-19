/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:26 by agan              #+#    #+#             */
/*   Updated: 2024/06/19 15:05:27 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void print_test(std::string string)
{
	std::cout << GREEN << std::endl << string << std::endl;
	for (int i = 0; i < 30; i++)
		std::cout << "-";
	std::cout << RESET << std::endl;
}

void subject_tests()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void test_cases()
{
	std::vector<int> test;
	test.push_back(0);
	test.push_back(100);
	test.push_back(101);
	test.push_back(150);
	test.push_back(200);

	print_test("Creating empty span with size 10000");
	Span sp = Span(10000);
	std::cout << sp << std::endl;

	print_test("Adding 5 elements");
	sp.addRange(test.begin(), test.end());
	std::cout << sp << std::endl;

	print_test("Testing addNumber function");
	sp.addNumber(99);
	sp.addNumber(109);
	std::cout << sp << std::endl;

	print_test("Testing shortestSpan - expected output 1");
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;

	print_test("Testing longestSpan - expected output 200");
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	print_test("Add 100000 and test longestSpan - expected 100000");
	sp.addNumber(100000);
	std::cout << sp << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;

	print_test("END OF TESTS");
}

int main()
{
	print_test("RUNNING SUBJECT TESTS");
	subject_tests();
	print_test("RUNNING OTHER TEST CASES");
	test_cases();
}
