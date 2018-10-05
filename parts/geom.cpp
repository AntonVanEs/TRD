struct vect {
    coord_t x, y;
    vect() = default;
    vect (coord_t _x, coord_t _y) : x(_x), y(_y) { }
};
struct punt {
    coord_t x, y;
    punt() = default;
    punt (coord_t _x, coord_t _y, coord_t _n) : x(_x), y(_y) { }
};

vect operator- (punt p, punt q) { return vect (q.x-p.x, q.y-p.y); }

ostream &operator<< (ostream &o, punt p) { o << p.naam; return o; }
ostream &operator<< (ostream &o, vect v) { o << v.x << ',' << v.y; return o; }
