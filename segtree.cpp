template<class T>
class segtree{
    public:
    segtree *left, *right;
    int lmost, rmost;
    T sum;

    // Build Tree works in O(n) -> 2 * n
    void build(const vector<T> &a, int l, int n){
        lmost = l;
        rmost = n;
        if(l==n){
            sum = a[l];
        }
        else{
            int m = l + (n - l) / 2;
            left = new segTree(a, l, m);
            right = new segTree(a, m+1, n);
            recalc();
        }
    }
    // just to make segTree with 0 value everywhere
    void build(int l, int n){
        lmost = l;
        rmost = n;
        if(l==n){
            sum = 0;
        }
        else{
            int m = l + (n - l) / 2;
            left = new segTree(l, m);
            right = new segTree(m+1, n);
            recalc();
        }
    }

    // O(1) 
    void recalc(){
        if(lmost==rmost)    return;
        sum = (left->sum + right->sum);
    }

    // O(logn * O(1));
    void pointUpdate(int indx, T val){
        if(lmost==rmost){
            // lmost = rmost = indx;
            sum = val;
            return;
        }
        if(left->rmost>=indx){
            left->pointUpdate(indx, val);
        }
        else if(right->lmost<=indx){
            right->pointUpdate(indx, val);
        }
        recalc();
    }

    // O(logn) Query 
    T rangeSum(int l, int r){
        if(l>rmost || r<lmost){
            return 0;
        }
        if(l<=lmost && r>=rmost){
            return sum;
        }
        return (left->rangeSum(l, r) + right->rangeSum(l, r));
    }
};
