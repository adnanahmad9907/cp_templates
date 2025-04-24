#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Define ordered_set type
typedef tree<
    int,                      // key type
    null_type,                // mapped type
    less<int>,                // comparison function
    rb_tree_tag,              // underlying tree structure
    tree_order_statistics_node_update> ordered_set;

int main() {
    ordered_set os;

    // Insert elements
    os.insert(10);
    os.insert(5);
    os.insert(20);

    // Erase an element
    os.erase(10);

    // Check if element exists
    if (os.find(5) != os.end()) {
        cout << "5 exists\n";
    }

    // Get k-th smallest element (0-based)
    cout << "1st smallest element: " << *os.find_by_order(0) << "\n";

    // Number of elements strictly less than x
    cout << "Elements less than 15: " << os.order_of_key(15) << "\n";

    return 0;
}
