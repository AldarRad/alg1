#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
using namespace std;

//int search(int * arr, int n)
//{
//	int sum = 0;
//	int oper = 0;
//	int min = 0;
//	for (int i = 0; i < n;i++)
//	{
//		oper++;
//		if (arr[i] == 0)
//			break;
//		if (arr[i] > 0)
//			sum += arr[i];
//	}
//	for (int i = 0; i < n;i++)
//	{
//		oper++;
//		if (arr[i] < min)
//		{
//			min = i;
//		}
//	}
//	arr[min] = sum;
//	return oper;
//}
//int main()
//{
//	uint32_t oper = 0;
//	int n = 10;
//	int* mas;
//	auto start = std::chrono::steady_clock::now();
//	auto end = std::chrono::steady_clock::now();
//	std::ofstream file;
//	file.open("lab11.csv");
//	file << "M_SIZE;M_TIME;M_SIZE;M_OPERATION;\n";
//	for (int i = 1000; i < 1000000;i+=500)
//	{
//		mas = new int[i];
//		for (int j = 0;j < n;j++)
//		{
//			mas[j] = rand() % i;
//		}
//		start = std::chrono::steady_clock::now();
//		oper = search(mas, n);
//		end = std::chrono::steady_clock::now();		
//		file << i << ";" << oper << ";";
//		file << i << ";" << oper << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "\n";
//		delete[] mas;
//	}
//}

int change(int** arr, int n)
{
	int oper = 0;
	int column_3 = 0;
	int column_2 = 0;
	int max3 = 0;
	int max2 = INT_MAX;
	int count = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			oper++;
			if (arr[j][i] % 3 == 0)
			{
				count++;
			}
		}
		if (count > max3)
		{
			max3 = count;
			column_3 = i;
		}
	}
	count = 0;
	for (int i = 0;i <n;i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (arr[j][i] % 2 == 0)
			{
				oper++;
				count += arr[j][i];
			}
		}
		if (count < max2)
		{
			max2 = count;
			column_2 = i;
		}
	}
	for (int i = 0; i < n;i++)
	{
		oper++;
		int temp = arr[column_2][i];
		arr[column_2][i] = arr[column_3][i];
		arr[column_3][i] = temp;
	}
	return oper;
}
int main()
{
	srand(time(0));
	uint32_t oper = 0;
	int** arr;
	auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();
	std::ofstream file;
	file.open("namber2.csv");
	file << "SIZE;TIME;SIZE;OPERATIONS\n";
	for (int i = 3; i < 30;i++)
	{
		arr = new int*[i];
		for (int j = 0;j < i;j++)
		{
			arr[j] = new int[i];
		}
		for (int j = 0; j < i;j++)
		{
			for (int k = 0; k < i; k++)
			{
				arr[j][k] = rand() % (i * 2);
			}
		}
		start = chrono::steady_clock::now();
		oper = change(arr, i);
		end = chrono::steady_clock::now();		
		file << i*i<< ";" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << ";";
		file << i * i << ";" << oper << "\n";
		for (int j = 0;j<i;j++)
			delete[] arr[j];
		delete[] arr;
	}
}
