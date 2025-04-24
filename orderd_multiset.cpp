// files for the orderd_multiset 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Custom comparator to allow duplicates in ordered set
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

// Define ordered_multiset type
typedef tree<
    pair<int, int>,       // value + unique id to support duplicates
    null_type,
    cmp,
    rb_tree_tag,
    tree_order_statistics_node_update> ordered_multiset;

int uid = 0; // global unique id to distinguish duplicates

// Insert an element x into the multiset
void insert(ordered_multiset &oms, int x) {
    oms.insert({x, uid++});
}

// Remove one instance of x (if exists)
void erase(ordered_multiset &oms, int x) {
    auto it = oms.lower_bound({x, 0});
    if (it != oms.end() && it->first == x) {
        oms.erase(it);
    }
}

// Query helpers
int count_less(ordered_multiset &oms, int x) {
    return oms.order_of_key({x, 0});
}

int count_less_equal(ordered_multiset &oms, int x) {
    return oms.order_of_key({x + 1, 0});
}

int count_greater(ordered_multiset &oms, int x) {
    return oms.size() - count_less_equal(oms, x);
}

int count_greater_equal(ordered_multiset &oms, int x) {
    return oms.size() - count_less(oms, x);
}

// Usage example
int main() {
    ordered_multiset oms;
    insert(oms, 5);
    insert(oms, 2);
    insert(oms, 5);
    insert(oms, 7);

    int x = 5;
    cout << "Elements < " << x << " = " << count_less(oms, x) << endl;
    cout << "Elements <= " << x << " = " << count_less_equal(oms, x) << endl;
    cout << "Elements > " << x << " = " << count_greater(oms, x) << endl;
    cout << "Elements >= " << x << " = " << count_greater_equal(oms, x) << endl;

    return 0;
}
