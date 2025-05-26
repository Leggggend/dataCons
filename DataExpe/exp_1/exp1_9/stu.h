// 任务描述
// 本关任务：编写一个函数实现线性表元素后继的获取。
// 函数原型：status NextElem(SqList L,ElemType e,ElemType &next)
// 功能说明：若线性表L不存在，返回INFEASIBLE；若没有找到指定元素e的后继，则查找失败，返回ERROR；若查找成功，则将值赋给next，并返回OK。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.顺序表的定义，3.线性表获取后继元素操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数NextElem的编写

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：1 11 12 13 14 15 0 14，第一个数1表示对一个已存在的线性表进行操作，后续是一个以0结束的数据元素序列，最后1个数据代表待查找后继的元素值。后续含义相同。
// 预期输出：
// OK
// 15

// 测试输入：1 11 12 13 14 15 0 15
// 预期输出：
// ERROR

// 测试输入：1 11 12 13 14 15 0 18
// 预期输出：
// ERROR

// 测试输入：0，此时表示对不存在的线性表进行查找
// 预期输出：
// INFEASIBLE

status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L.elem) { // 如果线性表不存在
        return INFEASIBLE;
    } 

    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            if (i == L.length-1) { // 如果是第一个
                return ERROR;
            } else {
                next = L.elem[i+1];
                return OK;
            }
        }
    }

    return ERROR;

    /********** End **********/
}