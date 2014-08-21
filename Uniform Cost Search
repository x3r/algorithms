#include<stdio.h>
#include<iostream>
#include<queue>
#include<limits.h>
#include<vector>
#define MAX 20
using namespace std;
int G[MAX][MAX], nodes, dist[MAX], set[MAX], parent[MAX];
int findIndex()
{
    int min = INT_MAX, index=0;
    for(int i=1; i<=nodes; i++)
    {
        if(!set[i] && dist[i]<=min)
        {
            min=dist[i], index = i;
        }
    }
    return index;
}
int ucs(int s)
{
    for(int i=1; i<=nodes; i++)
    {
        dist[i]=INT_MAX;
    }
    dist[s]=0;
    parent[s]=0;
    for(int i=1; i<=nodes; i++)
    {
        int u = findIndex();
        set[u]=1;
        for(int v=1; v<=nodes; v++)
        {
            if(!set[v] && G[u][v] && dist[u]!=INT_MAX && dist[u]+G[u][v]<dist[v])
            {
                parent[v]=u;
                dist[v] = dist[u]+G[u][v];
            }
        }
    }
}
int main()
{
    scanf("%d",&nodes);
    int edges, u, v, w, src, dest;
    scanf("%d",&edges);
    for(int i=0; i<edges; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        G[u][v]=w;
        G[v][u]=w;
    }
    scanf("%d%d",&src,&dest);
    ucs(src);
    int i=dest;
    printf("Cost = %d\nPath = %d",dist[dest], dest);
    while(parent[i]!=0)
    {
        printf("<--%d",parent[i]);
        i=parent[i];
    }
    return 0;
}
