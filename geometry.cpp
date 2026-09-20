double dis(pair<ll, ll> p1, pair<ll, ll> p2)
{
    double dx = (double)p1.first - p2.first;
    double dy = (double)p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}
array<ll, 3> line(pair<ll, ll> p1, pair<ll, ll> p2)
{
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;
    ll a = y1 - y2;
    ll b = x2 - x1;
    ll c = x1 * y2 - x2 * y1;
    return {a, b, c};
    // ax+by+c=0;
}
// vec a->b can also take vectors
pair<ll, ll> vec(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return {p2.first - p1.first, p2.second - p1.second};
}

// if cross >0 means angle between v1 and v2 is positive and vice versa
ll cross(pair<ll, ll> v1, pair<ll, ll> v2)
{

    return v1.first * v2.second - v1.second * v2.first;
}

ll dot(pair<ll, ll> v1, pair<ll, ll> v2)
{
    return v1.first * v2.first + v1.second * v2.second;
}
// range is [0,π]
double angle(pair<ll, ll> a, pair<ll, ll> b)
{
    double d = (double)dot(a, b);
    double len = dis({0, 0}, a) * dis({0, 0}, b);
    return acos(d / len);
}

// range is [-π, π]
double signedAngle(pair<ll, ll> a, pair<ll, ll> b)
{
    return atan2(
        (double)cross(a, b),
        (double)dot(a, b));
}
// point line dis
double pointLineDis(pair<ll, ll> p, array<ll, 3> L)
{
    auto [A, B, C] = L;

    return abs((double)A * p.first +
               (double)B * p.second + C) /
           sqrt((double)A * A + (double)B * B);
}
