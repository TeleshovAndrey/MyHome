#include <stdio.h>
#include <stdlib.h>
int main()
{
	int choise,massiv[100],n,max;
	printf("Enter the number of elements in the array\n");
	scanf_s("%i", &n);
	printf("How do you want to set the values \n1)themselves \n2)randomly\n");
	scanf_s("%i", &choise);
	switch (choise) {
	case 1:
		printf("Enter %d integers\n", n);
		for (int i = 0; n > i; i++) {
			scanf_s(" %d", &massiv[i]);
			if (massiv[i] % 2 == 0) max = i;
		}
		break;
	case 2:
		for (int i = 0; n > i; i++) {
			massiv[i] = rand();
			if (massiv[i] % 2 == 0) max = i;
		}
		break;
	default: printf("Not in this life");
		break;
	}
	printf("Remaining array ");
	for (int i = 0; i <= max; i++) printf("\n%d massiv[%d]", massiv[i],i);
}