void build(int s, int t, int p) {
    if (s == t) {
        d[p] = a[s];
        return;
    }
    int m = s + ((s - t) >> 1);
    build(s, m, p*2);
    build(m+1, t, p*2+1);
    d[p] = d[p*2] + d[p*2+1];
}