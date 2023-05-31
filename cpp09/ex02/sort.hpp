#ifndef SORT_HPP
# define SORT_HPP

# include <iostream>
# include <vector>
# include <list>

double	vec_merge_insert_sort (std::vector <int>& arr, int left, int right);
void	vec_insertion_sort (std::vector <int>& arr, int left, int right);
void	vec_merge (std::vector <int>& arr, int left, int mid, int right);

double	lst_merge_insert_sort (std::list <int>& arr, std::list <int>& left, std::list <int>& right);
void	lst_insertion_sort (std::list <int>& arr, std::list <int>& left, std::list <int>& right);
void	lst_merge (std::list <int>& arr, std::list <int>& left, std::list <int>& mid, std::list <int>& right);

#endif

