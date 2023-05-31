# include "sort.hpp"

double	lst_merge_insert_sort (std::list <int>& arr, int left, int right) {

	clock_t startTime = clock ();

	if (left < right)
	{
		if (right - left + 1 <= 10)
		{
			lst_insertion_sort (arr, left, right);
		}
		else 
		{
			int mid = left + (right - left) / 2;
			lst_merge_insert_sort (arr, left, mid);
			lst_merge_insert_sort (arr, mid + 1, right);
			lst_merge (arr, left, mid, right);
		}
	}
	clock_t endTime = clock ();
	return static_cast <double> (endTime - startTime) / CLOCKS_PER_SEC * 1000000.0;
}

void	lst_insertion_sort (std::list <int>& arr, int left, int right) {

	for (int j = left + 1; j <= right; j++)
	{
		int key = arr [j];
		int i = j - 1;
		while (i >= left && arr [i] > key)
		{
			arr [i + 1] = arr [i];
			i--;
		}
		arr [i + 1] = key;
	}
}

void lst_merge (std::list <int>& arr, int left, int mid, int right) {

	int end1 = mid - left + 1;
	std::list <int> L (end1);

	for (int i = 0; i < end1; i++)
		L [i] = arr [left + i];

	int end2 = right - mid;
	std::list <int> R (end2);

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

