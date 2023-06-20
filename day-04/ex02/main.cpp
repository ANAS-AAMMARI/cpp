/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaammari <aaammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:31:25 by aaammari          #+#    #+#             */
/*   Updated: 2023/06/19 18:09:08 by aaammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	
	Animal *animals[4];
	for (int i = 0; i < 2; i++)
		animals[i] = new Dog();
	for (int i = 2; i < 4; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 4; i++)
		delete animals[i];
	
	Dog d1;
	d1.getBrain()->ideas[0]= "d1";
	Dog tmp = d1;
	tmp.getBrain()->ideas[0] = "tmp";
	std::cout << d1.getBrain()->ideas[0] << std::endl;
	std::cout << tmp.getBrain()->ideas[0] << std::endl;
	// system("leaks polymorphism | grep 'leaks for'");

	return 0;
}