
class MedianDS
{
    multiset<ll> lh, rh;
    ll sum_lh = 0, sum_rh = 0;

    void rebalance()
    {
        while (lh.size() > rh.size() + 1)
        {
            ll val = *lh.rbegin();
            lh.erase(prev(lh.end()));
            sum_lh -= val;
            rh.insert(val);
            sum_rh += val;
        }
        while (lh.size() < rh.size())
        {
            ll val = *rh.begin();
            rh.erase(rh.begin());
            sum_rh -= val;
            lh.insert(val);
            sum_lh += val;
        }
    }

public:
    void insert(ll x)
    {
        if (lh.empty() || x <= *lh.rbegin())
        {
            lh.insert(x);
            sum_lh += x;
        }
        else
        {
            rh.insert(x);
            sum_rh += x;
        }
        rebalance();
    }

    void remove(ll x)
    {
        auto it = lh.find(x);
        if (it != lh.end())
        {
            lh.erase(it);
            sum_lh -= x;
        }
        else
        {
            it = rh.find(x);
            if (it != rh.end())
            {
                rh.erase(it);
                sum_rh -= x;
            }
        }
        rebalance();
    }

    ll getMedian() const
    {
        return *lh.rbegin();
    }

    ll getLeftSum() const
    {
        return sum_lh;
    }

    ll getRightSum() const
    {
        return sum_rh;
    }

    ll getLeftSize() const
    {
        return lh.size();
    }

    ll getRightSize() const
    {
        return rh.size();
    }
};
