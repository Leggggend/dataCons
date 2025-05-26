// 本关任务：编写一个函数查找v顶点的邻接点中w的下一个。
// 函数原型：int NextAdjVex(ALGraph G,KeyType v,KeyType w)；
// 功能说明：v和w是G中两个顶点的位序，v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.获得下一邻接点操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数NextAdjVex的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是关键字v和w的值；正确创建无向图的邻接表后，调用函数NextAdjVex，进行相关查找。查找成功时，输出v顶点邻接顶点中相对于w的下一顶点值。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  7 8 
// 预期输出： 6 无向图
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1   7 5
// 预期输出： 无下一邻接顶点
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  10 5 
// 预期输出： 无下一邻接顶点

int NextAdjVex(ALGraph G, KeyType v, KeyType w)
//v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!G.vexnum || !G.arcnum) return INFEASIBLE;

    int index = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v) {
            index = i; break;
        }
    }
    if (index < 0) return INFEASIBLE;      // 没有v结点
    ArcNode* p = G.vertices[index].firstarc;
    while (p) {
        if (G.vertices[p->adjvex].data.key == w) {
            if (!p->nextarc) return INFEASIBLE; // w是最后一个结点
            return p->nextarc->adjvex;
        }
        p = p->nextarc;
    }
    return INFEASIBLE;
    /********** End **********/
}
