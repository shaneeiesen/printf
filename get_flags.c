#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @index: Index to keep track of the current position in the format string
 * Return: Flags:
 */
int get_flags(const char *format, int *index)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int flags = 0;
	const char FLAGS_CHARACTERS[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUES[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (int current_index = *index + 1; format[current_index] != '\0'; current_index++)
	{
		for (int j = 0; FLAGS_CHARACTERS[j] != '\0'; j++)
		{
			if (format[current_index] == FLAGS_CHARACTERS[j])
			{
				flags |= FLAGS_VALUES[j];
				break;
			}
		}

		if (FLAGS_CHARACTERS[j] == 0)
			break;
	}

	*index = current_index - 1;

	return flags;
}
