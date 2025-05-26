// 任务描述
// 本关任务：编写程序实现双向栈。
// 假定以顺序存储结构实现一个双向栈，即在一个一维数组的存储空间中存在着两个栈，它们的栈底分别设在数组的两个端点。试编写实现着个双向栈的3个函数：
// 初始化栈inistack、入栈push和出栈pop

// 相关知识
// 为了完成本关任务，你需要掌握：1.栈，2.双向栈。
// 双向栈的物理结构示意图如下：

// 相应地，根据该示意图定义其数据类型：
// #define N 100
// typedef struct TWSTACK {
//      ElemType elem[N];
//      int top1,top2;
//      } TWSTACK;

// 编程要求
// 根据提示，在右侧编辑器补充代码，实现3个函数；相应函数原型如下：
// int inistack（TWSTACK &S）；
// int push（TWSTACK &S，int i，ElemType e）；
// int pop（TWSTACK &S，int i，ElemType &e）；

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：0    系统测试初始化
// 预期输出： OK

// 测试输入：1    系统测试入栈
// 预期输出： OK

// 测试输入：2    系统测试出栈
// 预期输出： OK

// 测试输入：3  1 1 1 -1 -1 1 1 0    系统仅测试第一个栈的进出栈操作序列，第一个3代表此含义，对提供的整数序列1、2、3、...，后面1代表进栈操作，-1代表出栈操作，0代表操作结束，完成操作序列后，依次显示栈底到栈顶的元素值。
// 预期输出：  1 4 5

//在下面的begin和end间填写相应代码
void inistack(TWSTACK &S)
//该函数实现初始化S，得到2个空栈。根据双向栈的示意图，理解初始化要求。
{
/***************begin***************/
    S.top1 = 0;
    S.top2 = N-1;

/*************** end ***************/
}
int push(TWSTACK &S,int i,ElemType e)
//i取值1或2，分别对应左或右栈，将元素e压入S的对应栈。成功入栈返回1，否则返回0
{
/***************begin***************/
    if (S.top1 > S.top2) {    //满栈
        return 0;
    } else {
        switch (i) {
            case 1: 
                S.elem[S.top1++] = e;
                break;
            case 2:
                S.elem[S.top2--] = e;
                break;
            default:
                return 0;
        }
        return 1;
    }

/*************** end ***************/
}
int pop(TWSTACK &S,int i, ElemType &e)
//i取值1或2，分别对应左或右栈，将S对应栈的栈顶元素出栈，赋值给e。成功出栈返回1，否则返回0
{
/***************begin***************/
    switch (i) {
        case 1:
            if (S.top1 == 0) { //下溢
                return 0;
            } else {
                e = S.elem[--S.top1];
                return 1;
            }
            break;
        case 2:
            if (S.top2 == N - 1) { //下溢
                return 0;
            } else {
                e = S.elem[++S.top2];
                return 1;
            }
            break;
        default:
            return 0;
    }
/*************** end ***************/
}
