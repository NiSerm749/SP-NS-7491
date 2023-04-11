#include <stdio.h>

int main()
{
	int array[12] = {12, 2, -2, 1, 13, 2, -11, 5, 4, -3, -14, 0};
	int pos_sum = 0;
	int neg_sum = 0;

	for (int i = 0; i < 12; i++)
	{
	
		if (array[i] < 10)
			neg_sum += array[i];
		else
			pos_sum += array[i];
	
	}	

	printf("Positive sum = %d\n", pos_sum);
	printf("Negative sum = %d\n", neg_sum);
	

	return 0;
} 
