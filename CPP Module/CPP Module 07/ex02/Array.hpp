#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
			T *arr;
			int arrSize;
	public:
			Array();
			Array(unsigned int n);
			Array(const Array<T> &src);
			~Array();
			Array<T> &operator=(const Array<T> &src);

			T &operator[](int index);
			T const & operator[](int index) const;

			int size() const;
};

template<typename T>
Array<T>::Array() : arr(), arrSize(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), arrSize(n)
{
}

template<typename T>
Array<T>::Array(const Array<T> &src)
{
	*this = src;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	if(this != &src)
	{
		delete[] arr;
		arrSize = src.arrSize;
		arr = new T[arrSize];
		memcmp(src.arr, arr, arrSize);
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template<typename T>
int Array<T>::size() const
{
	return (arrSize);
}

template<typename T>
T &Array<T>::operator[](int index)
{
	if(index < 0 || index >= arrSize)
		throw std::exception();
	return (arr[index]);
}

template<typename T>
T const &Array<T>::operator[](int index) const
{
	if(index < 0 || index >= arrSize)
		throw std::exception();
	return (arr[index]);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &arr)
{
	for(int i = 0; i < arr.size(); ++i)
		out << arr[i] << " ";
	return (out);
}

#endif
