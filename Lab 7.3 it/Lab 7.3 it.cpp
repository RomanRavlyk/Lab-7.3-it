#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Input(int** a, const int rowCount, const int colCount);
void Print(int** a, const int rowCount, const int colCount);
int countColumnsWithZero(int** a, int numRows, int numColumns, int& count);
void FindRowWithLongestSeries(int** arr, int rowCount, int colCount, int& rowWithLongestSeries, int& maxSeriesLength);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -17;
	int High = 15;
	int rowCount, colCount;
	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Input(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	int count = 0;
	countColumnsWithZero(a, rowCount, colCount, count);
	int longestSeriesRow = -1;
	int maxSeriesLength = 0;
	FindRowWithLongestSeries(a, rowCount, colCount, longestSeriesRow, maxSeriesLength);
	cout << "Longest Series Row:               " << longestSeriesRow << endl;
	cout << "Count of Columns which include 0: " << count << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int rowCount, const int colCount)
{
		for (int i = 0; i < rowCount; i++)
		{
			for (int j = 0; j < colCount; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int countColumnsWithZero(int** a, int numRows, int numColumns, int &count) {

	for (int j = 0; j < numColumns; j++) {
		bool hasZero = false;
		for (int i = 0; i < numRows; i++) {
			if (a[i][j] == 0) {
				hasZero = true;
				break;
			}
		}
		if (hasZero) {
			count++;
		}
	}

	return count;
}

void FindRowWithLongestSeries(int** arr, int rowCount, int colCount, int& rowWithLongestSeries, int& maxSeriesLength) {


	for (int i = 0; i < rowCount; i++) {
		int currentSeriesLength = 1;
		for (int j = 1; j < colCount; j++) {
			if (arr[i][j] == arr[i][j - 1]) {
				currentSeriesLength++;
				if (currentSeriesLength > maxSeriesLength) {
					maxSeriesLength = currentSeriesLength;
					rowWithLongestSeries = i;
				}
			}
			else {
				currentSeriesLength = 1;
			}
		}
	}


}