// 任务描述
// 本关任务：编写程序实现循环队列。
// 假定以循环队列定义为：以域变量front和length分别指示循环队列中的队首元素的位置和内含元素的个数。试编写实现循环队列3个函数：
// 初始化队列iniQueue、入队enQueue和出队deQueue

// 相关知识
// 为了完成本关任务，你需要掌握：1.队列，2.循环队列。
// 循环队列数据类型：
// #define MAXLENGTH 100
// typedef struct QUEUE {
//      ElemType elem[MAXLENGTH];
//      int front，length;
//      } QUEUE;

// 编程要求
// 根据提示，在右侧编辑器补充代码，实现3个函数；相应函数原型如下：
// int iniQueue（QUEUE &Q）；
// int enQueue（QUEUE &Q，ElemType e）；
// int deQueue（QUEUE，ElemType &e）；

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：0    系统测试初始化
// 预期输出： OK

// 测试输入：1    系统测试入队
// 预期输出： OK

// 测试输入：2    系统测试出队
// 预期输出： OK

// 测试输入：3  1 1 1 -1 -1 1 1 0    系统测试进出队操作序列，第一个3代表此含义，对提供的整数序列1、2、3、...，后面1代表进队操作，-1代表出队操作，0代表操作结束，完成操作序列后，依次显示队首到队尾的元素值。
// 预期输出：  3 4 5

//在下面的begin和end间填写相应代码
void iniQueue(QUEUE &Q)
//该函数实现初始化Q
{
/***************begin***************/
    Q.front = 0;
    Q.length = 0;

/*************** end ***************/
}
int enQueue(QUEUE &Q,ElemType e)
//将元素e入队Q。成功入栈返回1，否则返回0
{
/***************begin***************/
    if (Q.length >= MAXLENGTH) {
        return 0;
    } else {
        int index = (Q.front + Q.length) % MAXLENGTH; // 找到要插入的位置
        Q.elem[index] = e;
        Q.length++;
        return 1;
    }

/*************** end ***************/
}
int deQueue(QUEUE &Q, ElemType &e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
/***************begin***************/
    if (Q.length == 0) { // 判断非空
        return 0;
    } else {
        e = Q.elem[Q.front];
        Q.front = (Q.front + 1) % MAXLENGTH;
        Q.length--;
        return 1;        
    }

/*************** end ***************/
}
