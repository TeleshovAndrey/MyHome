//#include <stdio.h>
//#include <stdlib.h>
//int main() 
//{
//	int n, choise, i = 0, massiv[100] ;
//	printf("Enter the number of elements in the array\n");
//	scanf_s("%i", &n);
//	printf("How do you want to set the values \n1)themselves \n2)randomly\n");
//	scanf_s("%i", &choise);
//	switch (choise) {
//	case 1:
//		while (i < n)
//		{
//			scanf_s(" %d", &massiv[i]);
//			if (massiv[i] < massiv[0]) massiv[0] = massiv[i];
//			i++;
//		}
//		break;
//	case 2:
//		while (i < n)
//		{
//			massiv[i] = rand();
//			if (massiv[i] < massiv[0]) massiv[0] = massiv[i];
//			i++;
//		}
//		break;
//	default: printf("Not in this life");
//		break;
//	}
//		printf("Min value %d", massiv[0]);
//		return 0;
//}