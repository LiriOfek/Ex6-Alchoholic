/********************************************************\
File Name: main.c
Author: Liri (6/4/2020)
Purpose: This file run the program that swap number
		  by swap each corresponding elements
\********************************************************/

#define INITIAL_INDEX (0)
#define DECIMAL (10)
#define ONE (1)
#define INITIAL_NUMBER (0)
#define MIDDLE_OF_ARRAY (2)

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

unsigned int* swap_array_elements(unsigned int *number_array,
	int number_of_digits)
{
	/********************************************************\
	* Function name - swap_array_elements
	*
	* Function Purpose - reverse array by swap first element
	*					 with last element and so on
	*
	* Parameters - INOUT unsigned int *number_array - the array that contain the
	*									 digits of the number, that will be
	*									swapped
	*			   IN int number of digits - the number of the digits
	*									in the given number, which is
	*									the size of the array
	*
	* Return Value - swapped given array_number
	*
	* Side Effects - this function swap the elements in number_array
	*
	* Semantics - reverse array by swap first element
	*			 with last element, second element with element
	*			before last element and so on
	*
	* Author - Liri
	\********************************************************/
	int index = INITIAL_INDEX;
	int current_left_element = INITIAL_NUMBER;

	while (index < number_of_digits / MIDDLE_OF_ARRAY)
	{
		/*swap first element with last element and so on*/
		current_left_element = number_array[index];
		number_array[index] = number_array[number_of_digits - index - ONE];
		number_array[number_of_digits - index - ONE] = current_left_element;

		index += ONE;
	}
	return number_array;
}