#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

class DSU
{
private:
    vector<int> parent, size, rank;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

public:
    int findPar(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        // path compression -> (log n)
        // path compression and size -> O(4 x alpha)
        return parent[node] = findPar(parent[node]);
    }

public:
    void unionSize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
        {
            return;
        }
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

public:
    void unionRank(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if (pu == pv)
        {
            return;
        }
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, pair<ll, ll>>> graph;
    for (int i = 0; i < m; i++)
    {
        ll u, v, weight;
        cin >> u >> v >> weight;
        graph.push_back({weight, {u, v}});
    }
    sort(graph.begin(), graph.end());
    DSU dsu(n);
    ll total_weight = 0;
    for (int i = 0; i < m; i++)
    {
        ll weight = graph[i].first;
        ll node1 = graph[i].second.first;
        ll node2 = graph[i].second.second;
        ll parent1 = dsu.findPar(node1);
        ll parent2 = dsu.findPar(node2);
        if (parent1 != parent2)
        {
            total_weight += weight;
            dsu.unionSize(node1, node2);
        }
    }
    cout << total_weight << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
