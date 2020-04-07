/********************************************************\
File Name: main.c
Author: Liri (6/4/2020)
Purpose: This file run the program that reverse number
and check if the number is palindrome
\********************************************************/

#define DECIMAL (10)
#define ZERO (0)
#define STRING_GET_NUMBER_FROM_USER ("Enter number you want to reverse: \n")
#define GET_INTEGER ("%d")
#define STRING_PRINT_REVERSE_NUMBER ("The reverse number is:\n%d\n")

#include <stdio.h>
#include <stdbool.h>

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

void main()
{
	/********************************************************\
	* Function name - main
	*
	* Function Purpose - get number from the user and
	*					 run function that reverse the number
	*					 and check if number is palindrome
	*
	* Parameters - no Input/Output parameters
	*
	* Return Value - there isn't return value
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - get number from the user and run function that
	*			  reverse the number, and check if the number is palindrome
	*
	* Author - Liri
	\********************************************************/
	unsigned int original_number = ZERO;
	unsigned int reverse_number = ZERO;
	bool is_number_palindrome = false;

	printf(STRING_GET_NUMBER_FROM_USER);
	scanf_s(GET_INTEGER, &original_number);

	/*calculate the reverse number*/
	reverse_number = reverse_given_number(original_number);
	printf(STRING_PRINT_REVERSE_NUMBER, reverse_number);

}