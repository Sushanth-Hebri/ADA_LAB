#include<stdio.h>
#include<conio.h>
int Q[10],f=0,r=0;
int vis[10],a[10][10];
void bfs(int v,int n){
    vis[v]=1;
    Q[r]=v;
    while(f<=r){
        int u=Q[f];
        printf("%d",u);
        for(int i=1;i<=n;i++){
            if(a[u][i]==1 && vis[i]==0){
                r=r+1;
                Q[r]=i;
                vis[i]=1;
            }
        }
        f=f+1;
    }
}

void main()
{
    int n,begin;
    int m,c,d;
    printf("Enter the number of vertices");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=0;
        }
    }

    printf("Enter the number of edges\n");
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
printf("Enter the edges");
scanf("%d%d",&c,&d);
a[c][d]=1;
    }
    printf("Enter the first node");
    scanf("%d",&begin);
    printf("BFS traversal\n");
        
            bfs(begin,n);
        
    }