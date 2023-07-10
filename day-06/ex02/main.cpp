/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 16:48:47 by aaammari          #+#    #+#             */
/*   Updated: 2023/07/10 16:55:52 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

Base *generate(void)
{
	srand(time(0));
	int i = rand() % 3;
	if (i == 0)
		return (new A());
	else if (i == 1)
		return (new B());
	else
		return (new C());
}

void identify(Base *p)
{
	if (A *a = dynamic_cast<A *>(p))
		std::cout << "p: \"A\"" << std::endl;
	else if (B *b = dynamic_cast<B *>(p))
		std::cout << "p: \"B\"" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "p: \"C\"" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "p: \"A\"" << std::endl;
		(void)a;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "p: \"B\"" << std::endl;
			(void)b;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "p: \"C\"" << std::endl;
				(void)c;
			}
			catch (std::exception &e)
			{
				std::cout << "cast Error" << std::endl;
			}
		}
	}
}

int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}