#ifndef SPAN_HPP
# define SPAN_HPP

# define t_ui unsigned int
# define t_ull unsigned long long

# include <stdlib.h>
# include <time.h>
# include <vector>
# include <stdexcept>
# include <algorithm>
# include <limits>
# include <cstddef>
# include <iterator>

class Span {

	public:
		Span ();
		Span (t_ui N);
		Span (Span const& original);
		Span& operator= (Span const& rhs);
		~Span ();

		std::vector <int> const&	getSpan () const;
		t_ui						getN () const;

		void						addNumber (int n);
		template <typename InputIt>
		void						addNumbers (t_ull count, InputIt range_min, InputIt range_max);
		t_ull						shortestSpan ();
		t_ull						longestSpan () const;

	private:
		std::vector <int>	_span;
		t_ull				_max;
		t_ull				_shortestSpan;

};

#endif
