/********************************************************\
File Name: main.c
Author: Liri (6/4/2020)
Purpose: This file run the program that swap number
		  by swap each corresponding elements
\********************************************************/

#define INITIAL_INDEX (0)
#define DECIMAL (10)
#define ONE (1)

unsigned int* convert_number_to_array(unsigned int *number_array,
	int number_of_digits,
	unsigned int original_number)
{
	/********************************************************\
	* Function name - convert_number_to_array
	*
	* Function Purpose - save in array the digits of number
	*
	* Parameters - INOUT unsigned int *number_array - the array that contain the
	*									 digits of the number
	*			   IN int number of digits - the number of the digits
	*									in the given number, which is
	*									the size of the array
	*			   int unsigned original_number - the original number from user
	*
	* Return Value - array that contain the digits of given number
	*
	* Side Effects - this function change save in number_array the digits
	*				 of a given number
	*
	* Semantics - save in array the digits of the given number
	*
	* Author - Liri
	\********************************************************/
	int index = INITIAL_INDEX;

	for (index = INITIAL_INDEX; index < number_of_digits; ++index)
	{
		number_array[number_of_digits - index - ONE] = original_number % DECIMAL;
		original_number /= DECIMAL;
	}

	return number_array;
}