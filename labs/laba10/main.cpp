#include "h.h"

int main() {
	system("chcp 1251");
	int matrixValue;
	std::cout << "enter matrix size:";
	std::cin >> matrixValue;
	double** matrix = new double* [matrixValue];

	FillMatrix(matrix, matrixValue);
	InputMatrix(matrix, matrixValue);
	//PrintMatrix(matrix, matrixValue);
	


	if (Determinant(matrix, matrixValue) == 0.0) {
		std::cout << "\nMatrix can't be inverted!!\n";
		return 666;
	}
	std::cout << "\nmain:\n";
	MatrixInvert(matrix, matrixValue);
	PrintMatrix(matrix, matrixValue);
	
	std::cout << "\nmultiplier part:";
	double* multMatrix = new double[matrixValue];
	double* Answer = new double[matrixValue];
	InputMatrix(multMatrix,matrixValue);
	Multiply(matrix, matrixValue, multMatrix, Answer);

	PrintMatrix(Answer, matrixValue);


	return 0;
}