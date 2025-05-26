// �������񣺱�дһ������ʵ��ɾ�����㡣
// ����ԭ�ͣ�stasus DeleteVex((ALGraph &G,KeyType v)��
// ����˵����v�Ǻ�G�ж���ؼ���������ͬ�ĸ���ֵ�������������ͼG��ɾ���ؼ���v��Ӧ�Ķ����Լ���صĻ����ɹ�����OK�����򷵻�ERROR��
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.ͼ�ĸ��2.�ڽӱ�3.ɾ��������������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���DeleteVex�ı�д��
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ������������Ϊ�������к͹�ϵ�����У���-1��Ϊ�������,������v��ֵ����ȷ��������ͼ���ڽӱ���ٵ��ú���DeleteVex������vɾ���������ɹ�ʱ��������ж����Լ���ϵ���ݡ�
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  7
// Ԥ�������
// 5 ���Ա� 2
// 8 ����
// 6 ����ͼ 0
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1  10
// Ԥ������� ɾ���������ʧ��

// 5 ���Ա� -1 nil -1 -1 5

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
    if (index == -1) return ERROR; // û���ҵ�����v

    // ɾ����indexΪͷ���Ļ���
    ArcNode* p = G.vertices[index].firstarc;
    while (p != NULL) {
        ArcNode* temp = p;
        p = p->nextarc;
        free(temp); // �ͷŻ��ڵ�
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
    G.vexnum--; // ���¶�����
    return OK;
}