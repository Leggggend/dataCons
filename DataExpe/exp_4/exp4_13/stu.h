// 本关任务：编写两个函数，分别实现将无向图的数据写到文件中，和读入文件中的结点数据创建无向图的邻接表。
// 函数名原型： 
// status SaveGraph(ALGraph G,char FileName[])；
// status LoadGraph(ALGraph &G,char FileName[])；
// 功能说明：函数SaveGraph实现将图G写到文件名为FileName的文件中，返回OK；函数 LoadGraph读入文件名为FileName的结点数据，创建无向图的邻接表（采用首插法）。
// 相关知识
// 为了完成本关任务，你需要掌握：1.图的概念，2.邻接表，3.文件操作。
// 编程要求
// 根据提示，在右侧编辑器补充代码，完成函数 SaveGraph和LoadGraph的编写
// 测试说明
// 平台会自动提供输入，对你编写的代码进行测试：
// 下列输入序列为顶点序列和关系对序列，以-1作为结束标记；正确创建无向图的邻接表后，将图写到文件中，再从文件中读出重构临接边，通过依次输出顶点和关系序列检验正确性。
// 测试输入：5 线性表 8 集合 7 二叉树 6 无向图 -1 nil 5 6 5 7 6 7 7 8 -1 -1
// 预期输出：
// 5 线性表 2 3
// 8 集合 2
// 7 二叉树 1 3 0
// 6 无向图 2 0

// 判断是否关联
status Connect(ALGraph G, KeyType v1, KeyType v2) {
    int index1 = -1, index2 = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v1) {
            index1 = i;
        }
        if (G.vertices[i].data.key == v2) {
            index2 = i;
        }
        if (index1 != -1 && index2 != -1) {
            break;
        }
    }
    if (index1 == -1 || index2 == -1) {
        return FALSE; // 顶点不存在
    }
    ArcNode* p = G.vertices[index1].firstarc;
    while (p != NULL) {
        if (p->adjvex == index2) {
            return TRUE;
        }
        p = p->nextarc;
    }
    return FALSE;
}

status SaveGraph(ALGraph G, char FileName[]) {
    FILE* fp = fopen(FileName, "w");
    if (fp == NULL) return ERROR;

    // 遍历所有顶点，保存顶点信息
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        if (G.vertices[i].data.key != -1) {
            fprintf(fp, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
        } else {
            fprintf(fp, "-1 nil\n");
            break;
        }
    }
    //printf("顶点\n");

    // 关键字排序以生成原始边序列
    KeyType vex[G.vexnum - 1];
    for (int i = 0; i < G.vexnum; i++) {
        vex[i] = G.vertices[i].data.key;
    }
    for (int i = 0; i < G.vexnum; i++) {
        for (int j = 0; j < G.vexnum - i - 1; j++) {
            if (vex[j] > vex[j + 1]) {
                KeyType temp = vex[j];
                vex[j] = vex[j + 1];
                vex[j + 1] = temp;
            }
        }
    }

    // for (int i = 0; i < G.vexnum; i++) {
    //     printf("%d ", vex[i]);
    // }
    // printf("\n");

    // 遍历所有顶点，保存边信息
    for (int i = 0; i < G.vexnum - 1; i++) {
        for (int j = i + 1; j < G.vexnum; j++) {
            if (Connect(G, vex[i], vex[j]))
                fprintf(fp, "%d %d\n", vex[i], vex[j]);
        }
    }
    fprintf(fp, "-1 -1\n"); // 边信息结束标志

    fclose(fp);
    return OK;
}

status LoadGraph(ALGraph& G, char FileName[]) {
    if (G.vexnum) return INFEASIBLE;

    FILE* fp = fopen(FileName, "r");
    if (fp == NULL) return ERROR;

    G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        G.vertices[i].firstarc = NULL;
    }

    // 读取顶点信息
    int key;
    char others[20];
    while (fscanf(fp, "%d %s", &key, others) == 2) {
        if (key != -1) {
            G.vertices[G.vexnum].data.key = key;
            strcpy(G.vertices[G.vexnum].data.others, others);
            G.vexnum++;
        } else {
            break; // 顶点信息结束
        }
    }

    // 读取边信息
    int v1, v2;
    while (fscanf(fp, "%d %d", &v1, &v2) == 2 && v1 != -1) {
        int one = -1, two = -1;
        for (int i = 0; i < G.vexnum; i++) {
            if (G.vertices[i].data.key == v1) {
                one = i;
            }
            if (G.vertices[i].data.key == v2) {
                two = i;
            }
        }
        if (one == -1 || two == -1) {
            return ERROR; // 顶点关键字未找到
        }

        // 创建v1到v2的弧节点
        ArcNode* e1 = (ArcNode*)malloc(sizeof(ArcNode));
        if (!e1) return ERROR;
        e1->adjvex = two;
        e1->nextarc = G.vertices[one].firstarc;
        G.vertices[one].firstarc = e1;

        // 创建v2到v1的弧节点（无向图）
        ArcNode* e2 = (ArcNode*)malloc(sizeof(ArcNode));
        if (!e2) return ERROR;
        e2->adjvex = one;
        e2->nextarc = G.vertices[two].firstarc;
        G.vertices[two].firstarc = e2;

        G.arcnum++;
    }

    fclose(fp);
    return OK;
}