// 本关任务：编写一个函数查找顶点u的第一邻接点。
// 函数原型：int FirstAdjVex(ALGraph G,KeyType u)；
// 功能说明：u是和G中顶点关键字类型相同的给定值；返回关键字为u的顶点第一个邻接顶点位置序号（简称位序），否则返回-1。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.获得第一邻接点操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数FirstAdjVex的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是关键字u的值；正确创建无向图的邻接表后，调用函数FirstAdjVex，根据u进行查找。查找成功时，输出对应顶点第一个邻接顶点值。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  7 
// 预期输出： 8 集合
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  10 
// 预期输出： 查找失败

int FirstAdjVex(ALGraph G, KeyType u)
//根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!G.vexnum || !G.arcnum) return INFEASIBLE;

    int index = -1;
    for (int i = 0; i < G.vexnum;i++) {
        if (G.vertices[i].data.key == u) {
            index = i;
            break;
        }
    }
    if (index < 0) return INFEASIBLE;
    ArcNode* p = G.vertices[index].firstarc;
    if (!p) return INFEASIBLE;
    else return p->adjvex;
    /********** End **********/
}
