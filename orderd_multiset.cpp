#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

struct cmp {
    bool operator()(const pair<int,int> &a, const pair<int,int> &b) const {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

class OrderedMultiset {
private:
    typedef tree<
        pair<int,int>, 
        null_type, 
        cmp, 
        rb_tree_tag, 
        tree_order_statistics_node_update
    > pbds;

    pbds oms;
    int uid = 0;   // unique id for duplicates

public:
    // Insert value x
    void insert(int x) {
        oms.insert({x, uid++});
    }

    // Erase a single instance of x if it exists
    void erase(int x) {
        auto it = oms.lower_bound({x, 0});
        if (it != oms.end() && it->first == x)
            oms.erase(it);
    }

    // Count elements strictly less than x
    int count_less(int x) {
        return oms.order_of_key({x, 0});
    }

    // Count elements ≤ x
    int count_less_equal(int x) {
        return oms.order_of_key({x + 1, 0});
    }

    // Count elements strictly greater than x
    int count_greater(int x) {
        return oms.size() - count_less_equal(x);
    }

    // Count elements ≥ x
    int count_greater_equal(int x) {
        return oms.size() - count_less(x);
    }

    // k-th element (0-indexed)
    int kth(int k) {
        auto it = oms.find_by_order(k);
        if (it == oms.end()) return -1;  // or throw
        return it->first;
    }

    // current size
    int size() const {
        return oms.size();
    }
};

int main() {
    OrderedMultiset ms;
    ms.insert(5);
    ms.insert(2);
    ms.insert(5);
    ms.insert(7);

    int x = 5;
    cout << "Elements < " << x << " = " << ms.count_less(x) << endl;
    cout << "Elements <= " << x << " = " << ms.count_less_equal(x) << endl;
    cout << "Elements > " << x << " = " << ms.count_greater(x) << endl;
    cout << "Elements >= " << x << " = " << ms.count_greater_equal(x) << endl;

    return 0;
}
