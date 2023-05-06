# include "Span.hpp"

/****************************************************************/
/*						CONSTR / DESTR							*/
/****************************************************************/

Span::Span () : _max (0) {

	srand (time(NULL));
	_shortestSpan = std::numeric_limits<t_ull>::max();
}

Span::Span (t_ui N) : _max (N) { 

	srand (time(NULL));
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

void						Span::addNumber () {

	if (_span.size () == _max)
		throw std::length_error ("Span is full!");
	_span.push_back (rand ());
}

t_ui						Span::shortestSpan () {

	if (_span.size () <= 1)
		throw std::logic_error ("Span has less than 2 numbers");
	std::sort (_span.begin (), _span.end ());

	for (t_ull ull = 0; ull < _span.size () - 1; ull++)
	{
		t_ull tmp = std::distance (_span [ull], _span [ull + 1]);
		_shortestSpan = tmp < _shortestSpan ? tmp : _shortestSpan ;
	}
	return _shortestSpan;
}
