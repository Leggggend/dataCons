// 本关任务：编写一个函数实现广度优先搜索遍历。
// 函数原型：status BFSTraverse(ALGraph &G,void (*visit)(VertexType))；
// 功能说明：对图G进行广度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.图遍历操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数BFSTraverse的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是v和w的值；正确创建无向图的邻接表后，再调用函数BFSTraverse进行广度优先搜索遍历，输出遍历过程中访问的顶点序列。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1
// 预期输出：
// 5 线性表 7 二叉树 6 无向图 8 集合

status BFSTraverse(ALGraph& G, void (*visit)(VertexType)) {
    int visited[MAX_VERTEX_NUM] = { 0 };
    int queue[MAX_VERTEX_NUM];
    int front = 0;
    int rear = 0;

    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            visit(G.vertices[i].data);
            queue[rear++] = i;

            while (front < rear) {
                int v = queue[front++];
                ArcNode* p = G.vertices[v].firstarc;
                while (p != NULL) {
                    if (!visited[p->adjvex]) {
                        visited[p->adjvex] = 1;
                        visit(G.vertices[p->adjvex].data);
                        queue[rear++] = p->adjvex;
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    return OK;
}