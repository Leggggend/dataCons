// �������񣺱�дһ������ʵ�������������������
// ����ԭ�ͣ�status DFSTraverse(ALGraph &G, void (*visit)(VertexType))��
// ����˵������ͼG������������������������ζ�ͼ�е�ÿһ������ʹ�ú���visit����һ�Σ��ҽ�����һ�Ρ�
// ���֪ʶ
// Ϊ����ɱ�����������Ҫ���գ�1.ͼ�ĸ��2.�ڽӱ�3.ͼ�������������塣
// ���Ҫ��
// ������ʾ�����Ҳ�༭��������룬��ɺ���DFSTraverse�ı�д��
// ����˵��
// ƽ̨���Զ��ṩ���룬�����д�Ĵ�����в��ԣ�
// ������������Ϊ�������к͹�ϵ�����У���-1��Ϊ�������,������v��w��ֵ����ȷ��������ͼ���ڽӱ���ٵ��ú���DFSTraverse���������������������������������з��ʵĶ������С�
// �������룺5 ���Ա� 8 ���� 7 ������ 6 ����ͼ -1 nil 5 6 5 7 6 7 7 8 -1 -1
// Ԥ�������
// 5 ���Ա� 7 ������ 8 ���� 6 ����ͼ

// ������������ݹ麯��
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

status DFSTraverse(ALGraph& G, void (*visit)(VertexType)) {
    int visited[MAX_VERTEX_NUM];
    for (int i = 0; i < G.vexnum; i++)
        visited[i] = 0;
    // ��ͼ�е�ÿ��������������������
    for (int i = 0; i < G.vexnum; i++) {
        if (!visited[i]) // ������δ�����ʣ���Ӹö��㿪ʼ���������������
            DFS(G, i, visit, visited);
    }
    return OK;
}