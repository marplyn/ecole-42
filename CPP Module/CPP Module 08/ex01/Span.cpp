#include "Span.hpp"

Span::Span()
{
}

Span::Span(unsigned int N): maxSize(N)
{
}

Span::Span(const Span & src)
{
	*this = src;
}

Span & Span::operator=(const Span & src)
{
	if (this == &src)
		return (*this);
	this->maxSize = src.maxSize;
	this->vect = src.vect;
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber( int Number )
{
	if (this->maxSize == this->vect.size())
		throw Span::NoSpaceLeft();
	this->vect.push_back(Number);
}

int	Span::longestSpan()
{
	if (this->vect.size() <= 1)
		throw Span::NoSpan();
	return (*std::max_element(this->vect.begin(), this->vect.end())
		- *std::min_element(this->vect.begin(), this->vect.end()));
}

int	Span::shortestSpan()
{
	if (this->vect.size() <= 1)
		throw NoSpan();
	std::vector<int> sorted = this->vect;
	std::sort(sorted.begin(), sorted.end());
	int ret = sorted[1] - sorted[0];
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		if (ret > sorted[i + 1] - sorted[i])
			ret = sorted[i + 1] - sorted[i];
	}
	return (ret);
}

const char* Span::NoSpan::what() const throw()
{
	return ("There are no numbers or only one in the container!");
}

const char* Span::NoSpaceLeft::what() const throw()
{
	return ("No space left in the container!");
}
