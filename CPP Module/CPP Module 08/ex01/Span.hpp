#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private:
			unsigned int		maxSize;
			std::vector<int>	vect;
			Span();
	public:
			Span(unsigned int N);
			Span(const Span & src);
			~Span();
			Span & operator = (const Span & src);

			void	addNumber(int Number);
			int		longestSpan();
			int		shortestSpan();

			template<typename T>
			void	addNumber(T start, T end)
			{
				int dist = std::distance(start, end);
				if (dist + this->vect.size() > this->maxSize)
					throw Span::NoSpaceLeft();
				this->vect.insert(this->vect.end(), start, end);
			}
			
			class NoSpan: public std::exception
			{
				virtual const char* what() const throw();
			};

			class NoSpaceLeft: public std::exception
			{
				virtual const char* what() const throw();
			};
};

#endif
