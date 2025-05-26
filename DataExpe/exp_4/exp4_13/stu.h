// �������񣺱�д�����������ֱ�ʵ�ֽ�����ͼ������д���ļ��У��Ͷ����ļ��еĽ�����ݴ�������ͼ���ڽӱ�
// ������ԭ�ͣ� 
// status SaveGraph(ALGraph G,char FileName[])��
// status LoadGraph(ALGraph &G,char FileName[])��
// ����˵��������SaveGraphʵ�ֽ�ͼGд���ļ���ΪFileName���ļ��У�����OK������ LoadGraph�����ļ���ΪFileName�Ľ�����ݣ���������ͼ���ڽӱ������ײ巨����
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.ͼ�ĸ��2.�ڽӱ�3.�ļ�������
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ��� SaveGraph��LoadGraph�ı�д
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ������������Ϊ�������к͹�ϵ�����У���-1��Ϊ������ǣ���ȷ��������ͼ���ڽӱ�󣬽�ͼд���ļ��У��ٴ��ļ��ж����ع��ٽӱߣ�ͨ�������������͹�ϵ���м�����ȷ�ԡ�
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1
// Ԥ�������
// 5 ���Ա� 2 3
// 8 ���� 2
// 7 ������ 1 3 0
// 6 ����ͼ 2 0

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
        if (index1 != -1 && index2 != -1) {
            break;
        }
    }
    if (index1 == -1 || index2 == -1) {
        return FALSE; // ���㲻����
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
    for (int i = 0; i < MAX_VERTEX_NUM; i++) {
        if (G.vertices[i].data.key != -1) {
            fprintf(fp, "%d %s\n", G.vertices[i].data.key, G.vertices[i].data.others);
        } else {
            fprintf(fp, "-1 nil\n");
            break;
        }
    }
    //printf("����\n");

    // �ؼ�������������ԭʼ������
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

    // ��ȡ������Ϣ
    int key;
    char others[20];
    while (fscanf(fp, "%d %s", &key, others) == 2) {
        if (key != -1) {
            G.vertices[G.vexnum].data.key = key;
            strcpy(G.vertices[G.vexnum].data.others, others);
            G.vexnum++;
        } else {
            break; // ������Ϣ����
        }
    }

    // ��ȡ����Ϣ
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

        // ����v2��v1�Ļ��ڵ㣨����ͼ��
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