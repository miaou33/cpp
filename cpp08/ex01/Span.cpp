# include "Span.hpp"

/****************************************************************/
/*						CONSTR / DESTR							*/
/****************************************************************/

Span::Span () : _max (0) {

	_shortestSpan = std::numeric_limits<t_ull>::max();
}

Span::Span (t_ui N) : _max (N) { 

	_shortestSpan = std::numeric_limits<t_ull>::max();
}

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
		throw std::length_error ("Span is fi!");
	_span.push_back (n);
}

t_ull						Span::shortestSpan () {

	if (_span.size () <= 1)
		throw std::logic_error ("Span has less than 2 numbers");
	std::sort (_span.begin (), _span.end ());

	for (t_ull i = 0; i < _span.size () - 1; i++)
	{
		t_ull tmp = _span [i + 1] - _span [i];
		_shortestSpan = tmp < _shortestSpan ? tmp : _shortestSpan ;
	}
	return _shortestSpan;
}

t_ull						Span::longestSpan () const {

	if (_span.size () <= 1)
		throw std::logic_error ("Span has less than 2 numbers");
	return _span [_span.size () - 1] - _span [0];
}
