// 本关任务：编写一个函数实现删除弧。
// 函数原型：status DeleteArc(ALGraph &G, KeyType v, KeyType w)；
// 功能说明：v、w是和G中顶点关键字类型相同的给定值；操作结果是在图G中删除弧<v,w>。成功返回OK，否则返回ERROR。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.删除弧操作的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数DeleteArc的编写。
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记,接着是v和w的值；正确创建无向图的邻接表后，再调用函数DeleteArc删除弧<v,w>。操作成功时，输出所有顶点以及关系数据。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  5 6
// 预期输出：
// 5 线性表 2
// 8 集合 2
// 7 二叉树 1 3 0
// 6 无向图 2 0
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  8 5
// 预期输出： 删除弧操作失败
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1  16 5
// 预期输出： 删除弧操作失败

status DeleteArc(ALGraph& G, KeyType v, KeyType w)
//在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    if (G.vexnum < 2 || !G.arcnum) return INFEASIBLE;

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

    ArcNode* pre, * todlt;
    int flag = 0; // 标记是否存在弧线

    //  对v操作
    todlt = G.vertices[indexv].firstarc;
    pre = NULL;
    while (todlt) {
        if (todlt->adjvex == indexw) {   // 找到弧线
            if (!pre) {    // 第一个节点
                G.vertices[indexv].firstarc = NULL;
                free(todlt);
            } else {
                pre->nextarc = todlt->nextarc;
                free(todlt);
            }
            flag = 1;
            break;
        } else {
            pre = todlt;
            todlt = todlt->nextarc;
        }
    }

    if (!flag) return ERROR;   // 弧线不存在

    //  对w操作
    todlt = G.vertices[indexw].firstarc;
    pre = NULL;
    while (todlt) {
        if (todlt->adjvex == indexv) {   // 找到弧线
            if (!pre) {    // 第一个节点
                G.vertices[indexw].firstarc = NULL;
                free(todlt);
            } else {
                pre->nextarc = todlt->nextarc;
                free(todlt);
            }
            break;
        } else {
            pre = todlt;
            todlt = todlt->nextarc;
        }
    }

    G.arcnum--;

    return OK;

    /********** End **********/
}