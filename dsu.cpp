#include <bits/stdc++.h>
using namespace std;
int const N=1e5+10;
int parent[N],size[N];
void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        make_set(i);
    }
    while(k--)
    {
        int u,v;
        cin>>u>>v;
        union_sets(u,v);

    }
    int connected=0;
    for(int i=1;i<=n;i++)
    {
        if(i==find_set(i))
            connected++;
    }
    cout<<connected<<endl;




}

