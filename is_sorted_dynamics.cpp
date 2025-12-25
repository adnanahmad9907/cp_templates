class sorted_data
{
public:
    vector<ll> arr;
    ll n;
    vector<bool> brr;
    ll cnt = 0;
    sorted_data(vector<ll> &_arr)
    {
        arr = _arr;
        n = arr.size();
        cnt = 0;
        // debug(arr);
 
        brr.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            check(i);
        }
    }
    void check(int i)
    {
        if (i < 0)
            return;
        if (i >= n)
            return;
        bool ba = true;
        if (i > 0)
        {
            if (arr[i - 1] > arr[i])
                ba = false;
        }
        if (i < n - 1)
        {
            if (arr[i + 1] < arr[i])
            {
                ba = false;
            }
        }
        cnt -= brr[i];
        brr[i] = ba;
        cnt += brr[i];
    }
    void update(int i, int val)
    {
        arr[i] = val;
        check(i);
        check(i + 1);
        check(i - 1);
    }
    bool query()
    {
        return (cnt == n);
    }
};
