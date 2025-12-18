ll n;
vector<ll> arr;
ll block_size;
vector<ll> block_sum;
vector<ll> lazy;
vector<ll> lazy2;

void build()
{
    block_size = sqrt(n) + 1;
    block_sum.resize(500);
    lazy.resize(500);
    lazy2.resize(500, -1e15);
    for (ll i = 0; i < n; i++)
    {
        block_sum[i / block_size] += arr[i];
    }
}
void push(ll b)
{
    if (lazy[b] == 0 && lazy2[b] == -1e15)
    {
        return;
    }
    ll l = b * block_size;
    ll r = min(n, (b + 1) * block_size);
    block_sum[b] = 0;
    for (ll i = l; i < r; i++)
    {
        if (lazy2[b] != -1e15)
        {
            arr[i] = lazy2[b];
        }
        arr[i] += lazy[b];
        block_sum[b] += arr[i];
    }
    lazy2[b] = -1e15;
    lazy[b] = 0;
}
// range update for adding a value in a range
void range_update(ll l, ll r, ll val)
{
    ll bl = l / block_size;
    ll br = r / block_size;
    if (bl == br)
    {
        push(bl);
        for (ll i = l; i <= r; i++)
        {
            arr[i] += val;
            block_sum[bl] += val;
        }
        return;
    }

    push(bl);
    for (ll i = l; i < (bl + 1) * block_size; i++)
    {
        arr[i] += val;
        block_sum[bl] += val;
    }

    for (ll b = bl + 1; b <= br - 1; b++)
    {
        lazy[b] += val;
        block_sum[b] += val * block_size;
    }

    push(br);
    for (ll i = br * block_size; i <= r; i++)
    {
        arr[i] += val;
        block_sum[br] += val;
    }
}
// range update for assigning a value a value in a range

void range_update_2(ll l, ll r, ll val)
{
    ll bl = l / block_size;
    ll br = r / block_size;
    if (bl == br)
    {
        push(bl);
        for (ll i = l; i <= r; i++)
        {

            block_sum[bl] -= arr[i];
            arr[i] = val;
            block_sum[bl] += val;
        }
        return;
    }

    push(bl);
    for (ll i = l; i < (bl + 1) * block_size; i++)
    {
        block_sum[bl] -= arr[i];
        arr[i] = val;
        block_sum[bl] += val;
    }

    for (ll b = bl + 1; b <= br - 1; b++)
    {
        lazy2[b] = val;
        lazy[b] = 0;
        block_sum[b] = val * block_size;
    }

    push(br);
    for (ll i = br * block_size; i <= r; i++)
    {
        block_sum[br] -= arr[i];
        arr[i] = val;
        block_sum[br] += val;
    }
}

ll range_query(ll l, ll r)
{
    ll ans = 0;
    ll bl = l / block_size;
    ll br = r / block_size;

    if (bl == br)
    {
        push(bl);
        for (ll i = l; i <= r; i++)
        {
            ans += arr[i];
        }
        return ans;
    }

    push(bl);
    for (ll i = l; i < (bl + 1) * block_size; i++)
    {
        ans += arr[i];
    }
    for (ll b = bl + 1; b <= br - 1; b++)
    {
        ans += block_sum[b];
    }
    push(br);
    for (ll i = br * block_size; i <= r; i++)
    {
        ans += arr[i];
    }
    return ans;
}
