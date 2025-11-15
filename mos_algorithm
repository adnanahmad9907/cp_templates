
int block_size;
vector<ll> arr;
vector<ll> mp;
ll ans = 0;

void add(int idx)
{
    ll x = arr[idx];
    mp[x]++;
    if (mp[x] == 1)
    {
        ans++;
    }
}

void remove_(int idx)
{
    ll x = arr[idx];
    mp[x]--;
    if (mp[x] == 0)
    {
        ans--;
    }
}

ll get_ans()
{
    return ans;
}
struct Query
{
    int l, r, idx;

    bool operator<(Query const &other) const
    {
        int block_a = l / block_size;
        int block_b = other.l / block_size;
        if (block_a != block_b)
            return block_a < block_b;
        return (block_a & 1) ? (r > other.r) : (r < other.r);
    }
};

vector<ll> mos_algorithm(vector<Query> &queries, int n)
{
    block_size = max(1, (int)sqrt(n));
    sort(queries.begin(), queries.end());

    vector<ll> ans(queries.size());
    int cur_l = 0, cur_r = -1;

    for (auto &q : queries)
    {
        while (cur_l > q.l)
            add(--cur_l);
        while (cur_r < q.r)
            add(++cur_r);
        while (cur_l < q.l)
            remove_(cur_l++);
        while (cur_r > q.r)
            remove_(cur_r--);

        ans[q.idx] = get_ans();
    }
    return ans;
}
