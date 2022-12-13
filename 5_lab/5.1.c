#include <stdio.h>
#include <stdlib.h>
#include "arrays.h"

/*
1.��������� ������ � ���������� ������������� �������. ������� ��� ����� �����
*/

int main() {
	double *mass= NULL;
	int max_element;

	// ����� ������������ ������� 
	printf("Enter the maximum number of array elements \n");
	input_max(&max_element);
	
	// ����� ������������ ����������� �������
	mass = malloc(sizeof(double) * max_element);

	// ���� ������������ ��������� � ������
	input_mass(max_element, mass);
	
	// �������� ����� ����� �� �������
	delete_elements(&max_element, mass);
	
	// ����� �������
	outpoot_mass(max_element, mass);

	// ������� ��������� ������ ������
	free(mass);	
}
