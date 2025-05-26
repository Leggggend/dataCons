// 本关任务：编写一个函数创建无向图的邻接表。
// 函数原型：status CreateCraph(ALGraph &G,VertexType V,KeyType VR[][2])；
// 功能说明：根据顶点序列V和关系对序列VR构造一个无向图G（要求无向图G中各顶点关键字具有唯一性，结点数目不多于MAX_VERTEX_NUM）。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.创建图的语义。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数CreateCraph的编写。
// 为了验证的方便，要求顶点序列按V中的次序依次存放在表头结点数组中；依次处理VR中的关系，采用首插法，将表结点插入到对应的链表中。本次实验如不作特殊说明，均采用该方法创建图。
// 例如：
// V={{5，"线性表"}，{8，"集合"}，{7，"二叉树"}，{6，"无向图"}}；
// VR={{5，6}，{5，7}，{6，7}，{7，8}}；
// 对应算法生成的邻接表如下图所示：
// 相关类型定义详见简介部分。
// 测试说明
// 平台会自动提供输入、输出，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以关键字为-1作为结束标记；调用函数CreateCraph创建图的邻接表。正确创建无向图的邻接表后，通过依次输出顶点和关系序列检验正确性。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1
// 预期输出：此例子的输出结果参照上图进行理解。
// 5 线性表 2 3
// 8 集合 2
// 7 二叉树 1 3 0
// 6 无向图 2 0
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 7 7 8 7 8 7 -1 -1
// 预期输出：
// 5 线性表 2 3
// 8 集合 2
// 7 二叉树 1 3 0
// 6 无向图 2 0
// 测试输入：5 线性表 8 集合 7 二叉树 8 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1
// 预期输出：输入数据错，无法创建
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 10 8 -1 -1
// 预期输出：输入数据错，无法创建

status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/

    G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG; // 无向图
    if (V[0].key == -1) return ERROR;    // 顶点数为0

    for (int i = 0; V[i].key != -1; i++) {
        if (i >= MAX_VERTEX_NUM) { // 顶点数目超了
            return ERROR;
        }
        for (int j = 0; j < i; j++) {
            if (V[i].key == V[j].key) {
                return ERROR;  // 关键字重复
            }
        }
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;
        if (V[i + 1].key == -1) {
            G.vexnum = i + 1; // 获取顶点数
            break;
        }
    }

    int v1, v2;
    int flag1, flag2;           // 标记是否找到顶点
    for (int i = 0; VR[i][0] != -1; i++) {
        flag1 = flag2 = 0;
        for (v1 = 0; v1 < G.vexnum; v1++) {
            if (VR[i][0] == G.vertices[v1].data.key) {
                flag1++; break;
            }
        }
        for (v2 = 0; v2 < G.vexnum; v2++) {
            if (VR[i][1] == G.vertices[v2].data.key) {
                flag2++; break;
            }
        }
        if (!flag1 || !flag2) {    // 没有找到顶点
            return ERROR;
        }
        // 为顶点v1添加到顶点v2的边
        ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
        if (!p) return ERROR;
        p->adjvex = v2;
        p->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = p;

        // 为顶点v2添加到顶点v1的边
        p = (ArcNode*)malloc(sizeof(ArcNode));
        if (!p) return ERROR;
        p->adjvex = v1;
        p->nextarc = G.vertices[v2].firstarc;
        G.vertices[v2].firstarc = p;

        G.arcnum++;
    }
    return OK;
    /********** End **********/
}
