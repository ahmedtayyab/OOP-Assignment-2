/*Imagine you are working on a scientific research project that
involves collecting data from various sensors placed at different
locations. Each sensor generates a varying number of data points
over time, and you need to organize this data efficiently for
analysis. To do this, you decide to create a program that builds a
matrix to store the sensor data, where each row corresponds to a
different sensor, and the number of columns varies for each sensor
based on the data points collected.
Design a C++ program to build a matrix with a different number of
elements in each row (different number of columns in each row)
using a two-dimensional dynamic array.
For Example:

Your program must contain two functions. One for filling the elements into your two-dimensional array and the other for
printing that array or matrix.*/

#include<iostream>
using namespace std;

void FillData(int**matrix,int row,int* colForEachRow)
{
	for (int i = 0; i < row; i++)
	{
		int col;
		cout << "Enter DataPoints for Sensor " << i + 1 << " : ";
		cin >> col;
		colForEachRow[i] = col; // store num of cols for this row
		matrix[i] = new int[col];
		cout << endl;

		cout << "Enter Data for Sensor " << i + 1 << " : ";
		for (int j = 0; j < col; j++)
		{
			cout << "Enter data Point" << j + 1 << " For Sensor " << i + 1 << " : ";
			cin >> matrix[i][j];
		}
		cout << endl;
	}
}

void DisplayData(int** matrix, int rows, int* colsPerRow) 
{
	cout << "------------------------------------------------------" << endl;
	cout << "Matrix contents:" << endl;
	for (int i = 0; i < rows; i++)
	{
		int cols = colsPerRow[i]; 
		cout << "Sensor " << i + 1 << "-> ";
		for (int j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------------------------------" << endl;
}



int main()
{

	
	int row, col;
	cout << "Enter The Number Of Sensors" << endl;
	cin >> row;
	int** matrix = new int* [row];
	int* colForEachRow = new int[row];

	FillData(matrix, row,colForEachRow);
	DisplayData(matrix, row, colForEachRow);
	for (int i = 0; i < row; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] colForEachRow;
	matrix = nullptr;

	return 0;

	
}