#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
	//1 
	void fill_arr(T arr[], int length, int l, int r) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (r - l) + l;
}
	//2
template <typename T>
void print_arr(T arr[], int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
	//3 
int search_index(int arr[], int length, int num, int begin = 0) {
	for(int i = begin; i < length; i++)
		if (arr[i] == num) 
			return i;
	return -1;
}
int search_last_index(int arr[], int length, int num) {
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == num)
			return i;
	return -1;
}
int search_last_index(int arr[], int length, int num, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == num)
			return i;
	return -1;

}
int arr_min(int arr[], int length) {
	int min = arr[0];
	for (int i = 0; i < length; i++) {
		arr[i] < min ? min = arr[i] : min = min;
	}
	return min;
}
int arr_max(int arr[], int length) {
	int max = arr[0];
	for (int i = 0; i < length; i++) {
		arr[i] > max ? max = arr[i] : max = max;
	}
	return max;
}
int mean_value(int arr[], int length) {
	int sum = 0, counter = 0;
	for (int i = 0; i < length; i++) {
		sum += arr[i];
		counter++;
	}
	return sum / counter;
}
void range(int arr[], int length, int beg, int end) {
	for (int i = beg; i <= end; i++)
		std::cout << arr[i] << ' ';
}
int count(int arr[], int length, int n, int beg, int end) {
	int counter{};
	for (int i = beg; i <= end; i++) {
		if (arr[i] == n) {
			counter++;
		}
	}
	return counter;
}
void bubble_sort(int arr[], int length) {
	int tmp{};
	for (int i = 0; i < length; i++)
		for (int j = 0; j < i; j++)
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				(arr[j] = arr[j + 1]);
				arr[j + 1] = tmp;
			}
}


int main() {
	setlocale(LC_ALL, "Russian");
	const int size = 20;
	int arr[size];
	fill_arr(arr, size, 10, 50);
	std::cout << "Массив: \n";
	print_arr(arr, size);
	
	//3
	std::cout << "Задача 3.\n";
	std::cout << "Введите искомое число: -> ";
	int n;
	std::cin >> n;
	std::cout << "Индекс искомого числа: " << search_index(arr, size, n) << std::endl;

	//4
	std::cout << "Задача 4.\n";
	std::cout << "Введите искомое число: -> ";
	int n1;
	std::cin >> n1;
	std::cout << "Индекс искомого числа: " << search_last_index(arr, size, n1, 14) << std::endl;

	//5
	std::cout << "Значение минимального числа: " << arr_min(arr, size) << std::endl;

	//6
	std::cout << "Значение максимального числа: " << arr_max(arr, size) << std::endl;

	//7
	std::cout << "Среднее арифметическое число: " << mean_value(arr, size) << std::endl;

	//8 
	range(arr, size, 3, 16);

	//9
	std::cout << "\nЗадача 9. Введите нужное число -> ";
	int n2;
	std::cin >> n2;
	std::cout << "Число " << n2 << " входит в диапазон от 3 до 16 - " << count(arr, size, n2, 3, 16) << " раз(а)";
	
	//10
	std::cout << "\nОтсортированный массив: " << std::endl;
	bubble_sort(arr, size);
	print_arr(arr, size);

	return 0;
}