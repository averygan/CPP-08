/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:05:34 by agan              #+#    #+#             */
/*   Updated: 2024/06/19 15:05:35 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span() : _maxSize(DEFAULT_SIZE)
{
	std::cout << "Default Constructor called" << std::endl;
}

Span::Span(unsigned int N) : _maxSize(N)
{
	std::cout << "Parameter Constructor called" << std::endl;
}

Span::Span(const Span &copy)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = copy;
}

// Destructor
Span::~Span()
{
	std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Span &Span::operator=(const Span &copy)
{
	std::cout << "Span Assignment operator called" << std::endl;
	if (this == &copy)
		return *this;
	this->_maxSize = copy._maxSize;
	this->_vect = copy._vect;
	return *this;
}

void Span::addNumber(const int num)
{
	if (this->_vect.size() < this->_maxSize)
		this->_vect.push_back(num);
	else
		throw (VectorFullException());
}

const char *Span::VectorFullException::what() const throw()
{
	return ("exception: vector is full");
}

const char *Span::VectorTooSmallException::what() const throw()
{
	return ("exception: vector is too small");
}

int Span::shortestSpan() const
{
	std::vector<int> sorted = _vect;
	std::sort(sorted.begin(), sorted.end());
	std::vector<int> difference(sorted.size());

	if (this->_vect.size() <= 1)
		throw (VectorTooSmallException());
	// Get differences between adjacent elements in vector
	std::adjacent_difference(sorted.begin(), sorted.end(), difference.begin());
	// Erase first el storing first element
	difference.erase(difference.begin());

	return (*std::min_element(difference.begin(), difference.end()));
}

int Span::longestSpan() const
{
	unsigned int max;
	unsigned int min;

	if (this->_vect.size() <= 1)
		throw (VectorTooSmallException());
	max = *std::max_element(this->_vect.begin(), this->_vect.end());
	min = *std::min_element(this->_vect.begin(), this->_vect.end());

	return (max - min);
}

const std::vector<int> &Span::getVect() const
{
	return this->_vect;
}

unsigned int Span::getMaxSize() const 
{
	return this->_maxSize;
}

std::ostream &operator<<(std::ostream &os, const Span &src)
{
	os << "Span max: " << src.getMaxSize() << " | elements: ";
	const std::vector<int> &vect = src.getVect();
	std::vector<int>::const_iterator i;
	if (vect.size() == 0)
	{
		os << "empty";
		return os;
	}
	for (i = vect.begin(); i != vect.end(); i++)
	{
		os << "[" << *i << "]";
	}
	return os;
}
