struct node{
    ll sum, upv;
    bool upd;
    node(int x = 0) {
        sum = x;
        upd = 0, upv = 0;
    }
    void add(int x, int l = 0, int r = 0) { // just change this for update
        sum += (r - l + 1) * x;
        upv += x;
        upd = 1;
    }
    friend node merge(const node &a, const node &b) { // just change this for query
        node tmp;
        tmp.sum = a.sum + b.sum;
        return tmp;
    }
};

struct segtree{
    int n;
    vector<node> tree;
    node __default;

    segtree(const vector<int> &a) {
        __default = 0;
        this -> n = sz(a);
        tree.resize(sz(a) << 2);
        build(a, 0, sz(a) - 1, 1);
    }

    void build(const vector<int> &a, int l, int r, int v) {
        if(l == r) {
            tree[v] = a[l];
            return;
        }
        int m = l + r >> 1;
        build(a, l, m, 2 * v);
        build(a, m + 1, r, 2 * v + 1);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    void push(int v, int l, int r) {
        if(!tree[v].upd)
            return;
        int mid = l + r >> 1;
        update(l, r, tree[v].upv, 2 * v, l, mid);
        update(l, r, tree[v].upv, 2 * v + 1, mid + 1, r);
        tree[v].upv = 0, tree[v].upd = 0;
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }

    void update(int l, int r, int val, int v = 1, int lmost = 0, int rmost = -1) {
        if(rmost < 0)   rmost += n;
        if(l > rmost || r < lmost)
            return;
        if(l <= lmost && r >= rmost) {
            tree[v].add(val, lmost, rmost);
            return;
        }
        push(v, lmost, rmost);
        int mid = lmost + rmost >> 1;
        update(l, r, val, 2 * v, lmost, mid);
        update(l, r, val, 2 * v + 1, mid + 1, rmost);
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
    }
    node query(int l, int r, int v = 1, int lmost = 0, int rmost = -1) {
        if(rmost < 0)   rmost += n;
        if(r < lmost || l > rmost) {
            return __default;
        }
        if(l <= lmost && r >= rmost) {
            return tree[v];
        }
        push(v, lmost, rmost);
        int mid = lmost + rmost >> 1;
        return merge(query(l, r, 2 * v, lmost, mid), query(l, r, 2 * v + 1, mid + 1, rmost));
    }
};

