#include <stdio.h>
#include <stdlib.h>
/*
2.	¬ матрице размером NxM выполнить сортировку строк по возрастанию суммы четных элементов методом сли€ни€
*/
void merge(int **NextArray, int** array1,  int **array2, int lenght1, int lenght2, int col)
{
	int array1MinIndex=0, array2MinIndex=0, nextArrayMinIndex =0;
	while (array1MinIndex< lenght1 && array2MinIndex < lenght2) {
		if (array1[array1MinIndex][col] <= array2[array2MinIndex][col])
		{
			*(NextArray + nextArrayMinIndex) = realloc(*(array1 + array1MinIndex), (col + 1) * sizeof(int));
			array1MinIndex++;
		}
		else
		{
			*(NextArray + nextArrayMinIndex) = realloc(*(array2 + array2MinIndex), (col + 1) * sizeof(int));
			array2MinIndex++;
		}
		nextArrayMinIndex++;
	}
	if (array1MinIndex < lenght1)
		while (array1MinIndex < lenght1) 
		{
			*(NextArray + nextArrayMinIndex) = realloc(*(array1 + array1MinIndex), (col + 1) * sizeof(int));
			array1MinIndex++;
			nextArrayMinIndex++;
		}
	if (array2MinIndex < lenght2)
		while (array2MinIndex < lenght2)
		{
			*(NextArray + nextArrayMinIndex) = realloc(*(array2 + array2MinIndex), (col + 1) * sizeof(int));
			array2MinIndex++;
			nextArrayMinIndex++;
		}
}

void MergeSort_matrix_row(int **array, int maxEll, int col) {
	int** left;
	int** right;

	if (maxEll < 2) return;
	int mid = maxEll / 2;
	left = (int**)malloc(mid * sizeof(int*));
	right = (int**)malloc((maxEll - mid) * sizeof(int*));
	
	for (int i = 0; i < mid; i++)
	{
		*(left + i) = realloc(*(array + i), (col + 1) * sizeof(int));
	}
	for (int i = mid; i < maxEll; i++) 
	{
		*(right + i-mid) = realloc(*(array + i), (col + 1) * sizeof(int));
	}
	MergeSort_matrix_row(left, mid, col);
	MergeSort_matrix_row(right, maxEll - mid, col);
	merge(array, left, right, mid, maxEll-mid, col);
}

void scanf_s_secure(int* number, int min, int max) {
	while (scanf_s("%d", number) == 0 || *number <= min || *number > max || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}

void input_matrix(int** matrix, int row,  int col) {
	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int*)malloc((col + 1) * sizeof(int));
		for (int j = 0; j < col; j++) {
			printf("\n mareix[%d][%d]= ", i, j);
			scanf_s_secure(&matrix[i][j], -10000, 10000);
		}
	}
}

void sum_chetnih_elementov_array(int *array, int max, int *sum) {
	for (int i = 0; i < max; i++) 
		if (array[i] % 2 == 0)
			*sum += array[i];
}

void output_matrix(int** matrix , int row, int col) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < col; j++)
			printf(" %d", matrix[i][j]);
	}
}

void free_DuoMass(int** matrix, int row) {
	for (int i = 0; i < row; i++) {
		free(*(matrix + i));
	}
	free(matrix);
}

int main() {
	int** matrix;
	int sum;
	int row, col;

	printf("Enter row ");
	scanf_s_secure(&row, 1 ,10);

	printf("\nEnter col ");
	scanf_s_secure(&col, 1, 10);
	
	matrix = (int**)malloc(row * sizeof(int*));
	
	input_matrix(matrix, row, col);

	for (int i = 0; i < row; i++) {
		sum = 0;
		sum_chetnih_elementov_array(*(matrix+i), row, &sum);
		matrix[i][col] = sum;
	}

	printf("\nstart matrix");
	output_matrix(matrix, row, col);

	MergeSort_matrix_row(matrix, row, col);

	printf("\nresulting mass");
	output_matrix(matrix, row, col);

	free_DuoMass(matrix, row);
}