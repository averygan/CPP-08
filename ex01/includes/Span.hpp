/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:30 by agan              #+#    #+#             */
/*   Updated: 2024/06/19 15:05:31 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <iterator>

#define DEFAULT_SIZE 100

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

class Span 
{
	public:
		// Constructors
		Span();
		Span(unsigned int N);
		Span(const Span &copy);

		// Destructor
		~Span();

		// Assignment operator
		Span &operator=(const Span &copy);

		// Member functions
		void addNumber(const int num);
		int shortestSpan() const;
		int longestSpan() const;

		// Exceptions
		class VectorFullException : public std::exception {
			virtual const char *what() const throw();
		};

		class VectorTooSmallException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		template <typename inputIterator>
		void addRange(inputIterator first, inputIterator last) {
			unsigned int distance = std::distance(first, last);
			if (this->_vect.size() + distance > this->_maxSize)
			{
				throw VectorFullException();
			}
			this->_vect.insert(_vect.end(), first, last);
		}

		// Getters
		const std::vector<int> &getVect() const;
		unsigned int getMaxSize() const;

	private:
		unsigned int		_maxSize;
		std::vector<int>	_vect;
};

std::ostream &operator<<(std::ostream &os, const Span &obj);

#endif