#include<bits/stdc++.h>
using namespace std;

#define f(i,x,n) for(int i=x;i<n;i++)
#define ll long long
#define pb(i) push_back(i)
#define mp(i,j) make_pair(i,j)
#define test ll t; cin>>t; while(t--)

int main()
{
	ll n;
    cin >> n;

    vector<ll>height(n, 0);

    f(i,0,n)
	{
		cin>>height[i];
	}

    vector<ll>nexthop(n, 0);

    stack<ll>s;
    s.push(0);

    f(i,1,n)
	{
        while(!s.empty() && height[i]>height[s.top()])
		{
            nexthop[s.top()] = i;
            s.pop();
        }

        s.push(i);
    }

    while(!s.empty())
	{
        nexthop[s.top()] = -1;
        s.pop();
    }

    vector<ll>xors(n, 0);
    ll res = 0;

    for(int i = n - 1; i >= 0; i--)
	{
        if(nexthop[i] == -1)
		{
            xors[i] = height[i];
            res = max(res, xors[i]);
            continue;
        }

        xors[i] = height[i]^xors[nexthop[i]];
        res = max(res,xors[i]);
    }

    cout<<res;

    return 0;
}
