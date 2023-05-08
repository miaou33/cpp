# include "Span.hpp"

/****************************************************************/
/*						CONSTR / DESTR							*/
/****************************************************************/

Span::Span () : _max (0) {}

Span::Span (t_ui N) : _max (N) {}

Span::Span (Span const& original) { *this = original; }

Span& Span::operator= (Span const& rhs) {

	if (this != &rhs)
	{
		_span = rhs.getSpan ();
		_max = rhs.getN ();
	}
	return *this;
}

Span::~Span () {}

/****************************************************************/
/*						FUNCTIONS								*/
/****************************************************************/

std::vector <int> const&	Span::getSpan () const { return _span; }

t_ui						Span::getN () const { return _max; }

void						Span::addNumber (int n) {

	if (_span.size () == _max)
		throw std::length_error ("Span is full!");
	_span.push_back (n);
}

t_ull						Span::shortestSpan () {

	if (_span.size () <= 1)
		throw std::logic_error ("Span has less than 2 numbers");

	std::vector <int> sorted (_span);
	std::sort (sorted.begin (), sorted.end ());
	t_ull shortest = sorted [1] - sorted [0];
	for (t_ull i = 2; i < sorted.size (); i++)
	{
		t_ull tmp = sorted [i] - sorted [i - 1];
		shortest = tmp < shortest ? tmp : shortest ;
	}
	return shortest;
}

t_ull						Span::longestSpan () const {

	if (_span.size () <= 1)
		throw std::logic_error ("Span has less than 2 numbers");
	int min = *std::min_element (_span.begin (), _span.end ());
	int max = *std::max_element (_span.begin (), _span.end ());
	return max - min;
}
