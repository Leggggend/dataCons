// 基础定义
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
typedef struct {  // 线性表
	ElemType * elem;
     int length;
     int listsize;
} SqList;
typedef struct {  // 总表
     struct { 
          char name[30];
     	SqList L;	
     } elem[10];
     int length;
     int listsize;
} LISTS;