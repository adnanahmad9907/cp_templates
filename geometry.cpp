// cf-adnanahmad
typedef long double ld;
const ld EPS = 1e-12;
// this accepts both ll and ld
template <typename T, typename U>
ld dis(pair<T, T> p1, pair<U, U> p2)
{
    ld dx = (ld)p1.first - (ld)p2.first;
    ld dy = (ld)p1.second - (ld)p2.second;

    return sqrtl(dx * dx + dy * dy);
}
array<ll, 3> line(pair<ll, ll> p1, pair<ll, ll> p2)
{
    // point should be different
    ll x1 = p1.first, y1 = p1.second;
    ll x2 = p2.first, y2 = p2.second;

    ll a = y1 - y2;
    ll b = x2 - x1;
    ll c = x1 * y2 - x2 * y1;

    ll g = __gcd(abs(a), abs(b));
    g = __gcd(g, abs(c));

    a /= g;
    b /= g;
    c /= g;

    if (a < 0 || (a == 0 && b < 0))
    {
        a = -a;
        b = -b;
        c = -c;
    }

    return {a, b, c};
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
// orientation between three points a-b->c if possitive then anticlockwise other  wise clockwise
ll orientation(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    return cross(vec(a, b), vec(a, c));
}
ll dot(pair<ll, ll> v1, pair<ll, ll> v2)
{
    return v1.first * v2.first + v1.second * v2.second;
}
// range is [0,π]
ld angle(pair<ll, ll> a, pair<ll, ll> b)
{
    ld d = (ld)dot(a, b);
    ld len = dis(make_pair(0LL, 0LL), a) *
             dis(make_pair(0LL, 0LL), b);
    return acosl(d / len);
}

// range is [-π, π]
ld signedAngle(pair<ll, ll> a, pair<ll, ll> b)
{
    return atan2l(
        (ld)cross(a, b),
        (ld)dot(a, b));
}
// point line dis
ld pointLineDis(pair<ll, ll> p, array<ll, 3> L)
{
    auto [A, B, C] = L;

    return abs((ld)A * p.first +
               (ld)B * p.second + C) /
           sqrt((ld)A * A + (ld)B * B);
}
// gives you point of intersection of two lines
pair<ld, ld> lineIntersection(array<ll, 3> l1, array<ll, 3> l2)
{
    auto [A1, B1, C1] = l1;
    auto [A2, B2, C2] = l2;

    ld D = (ld)A1 * B2 - (ld)A2 * B1;

    ld x = ((ld)B1 * C2 - (ld)B2 * C1) / D;
    ld y = ((ld)C1 * A2 - (ld)C2 * A1) / D;

    return {x, y};
}
bool onSegment(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c)
{
    ll cr = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);

    if (cr != 0)
        return false;

    ll dot = (c.first - a.first) * (c.first - b.first) + (c.second - a.second) * (c.second - b.second);

    return dot <= 0;
}
