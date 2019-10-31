#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>gr[1000000];int used[1000000];
int dist[1000000];
void bfs(int s){
    used[s]=1;
    dist[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v:gr[u]){
            if(!used[v]){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
int main(void)
{
   int n,k;
   cin>>n>>k;
   while(k--){
       int u,v;
       cin>>u>>v;
       gr[u].push_back(v);
       gr[v].push_back(u);
   }
   bfs(1);
   for(int i=1;i<=n;i++){
       cout<<dist[i]<<" ";
   }
   cout<<endl;
}