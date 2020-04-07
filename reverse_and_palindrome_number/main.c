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
#define STRING_NUMBER_IS_PALINDROME ("The number you entered: %d is a palindrome\n")
#define STRING_NUMBER_IS_NOT_PALINDROME ("The number you entered: %d is not a palindrome\n")

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

bool check_if_number_is_palindrome(unsigned int number) {
	/********************************************************\
	* Function name - check_if_number_is_palindrome
	*
	* Function Purpose - check if the given number is a palindrome
	*
	* Parameters - IN unsigned int number - number from user
	*			   OUT bool - true - if the given number is a palindrome
	*						  false - otherwise
	*
	* Return Value - true - if the given number is a palindrome
	*				 false - otherwise
	*
	* Side Effects - this function has no side effects
	*
	* Semantics - this function check if the given number is a plindrome
	*
	* Author - Liri
	\********************************************************/
	unsigned int reverse_number = ZERO;
	reverse_number = reverse_given_number(number);
	if (number == reverse_number)
	{
		return true;
	}
	else
	{
		return false;
	}
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

	/*check if the given number is palindrome*/
	is_number_palindrome = check_if_number_is_palindrome(original_number);
	if (is_number_palindrome == true)
	{
		printf(STRING_NUMBER_IS_PALINDROME, original_number);
	}
	else
	{
		printf(STRING_NUMBER_IS_NOT_PALINDROME, original_number);
	}
}