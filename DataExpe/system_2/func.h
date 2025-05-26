// 1.���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
status InitList(LinkList &L) {
    // ���LΪ��
    if (L != NULL) {
        return INFEASIBLE;
    }
    L = (LinkList)malloc(sizeof(LNode));
    if (L == NULL) {
        return ERROR;
    }
    L->next = NULL;
    return OK;
}

// 2.������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
status DestroyList(LinkList &L) {
    if (L == NULL) {
        return INFEASIBLE;
    } 
    // �ͷ�����ռ�
    LNode *current = L;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp); // �ͷŵ�ǰ�ڵ�
    }
    L = NULL;
    return OK;
}

// 3.������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
status ClearList(LinkList &L) {
    if (L == NULL) {
        return INFEASIBLE;
    } 
    // �ͷ�����ռ�
    LNode *current = L->next;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp); // �ͷŵ�ǰ�ڵ�
    }
    L->next = NULL;
    return OK;
}

// 4.������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
status ListEmpty(LinkList &L) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (L->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
    return OK;
}

// 5.������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
status ListLength(LinkList L) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    int length = 0;
    LNode* p = L->next;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    return length;
}

// 6.������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status GetElem(LinkList &L, int i, ElemType& e) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    int length = 0;
    LNode* p = L->next;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    if (i < 1 || i > length) {
        return ERROR;
    }
    int k = 0;
    p = L->next;
    while(k < i-1) {
        p = p->next;
        k++;
    }
    e = p->data;
    return OK;
}

// 7.������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
status LocateElem(LinkList &L, ElemType e) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    int length = 0;
    LNode* p = L->next;
    while (p != NULL) {
        p = p->next;
        length++;
    }
    int k = 1;
    p = L->next;
    while(k <= length) {
        if (p->data == e) {
            return k;
        }     
        p = p->next;
        k++;
    }
    return ERROR;
}

// 8.������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status PriorElem(LinkList &L, ElemType cur, ElemType &pre_e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (L->next == NULL || L->next->next == NULL) {
        return ERROR;
    }
    LNode* temp = L->next; 
    while (temp->next != NULL) { // ��������
        if (temp->next->data == cur) { // ����ҵ�Ŀ��Ԫ��
            pre_e = temp->data; // ��ǰ��Ԫ�ظ�ֵ�� pre
            return OK;
        }
        temp = temp->next; // �ƶ�����һ���ڵ�
    }
    return ERROR;
}

// 9.������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status NextElem(LinkList &L, ElemType cur, ElemType &next_e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (L->next == NULL || L->next->next == NULL) {
        return ERROR;
    }
    LNode* temp = L->next; 
    while (temp->next != NULL) { 
        if (temp->data == cur) { // ����ҵ�Ŀ��Ԫ��
            next_e = temp->next->data; 
            return OK;
        }
        temp = temp->next; // �ƶ�����һ���ڵ�
    }
    return ERROR;
}

// 10.������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListInsert(LinkList &L, int i, ElemType e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (i < 1) { // iֵ���Ϸ�
        return ERROR;
    }
    LNode *p = L;
    int k = 0; // ��ǰ�ڵ����ţ�ͷ�ڵ�Ϊ0��
    // ���ҵ� i-1 ���ڵ�
    while (p != NULL && k < i - 1) {
        p = p->next;
        k++;
    }
    if (p == NULL || k > i - 1) { // ���δ�ҵ��� i-1 ���ڵ㣬�� i ������Χ
        return ERROR;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL) {
        return OVERFLOW; // �ڴ����ʧ��
    }
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

// 11.������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListDelete(LinkList &L, int i, ElemType &e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (i < 1) { // iֵ���Ϸ�
        return ERROR;
    }
    LNode *p = L; // ��ͷ�ڵ㿪ʼ
    int k = 0; // ��ǰ�ڵ����ţ�ͷ�ڵ�Ϊ0��
    // ���ҵ� i-1 ���ڵ�
    while (p != NULL && k < i - 1) {
        p = p->next;
        k++;
    }
    if (p == NULL || p->next == NULL || k > i - 1) { // ���δ�ҵ��� i-1 ���ڵ㣬��� i ���ڵ㲻���ڣ��� i ������Χ
        return ERROR;
    }
    LNode* temp = p->next->next;
    e = p->next->data;
    free(p->next);
    p->next = temp;
    return OK;
}

// 12.������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
status ListTrabverse(LinkList &L) {
    if (L == NULL) {
        return INFEASIBLE;
    } 
    LinkList p = L->next; // �ӵ�һ���ڵ㿪ʼ
    while (p != NULL) { // ��һ���ڵ�ǿ�
        if (p->next != NULL) { // ���ں�̽ڵ�
            printf("%d ", p->data);
        } else {
            printf("%d", p->data);
        }
        p = p->next;    
    }
    return OK;
}

// 13.��ת˳���
status ReverseList(LinkList &L) {
    if (!L) {
        return INFEASIBLE; 
    } else if(!L->next || !L->next->next) {
        return ERROR;
    }
    LinkList prev = NULL;
    LinkList current = L->next;
    LinkList next = NULL;
    while (current) {
        next = current->next;
        current->next = prev; 
        prev = current;       
        current = next;       
    }
    L->next = prev;        
    return OK;
}

// 14.ɾ��������k��Ԫ��
status RemoveNthFromEnd(LinkList &L, int k, int &e)  {
    if (!L) {
        return INFEASIBLE;
    } else if (k < 1 || k > ListLength(L)) {
        return ERROR;
    }
    LNode head;
    head.next = L;
    LinkList first = &head;
    LinkList second = &head;
    // ��firstָ�����ƶ�k+1��
    for (int i = 0; i <= k; i++) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    // ɾ����һ���ڵ�
    LinkList toDelete = second->next;
    second->next = second->next->next;
    e = toDelete->data;
    free(toDelete);

    L = head.next;
    return OK; // �����µ�����ͷ
}

// 15.˳������У�ð������
status SortList(LinkList &L) {
    if (!L || !L->next) {
        return INFEASIBLE;
    }
    int length = ListLength(L);
    for (int i = 0; i < length; i++) {
        LinkList current = L->next;        
        for (int j = 0; j < length - i - 1; j++) {
            if (current->data > current->next->data) {
                ElemType temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }   
            current = current->next;         
        }
    }
    return OK;
}

// 16.��Lists������һ������ΪListName�Ŀ����Ա�
status AddList(LISTS &Lists, char ListName[]) {
    if (Lists.length >= 10) {
        return ERROR;
    }
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length++].L = NULL;
    return OK;
}

// 17.��Lists�в���һ������ΪListName�����Ա��ɹ������߼���ţ����򷵻�0
status LocateList(LISTS &Lists,char ListName[]) {
    for (int i = 0; i < Lists.length; i++) {
        if (strcmp(Lists.elem[i].name, ListName) == 0) {
            return (i+1); 
        }        
    }
    return 0;
}

// 18.Lists��ɾ��һ������ΪListName�����Ա�
status RemoveList(LISTS &Lists, char ListName[]) {
    if (Lists.length == 0) {
        return ERROR;
    }
    for (int i = 0; i < Lists.length; i++) {
        if (strcmp(Lists.elem[i].name, ListName) == 0) {
            DestroyList(Lists.elem[i].L);
            for (int j = i; j < Lists.length-1; j++) {
                Lists.elem[j] = Lists.elem[j+1];
            }
            Lists.length--;
            return OK;
        }        
    }
    return ERROR;
}

// 19.������Ա�L���ڣ������Ա�L�ĵ�Ԫ��д��FileName�ļ��У�����OK�����򷵻�INFEASIBLE��
status  SaveList(LinkList &L, char FileName[]) {
    if (L == NULL) {
        return INFEASIBLE;
    }
    FILE *fp = fopen(FileName, "wb");
    if (fp == NULL) {
        return ERROR;
    }
    LNode *p = L->next;
    while (p != NULL) {
        fwrite(&(p->data), sizeof(ElemType), 1, fp);
        p = p->next;
    }
    fclose(fp);
    return OK;
}

// 20. ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
status  LoadList(LinkList &L,char FileName[]) {
    if (L != NULL) {
        return INFEASIBLE;
    }
    FILE *fp = fopen(FileName, "rb");
    if (fp == NULL) {
        return ERROR;
    }
    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *r = L;
    ElemType e;
    while (fread(&e, sizeof(ElemType), 1, fp) == 1) {
        LNode *s = (LNode*)malloc(sizeof(LNode));
        s->data = e;
        s->next = NULL;
        r->next = s;
        r = s;
    }
    fclose(fp);
    return OK;
}

// 21. ��ʾ���пɲ���������
status ShowAllLists(LISTS &Lists) {
    if (!Lists.length) {
        return INFEASIBLE;
    }
    printf("Ŀǰϵͳ�пɲ��������Ա��У�\n");
    for (int i = 0; i < Lists.length; i++) {
        printf("%d��%s ", i+1, Lists.elem[i].name);
        printf("(%s)\n", Lists.elem[i].L ? "�ѳ�ʼ��������Ԫ��" : "δ��ʼ��");
    }
    return OK;
}