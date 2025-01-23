#include <stdio.h>
#include <stdlib.h>
#define MAX 99
struct node {
     struct node *next;
      int vertex;
};
typedef struct node * GNODE;
GNODE graph[20];
int visited[20];
int q[MAX], f = -1,r = -1;
int n;
void insertQueue(int vertex) {
     if (r == MAX - 1)
     printf("\nQueue Overflow\n");
     else {
       if (f == -1)
       f = 0;
       r = r +1;
       q[r] = vertex;
       }
}
int isEmptyQueue() {
     if (f == -1 || f > r)
     return 1;
     else
     return 0;
}
int deleteQueue() {
     int del;
      if (f == -1 || f > r) {
         printf("Queue Underflow\n");
          exit(1);
      }
       del = q[f];
       f = f +1;
       return del;
}

void BFS(int i) {
     GNODE p;
     insertQueue(i);
     printf("%d\n", i);
     visited[i]=1;

      while (!isEmptyQueue())
     {
       i = deleteQueue();
       for (p = graph[i]; p != NULL; p = p->next) {
           if (!visited[p->vertex]) {
             insertQueue(p->vertex);
             visited[p->vertex] = 1;
             printf("%d\n",p->vertex);
           }
        }
      }
}


void main() {
     int N, E, s, d, i, j, v;
     GNODE p, q;

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

     if(graph[s]==NULL) {
        graph[s]=q;
        }
      else {
        p=graph[s];
        while(p->next!=NULL)
          p=p->next;
          p->next=q;
        }
     }
            for(i=1;i<=n;i++)
            visited[i]=0;

            printf("Enter Start Vertex for BFS : ");
            scanf("%d", &v);
            printf("BFS of graph : \n");
            BFS(v);
            printf("\n");
}
