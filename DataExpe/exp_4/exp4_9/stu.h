// 本关任务：编写一个函数实现插入弧。
// 函数原型：status InsertArc(ALGraph &G,KeyType v,KeyType w)；
// 功能说明：v、w是和G中顶点关键字类型相同的给定值；操作结果是在图G中增加弧<v,w>。成功返回OK，否则返回ERROR。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.插入弧操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数InsertArc的编写。
// 插入表结点时，约定用首插法。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是v和w的值；正确创建无向图的邻接表后，再调用函数InsertArc插入弧<v,w>。操作成功时，输出所有顶点以及关系数据。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 8
// 预期输出：
// 5 线性表 2 3
// 8 集合 3 2
// 7 二叉树 1 3 0
// 6 无向图 1 2 0
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  6 5
// 预期输出： 插入弧操作失败
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  16 15
// 预期输出： 插入弧操作失败

status InsertArc(ALGraph& G, KeyType v, KeyType w)
//在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    // 查找关键字为v的顶点位置
    if (G.vexnum < 2) return INFEASIBLE;

    int indexv = -1;
    int indexw = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (indexv < 0 || indexw < 0) {    // 查找
            int k = G.vertices[i].data.key;
            if (k == v)
                indexv = i;
            if (k == w)
                indexw = i;
        } else break;
    }
    if (indexv < 0 || indexw < 0) return ERROR; // 没有找到顶点v和w

    ArcNode* p;
    ArcNode* pnew;

    // 检查原有的弧
    p = G.vertices[indexv].firstarc;
    while (p) {
        if (p->adjvex == indexw) return ERROR;   // 弧线已经存在
        p = p->nextarc;
    }

    //  对v操作
    p = G.vertices[indexv].firstarc;
    pnew = (ArcNode*)malloc(sizeof(ArcNode));
    pnew->adjvex = indexw;
    pnew->nextarc = p;
    G.vertices[indexv].firstarc = pnew;

    //  对w操作
    p = G.vertices[indexw].firstarc;
    pnew = (ArcNode*)malloc(sizeof(ArcNode));
    pnew->adjvex = indexv;
    pnew->nextarc = p;
    G.vertices[indexw].firstarc = pnew;

    G.arcnum++;

    return OK;
    /********** End **********/
}