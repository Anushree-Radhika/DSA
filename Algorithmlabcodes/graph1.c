#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
        int vertex,weight;
        struct Node* next;
}Node;

typedef struct UnweightNode{
        int vertex;
        struct UnweightNode* next;
}UnNode;

UnNode* UnEdges[101];
Node* Edges[101];

void addEdge(int src, int des, int wei){

        Node* x = (Node *)malloc(sizeof(Node));
        x->vertex = des;
        x->weight = wei;
        x->next = Edges[src];
        Edges[src] = x;
        Node *y = (Node *)malloc(sizeof(Node));
        y->vertex = src;
        y->weight = wei;
        y->next = Edges[des];
        Edges[des] = y;
}

void addEdgeUnweighted(int src,int des){
        UnNode* x = (UnNode *)malloc(sizeof(UnNode));
        x->vertex = des;
        x->next = UnEdges[src];
        UnEdges[src] = x;
        UnNode *y = (UnNode *)malloc(sizeof(UnNode));
        y->vertex = src;
        y->next = UnEdges[des];
        UnEdges[des] = y;

}

int main(){

        for(int i = 1; i <= 100; i++){
                Edges[i] = NULL;
                UnEdges[i] = NULL;
        }

        // Weighted Adjacency List
        for(int i = 0;i<120;i++){
                int src = (rand()%100)+1;
                int des = (rand()%100)+1;
                int wei = (rand()%10)+1;
                addEdge(src,des,wei);
        }
        //Unweighted Adjacency List

        for(int i = 0;i<120;i++){
                int src = (rand()%100)+1;
                int des = (rand()%100)+1;
                addEdgeUnweighted(src,des);
        }
        // Weighted Adjacency List

        for(int i = 1;i<=100;i++){
                Node* z = Edges[i];
                printf("%d ->",i);
                while(z != NULL){
                        printf("%d (%d)->",z->vertex,z->weight);
                                                z = z->next;
                }
                printf("\n");
        }

        printf("\n");

        // Unweighted Adjacency List

        for(int i = 1;i <= 100;i++){
                UnNode* z = UnEdges[i];
                printf("%d ->",i);
                while(z != NULL){
                        printf("%d ->",z->vertex);
                        z = z-> next;
                }
                printf("\n");
        }
        printf("\n");
        // Weighted Adjacency Matrix

        int matrix[101][101] = {0};
        for(int i = 1;i<=4500;i++){

                int src = (rand()%100)+1;
                int des = (rand()%100)+1;
                int wei = (rand()%10)+1;
                matrix[src][des] = wei;
                matrix[des][src] = wei;
        }

        for(int i = 1;i<= 100;i++){
                printf("Vertex %d connected to:",i);
                                for(int j = 1;j<=100;j++){
                        printf("%d ",matrix[i][j]);

                }
                printf("\n");
        }

        // Unweighted Adjacency Matrix
        printf("\n");

        int unmatrix[101][101] = {0};
        for(int i = 1;i<= 4500;i++){

                int src = (rand()%100)+1;
                int des = (rand()%100)+1;
                unmatrix[src][des] = 1;
                unmatrix[des][src] = 1;
        }

        for(int i = 1;i<= 100;i++){
                printf("\n");
                for(int j = 1;j<=100;j++){
                        printf("%d ",unmatrix[i][j]);

                }
                printf("\n");
        }
        return 0;
}
