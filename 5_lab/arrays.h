
										//1 задание 


void input_max(int * max) {
	while (scanf_s("%d", max) == 0 || *max <= 0 || *max > 100 || getchar() != '\n')
	{
		printf("Error, try again\n");
		rewind(stdin);
	}
}

void input_mass(int max_element, double *mass) {
	for (int i = 0; i < max_element; i++) {
		printf("mass[%d]=", i);
		while (scanf_s("%lf", (mass + i)) == 0 || *(mass + i) <= -10000 || *(mass + i) > 10000 || getchar() != '\n')
		{
			printf("Error, try again\n");
			rewind(stdin);
		}
	}
}

void delete_elements(int *max, double *mass) {
	for (int k = 0; k < *max; k++)
		if (*(mass + k) == (int)*(mass + k)) {
			for (int i = k + 1; i < *max; i++)
				*(mass + i - 1) = *(mass + i);
			*max = *max - 1;

			//коректировка для двух подряд идущих значений для затирания
			k--;
		}
}

void outpoot_mass(int max, double *mass) {
	if (max == 0) printf("Mass is empty");
	else printf("\n Resulsing mass");
	for (int i = 0; i < max; i++)
		printf("\n mass[%d]=%lf", i, *(mass + i));
}


										// 2 задача


void delete_side_diagonal(int row, int col, int **matrix) {
	for (int i = row - 1, j = 0; i >= 0; i--) {

		for (int k = j; k < col; k++)
			matrix[i][k] = matrix[i][k + 1];
		*(matrix + i) = realloc(*(matrix + i), (col - 1) * sizeof(int));
		j++;
	}
}

void input_matrix(int row,int col, int **matrix) {
	for (int i = 0; i < row; i++) {
		*(matrix + i) = (int*)malloc(col * sizeof(int));
		for (int j = 0; j < col; j++) {
			printf("\n mareix[%d][%d]= ", i, j);
			while (scanf_s("%d", &matrix[i][j] == 0 || matrix[i][j] <= -10000 || matrix[i][j] > 10000 || getchar() != '\n'))
			{
				printf("Error, try again\n");
				rewind(stdin);
			}
		}
	}
}

void output_matrix(int row, int col, int **matrix) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < col; j++)
			printf(" %d", matrix[i][j]);
	}
}

void free_DuoMass(int row, int** matrix) {
	for (int i = 0; i < row; i++) {
		free(*(matrix + i));
	}
	free(matrix);
}


										// 3 задача


void input_DuoMass(int row, int *col, int **mass) {
	for (int i = 0; i < row; i++) {
		printf("How many number are you want in the %d string?\n", i + 1);
		input_max(&col[i]);
		*(mass + i) = (int*)malloc(col[i] * sizeof(int));
		printf("Enter numbers in the %d string\n", i + 1);
		for (int j = 0; j < col[i] - 1; j++) {

			scanf_s("%d", &mass[i][j]);
		}
		mass[i][col[i] - 1] = -100;
	}
}

void add_odd_element_even_line(int row, int* col,int **mass) {
	for (int i = 0; i < row; i++)
		if (i % 2 != 0) {
			for (int j = col[i] - 1; j >= 0; j--)
				if (mass[i][j] % 2 != 0) {
					*(mass + i) = realloc(*(mass + i), (col[i] + 1) * sizeof(int));

					for (int k = col[i] - 1; k >= j; k--) {
						mass[i][k + 1] = mass[i][k];
					}
					col[i]++;
				}
		}
}

void output_DouMass(int row, int *col, int **mass) {
	for (int i = 0; i < row; i++) {
		printf("\n");
		for (int j = 0; j < col[i]; j++) {
			printf(" %d,", mass[i][j]);
		}
	}
}