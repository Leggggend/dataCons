#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int KeyType; 

typedef struct {   // ������������Ͷ���
     KeyType  key;
	char others[20];
} TElemType;        

typedef struct {    // �������������
     int pos;
     TElemType data;
} DEF;

typedef struct BiTNode{     // ����������Ķ���
	TElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
} BiTNode, *BiTree;

typedef struct{         // ɭ�ֵĶ���
     struct { 
          char name[30];
          BiTree T;
     } elem[10];
     int length;
} Forest, *BiForest;
