#include<stdio.h>
#include<iostream>
#include<queue>
#include<limits.h>
#include<vector>
#define BLACK 2
#define GRAY 1
#define WHITE 0
#define MAX 100
using namespace std;
int G[MAX][MAX], nodes, dist[MAX], set[MAX], parent[MAX], h[MAX], f[MAX], color[MAX], dest;
bool isEmpty()
{
    for(int i=1; i<=nodes; i++)
        if(set[i]==0)
            return 0;
    return 1;
}
int findIndex()
{
    int min = INT_MAX, index=0;
    for(int i=1; i<=nodes; i++)
    {
        if(!set[i] && f[i]<=min)
        {
            min=dist[i], index = i;
        }
    }
    return index;
}
int astar(int s)
{
    for(int i=1; i<=nodes; i++)
    {
        dist[i]=INT_MAX;
        color[i]=WHITE;
        f[i]=INT_MAX;
        set[i]=1;
    }
    dist[s]=0;
    parent[s]=0;
    color[s]=GRAY;
    f[s] = h[s];
    set[s] = 0;
    while(!isEmpty())
    {
        int u = findIndex();
        if(u==dest)
            break;
        set[u] = 1;
        for(int v=1; v<=nodes; v++)
        {
            if(G[u][v] && dist[u]!=INT_MAX && dist[u]+G[u][v]<dist[v])
            {
                parent[v]=u;
                dist[v] = dist[u]+G[u][v];
                f[v]=dist[v]+h[v];
                if (color[v] == WHITE)
                {
                    color[v] = GRAY;
                    set[v]=0;
                }
                else if (color[v] == BLACK)
                {
                    color[v] = GRAY;
                    set[v]=0;
                }
            }
            color[u] = BLACK;
        }
    }
}
int main()
{
    printf("A* Search:\n");
    freopen("a.txt","r",stdin);
    scanf("%d",&nodes);
    int edges, u, v, w, src;
    scanf("%d",&edges);
    for(int i=0; i<edges; i++)
    {
        scanf("%d%d%d",&u,&v,&w);
        G[u][v]=w;
        G[v][u]=w;
    }
    for(int i=1; i<=nodes; i++)
        scanf("%d",&h[i]);
    scanf("%d%d",&src,&dest);

    astar(src);
    int i=dest;
    printf("Source: %d\tDestination: %d\n",src,dest);
    printf("Cost = %d\nPath = %d",f[dest], dest);
    while(parent[i]!=0)
    {
        printf("<--%d",parent[i]);
        i=parent[i];
    }
    printf("\n");
    return 0;
}
