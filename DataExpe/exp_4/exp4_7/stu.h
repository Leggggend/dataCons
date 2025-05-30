// 本关任务：编写一个函数实现插入顶点。
// 函数原型：stasus InsertVex(ALGraph &G,VertexType v)；
// 功能说明：在图G中插入新顶点关v（要求关键字具有唯一性，注意判断顶点个数是否已满）。成功返回OK，否则返回ERROR。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.插入顶点操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数InsertVex的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是新顶点v的值；正确创建无向图的邻接表后，再调用函数InsertVex将顶点v插入。操作成功时，输出所有顶点以及关系数据。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  9 有向图
// 预期输出：
// 5 线性表 2 3
// 8 集合 2
// 7 二叉树 1 3 0
// 6 无向图 2 0
// 9 有向图
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  8 有向图
// 预期输出： 插入操作失败

status InsertVex(ALGraph& G, VertexType v)
//在图G中插入顶点v，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    int i = 0;
    for (i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v.key) {
            return ERROR; // 关键字重复
        }
    }
    if (i >= MAX_VERTEX_NUM) {
        return ERROR;
    }
    G.vertices[i].data.key = v.key;
    strcpy(G.vertices[i].data.others, v.others);
    G.vexnum++;
    return OK;
    /********** End **********/
}
