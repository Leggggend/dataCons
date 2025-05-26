// 本关任务：编写一个函数实现顶点赋值。
// 函数原型：stasus PutVex(ALGraph &G,KeyType u,VertexType value)；
// 功能说明：u是和G中顶点关键字类型相同的给定值；操作结果是对关键字为u的顶点赋值value（要求关键字具有唯一性）。成功赋值返回OK，否则返回ERROR。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.顶点赋值操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数PutVex的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是关键字u和value的值；正确创建无向图的邻接表后，调用函数PutVex，根据u进行查找到顶点，赋值value。赋值操作成功时，输出所有顶点数据。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 9 有向图
// 预期输出： 5 线性表 8 集合 7 二叉树 9 有向图
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  10 9 有向图
// 预期输出： 赋值操作失败
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 5 有向图
// 预期输出： 赋值操作失败

#include <string.h>
status PutVex(ALGraph& G, KeyType u, VertexType value)
//根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；
//如果查找失败或关键字不唯一，返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (G.vexnum == 0) return INFEASIBLE;
    int index = -1;
    int bad = -1;      // 检测重复关键字
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == value.key) {
            bad = i; break;
        }
        if (G.vertices[i].data.key == u) {
            index = i; break;
        }
    }
    if (index >= 0 && (bad < 0 || bad == index)) {
        G.vertices[index].data.key = value.key;
        strcpy(G.vertices[index].data.others, value.others);
        return OK;
    } else return ERROR;
    /********** End **********/
}
