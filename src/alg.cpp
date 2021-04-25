// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int desir = 0;
	for (int i = 0; i < SIZE_ARR; i++)
	{
		for (int j = i + 1; j < SIZE_ARR; j++)
			if (arr[i] + arr[j] == input)
				desir++;
	}
	return desir;
}

int countPairs2(int *arr, int len, int value) {
 int left_border = 0;
	int right_border = SIZE_ARR;
	int buff = 0;

	while (arr[0]+arr[right_border]>input)
	{
		right_border--;
	}
	cout << "Подходящие значения: " << endl;

	for (int i = left_border; i <= right_border; i++)
	{
		for (int j = i + 1; j <= right_border; j++)
		{
			if (arr[i] + arr[j] == input)
			{
			cout << endl << arr[i]
				<< "+" << arr[j]
				<< endl;

			buff++;
			}
			}

	}
	return buff;
}

int countPairs3(int *arr, int SIZE_ARR, int input) {
  int left_border = 0;
	int right_border = SIZE_ARR;
	int mid = 0;
	int desir = 0;

	while (left_border < right_border)
		{
			mid = (left_border + right_border) / 2;

			if (arr[left_border] + arr[mid] > input)
			{
				right_border = mid;
			}
			else if (arr[left_border] + arr[mid] < input)
			{
				left_border = mid++;
			}
			else if (arr[left_border] + arr[mid] == input)
			{				
				for (int i = mid; i <= mid; i++)
				
				{
					if (arr[left_border] + arr[i] == input)
					{
						cout << endl << arr[left_border] << "+" << arr[i] << endl;
						desir++;
					}
				}
				for ( int j = mid; j >= left_border; j--)
				{
					if (arr[left_border] +arr[j - 1] == input)
					{
						cout << endl << arr[left_border] << "+" << arr[j] << endl;
						desir++;
					}
				}
				left_border++;
			}
			else break;
		}

	return desir;
}
