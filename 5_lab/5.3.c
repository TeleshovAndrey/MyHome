#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

/*
3.� ��������� ������� 
(���������� ����� � ������ ����� ���� ���������, ��������� ����� - -100.) 
� ������ ������ ������ �������������� �������� �������.
*/

int main () {
	int **mass;
	int* col;
	int row;
	
	//������ ����� ����� � ������� � �������� ������ �� ������ ����������
	printf("Enter row \n");
	input_max(&row);
	mass = (int**)malloc(row * sizeof(int*));
	col = malloc(row * sizeof(int));

	//������ �������� � ����������� ������ � �� ���-�� ����� �� ������
	input_DuoMass(row, col, mass);

	//��������� ������ ��������
	add_odd_element_even_line(row, col, mass);
	
	//������� ������������ ������
	output_DouMass(row, col, mass);
	
	//������� ������ ������� ��������� � ������� � ��� ������
	free_DuoMass(row, mass);
	
}
