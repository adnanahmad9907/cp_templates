
class XorTrie
{
    struct Node
    {
        Node *arr[2] = {nullptr, nullptr};
    };

public:
    Node *root;

    XorTrie()
    {
        root = new Node();
    }

    void insert(ll x)
    {
        Node *cur = root;

        for (int i = 63; i >= 0; i--)
        {
            int bit = (x >> i) & 1LL;

            if (!cur->arr[bit])
                cur->arr[bit] = new Node();

            cur = cur->arr[bit];
        }
    }

    ll find(ll x)
    {
        Node *cur = root;
        ll ans = 0;

        for (int i = 63; i >= 0; i--)
        {
            int bit = (x >> i) & 1LL;
            int opposite = bit ^ 1;

            if (cur->arr[opposite])
            {
                ans |= (1LL << i);
                cur = cur->arr[opposite];
            }
            else
            {
                cur = cur->arr[bit];
            }
        }

        return ans;
    }
};
