#include "Point.hpp"

static float crossProduct(Point A, Point B, Point p)
{
	Fixed res ((B.X () - A.X ()) * (p.Y () - A.Y ())
				- (B.Y () - A.Y ()) * (p.X () - A.X ()));
	return res.toFloat ();
}

bool bsp (Point const a, Point const b, Point const c, Point const point)
{
	float	f1 = crossProduct (a, b, point);
	float	f2 = crossProduct (b, c, point);
	float	f3 = crossProduct (a, c, point);

	return (f1 < 0 && f2 < 0 && f3 < 0) || (f1 > 0 && f2 > 0 && f3 > 0);
}