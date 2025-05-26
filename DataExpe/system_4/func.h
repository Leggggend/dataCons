// 1.根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR；如果有相同的关键字，返回ERROR。
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]) {
    G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG;                          // 无向图
    if (V[0].key == -1) return ERROR;      // 顶点数为0

    for (int i = 0; V[i].key != -1; i++) {
        if (i >= MAX_VERTEX_NUM) {         // 顶点数目超了
            return ERROR;
        }
        for (int j = 0; j < i; j++) {
            if (V[i].key == V[j].key) {
                return ERROR;              // 关键字重复
            }
        }
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;
        if (V[i + 1].key == -1) {
            G.vexnum = i + 1;              // 获取顶点数
            break;
        }
    }
    int v1, v2;
    int flag1, flag2;                       // 标记是否找到顶点
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
        if (!flag1 || !flag2) return ERROR;  // 没有找到顶点
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
}

// 2.销毁无向图G,删除G的全部顶点和边
status DestroyGraph(ALGraph& G) {
    // 遍历每个顶点
    for (int i = 0; i < G.vexnum; i++) {
        ArcNode* p = G.vertices[i].firstarc;
        while (p != NULL) {
            ArcNode* temp = p;
            p = p->nextarc;
            free(temp);
        }
        G.vertices[i].firstarc = NULL;
    }
    G.vexnum = 0;
    G.arcnum = 0;
    return OK;
}

// 3.根据u在图G中查找顶点，查找成功返回位序，否则返回-1；
int LocateVex(ALGraph G, KeyType u) {
    if (G.vexnum == 0) return INFEASIBLE;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == u) {
            return i;
        }
    }
    return ERROR;
}

// 4.根据u在图G中查找顶点，查找成功将该顶点值修改成value，返回OK；如果查找失败或关键字不唯一，返回ERROR
status PutVex(ALGraph& G, KeyType u, VertexType value) {
    if (G.vexnum == 0) return INFEASIBLE;
    int index = -1;
    int bad = -1;      // 检测重复关键字
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == value.key)
            bad = i;
        if (G.vertices[i].data.key == u)
            index = i;
    }
    if (index < 0 || (bad >= 0 && bad != index)) return ERROR;
    G.vertices[index].data.key = value.key;
    strcpy(G.vertices[index].data.others, value.others);
    return OK;
}

// 5.根据u在图G中查找顶点，查找成功返回顶点u的第一邻接顶点位序，否则返回-1；
int FirstAdjVex(ALGraph G, KeyType u) {
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
}

// 6.v对应G的一个顶点,w对应v的邻接顶点；操作结果是返回v的（相对于w）下一个邻接顶点的位序；如果w是最后一个邻接顶点，或v、w对应顶点不存在，则返回-1。
int NextAdjVex(ALGraph G, KeyType v, KeyType w) {
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
}

// 7.在图G中插入顶点v，成功返回OK,否则返回ERROR
status InsertVex(ALGraph& G, VertexType v) {
    int i = 0;
    for (i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v.key) {
            return ERROR;      // 关键字重复
        }
    }
    if (i >= MAX_VERTEX_NUM) {
        return ERROR;
    }
    G.vertices[i].data.key = v.key;
    strcpy(G.vertices[i].data.others, v.others);
    G.vexnum++;
    return OK;
}

// 8.
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
    if (index == -1) return ERROR;   // 没有找到顶点v
    // 删除以index为头结点的弧表
    ArcNode* p = G.vertices[index].firstarc;
    while (p != NULL) {
        ArcNode* temp = p;
        p = p->nextarc;
        free(temp);
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
    G.vexnum--;
    return OK;
}

// 9.在图G中增加弧<v,w>，成功返回OK,否则返回ERROR
status InsertArc(ALGraph& G, KeyType v, KeyType w) {
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
}

// 10.在图G中删除弧<v,w>，成功返回OK,否则返回ERROR
status DeleteArc(ALGraph& G, KeyType v, KeyType w) {
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
    if (indexv < 0 || indexw < 0) return ERROR; // 没有找到顶点v或w
    ArcNode* pre, * todlt;
    int flag = 0; // 标记是否存在弧线
    //  对v操作
    todlt = G.vertices[indexv].firstarc;
    pre = NULL;
    while (todlt) {
        if (todlt->adjvex == indexw) {   // 找到弧线
            if (!pre) {    // 刚好是第一个节点
                G.vertices[indexv].firstarc = todlt->nextarc;
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
                G.vertices[indexw].firstarc = todlt->nextarc;
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
}

void visit(VertexType v) {
    printf(" %d %s", v.key, v.others);
}

// 11.
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

status DFSTraverse(ALGraph& G, int start, void (*visit)(VertexType)) {
    if (G.vexnum == 0) return INFEASIBLE;
    int visited[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    int index = 0;
    for (int i = 0; i < G.vexnum; i++) {
        index = (start + i) % G.vexnum;
        if (!visited[index]) // 若顶点未被访问，则从该顶点开始进行深度优先搜索
            DFS(G, index, visit, visited);
    }
    return OK;
}

// 12.
status BFSTraverse(ALGraph& G, int start, void (*visit)(VertexType)) {
    if (G.vexnum == 0) return INFEASIBLE;
    int visited[MAX_VERTEX_NUM] = { 0 };
    int queue[MAX_VERTEX_NUM];
    int front = 0;
    int rear = 0;
    int index = 0;
    for (int i = 0; i < G.vexnum; i++) {
        index = (start + i) % G.vexnum;
        if (!visited[index]) {
            visited[index] = 1;
            visit(G.vertices[index].data);
            queue[rear++] = index;
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

// 13.
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
    }
    if (index1 == -1 || index2 == -1) {
        return FALSE;       // 顶点不存在
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
    for (int i = 0; i < G.vexnum; i++) {
        fprintf(fp, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    fprintf(fp, "-1 nil\n");
    // 关键字排序以生成原始边序列
    KeyType vex[G.vexnum];
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

// 14.
status LoadGraph(ALGraph& G, char FileName[]) {
    if (G.vexnum) return INFEASIBLE;
    FILE* fp = fopen(FileName, "r");
    if (fp == NULL) {
        printf("\n文件打开失败！");
        return ERROR;
    }
    G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG;
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        G.vertices[i].firstarc = NULL;
    }

    int key;
    char others[20];
    while (fscanf(fp, "%d %s", &key, others) == 2 && key != -1) {
        G.vertices[G.vexnum].data.key = key;
        strcpy(G.vertices[G.vexnum].data.others, others);
        G.vexnum++;
    }
    printf("\n成功读取顶点信息！");
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
        // 创建v2到v1的弧节点
        ArcNode* e2 = (ArcNode*)malloc(sizeof(ArcNode));
        if (!e2) return ERROR;
        e2->adjvex = one;
        e2->nextarc = G.vertices[two].firstarc;
        G.vertices[two].firstarc = e2;

        G.arcnum++;
    }
    printf("\n成功读取边信息！");
    fclose(fp);
    return OK;
}

// 17.
int LocateGraph(Graphs& Gs, char GName[]) {
    if (Gs->length <= 0) return INFEASIBLE;
    for (int i = 0; i < Gs->length;i++) {
        if (strcmp(Gs->elem[i].GName, GName) == 0) {
            return i;
        }
    }
    return -1;
}

// 15.
status AddGraph(Graphs& Gs, char GName[]) {
    if (Gs->length >= Gs->maxsize) return INFEASIBLE;
    if (LocateGraph(Gs, GName) >= 0) return ERROR;
    int l = Gs->length;
    strcpy(Gs->elem[l].GName, GName);
    Gs->elem[l].G = (ALGraph*)malloc(sizeof(ALGraph));
    Gs->elem[l].G->vexnum = 0;
    Gs->elem[l].G->arcnum = 0;
    Gs->length++;
    return OK;
}

// 16.
status RemoveGraph(Graphs& Gs, char GName[]) {
    if (Gs->length <= 0) return INFEASIBLE;
    int index = LocateGraph(Gs, GName);
    if (index < 0) return ERROR;
    if (DestroyGraph(*(Gs->elem[index].G)) != OK) return ERROR;
    for (int i = index; i < Gs->length - 1; i++) {
        strcpy(Gs->elem[i].GName, Gs->elem[i + 1].GName);
        Gs->elem[i].G = Gs->elem[i + 1].G;
    }
    Gs->length--;
    return OK;
}

// 18.
int VerticesSetLessThanK(ALGraph& G, KeyType v, int k, KeyType ans[]) {
    if (k < 0 || G.vexnum == 0) return INFEASIBLE;

    int visited[G.vexnum] = { 0 };
    int queue[G.vexnum], front = 0, rear = 0;
    int distance[G.vexnum] = { 0 }; // 距离数组
    int count = 0;

    int vIndex = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v) {
            vIndex = i;
            break;
        }
    }
    if (vIndex == -1) return -1; // 如果顶点v不存在

    queue[rear++] = vIndex;       // 将顶点v入队
    visited[vIndex] = 1;
    distance[vIndex] = 0;         // v到自身的距离为0

    while (front < rear) {
        int u = queue[front++];
        if (distance[u] < k && u != vIndex) {
            ans[count++] = u;
        }
        ArcNode* p = G.vertices[u].firstarc;
        while (p) {
            int w = p->adjvex;
            if (!visited[w]) {
                visited[w] = 1;
                distance[w] = distance[u] + 1; // 更新距离
                queue[rear++] = w;
            }
            p = p->nextarc;
        }
    }

    return count;
}

// 19.
int ShortestPathLength(ALGraph& G, KeyType v, KeyType w) {
    if (G.vexnum == 0 || G.arcnum == 0)return INFEASIBLE;
    int visited[G.vexnum] = { 0 };
    int queue[50], front = 0, rear = 0;
    int distance[G.vexnum] = { 0 };

    int vIndex = -1, wIndex = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v) {
            vIndex = i;
        }
        if (G.vertices[i].data.key == w) {
            wIndex = i;
        }
    }
    if (vIndex == -1 || wIndex == -1) return -1;

    queue[rear++] = vIndex;
    visited[vIndex] = 1;

    while (front < rear) {
        int u = queue[front++];
        if (u == wIndex) {
            return distance[wIndex];
        }
        ArcNode* p = G.vertices[u].firstarc;
        while (p) {
            int w = p->adjvex;
            if (!visited[w]) {
                visited[w] = 1;
                distance[w] = distance[u] + 1;
                queue[rear++] = w;
            }
            p = p->nextarc;
        }
    }

    return -1;
}

// 20.
int ConnectedComponentsNums(ALGraph& G) {
    if (G.vexnum == 0) return INFEASIBLE;
    int visited[G.vexnum] = { 0 }; // 标记数组
    int componentNum = 0; // 初始化连通分量数量

    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) { // 如果顶点i未被访问
            componentNum++; // 连通分量数量加1
            int queue[50], front = 0, rear = 0; // 队列
            queue[rear++] = i; // 将顶点i入队
            visited[i] = 1; // 标记i为已访问

            while (front < rear) {
                int u = queue[front++]; // 出队
                ArcNode* p = G.vertices[u].firstarc; // 遍历u的邻接表
                while (p) {
                    int w = p->adjvex;
                    if (!visited[w]) { // 如果邻接点未被访问
                        visited[w] = 1;
                        queue[rear++] = w; // 邻接点入队
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    return componentNum; // 返回连通分量数量
}

// 21.
status TraverseGraphs(Graphs Gs) {
    if (Gs->length <= 0) return INFEASIBLE;
    for (int i = 0; i < Gs->length; i++) {
        printf("\n");
        printf("----------%s-----------\n", Gs->elem[i].GName);
        ALGraph* g = Gs->elem[i].G;
        for (int i = 0;i < g->vexnum;i++) {
            ArcNode* p = g->vertices[i].firstarc;
            printf("  | %d %s", g->vertices[i].data.key, g->vertices[i].data.others);
            while (p) {
                printf(" %d", p->adjvex);
                p = p->nextarc;
            }
            printf("\n");
        }
    }
    printf("\n");
    return OK;
}