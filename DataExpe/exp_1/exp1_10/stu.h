// 任务描述
// 本关任务：编写一个函数实现顺序表的插入操作。
// 函数原型：status ListInsert(SqList &L,int i,ElemType e)
// 功能说明：如果线性表L不存在，返回INFEASIBLE；否则在线性表L的第i个元素前插入新的元素e，插入成功返回OK，失败返回ERROR。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.顺序表的定义，3. 线性表插入操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数ListInsert的编写

// 测试说明
// 平台会自动读取输入数据，对你编写的代码进行测试，并输出结果。

// 测试输入：0；此时表示对不存在的线性表进行插入操作
// 预期输出：
// INFEASIBLE

// 测试输入：1 11 12 13 14 15 0 3 20，第一个数1表示对一个已存在的线性表进行操作，后续是一个以0结束的数据元素序列，最后2个数据分别代表插入位置和新元素值。 后续含义相同。
// 预期输出：
// OK
// 11 12 20 13 14 15

// 测试输入：1 11 12 13 14 15 0 8 20
// 预期输出：
// ERROR
// 11 12 13 14 15

// 测试输入：1 11 12 13 14 15 0 0 20
// 预期输出：
// ERROR
// 11 12 13 14 15

status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    if (!L.elem) { // 如果线性表不存在
        return INFEASIBLE;
    } else if (i <= 0 || i > L.length+1) { // i值不合法
        return ERROR;
    } else if (L.length == L.listsize || i > L.length) {  // 溢出
        L.elem = (ElemType *)realloc(L.elem, sizeof(ElemType)*(LIST_INIT_SIZE+10));
        if (!L.elem) {
            return ERROR;
        }
    }

    int j;
    for (j = L.length; j > i-1; j--) {
        L.elem[j] = L.elem[j-1];
    }
    L.elem[j] = e;
    L.length++;

    return OK;
    /********** End **********/
}