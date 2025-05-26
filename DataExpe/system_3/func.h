// 6.���ҽ�㣬���ڱ���˳�򣬽�����ǰ
BiTree LocateNode(BiTree T, KeyType e) {
    if (!T) return NULL;
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        if (p->data.key == e) return p;
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return NULL;
}

// 1.����������
status CreateBiTree1(BiTree &T, TElemType definition[]) {
    static int Cindex = 0;      // ��¼��ǰ����λ��
    static BiTree root = NULL;  // ��¼�������ĸ������ڼ��ؼ���Ψһ��
    if (Cindex == 0) root = NULL;     
    if (definition[Cindex].key == -1) return OK;
    else if (definition[Cindex].key == 0) {
        T = NULL;
        Cindex++;
        return OK;
    }
    if (LocateNode(root, definition[Cindex].key)) return ERROR;
    T = (BiTree)malloc(sizeof(BiTNode));
    if (!T) return ERROR;
    T->data.key = definition[Cindex].key;
    strcpy(T->data.others, definition[Cindex].others);
    T->lchild = T->rchild = NULL;

    if (Cindex == 0) root = T;    // ��¼���ڵ�
    Cindex++;
    if (CreateBiTree1(T->lchild, definition) != OK) 
        return ERROR;
    if (CreateBiTree1(T->rchild, definition) != OK)
        return ERROR;
    return OK;
}

status CreateBiTree2(BiTree &T, DEF definition[], int size) {
    for (int i = 0; i < size; i++) { // ���ؼ���
        for (int j = i + 1; j < size; j++) {
            if (definition[i].data.key == definition[j].data.key) {
                return ERROR;
            }
        }
    }
    int i = 0, j;
    static BiTree p[100];
    while (j = definition[i].pos) {
    	p[j] = (BiTree)malloc(sizeof(BiTNode));
        p[j]->data = definition[i].data;
        p[j]->lchild = NULL;
        p[j]->rchild = NULL;
        if (j != 1)
       		if (j % 2) p[j/2]->rchild = p[j];  
       	    else p[j/2]->lchild = p[j];
        i++;
    }
    T = p[1];
    return OK;
}

// 2.���ٶ�����
status DestroyBiTree(BiTree &T) {
    if (T) {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
        T = NULL;
    }
    return OK;
}

// 3.��ն�����
status ClearBiTree (BiTree &T) {
    if (T == NULL) return OK;
    ClearBiTree(T->lchild);    
    ClearBiTree(T->rchild);
    free(T);
    return OK;
}

// 4.�ж��ն�����
status BiTreeEmpty(BiTree T) {
    if (!T) return TRUE;
    return FALSE;
}

// 5.����������
int BiTreeDepth(BiTree T) {
    if (!T) return 0;        
    else {
        int leftDepth = BiTreeDepth(T->lchild);
        int rightDepth = BiTreeDepth(T->rchild);
        int x = (leftDepth > rightDepth) ? leftDepth : rightDepth;
        return (x + 1);
    }
}

// 6.���ҽ��
// BiTree LocateNode(BiTree T, KeyType e) {
//     if (!T) return NULL;
//     BiTree queue[100];
//     int front = 0, rear = 0;
//     queue[rear++] = T;
//     while (front < rear) {
//         BiTree p = queue[front++];
//         if (p->data.key == e) return p;
//         if (p->lchild) queue[rear++] = p->lchild;
//         if (p->rchild) queue[rear++] = p->rchild;
//     }
//     return NULL;
// }

// 7.��㸳ֵ
status AssignNode(BiTree T, KeyType e, TElemType value) {
    BiTree p = LocateNode(T, e);
    BiTree q = LocateNode(T, value.key);
    if (!p || (value.key != e && q) ) return ERROR;
    p->data.key = value.key;
    strcpy(p->data.others, value.others);
    return OK;    
}

// 8.����ֵܽ��
BiTree GetSibling(BiTree T, KeyType e) {
    if (!T) return NULL;
    if (T->lchild && T->lchild->data.key == e) return T->rchild;
    if (T->rchild && T->rchild->data.key == e) return T->lchild;
    BiTree leftResult = GetSibling(T->lchild, e);
    if (leftResult) return leftResult;
    else return GetSibling (T->rchild , e);
}

// 9.������
status InsertNode(BiTree T, KeyType e, int LR, TElemType c) {
    BiTree newnode = (BiTNode*)malloc(sizeof(BiTNode));
    if (!newnode) return ERROR;
    newnode->data.key = c.key;
    strcpy(newnode->data.others, c.others);
    newnode->lchild = newnode->rchild = NULL;
    if (LR == -1) {      // ��Ϊ��������
        newnode->rchild = T;
        T = newnode;
        return OK;
    } else {
        if (!T) return INFEASIBLE;
        BiTree node = LocateNode(T, c.key);
        if (node) return ERROR;    // ���ظ��ؼ���
        BiTree des = LocateNode(T, e);
        if (!des) return ERROR;    // û���ҵ�����λ��
        BiTree ltemp = des->lchild;
        BiTree rtemp = des->rchild;    
        if (LR == 0) {          // ��Ϊ����������
            des->lchild = newnode;
            newnode->rchild = ltemp;
            return OK;
        } else if (LR == 1) {   // ��Ϊ����������
            des->rchild = newnode;
            newnode->rchild = rtemp;
            return OK;
        }        
    }
    return ERROR;
}

// 10.ɾ�����
// ��������1�����ݹؼ��ֲ��ҽ��͸��ڵ�
BiTNode* LocatePNodeByKey(BiTree T, KeyType e, BiTNode*& parent, int &islor) {
    if (!T) return NULL;
    parent = NULL;
    islor = 0;
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        if (p->lchild && p->lchild->data.key == e) {
            parent = p;
            islor = 0;
        } else if (p->rchild && p->rchild->data.key == e) {
            parent = p;
            islor = 1;
        }
        if (p->data.key == e) return p;
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return NULL;
}
BiTNode* MostRightNode(BiTree &T) {
    BiTNode* msn = T;
    while (msn && msn->rchild) msn = msn->rchild;
    return msn;
}
status DeleteNode(BiTree T, KeyType e) {
    BiTNode* parent = NULL;
    int islor = 0;
    BiTNode* todelete = LocatePNodeByKey(T, e, parent, islor);
    if (!todelete) return ERROR;
    printf("\n��ɾ���Ľ��Ϊ(%d, %s).", todelete->data.key, todelete->data.others);
    BiTNode* ltemp = todelete->lchild; // ������
    BiTNode* rtemp = todelete->rchild; // ������
    BiTNode* msn = NULL; // ���ҽ��
    if (!ltemp && !rtemp) { // ��Ϊ0
        if (parent) {
            if (!islor) parent->lchild = NULL;
            else parent->rchild = NULL;
        } else T = NULL; // ɾ�����ڵ�
        free(todelete);
    } else if (!ltemp || !rtemp) { // ��Ϊ1
        BiTNode* child = ltemp ? ltemp : rtemp; // ��ȡ�ǿ�����
        if (parent) {
            if (!islor) parent->lchild = child;
            else parent->rchild = child;
        } else T = child; // ɾ�����ڵ�
        free(todelete);
    } else { // ��Ϊ2
        msn = MostRightNode(ltemp); // �ҵ������������ҽڵ�
        msn->rchild = rtemp; // ���������ҵ����ҽڵ���Һ�����
        if (parent) {
            if (!islor) parent->lchild = ltemp;
            else parent->rchild = ltemp;
        } else T = ltemp; // ɾ�����ڵ�
        free(todelete);
    }
    return OK;
}

// 11.ǰ�����
void Visit(BiTree T) {
    if (!T) return;
    printf("(%d, %s) ", T->data.key, T->data.others);
}

status PreOrderTraverse(BiTree T, void (*Visit)(BiTree)) {
    if (T){
        Visit(T);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
    return OK;
}

// 12.�������
status InOrderTraverse(BiTree T, void (*Visit)(BiTree)) {
    if (T) {
        InOrderTraverse(T->lchild, Visit);
        Visit(T);        
        InOrderTraverse(T->rchild, Visit);
    }
    return OK;
}

// 13.�������
status PostOrderTraverse(BiTree T, void (*Visit)(BiTree)) {
    if (T == NULL) return OK; // ����ֱ�ӷ���
    PostOrderTraverse(T->lchild, Visit); 
    PostOrderTraverse(T->rchild, Visit); 
    Visit(T); 
    return OK;
}

// 14.�������
status LevelOrderTraverse(BiTree T, void (*Visit)(BiTree)) {
    if (!T) return ERROR;
    BiTree queue[100];
    int front = 0, rear = 0;
    queue[rear++] = T;
    while (front < rear) {
        BiTree p = queue[front++];
        Visit(p);
        if (p->lchild) queue[rear++] = p->lchild;
        if (p->rchild) queue[rear++] = p->rchild;
    }
    return OK;
}

// 15.���·����
int MaxPathSum(BiTree T) {
    if (!T) return 0;        
    else {
        int left = MaxPathSum(T->lchild);
        int right = MaxPathSum(T->rchild);
        int x = (left > right) ? left : right;
        return (x + T->data.key);
    }
}

// 16.�����������
BiTree LowestCommonAncestor(BiTree T, KeyType e1, KeyType e2) {
    if (!T || T->data.key == e1 || T->data.key == e2) return T;
    BiTree left = LowestCommonAncestor(T->lchild , e1 , e2);
    BiTree right = LowestCommonAncestor(T->rchild , e1 , e2);
    if ( left && !right) return left ;
    if (!left && right) return right ;
    if (!left && !right) return NULL;
    if ( left && right) return T;
}

// 17.��ת������
status InvertBiTree(BiTree &T) {
    if (T == NULL) return OK;  
    BiTree temp = T->lchild;
    T->lchild = T->rchild;
    T->rchild = temp;
    if (InvertBiTree(T->lchild) != OK) return ERROR;
    if (InvertBiTree(T->rchild) != OK) return ERROR;
    return OK;
}

// 18.�ļ�����
// �������������������Ľ������д���ļ�
status SaveNode(BiTree node, FILE* fp) {
    if (node == NULL) {
        fprintf(fp, "0 null ");
        return OK;
    }
    fprintf(fp, "%d %s ", node->data.key, node->data.others);
    if (SaveNode(node->lchild, fp) != OK) return ERROR;
    if (SaveNode(node->rchild, fp) != OK) return ERROR;
    return OK;
}
status SaveBiTree(BiTree T, char FileName[]) {
    FILE *fp = fopen(FileName, "w");
    if (!fp) return ERROR; 
    // char ch;
    // ch = fgetc(fp);
    // if(ch != EOF){
    //     printf("\n���ļ����ܶ��룡\n");
    //     return ERROR;
    // }
    if (SaveNode(T, fp) != OK) {
        fclose(fp);
        return ERROR; 
    }
    fclose(fp); 
    return OK;
}

// 19.�ļ���ȡ
// ������������ȡ�ļ��еĽ�����ݣ�����������
status LoadNode(BiTree &node, FILE* fp) {
    KeyType key;
    char others[20];
    int x = fscanf(fp, "%d %s ", &key, others);
    if (x == EOF) {
        printf("�ļ���ȡ����\n");
        return OK; 
    } else if (x != 2) return ERROR;
    if (key == 0) {
        node = NULL;
        return OK;
    }
    node = (BiTree)malloc(sizeof(BiTNode));  
    if (!node) return ERROR;  
    node->data.key = key;
    strcpy(node->data.others, others);
    node->lchild = node->rchild = NULL;
    if (LoadNode(node->lchild, fp) != OK) return ERROR; 
    if (LoadNode(node->rchild, fp) != OK) return ERROR; 
    return OK;
}
status LoadBiTree(BiTree &T, char FileName[]) {
    if (T) return INFEASIBLE;
    FILE *fp = fopen(FileName, "r");
    if (!fp) return ERROR; 
    if (LoadNode(T, fp) != OK) {
        fclose(fp);
        return ERROR; 
    }
    fclose(fp); 
    return OK;
}

// 21.��λ��(�����߼����)
int LocateBiTree(BiForest F, char TreeName[]) {
    for (int i = 0; i < F->length; i++)
        if (!strcmp(TreeName, F->elem[i].name))
            return (i+1);
    return 0;
}

// 20.�����
status AddBiTree(BiForest F, char TreeName[]) {
    if (LocateBiTree(F, TreeName)) return ERROR;
    strcpy(F->elem[F->length].name, TreeName);
    F->elem[F->length].T = NULL;
    F->length++;
    return OK;
}

// 22.�Ƴ���
status RemoveBiTree(BiForest F, char TreeName[]) {
    if (F->length == 0) return INFEASIBLE;
    int toremove = 0;
    toremove = LocateBiTree(F, TreeName);
    if (!toremove) return ERROR;
    if (F->elem[toremove-1].T) DestroyBiTree(F->elem[toremove-1].T);
    for (int i = toremove-1; i < F->length - 1; i++) {
        strcpy(F->elem[i].name, F->elem[i+1].name);     
        F->elem[i].T = F->elem[i+1].T;       
    }
    F->length--;
    return OK;    
}

// 23.����������
status TraverseBiForest(BiForest F) {
    if (F->length == 0) return INFEASIBLE;
    printf ("\n�ɹ����������У�\n");
    int i;
    for (i = 0; i < F->length ; i++) {
        printf("%d: %s" , i+1, F->elem[i].name);
        printf("(%s)\n", (F->elem[i].T != NULL) ? "�ǿ�" : "Ϊ��");        
    }

    return OK;
}

// 24.�л���
status TurnToBiTree(BiForest F, BiTree &T, int &curindex, char CurrentTName[], int order) {
    if (F->length == 0) return INFEASIBLE;
    if (order < 1 || order > F->length) return ERROR;
    T = F->elem[order-1].T;
    curindex = order;    
    strcpy(CurrentTName, F->elem[order-1].name);
    return OK;
}