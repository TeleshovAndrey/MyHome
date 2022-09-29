#include <stdio.h>
#include <stdlib.h>
int main()
{
	int choise, massiv[100], n1,n2, mass2[100];
	printf("Enter the number of elements in the first and second array\n");
	scanf_s("%i,%i", &n1, &n2);
	printf("How do you want to set the values \n1)themselves \n2)randomly\n");
	scanf_s("%i", &choise);
	switch (choise) {
	case 1:
		printf("Enter %d numbers in the first array \n", n1);
		for (int i = 0; n1 > i; i++) scanf_s(" %d", &massiv[i]);
		printf("Enter %d numbers in the first array \n", n2);
		for (int i = 0; n2 > i; i++) scanf_s(" %d", &mass2[i]);
		break;
	case 2:
		for (int i = 0; n1 > i; i++) massiv[i] = rand();
		for (int i = 0; n2 > i; i++) mass2[100] = rand();
		break;
	default: printf("Not in this life");
		break;
	}
	printf("Remaining array ");
}