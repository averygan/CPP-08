/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:28:32 by agan              #+#    #+#             */
/*   Updated: 2024/06/19 17:28:32 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <vector>
#include <ctime>

// Colors
# define BROWN "\033[1;33m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE	"\033[1;34m"
# define CYAN	"\033[1;36m"
# define RESET "\033[0m"

# define BROWN_R "\033[33m"
# define RED_R "\033[31m"
# define GREEN_R "\033[32m"
# define BLUE_R	"\033[34m"
# define CYAN_R	"\033[36m"

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		// Constructor
		MutantStack() : std::stack<T, Container>() {};
		MutantStack(const MutantStack &copy) : std::stack<T, Container>(copy) {};

		// Destructor
		~MutantStack() {};

		// Assignment operator
		MutantStack &operator=(const MutantStack &copy) 
		{
			if (this != &copy)
				std::stack<T, Container>::operator=(copy);
			return *this;
		};

		// Iterators
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator begin()
		{
			return this->c.begin();
		};

		iterator end()
		{
			return this->c.end();
		};

		const_iterator begin() const
		{
			return this->c.begin();
		};

		const_iterator end() const
		{
			return this->c.end();
		};
};

// template <typename T>
// class MutantStack : public std::stack<T>
// {
// 	public:
// 		// Constructor
// 		MutantStack() : std::stack<T>() {};
// 		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {};

// 		// Destructor
// 		~MutantStack() {};

// 		// Assignment operator
// 		MutantStack &operator=(const MutantStack &copy) 
// 		{
// 			if (this != &copy)
// 				std::stack<T>::operator=(copy);
// 			return *this;
// 		};

// 		// Iterators
// 		typedef typename std::deque<T>::iterator iterator;
// 		typedef typename std::deque<T>::const_iterator const_iterator;

// 		iterator begin()
// 		{
// 			return std::stack<T>::c.begin();
// 		};

// 		iterator end()
// 		{
// 			return std::stack<T>::c.end();
// 		};

// 		const_iterator begin() const
// 		{
// 			return std::stack<T>::c.begin();
// 		};

// 		const_iterator end() const
// 		{
// 			return std::stack<T>::c.end();
// 		};
// };

#endif
