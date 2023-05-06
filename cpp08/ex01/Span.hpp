#ifndef SPAN_HPP
# define SPAN_HPP

class Span {

	public:
		Span ();
		Span (Span const& original);
		Span& operator= (Span const& rhs);
		~Span ();

	private:
		std::vector <int> _span;
	
};

#endif
