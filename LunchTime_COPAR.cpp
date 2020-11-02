//rs
#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;

const int MAX = 1e5 + 5;
bool prime[MAX];
int spf[MAX];

void sieve()
{
    fill(prime, prime + MAX, true);
    for (int i = 1; i < MAX; i++)spf[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                if (prime[j]) spf[j] = i;
                prime[j] = false;
            }
        }
    }
}

//Multiple Query
vector<int> getFactorization(long long int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main()
{
    boost;
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map <int, int> f, l;
        for (int i = 1; i <= n; i++) {
            int num;
            cin >> num;
            vector<int> fact = getFactorization(num);
            for (auto x : fact) {
                if (f[x] == 0)f[x] = i;
                l[x] = i;
            }
        }
        vector<int> cover(n + 1, 0);
        for (auto x : f)cover[x.second]++;
        for (auto x : l)cover[x.second]--;
        for (int i = 1; i <= n; i++) {
            cover[i] += cover[i - 1];
            if (cover[i] == 0) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
