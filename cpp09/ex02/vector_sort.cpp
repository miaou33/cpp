# include "sort.hpp"

double	vec_merge_insert_sort (std::vector <int>& arr, int left, int right) {

	clock_t startTime = clock ();

	if (left < right)
	{
		if (right - left + 1 <= 10)
		{
			vec_insertion_sort (arr, left, right);
		}
		else 
		{
			int mid = left + (right - left) / 2;
			vec_merge_insert_sort (arr, left, mid);
			vec_merge_insert_sort (arr, mid + 1, right);
			vec_merge (arr, left, mid, right);
		}
	}
	clock_t endTime = clock ();
	return static_cast <double> (endTime - startTime) / CLOCKS_PER_SEC * 1000000.0;
}

void	vec_insertion_sort (std::vector <int>& arr, int left, int right) {

	for (int i = left + 1; i <= right; i++)
	{
		int key = arr [i];
		int j = i - 1;
		while (j >= left && arr [j] > key)
		{
			arr [j + 1] = arr [j];
			j--;
		}
		arr [j + 1] = key;
	}
}

void vec_merge (std::vector <int>& arr, int left, int mid, int right) {

	int end1 = mid - left + 1;
	std::vector <int> L (end1);

	for (int i = 0; i < end1; i++)
		L [i] = arr [left + i];

	int end2 = right - mid;
	std::vector <int> R (end2);

	for (int j = 0; j < end2; j++)
		R [j] = arr [mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = left;

	while (i < end1 && j < end2)
	{
		if (L [i] <= R [j])
			arr [k] = L [i++];
		else
			arr [k] = R [j++];
		k++;
	}

	while (i < end1)
		arr [k++] = L [i++];

	while (j < end2)
		arr [k++] = R [j++];
}

