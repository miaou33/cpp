#ifndef SORT_HPP
# define SORT_HPP

# include <iostream>
# include <vector>

double	vec_merge_insert_sort (std::vector <int>& arr, int left, int right);
void	vec_insertion_sort (std::vector <int>& arr, int left, int right);
void	vec_merge (std::vector <int>& arr, int left, int mid, int right);

#endif // !SORT_HPP

