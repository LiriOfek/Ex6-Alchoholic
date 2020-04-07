/********************************************************\
File Name: main.c
Author: Liri (6/4/2020)
Purpose: This file run the program that reverse number
and check if the number is palindrome
\********************************************************/

#define DECIMAL (10)
#define ZERO (0)

unsigned int reverse_given_number(unsigned int original_number)
{
	/********************************************************\
	* Function name - reverse_given_number
	*
	* Function Purpose - reverse given number
	*
	* Parameters - IN unsigned int original_number - number from user,
	*												before swapping
	*			   OUT unsigned int reverse_number - number after swapping
	*
	* Return Value - reverse number
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function calculate from the given number its
	*			 reverse number
	*
	* Author - Liri
	\********************************************************/
	unsigned int reverse_number = ZERO;
	while (original_number != ZERO)
	{
		reverse_number = reverse_number * DECIMAL;
		reverse_number = reverse_number + original_number % DECIMAL;
		original_number = original_number / DECIMAL;
	}
	return reverse_number;
}
