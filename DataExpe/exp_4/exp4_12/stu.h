// �������񣺱�дһ������ʵ�ֹ����������������
// ����ԭ�ͣ�status BFSTraverse(ALGraph &G,void (*visit)(VertexType))��
// ����˵������ͼG���й�������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ�Ρ�
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.ͼ�ĸ��2.�ڽӱ�3.ͼ�������������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���BFSTraverse�ı�д��
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ������������Ϊ�������к͹�ϵ�����У���-1��Ϊ�������,������v��w��ֵ����ȷ��������ͼ���ڽӱ���ٵ��ú���BFSTraverse���й����������������������������з��ʵĶ������С�
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1
// Ԥ�������
// 5 ���Ա� 7 ������ 6 ����ͼ 8 ����

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