#include <stdio.h>
#include <stdlib.h>
/*
1.	В одномерном массиве выполнить сортировку четных элементов методом выбора
*/

void Sortirovka_Viborom_Chetnih_Elemenytov(int* array, int vibor) {
	for (int i = 0; i < vibor - 1; i++) // выбор исходного элемента к сравнению
	{
		int i1 = i;
		int m;
		if ((i + 1) % 2 == 0) {
			for (int j = i + 1; j < vibor; j++) // просмотр массива ”снизу” ”вверх”
				if (array[i1] > array[j] && (j + 1) % 2 == 0) i1 = j; // фиксируем координату элемента в массиве
			m = array[i]; // замена i1 и i элементов
			array[i] = array[i1];
			array[i1] = m;
		}
	}
}

void scanf_s_secure(int* number, int min, int max) {
	while (scanf_s("%d", number) == 0 || *number <= min || *number > max || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}

int main() {
	int* mass;
	int max_element, vibor;
	printf("\nEnter max ell array ");
	scanf_s_secure(&max_element, 0 , 50);
	mass = malloc(max_element*sizeof(int));
	
	for (int i = 0; i < max_element; i++) {
		printf("\narray[%d]=", i);
		scanf_s_secure(&mass[i], -10000, 10000);
	}
	printf("\nVIBOR ");
	scanf_s_secure(&vibor, 0, max_element);
	
	for (int i = 0; i < max_element; i++)
		printf(" %d", mass[i]);
	free(mass);
}

