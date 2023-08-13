/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:20:16 by aaammari          #+#    #+#             */
/*   Updated: 2023/08/10 19:35:00 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

template <class T>
class Array
{
	private:
		T *array;
		unsigned int _size;
	public:
		Array()
		{
			this->array = new T[0];
			this->_size = 0;
		}
		
		Array(unsigned int n)
		{
			this->array = new T[n];
			this->_size = n;
		}
		
		Array(const Array &src)
		{
			this->array = new T[src._size];
			this->_size = src._size;
			for (unsigned int i = 0; i < src._size; i++)
				this->array[i] = src.array[i];	
		}
		
		~Array()
		{
			delete [] this->array;
		}
		
		Array &operator=(const Array &src)
		{
			if (this != &src)
			{
				delete [] this->array;
				this->array = new T[src._size];
				this->_size = src._size;
				for (unsigned int i = 0; i < src._size; i++)
					this->array[i] = src.array[i];
			}
			return (*this);
		}
		T &operator[](unsigned int i)
		{
			if (i >= this->_size)
				throw OutOfRangeException();
			return (this->array[i]);
		}
		unsigned int size() const
		{
			return (this->_size);
		}
		class OutOfRangeException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Out of range");
				}
		};
};

#endif