#include <bits/stdc++.h>
#define ll long long int
#define N 1000
#define M 1000000007
#define f(i, a, b) for (ll i = (ll)a; i <= (ll)b; i++)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define po pop_back
#define pb push_back
#define lb lower_bound
#define fi first
#define se second
#define mp make_pair
#define bs binary_search
#define debug(x) cout << #x << " = " << x << endl
#define ub upper_bound
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define all(x) x.begin(), x.end()
#define PI 3.14159265
#define cot cout.tie(0)
using namespace std;
/**
  * @author :: Rishabh
  *
  */
unordered_map<int,vector<pair<int,int>>>adj;
void addedge(int v1,int v2,int f,int wt)
{
    adj[v1].pb(make_pair(v2,wt));
    if(f==1)
        adj[v2].pb(make_pair(v1,wt));
}
void printgraph()
{
    for(auto it:adj)
    {
        cout<<it.first;
        vector<pair<int,int>> temp=it.second;
        for(auto x:temp)
        {
            cout<<"-> ("<<x.first<< " , "<<x.second<<") ";
        }
        cout<<"\n";
    }
}
int main()
{
    ibs;
    cti;
    int t;
    cin>>t;
    while(t--)
    {
        int v,e;
        cin>>v>>e;
        while(e--)
        {
            int v1,v2,d;
            int f;
            cin>>v1>>v2>>d>>f;
            // 1 = true means this edge is bidirectional/undirected
            // 0 = false means this edge is directional
            addedge(v1,v2,f,d);
        }
        printgraph();
        adj.clear();
    }
    return 0;
}