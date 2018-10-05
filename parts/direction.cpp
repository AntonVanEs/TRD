// tegen overflows bij vermenigvuldigen van uitvoer van direction
int sgn (coord_t i) { return (i > 0) ? 1 : ((i < 0) ? -1 : 0); }

// Geef de orientatie van het lijnstuk van a naar c
// ten opzichte van het lijnstuk van a naar b.
int direction (punt a, punt b, punt c) { return sgn (cross (b-a, c-a)); }
