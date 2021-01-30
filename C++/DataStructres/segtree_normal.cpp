// segtree begins
// Required
// Identity Function ==> X = X * I 
// Comp Funcntion Z = X * Y  

template <typename T>
class segtree {
  vector<T> val;
  int n;
  T identity;
  function<T(T, T)> comp;

  void build(vector<T> &v, int node, int l, int r) {
    if (l == r) {
      val[node] = v[l];
      return;
    }
    int mid = (l + r) / 2;
    build(v, 2 * node + 1, l, mid);
    build(v, 2 * node + 2, mid + 1, r);
    val[node] = comp(val[2 * node + 1], val[2 * node + 2]);
  }

  void update(int node, int l, int r, int idx, T v) {
    if (idx > r || idx < l) return;
    if (l == r && r == idx) {
      val[node] = v;
      return;
    }
    int mid = (l + r) / 2;
    update(2 * node + 1, l, mid, idx, v);
    update(2 * node + 2, mid + 1, r, idx, v);
    val[node] = comp(val[2 * node + 1], val[2 * node + 2]);
  }
  T query(int node, int l, int r, int ql, int qr) {
    if (l > qr || ql > r) return identity;
    if (l >= ql && qr >= r) return val[node];
    int mid = (l + r) / 2;
    return comp(query(2 * node + 1, l, mid, ql, qr),
                query(2 * node + 2, mid + 1, r, ql, qr));
  }

 public:
  segtree(vector<T> &v, T Identity, function<T(T, T)> Comp) {
    n = v.size();
    identity = Identity;
    comp = Comp;
    val.assign(4 * n, 0);
    build(v, 0, 0, n - 1);
  }
  void print() {
    for (auto &i : val) cout << i << " ";
    cout << endl;
  }
  void update(int idx, T v) { update(0, 0, n - 1, idx, v); }

  T query(int l, int r) { return query(0, 0, n - 1, l, r); }
};

// Segtree Ends
