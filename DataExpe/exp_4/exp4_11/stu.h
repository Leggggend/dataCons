// 本关任务：编写一个函数实现深度优先搜索遍历。
// 函数原型：status DFSTraverse(ALGraph &G, void (*visit)(VertexType))；
// 功能说明：对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.图遍历操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数DFSTraverse的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是v和w的值；正确创建无向图的邻接表后，再调用函数DFSTraverse进行深度优先搜索遍历，输出遍历过程中访问的顶点序列。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1
// 预期输出：
// 5 线性表 7 二叉树 8 集合 6 无向图

// 深度优先搜索递归函数
void DFS(ALGraph& G, int v, void (*visit)(VertexType), int visited[]) {
    visit(G.vertices[v].data);
    visited[v] = 1;
    ArcNode* p = G.vertices[v].firstarc;
    while (p != NULL) {
        if (!visited[p->adjvex])
            DFS(G, p->adjvex, visit, visited);
        p = p->nextarc;
    }
}

status DFSTraverse(ALGraph& G, void (*visit)(VertexType)) {
    int visited[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    // 对图中的每个顶点进行深度优先搜索
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) // 若顶点未被访问，则从该顶点开始进行深度优先搜索
            DFS(G, i, visit, visited);
    }
    return OK;
}