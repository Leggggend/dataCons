// ��������
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;
typedef int ElemType; 
#define LIST_INIT_SIZE 100
#define LISTINCREMENT  10
typedef struct {  // ���Ա�
	ElemType * elem;
     int length;
     int listsize;
} SqList;
typedef struct {  // �ܱ�
     struct { 
          char name[30];
     	SqList L;	
     } elem[10];
     int length;
     int listsize;
} LISTS;