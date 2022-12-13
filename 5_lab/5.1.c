#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

/*
1.Заполнить массив с клавиатуры вещественными числами. Удалить все целые числа
*/

int main() {
	double *mass= NULL;
	int max_element;

	// Задаём максимальный элемент 
	printf("Enter the maximum number of array elements \n");
	input_max(&max_element);
	
	// Задаём максимальную размерность массива
	mass = malloc(sizeof(double) * max_element);

	// Ввод вещественных елементов в массив
	input_mass(max_element, mass);
	
	// Удаление целых чисел из массива
	delete_elements(&max_element, mass);
	
	// Вывод массива
	outpoot_mass(max_element, mass);

	// Очищаем выделеную память масива
	free(mass);	
}
