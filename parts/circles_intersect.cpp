
struct circle {
    long double x, y;
    long double r;
    long double dist(const circle& other) const {
        return sqrtl(sq(x - other.x) + sq(y - other.y));
    }
    bool intersects(const circle& other) const {
        long double d = dist(other);
        return (d <= r + other.r) && (d >= abs(r - other.r)); // epsilon?
    }
    pair<circle,bool> findIntersection(const circle& other) const {
        if (*this == other) return make_pair(*this,true); // pas op!
        if (!intersects(other)) return make_pair(*this,false);
        long double d = dist(other);
        circle diff = other - *this;
        diff *= 1/d;
        circle antiDiff = (circle) {diff.y, -diff.x, 0};
        long double keer = (sq(r) - sq(other.r) + sq(d)) / (2.0L * d);
        diff *= keer;
        antiDiff *= sqrtl(sq(r) - sq(keer));
        diff += antiDiff;
        diff += *this;
        return make_pair(diff,true);
    }
};

