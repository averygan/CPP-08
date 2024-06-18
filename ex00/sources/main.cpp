/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:41:55 by agan              #+#    #+#             */
/*   Updated: 2024/06/18 18:41:56 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void print_test(std::string string)
{
	std::cout << GREEN << std::endl << string << std::endl;
	for (int i = 0; i < 30; i++)
		std::cout << "-";
	std::cout << RESET << std::endl;
}

void try_catch_blocks(std::vector<int> vect, int to_find)
{
	std::cout << "searching for " << to_find << std::endl;
	try
	{
    	std::vector<int>::iterator it = easyfind(vect, to_find);
    	std::cout << "found at " << "[" << it - vect.begin() << "]" <<std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int main(void)
{
	print_test("Creating vector with 10 random integers");
	std::vector<int> vect;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int b = (rand() % 20) + 1;
		vect.push_back(b);
		std::cout << "pushing " << b << std::endl;
	}
	print_test("Searching within container");
	try_catch_blocks(vect, 2);
	try_catch_blocks(vect, 12);
	try_catch_blocks(vect, 20);
	try_catch_blocks(vect, 9);
}
