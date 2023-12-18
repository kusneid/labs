#include "h.h"

void FillMatrix(double** matrix, int matrixValue) {
	for (int row = 0; row < matrixValue+1; row++) {
		matrix[row] = new double[matrixValue * 2];
	}
	for (int row = 0; row < matrixValue; row++) {
		for (int col = 0; col < matrixValue*2; col++) {
			if (col==row+matrixValue)
			{
				matrix[row][col] = 1.0;
			}
			else
			{
				matrix[row][col] = 0.0;
			}

		}
	}
}


void PrintMatrix(double** matrix, int matrixValue) {
	for (int row = 0; row < matrixValue; row++) {
		for (int col = 0; col < matrixValue*2; col++)
		{
			if (col == matrixValue) {
				std::cout << std::setw(14) <<"|";
			}
			if (matrix[row][col]==-0)
			{
				matrix[row][col] = 0;
			}
			std::cout << std::setw(14) << matrix[row][col];

		}
		std::cout << "\n";
	}
}

void InputMatrix(double** matrix, int matrixValue) {
	for (int row = 0; row < matrixValue; row++)
	{
		for (int col = 0; col < matrixValue; col++)
		{
			std::cout << "\n row:" << row << " col:" << col<<" Number:";
			std::cin >> matrix[row][col];
			std::cout << "\n";
		}
	}
}

void InputMatrix(double* matrix, int matrixValue) {
	std::cout << "\nfill matrix to multiply with\n";
	for (int row = 0; row < matrixValue; row++)
	{
			std::cout << row + 1 << "row:";
			std::cin >> matrix[row];
			std::cout << "\n";
	}
}

double Determinant(double** matrix, int currentMatrixValue) {
	if (currentMatrixValue==1)
	{
		return matrix[0][0];
	}

	double Determinan = 0;
	short int koef = 1;

	double** matrixNext = new double* [currentMatrixValue - 1];
	for (int row = 0; row < currentMatrixValue-1; row++)
	{
		matrixNext[row] = new double[currentMatrixValue - 1];
	}

	for (int row = 0; row < currentMatrixValue-1; row++)
	{
		for (int col = 0; col < currentMatrixValue-1; col++)
		{
			matrixNext[row][col] = matrix[row + 1][col + 1];
		}
	}

	for (int col = 0; col < currentMatrixValue-1; col++)
	{
		Determinan += koef * matrix[0][col] * Determinant(matrixNext, currentMatrixValue - 1);
		koef *= -1;
	}

	for (int row = 0; row < currentMatrixValue - 1; row++)
	{
		delete[] matrixNext[row];
	}
	delete[] matrixNext;

	return Determinan;
}

void MinusRows(double** matrix, int matrixValue, int row, int column, double koef) {
	koef = matrix[row][column];
	for (int col1 = 0; col1 < matrixValue * 2; col1++)
	{
		//std::cout << "\ntututu\n";
		matrix[row][col1] -= (matrix[0][col1] * koef);
	}
}

void ZeroColumn(double** matrix, int matrixValue, int column) {
	int temp = 1;
	double koef;
	std::swap(matrix[column], matrix[0]);
	while (matrix[0][column] == 0)
	{
		std::cout << "\nlol\n";
		std::swap(matrix[0], matrix[temp]);
		temp++;
	}

	double k = matrix[0][column];

	for (int row = 0; row < matrixValue; row++)
	{
		//std::cout << "\nlol1\n";
		for (int col = 0; col < matrixValue * 2; col++)
		{
			//std::cout << "\nlol\n";
			if (row == 0) {
				
				matrix[0][col] /= k;
			}
			else if (column != matrixValue)
			{
				//std::cout << "\ntut\n";
				while (matrix[row][column] != 0) {
					//std::cout << "\ntut\n";
					
					//MinusRows(matrix, matrixValue, row, column, koef);
					koef = matrix[row][column];
					for (int col1 = 0; col1 < matrixValue * 2; col1++)
					{
						//std::cout << "\ntututu\n";
						matrix[row][col1] -= matrix[0][col1] * koef;
					}


				}
			}

		}
	}
}

void MatrixInvert(double** matrix, int matrixValue) {
	for (int col = 0; col < matrixValue; col++)
	{
		ZeroColumn(matrix, matrixValue, col);
		//std::cout << "\nlol\n";
	}
	std::swap(matrix[0], matrix[matrixValue]);
	for (int row = 1; row < matrixValue; row++)
	{
		
		std::swap(matrix[row], matrix[row - 1]);
	}
	
	std::swap(matrix[matrixValue], matrix[matrixValue - 1]);
}

void Multiply(double** matrix, int matrixValue, double* multMatrix, double* Answer) {
	for (int row = 0; row < matrixValue; row++)
	{
		for (int col = 0; col < matrixValue; col++) {
			Answer[row] += matrix[row][col + matrixValue] * multMatrix[col];
		}
	}

}
void PrintMatrix(double* Answer, int matrixValue) {
	for (int row = 0; row < matrixValue ; row++)
	{
		std::cout << "\nx" << row + 1 << ":" << Answer[row];
	}
}

