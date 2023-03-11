#include "Point.hpp"

static bool crossProduct(Point A, Point B, Point p)
{
	return ((B.X () - A.X ()) * (p.Y () - A.Y ())
				- (B.Y () - A.Y ()) * (p.X () - A.X ())) > 0;
}

bool bsp (Point const a, Point const b, Point const c, Point const point)
{
	bool	f1 = crossProduct (a, b, point);
	bool	f2 = crossProduct (b, c, point);
	bool	f3 = crossProduct (a, c, point);

	return (f1 == f2 == f3);
}