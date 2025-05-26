#include "..\def.h"
#include "stu.h"
#include "string.h"
typedef struct {
    int pos;
    TElemType data; 
} DEF;
status DestroyBiTree(BiTree &T)
{
   if (T)
   {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
        T=NULL;
   }
   return OK;
}
status CreateBiTree(BiTree &T,DEF definition[])
{
    int i=0,j;
    static BiTNode *p[100];
    while (j=definition[i].pos)
    {
    	 p[j]=(BiTNode *)malloc(sizeof(BiTNode));
       p[j]->data=definition[i].data;
       p[j]->lchild=NULL;
       p[j]->rchild=NULL;
       if (j!=1)
       		if (j%2)   p[j/2]->rchild=p[j];  
       	   else      p[j/2]->lchild=p[j];
       i++;
    }
    T=p[1];
    return OK;
}

void PreOrderTraverse(BiTree T)
{
    if (T)
    {
        printf(" %d,%s",T->data.key,T->data.others);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)
{
    if (T)
    {
        InOrderTraverse(T->lchild);
        printf(" %d,%s",T->data.key,T->data.others);
        InOrderTraverse(T->rchild);
    }
}

int main()
{
    DEF definition[100];
    BiTree T;
    TElemType e;
    int ans,i=0,key;
    do {
        scanf("%d%d%s",&definition[i].pos,&definition[i].data.key,definition[i].data.others);
    } while (definition[i++].pos);
    ans=CreateBiTree(T,definition);
    PreOrderTraverse(T);
    printf("\n");

    char FileName[20];
    strcpy( FileName,"test.txt");
    // SaveBiTree(T,"test.dat");

    if (SaveBiTree(T,FileName) != OK) printf("保存失败\n");
    else printf("保存成功\n");
    if (DestroyBiTree(T) != OK) printf("销毁失败\n");
    // LoadBiTree(T,"test.dat");
    if (LoadBiTree(T,FileName) != OK) printf("读取失败\n");
    else printf("读取成功\n");
    PreOrderTraverse(T);
    printf("\n");
    InOrderTraverse(T);
    return 0;
}
