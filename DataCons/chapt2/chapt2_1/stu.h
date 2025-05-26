// 任务描述
// 本关任务：已知顺序表L中的数据元素递增有序，数据元素类型为int。相关定义如下：
// #define LIST_INIT_SIZE 20
// #define LISTINCREMENT 10
// typedef int ElemType;
// typedef struct
//    { ElemType *elem;
//      int length;
//      int listsize;
//     } SqList;
// 试写一算法，将x插入到顺序表的适当位置上，以保持该表的有序性。
// 函数原型：int insert(SqList &L,ElemType x);

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的物理结构，2.线性表的运算。

// 编程要求
// 根据提示，在右侧编辑器补充代码，写出函数 int insert(SqList &L,ElemType x) 的定义。

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：0 1 
// 预期输出：   1

// 测试输入：1 3 5 7 9 0 6
// 预期输出：   1   3   5   6   7   9

typedef int ElemType;
typedef struct
{   ElemType *elem;
    int length;
    int listsize;
} SqList;

int insert(SqList &L, ElemType x) {
    // 检查表是否已满
    if (L.length + 1 > L.listsize) {
        ElemType *newspace = (ElemType *)realloc(L.elem, (L.length + 1) * sizeof(ElemType));
        if (!newspace) return 0;
        L.elem = newspace;
        L.listsize++;
    }

    // 找到第一个大于x的元素的位置
    int i = 0;
    while (i < L.length && L.elem[i] < x) {
        i++;
    }

    // 从最后一个元素开始，逐个后移，为x腾出位置
    for (int j = L.length; j > i; j--) {
        L.elem[j] = L.elem[j - 1];
    }

    // 插入x
    L.elem[i] = x;
    L.length++;  // 更新表的长度

    return 1;  // 插入成功
}


int insert(SqList &L,ElemType x){
    /**********begin**********/
    int left = 0, right = L.length - 1;
    while (left <= right) {    
        int mid = (left + right) / 2;    
        if (x < L.elem[mid]) {        
            right = mid - 1;    }    
        else {        
            left = mid + 1;    
        }
    }
    int index = left;
    ElemType *newElem = (ElemType *)realloc(L.elem, (L.length + 1) * sizeof(ElemType));
    if (!newElem) {    
        printf("Erro");    
        return 0;
    }
    L.elem = newElem;
    L.length += 1, L.listsize += sizeof(ElemType);
    for (int i = L.length - 2; i >= index; i--) {    
        L.elem[i+1] = L.elem[i];
    }
    L.elem[index] = x;
    return 1;
    /**********end**********/
}
