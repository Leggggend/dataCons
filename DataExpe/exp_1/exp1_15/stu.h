// 任务描述
// 本关任务：编写一个函数实现移除一个指定的线性表。
// 函数原型：status RemoveList(LISTS &Lists,char ListName[])
// 功能说明：Lists是一个以顺序表形式管理的线性表的集合，在集合中查找名称为ListName的线性表，有则删除，返回OK，无则返回ERROR。

// 相关知识
// 为了完成本关任务，你需要掌握：1.线性表的概念，2.顺序表的定义，3. 删除线性表操作的语义。

// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数
// status RemoveList(LISTS &Lists,char ListName[])的编写
// 此关要调用第1、2、10、12和14关的函数，所以要求这五关要提前通过才能完成此关任务。

// 测试说明
// 测试输入数据说明，第一行数n是要增加的线性表个数，调用你编写的函数增加n个空线性表到集合中；接着每行是一个线性表名称和以0结束的线性表数据元素，后台自动读入这些数据，依次插入到对应线性表中。最后一行是要删除的线性表名称，删除成功后显示剩余的线性表。

// 测试输入：3
//           湖北 5 10 20 30 50 0；
//           北京 30 50 60 70 80 0；
//           湖南 3 12 21 13 60 0；
//           北京
// 预期输出：湖北 5 10 20 30 50；
//        湖南 3 12 21 13 60；

// 测试输入：2
//           湖北 5 10 20 30 50 0；
//           湖南 3 12 21 13 60 0；
//           北京
// 预期输出：删除失败
#include <string.h>
status RemoveList(LISTS &Lists,char ListName[])
// Lists中删除一个名称为ListName的线性表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (Lists.length == 0) {
        return ERROR;
    }

    for (int i = 0; i < Lists.length; i++) {
        // 逐一对比线性表名称
        if (strcmp(Lists.elem[i].name, ListName) == 0) {
            DestroyList(Lists.elem[i].L);
            for (int j = i; j < Lists.length-1; j++) {
                Lists.elem[j] = Lists.elem[j+1];
            }
            Lists.length--;
            return OK;
        }        
    }
    return ERROR;

    /********** End **********/
}