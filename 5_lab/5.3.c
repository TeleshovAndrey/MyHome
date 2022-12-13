#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

/*
3.В двумерном массиве 
(количество чисел в строке может быть различным, последнее число - -100.) 
в каждой четной строке продублировать нечетный элемент.
*/

int main () {
	int **mass;
	int* col;
	int row;
	
	//Вводим число строк в массиве и выделяем память на массив указателей
	printf("Enter row \n");
	input_max(&row);
	mass = (int**)malloc(row * sizeof(int*));
	col = malloc(row * sizeof(int));

	//Вводим элементы в определённой строке и их кол-во задаём им память
	input_DuoMass(row, col, mass);

	//Дублируем нужные элементы
	add_odd_element_even_line(row, col, mass);
	
	//Выводим получившийся массив
	output_DouMass(row, col, mass);
	
	//Очищаем память каждого указателя в массиве и сам массив
	free_DuoMass(row, mass);
	
}
