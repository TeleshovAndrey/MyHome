#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

/*
2.� ������� �������� NxM ������� ��� �������� �� �������� ���������
*/
int main() {
	int** matrix;
	int row, col;

	printf("Enter row \n");
	input_max(&row);

	printf("Enter col \n");
	input_max(&col);
	matrix = (int**)malloc(row * sizeof(int*));

	input_matrix(row, col, matrix);
	
	printf("Start matrix \n");
	output_matrix(row, col, matrix);
	
	delete_side_diagonal(row, col, matrix);
	col -= 1;
	
	printf("\n Resulting matrix \n");
	output_matrix(row, col, matrix);
	

	free_DuoMass(row, col, matrix);

// 1 2 
// 1 3
// 2 3 

//���� ������� NxM ���� ������� ��� �������� �� ���������� ��������� � ������ ���������
}
	