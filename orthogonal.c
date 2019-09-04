#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *right,*down; 
} node;

node **row,**col,**lastd;
node* lastr;

node* craftnode(int value,int i,int j){
    if(*(row+i) == NULL){
        *(row+i) = (node*)malloc(sizeof(node));
        (*(row+i))->data = value;
        (*(row+i))->right = NULL;
        (*(row+i))->down = NULL;
        lastr = *(row+i);
        if(*(lastd+j) == NULL){
            *(lastd+j) = *(row+i);
            *(col+j) = *(row+i);
        }
        else{
            (*(lastd+j))->down = *(row+i);
            *(lastd+j) = *(row+i);
        }
    }
    else{
        node* temp;
        temp = (node*)malloc(sizeof(node));
        temp->data = value;
        temp->down = NULL;
        temp->right = NULL;
        lastr->right = temp;
        lastr = temp;
        if(*(lastd+j) == NULL){
            *(lastd+j) = *(row+i);
            *(col+j) = *(row+i);
        }
        else{
            (*(lastd+j))->down = *(row+i);
            *(lastd+j) = *(row+i);
        }
    }
}

int main(){
    int i,j,m,n,d,c;
    printf("enter the dimensions\n");
    scanf("%d%d",&m,&n);
    row = (node**)malloc(m*sizeof(node*));
    col = (node**)malloc(n*sizeof(node*));
    lastd = (node**)malloc(n*sizeof(node*));
    int arr[m][n];
    for(i=0;i<m;i++){
        *(row+i) = NULL;
        for(j=0;j<n;j++){
            if(i == 0){               
                *(col+j) = NULL;
                *(lastd+j) = NULL;
            }
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(arr[i][j] != 0){
                *(row+i) = craftnode(arr[i][j],i,j);
            }
        }
    }
}