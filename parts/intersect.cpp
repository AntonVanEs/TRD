// Check of c op het lijnstuk van a naar b ligt,
// gegeven het feit dat c op de lijn door a en b ligt.
bool onSegment(punt a, punt b, punt c) {
	return (min(a.x, b.x) <= c.x && max(a.x, b.x) >= c.x
	     && min(a.y, b.y) <= c.y && max(a.y, b.y) >= c.y);
}

bool segmentsIntersect (punt p1, punt p2, punt p3, punt p4) {
	int d1 = ccw(p3, p4, p1);
	int d2 = ccw(p3, p4, p2);
	int d3 = ccw(p1, p2, p3);
	int d4 = ccw(p1, p2, p4);

	if (d1 * d2 < 0 && d3 * d4 < 0) return true;
	if (d1 == 0 && onSegment(p3, p4, p1)) return true;
	if (d2 == 0 && onSegment(p3, p4, p2)) return true;
	if (d3 == 0 && onSegment(p1, p2, p3)) return true;
	if (d4 == 0 && onSegment(p1, p2, p4)) return true;
	return false;
}
