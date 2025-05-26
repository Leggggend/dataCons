// 本关任务：编写一个函数实现删除顶点。
// 函数原型：stasus DeleteVex((ALGraph &G,KeyType v)；
// 功能说明：v是和G中顶点关键字类型相同的给定值；操作结果是在图G中删除关键字v对应的顶点以及相关的弧。成功返回OK，否则返回ERROR。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.删除顶点操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数DeleteVex的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是v的值；正确创建无向图的邻接表后，再调用函数DeleteVex将顶点v删除。操作成功时，输出所有顶点以及关系数据。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  7
// 预期输出：
// 5 线性表 2
// 8 集合
// 6 无向图 0
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  10
// 预期输出： 删除顶点操作失败

// 5 线性表 -1 nil -1 -1 5

status DeleteVex(ALGraph& G, KeyType v) {
    if (!G.arcnum || !G.vexnum) return INFEASIBLE;
    // 查找关键字为v的顶点位置
    int index = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v) {
            index = i;
            break;
        }
    }
    if (index == -1) return ERROR; // 没有找到顶点v

    // 删除以index为头结点的弧表
    ArcNode* p = G.vertices[index].firstarc;
    while (p != NULL) {
        ArcNode* temp = p;
        p = p->nextarc;
        free(temp); // 释放弧节点
    }
    G.vertices[index].firstarc = NULL;

    // 删除所有指向index的弧
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode* p = G.vertices[i].firstarc;
        ArcNode* prev = NULL;
        while (p != NULL) {
            if (p->adjvex == index) {
                if (prev == NULL)
                    G.vertices[i].firstarc = p->nextarc;
                else
                    prev->nextarc = p->nextarc;
                free(p);
                p = prev ? prev->nextarc : G.vertices[i].firstarc;
                G.arcnum--;
            } else {
                if (p->adjvex > index) p->adjvex--;
                prev = p;
                p = p->nextarc;
            }
        }
    }
    // 将第index个顶点之后的顶点位置前移
    for (int i = index; i < G.vexnum - 1; i++)
        G.vertices[i] = G.vertices[i + 1];
    G.vexnum--; // 更新顶点数
    return OK;
}