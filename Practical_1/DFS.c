#include<stdio.h>
#include<stdlib.h>
struct node {
    struct node *next;
    int vertex;
};
typedef struct node * GNODE;
GNODE graph[20];
int visited[20];
int n;
void DFS(int i) {
    GNODE p;
    printf("%d\n",i);
    visited[i]=1;

    for(p = graph[i]; p!=NULL; p =p->next){
        if(!visited[p->vertex]){
            DFS(p->vertex);
        }
    }
}
void main() {
    int N,E,i,s,d,v;
    GNODE q,p;

    printf("Enter the number of vertices : ");
    scanf("%d",&N);
    printf("Enter the number of edges : ");
    scanf("%d",&E);

    for(i=1;i<=E;i++) {
        printf("Enter source : ");
        scanf("%d",&s);
        printf("Enter destination : ");
        scanf("%d",&d);

        q=(GNODE)malloc(sizeof(struct node));
        q->vertex=d;
        q->next=NULL;

        if(graph[s]==NULL)
            graph[s]=q;
        else {
            p=graph[s];
            while(p->next!=NULL)
                p=p->next;
                p->next=q;
        }
    }

    for(i=0;i<n;i++)
        visited[i]=0;
        printf("Enter Start Vertex for DFS : ");
        scanf("%d",&v);

    printf("DFS of graph : \n");
    DFS(v);
    printf("\n");
}
