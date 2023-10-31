// The sky's the limit.........................
#include <bits/stdc++.h>
#define dhoom3                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define int long long
#define endl "\n"
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)x.size()

const int MOD = 1e9 + 7;
// const int MOD = 998244353;

using namespace std;

int power(int a, int n, int MOD)
{
    int ans = 1LL;
    while (n)
    {
        if (n & 1)
            ans = 1LL * (ans % MOD * a % MOD) % MOD;
        n >>= 1;
        a = 1LL * (a % MOD * a % MOD) % MOD;
    }
    return ans;
}

int lcm(int a, int b)
{
    return 1LL * a * b / (__gcd(a, b));
}
const int N = 1e5 + 4;
// mmi of a under mod M is power(a,M-2,M); M is a prime number
vector<int> fact(N), invfact(N);

void pnc()
{
    fact[0] = fact[1] = invfact[0] = invfact[1] = 1LL;
    int i;
    for (i = 2; i < N; i++)
        fact[i] = 1LL * (i % MOD * fact[i - 1] % MOD) % MOD;
    i--;
    invfact[i] = power(fact[i], MOD - 2, MOD);
    for (i = N - 2; i >= 2; i--)
    {
        invfact[i] = (invfact[i + 1] % MOD * (i + 1) % MOD) % MOD;
    }
}

int ncr(int n, int r)
{
    if (r > n)
        return 0;
    int ans = 1LL * fact[n];
    ans = 1LL * (ans % MOD * invfact[n - r] % MOD) % MOD;
    ans = 1LL * (ans % MOD * invfact[r] % MOD) % MOD;
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int j=0;j<n;j++)
    {
        cin>>b[j];
    }
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++)
    {
        vp[i].first=b[i];
        vp[i].second=a[i];
    }
    int ans=0;
    sort(all(vp));
    reverse(all(vp));
    int i=0,j=n-1;
    for(int i=0;i<n-1;i++)
    {
        if(vp[i].first+vp[i+1].first>=vp[i].second+vp[i+1].second)
        {
            ans++;
            i++;
        }
        else
        {
            vp[i+1].first+=vp[i].first;
            vp[i+1].second+=vp[i].second;

        }
    }
    cout<<ans<<endl;
    
}

    bool check(string s, string goal) 
    {
        for(int i=0;i<s.size();i++){
            s+=s[0];
            s.erase(0,1);
            if(s==goal)return true;
        }
        return false;
    }

int32_t main()
{
    string s1,s2;
    int n=s1.size();
    int m=s2.size();
    if(n!=m)return false;
    string a="",b="";
    for(int i=0;i<n;i++)
    {
        if(s1[i]==' ')continue;
        else a+=s1[i];
    }

    for(int i=0;i<n;i++)
    {
        if(s2[i]==' ')continue;
        else b+=s2[i];
    }
    bool ans;
    ans= check(a,b);
    if(ans==true) cout<<"TRUE";
    else cout<<"FALSE";
    

}
