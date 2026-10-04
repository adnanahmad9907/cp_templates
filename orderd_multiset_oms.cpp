
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

template <typename T>
class OrderedMultiset
{
private:
    typedef pair<T, int> PT;

    tree<PT, null_type, less<PT>, rb_tree_tag,
         tree_order_statistics_node_update>
        os;

    int uid = 0;

public:
    void insert(T x)
    {
        os.insert({x, uid++});
    }

    void erase(T x)
    {
        auto it = os.lower_bound({x, -1});
        if (it != os.end() && it->first == x)
            os.erase(it);
    }

    bool exists(T x)
    {
        auto it = os.lower_bound({x, -1});
        return it != os.end() && it->first == x;
    }

    int count_less(T x)
    {
        return os.order_of_key({x, -1});
    }

    int count_lesseq(T x)
    {
        return os.order_of_key({x, INT_MAX});
    }

    int count_greater(T x)
    {
        return os.size() - count_lesseq(x);
    }

    int count_greatereq(T x)
    {
        return os.size() - count_less(x);
    }

    // 0-based kth element
    T kth_element(int k)
    {
        if (k < 0 || k >= (int)os.size())
            throw out_of_range("Index out of bounds");

        return os.find_by_order(k)->first;
    }

    T lower_bound(T x)
    {
        auto it = os.lower_bound({x, -1});

        if (it == os.end())
            throw out_of_range("No element >= x");

        return it->first;
    }

    T upper_bound(T x)
    {
        auto it = os.upper_bound({x, INT_MAX});

        if (it == os.end())
            throw out_of_range("No element > x");

        return it->first;
    }

    T first_less(T x)
    {
        auto it = os.lower_bound({x, -1});

        if (it == os.begin())
            throw out_of_range("No element < x");

        --it;
        return it->first;
    }

    T first_lesseq(T x)
    {
        auto it = os.upper_bound({x, INT_MAX});

        if (it == os.begin())
            throw out_of_range("No element <= x");

        --it;
        return it->first;
    }

    T smallest()
    {
        if (os.empty())
            throw out_of_range("Set is empty");

        return os.begin()->first;
    }

    T largest()
    {
        if (os.empty())
            throw out_of_range("Set is empty");

        return os.rbegin()->first;
    }

    int size()
    {
        return os.size();
    }
};
