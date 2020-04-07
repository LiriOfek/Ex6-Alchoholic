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

unsigned int convert_array_to_number(unsigned int *number_array,
	int number_of_digits)
{
	/********************************************************\
	* Function name - convert_array_to_number
	*
	* Function Purpose - convert the elements of the array to number
	*
	* Parameters - INOUT unsigned int *number_array - the array that contain the
	*									 digits of the number, that will be
	*									swapped
	*			   IN int number of digits - the number of the digits
	*									in the given number, which is
	*									the size of the array
	*
	* Return Value - number that its digits are the elements of number_array
	*
	* Side Effects - this function convert the elements of array to number
	*
	* Semantics - convert the elements of array to number
	*
	* Author - Liri
	\********************************************************/
	int index = INITIAL_INDEX;
	unsigned int number_after_swap = INITIAL_NUMBER;

	for (index = INITIAL_INDEX; index < number_of_digits; ++index)
	{
		number_after_swap = DECIMAL * number_after_swap + number_array[index];
	}
	return number_after_swap;
}

unsigned int swap_number_digits(unsigned int original_number)
{
	/********************************************************\
	* Function name - swap_number_digits
	*
	* Function Purpose - run functions that reverse the number
	*					 such that it swaps first digit with last digit
	*					 and so on
	*
	* Parameters - IN unsigned int original_number - the number before swapping
	*			   OUT unsigned int number number_after_swap - the number after
	*						swapping its digits
	*
	* Return Value - the reverse number
	*
	* Side Effects - this function allocate memory in order to
	*				 save the digits of the number and swap them
	*				 and in the end the function free this memory
	*
	* Semantics -   run functions that convert number to array,
	*				reverse the elements in the array such that it swaps first element
	*				with last element and so on, and convert the array to number
	*
	* Author - Liri
	\********************************************************/
	int number_of_digits = INITIAL_NUMBER;
	unsigned int* number_array;
	unsigned int number_after_swap = INITIAL_NUMBER;

	/*calculate the number i=of the digits in the given number*/
	number_of_digits = (int)log10(original_number) + ONE;
	/*allocate array in size of the number of the digits*/
	number_array = calloc(number_of_digits, sizeof(int));

	/*save the digits of the number in array*/
	number_array = convert_number_to_array(number_array,
		number_of_digits,
		original_number);

	/*swap array elements*/
	number_array = swap_array_elements(number_array,
		number_of_digits);

	/*save the elements from the array to number*/
	number_after_swap = convert_array_to_number(number_array,
		number_of_digits);

	free(number_array);

	return number_after_swap;
}