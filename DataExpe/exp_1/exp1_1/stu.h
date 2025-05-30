// 任务描述
// 本关任务：编写一个函数实现线性表的初始化。
// 函数原型：status InitList(SqLIST &L)
// 功能说明：如果线性表L不存在，操作结果是构造一个空的线性表，返回OK，否则返回INFEASIBLE。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.顺序表的定义，3. 初始化操作的语义，4. 引用参数的概念。
// 后台已经给出，可以直接使用的有关定义（详细代码可在编程界面右上方的文件夹图标下查看）：


// #define TRUE 1
// #define FALSE 0
// #define OK 1
// #define ERROR 0
// #define INFEASIBLE -1
// #define OVERFLOW -2
// typedef int status;
// typedef int ElemType; //数据元素类型定义
// #define LIST_INIT_SIZE 100
// #define LISTINCREMENT  10
// typedef int ElemType；
// typedef struct{  //顺序表（顺序结构）的定义
//       ElemType * elem;
//       int length;
//       int listsize;
//  }SqList;
// 有关约定说明：
// （1）如下图所示，L的elem成员为空，表示未分配数据元素的空间，线性表L不存在，可以进行初始化操作。

// （2）下图中L的成员elem指向100个数据元素的空间，当前有5个元素，如果进行初始化操作，就会改变elem的指向，造成现有数据丢失，所以对存在的线性表不允许再初始化。

// （3）对成功完成初始化L后，得到一个空线性表，对应的物理结构示意图如下：


// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数InitList的编写

// 测试说明
// 平台会自动读入输入数据，评测程序根据输入设置不同状态，对你编写的代码进行测试：特别要说明的是实验中，各题目函数只要正确实现其功能就行，一般不用考虑输入输出格式，这些由后台测试程序负责处理。

// 测试输入：0；此时表示对不存在的线性表初始化，评测程序会设置一个不存在的线性表，调用此关函数进行初始化。
// 预期输出：
// OK

// 测试输入：1，此时表示对已存在的线性表初始化，评测程序会设置一个存在的线性表，调用此关函数进行初始化。
// 预期输出：
// INFEASIBLE

status InitList(SqList& L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) { // 如果非空
        return INFEASIBLE;
    }
        
    L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (!L.elem) {
        return ERROR;
    }  
    L.listsize = LIST_INIT_SIZE;
    L.length = 0;
    return OK;
    /********** End **********/
}
