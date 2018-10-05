unsigned ggd(unsigned a, unsigned b) {
    while(b) {
        a %= b;
        swap(a,b);
    }
    return a;
}
