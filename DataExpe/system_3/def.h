#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int KeyType; 

typedef struct {   // 二叉树结点类型定义
     KeyType  key;
	char others[20];
} TElemType;        

typedef struct {    // 满二叉树结点编号
     int pos;
     TElemType data;
} DEF;

typedef struct BiTNode{     // 二叉链表结点的定义
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct{         // 森林的定义
     struct { 
          char name[30];
          BiTree T;
     } elem[10];
     int length;
} Forest, *BiForest;
