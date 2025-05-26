// 1.����V��VR����ͼT������OK�����V��VR����ȷ������ERROR���������ͬ�Ĺؼ��֣�����ERROR��
status CreateCraph(ALGraph& G, VertexType V[], KeyType VR[][2]) {
    G.vexnum = 0;
    G.arcnum = 0;
    G.kind = UDG;                          // ����ͼ
    if (V[0].key == -1) return ERROR;      // ������Ϊ0

    for (int i = 0; V[i].key != -1; i++) {
        if (i >= MAX_VERTEX_NUM) {         // ������Ŀ����
            return ERROR;
        }
        for (int j = 0; j < i; j++) {
            if (V[i].key == V[j].key) {
                return ERROR;              // �ؼ����ظ�
            }
        }
        G.vertices[i].data = V[i];
        G.vertices[i].firstarc = NULL;
        if (V[i + 1].key == -1) {
            G.vexnum = i + 1;              // ��ȡ������
            break;
        }
    }
    int v1, v2;
    int flag1, flag2;                       // ����Ƿ��ҵ�����
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
        if (!flag1 || !flag2) return ERROR;  // û���ҵ�����
        // Ϊ����v1��ӵ�����v2�ı�
        ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
        if (!p) return ERROR;
        p->adjvex = v2;
        p->nextarc = G.vertices[v1].firstarc;
        G.vertices[v1].firstarc = p;
        // Ϊ����v2��ӵ�����v1�ı�
        p = (ArcNode*)malloc(sizeof(ArcNode));
        if (!p) return ERROR;
        p->adjvex = v1;
        p->nextarc = G.vertices[v2].firstarc;
        G.vertices[v2].firstarc = p;

        G.arcnum++;
    }
    return OK;
}

// 2.��������ͼG,ɾ��G��ȫ������ͱ�
status DestroyGraph(ALGraph& G) {
    // ����ÿ������
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

// 3.����u��ͼG�в��Ҷ��㣬���ҳɹ�����λ�򣬷��򷵻�-1��
int LocateVex(ALGraph G, KeyType u) {
    if (G.vexnum == 0) return INFEASIBLE;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == u) {
            return i;
        }
    }
    return ERROR;
}

// 4.����u��ͼG�в��Ҷ��㣬���ҳɹ����ö���ֵ�޸ĳ�value������OK���������ʧ�ܻ�ؼ��ֲ�Ψһ������ERROR
status PutVex(ALGraph& G, KeyType u, VertexType value) {
    if (G.vexnum == 0) return INFEASIBLE;
    int index = -1;
    int bad = -1;      // ����ظ��ؼ���
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

// 5.����u��ͼG�в��Ҷ��㣬���ҳɹ����ض���u�ĵ�һ�ڽӶ���λ�򣬷��򷵻�-1��
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

// 6.v��ӦG��һ������,w��Ӧv���ڽӶ��㣻��������Ƿ���v�ģ������w����һ���ڽӶ����λ�����w�����һ���ڽӶ��㣬��v��w��Ӧ���㲻���ڣ��򷵻�-1��
int NextAdjVex(ALGraph G, KeyType v, KeyType w) {
    if (!G.vexnum || !G.arcnum) return INFEASIBLE;
    int index = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v) {
            index = i; break;
        }
    }
    if (index < 0) return INFEASIBLE;      // û��v���
    ArcNode* p = G.vertices[index].firstarc;
    while (p) {
        if (G.vertices[p->adjvex].data.key == w) {
            if (!p->nextarc) return INFEASIBLE; // w�����һ�����
            return p->nextarc->adjvex;
        }
        p = p->nextarc;
    }
    return INFEASIBLE;
}

// 7.��ͼG�в��붥��v���ɹ�����OK,���򷵻�ERROR
status InsertVex(ALGraph& G, VertexType v) {
    int i = 0;
    for (i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v.key) {
            return ERROR;      // �ؼ����ظ�
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
    // ���ҹؼ���Ϊv�Ķ���λ��
    int index = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v) {
            index = i;
            break;
        }
    }
    if (index == -1) return ERROR;   // û���ҵ�����v
    // ɾ����indexΪͷ���Ļ���
    ArcNode* p = G.vertices[index].firstarc;
    while (p != NULL) {
        ArcNode* temp = p;
        p = p->nextarc;
        free(temp);
    }
    G.vertices[index].firstarc = NULL;
    // ɾ������ָ��index�Ļ�
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
    // ����index������֮��Ķ���λ��ǰ��
    for (int i = index; i < G.vexnum - 1; i++)
        G.vertices[i] = G.vertices[i + 1];
    G.vexnum--;
    return OK;
}

// 9.��ͼG�����ӻ�<v,w>���ɹ�����OK,���򷵻�ERROR
status InsertArc(ALGraph& G, KeyType v, KeyType w) {
    // ���ҹؼ���Ϊv�Ķ���λ��
    if (G.vexnum < 2) return INFEASIBLE;
    int indexv = -1;
    int indexw = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (indexv < 0 || indexw < 0) {    // ����
            int k = G.vertices[i].data.key;
            if (k == v)
                indexv = i;
            if (k == w)
                indexw = i;
        } else break;
    }
    if (indexv < 0 || indexw < 0) return ERROR; // û���ҵ�����v��w
    ArcNode* p;
    ArcNode* pnew;
    // ���ԭ�еĻ�
    p = G.vertices[indexv].firstarc;
    while (p) {
        if (p->adjvex == indexw) return ERROR;   // �����Ѿ�����
        p = p->nextarc;
    }
    //  ��v����
    p = G.vertices[indexv].firstarc;
    pnew = (ArcNode*)malloc(sizeof(ArcNode));
    pnew->adjvex = indexw;
    pnew->nextarc = p;
    G.vertices[indexv].firstarc = pnew;
    //  ��w����
    p = G.vertices[indexw].firstarc;
    pnew = (ArcNode*)malloc(sizeof(ArcNode));
    pnew->adjvex = indexv;
    pnew->nextarc = p;
    G.vertices[indexw].firstarc = pnew;

    G.arcnum++;
    return OK;
}

// 10.��ͼG��ɾ����<v,w>���ɹ�����OK,���򷵻�ERROR
status DeleteArc(ALGraph& G, KeyType v, KeyType w) {
    if (G.vexnum < 2 || !G.arcnum) return INFEASIBLE;
    int indexv = -1;
    int indexw = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (indexv < 0 || indexw < 0) {    // ����
            int k = G.vertices[i].data.key;
            if (k == v)
                indexv = i;
            if (k == w)
                indexw = i;
        } else break;
    }
    if (indexv < 0 || indexw < 0) return ERROR; // û���ҵ�����v��w
    ArcNode* pre, * todlt;
    int flag = 0; // ����Ƿ���ڻ���
    //  ��v����
    todlt = G.vertices[indexv].firstarc;
    pre = NULL;
    while (todlt) {
        if (todlt->adjvex == indexw) {   // �ҵ�����
            if (!pre) {    // �պ��ǵ�һ���ڵ�
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
    if (!flag) return ERROR;   // ���߲�����
    //  ��w����
    todlt = G.vertices[indexw].firstarc;
    pre = NULL;
    while (todlt) {
        if (todlt->adjvex == indexv) {   // �ҵ�����
            if (!pre) {    // ��һ���ڵ�
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
        if (!visited[index]) // ������δ�����ʣ���Ӹö��㿪ʼ���������������
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
// �ж��Ƿ����
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
        return FALSE;       // ���㲻����
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
    // �������ж��㣬���涥����Ϣ
    for (int i = 0; i < G.vexnum; i++) {
        fprintf(fp, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
    }
    fprintf(fp, "-1 nil\n");
    // �ؼ�������������ԭʼ������
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
    // �������ж��㣬�������Ϣ
    for (int i = 0; i < G.vexnum - 1; i++) {
        for (int j = i + 1; j < G.vexnum; j++) {
            if (Connect(G, vex[i], vex[j]))
                fprintf(fp, "%d %d\n", vex[i], vex[j]);
        }
    }
    fprintf(fp, "-1 -1\n"); // ����Ϣ������־
    fclose(fp);
    return OK;
}

// 14.
status LoadGraph(ALGraph& G, char FileName[]) {
    if (G.vexnum) return INFEASIBLE;
    FILE* fp = fopen(FileName, "r");
    if (fp == NULL) {
        printf("\n�ļ���ʧ�ܣ�");
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
    printf("\n�ɹ���ȡ������Ϣ��");
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
            return ERROR; // ����ؼ���δ�ҵ�
        }
        // ����v1��v2�Ļ��ڵ�
        ArcNode* e1 = (ArcNode*)malloc(sizeof(ArcNode));
        if (!e1) return ERROR;
        e1->adjvex = two;
        e1->nextarc = G.vertices[one].firstarc;
        G.vertices[one].firstarc = e1;
        // ����v2��v1�Ļ��ڵ�
        ArcNode* e2 = (ArcNode*)malloc(sizeof(ArcNode));
        if (!e2) return ERROR;
        e2->adjvex = one;
        e2->nextarc = G.vertices[two].firstarc;
        G.vertices[two].firstarc = e2;

        G.arcnum++;
    }
    printf("\n�ɹ���ȡ����Ϣ��");
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
    int distance[G.vexnum] = { 0 }; // ��������
    int count = 0;

    int vIndex = -1;
    for (int i = 0; i < G.vexnum; i++) {
        if (G.vertices[i].data.key == v) {
            vIndex = i;
            break;
        }
    }
    if (vIndex == -1) return -1; // �������v������

    queue[rear++] = vIndex;       // ������v���
    visited[vIndex] = 1;
    distance[vIndex] = 0;         // v������ľ���Ϊ0

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
                distance[w] = distance[u] + 1; // ���¾���
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
    int visited[G.vexnum] = { 0 }; // �������
    int componentNum = 0; // ��ʼ����ͨ��������

    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) { // �������iδ������
            componentNum++; // ��ͨ����������1
            int queue[50], front = 0, rear = 0; // ����
            queue[rear++] = i; // ������i���
            visited[i] = 1; // ���iΪ�ѷ���

            while (front < rear) {
                int u = queue[front++]; // ����
                ArcNode* p = G.vertices[u].firstarc; // ����u���ڽӱ�
                while (p) {
                    int w = p->adjvex;
                    if (!visited[w]) { // ����ڽӵ�δ������
                        visited[w] = 1;
                        queue[rear++] = w; // �ڽӵ����
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    return componentNum; // ������ͨ��������
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