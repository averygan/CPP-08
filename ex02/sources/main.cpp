/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:28:28 by agan              #+#    #+#             */
/*   Updated: 2024/06/19 17:28:28 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void print_test(std::string string)
{
	std::cout << GREEN << std::endl << string << std::endl;
	for (int i = 0; i < 30; i++)
		std::cout << "-";
	std::cout << RESET << std::endl;
}

void additional_test()
{
	srand((unsigned)time(0));

	print_test("Create stack, push 20 values");
	MutantStack<int>					mstack;
	MutantStack<int>::const_iterator	i;
	int									random;

	for (int i = 0; i < 20; i++)
	{
		random = (rand() % 20) + 1;
		std::cout << "[" << random << "]";
		mstack.push(random);
	}
	std::cout << std::endl;

	print_test("Use iterators to print vals");
	for (i = mstack.begin(); i != mstack.end(); i++)
	{
		std::cout << "[" << *i << "]";
	}
	std::cout << std::endl;
}

int vector_test()
{
	MutantStack<int, std::vector<int> > mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int, std::vector<int> >::iterator it = mstack.begin();
	MutantStack<int, std::vector<int> >::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int, std::vector<int> > s(mstack);
	return 0;
}

int subject_test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int list_test()
{
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
	return 0;
}

int main(void)
{
	print_test("SUBJECT TESTS");
	subject_test();
	print_test("OUTPUT FROM STD::LIST TESTS");
	list_test();
	print_test("UPDATED UNDERLYING CONTAINER TO STD::VECTOR");
	vector_test();
	print_test("ADDITIONAL TESTS");
	additional_test();
	print_test("END OF TESTS");
}