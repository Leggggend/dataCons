// 1.线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
status InitList(LinkList &L) {
    // 如果L为空
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

// 2.如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
status DestroyList(LinkList &L) {
    if (L == NULL) {
        return INFEASIBLE;
    } 
    // 释放链表空间
    LNode *current = L;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp); // 释放当前节点
    }
    L = NULL;
    return OK;
}

// 3.如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
status ClearList(LinkList &L) {
    if (L == NULL) {
        return INFEASIBLE;
    } 
    // 释放链表空间
    LNode *current = L->next;
    while (current != NULL) {
        LNode* temp = current;
        current = current->next;
        free(temp); // 释放当前节点
    }
    L->next = NULL;
    return OK;
}

// 4.如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
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

// 5.如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
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

// 6.如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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

// 7.如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
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

// 8.如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status PriorElem(LinkList &L, ElemType cur, ElemType &pre_e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (L->next == NULL || L->next->next == NULL) {
        return ERROR;
    }
    LNode* temp = L->next; 
    while (temp->next != NULL) { // 遍历链表
        if (temp->next->data == cur) { // 如果找到目标元素
            pre_e = temp->data; // 将前驱元素赋值给 pre
            return OK;
        }
        temp = temp->next; // 移动到下一个节点
    }
    return ERROR;
}

// 9.如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status NextElem(LinkList &L, ElemType cur, ElemType &next_e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (L->next == NULL || L->next->next == NULL) {
        return ERROR;
    }
    LNode* temp = L->next; 
    while (temp->next != NULL) { 
        if (temp->data == cur) { // 如果找到目标元素
            next_e = temp->next->data; 
            return OK;
        }
        temp = temp->next; // 移动到下一个节点
    }
    return ERROR;
}

// 10.如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListInsert(LinkList &L, int i, ElemType e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (i < 1) { // i值不合法
        return ERROR;
    }
    LNode *p = L;
    int k = 0; // 当前节点的序号（头节点为0）
    // 查找第 i-1 个节点
    while (p != NULL && k < i - 1) {
        p = p->next;
        k++;
    }
    if (p == NULL || k > i - 1) { // 如果未找到第 i-1 个节点，或 i 超出范围
        return ERROR;
    }
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL) {
        return OVERFLOW; // 内存分配失败
    }
    newNode->data = e;
    newNode->next = p->next;
    p->next = newNode;
    return OK;
}

// 11.如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status ListDelete(LinkList &L, int i, ElemType &e) {
    if (L == NULL) {
        return INFEASIBLE;
    } else if (i < 1) { // i值不合法
        return ERROR;
    }
    LNode *p = L; // 从头节点开始
    int k = 0; // 当前节点的序号（头节点为0）
    // 查找第 i-1 个节点
    while (p != NULL && k < i - 1) {
        p = p->next;
        k++;
    }
    if (p == NULL || p->next == NULL || k > i - 1) { // 如果未找到第 i-1 个节点，或第 i 个节点不存在，或 i 超出范围
        return ERROR;
    }
    LNode* temp = p->next->next;
    e = p->next->data;
    free(p->next);
    p->next = temp;
    return OK;
}

// 12.如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
status ListTrabverse(LinkList &L) {
    if (L == NULL) {
        return INFEASIBLE;
    } 
    LinkList p = L->next; // 从第一个节点开始
    while (p != NULL) { // 第一个节点非空
        if (p->next != NULL) { // 存在后继节点
            printf("%d ", p->data);
        } else {
            printf("%d", p->data);
        }
        p = p->next;    
    }
    return OK;
}

// 13.翻转顺序表
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

// 14.删除倒数第k个元素
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
    // 让first指针先移动k+1步
    for (int i = 0; i <= k; i++) {
        first = first->next;
    }
    while (first) {
        first = first->next;
        second = second->next;
    }
    // 删除下一个节点
    LinkList toDelete = second->next;
    second->next = second->next->next;
    e = toDelete->data;
    free(toDelete);

    L = head.next;
    return OK; // 返回新的链表头
}

// 15.顺序表排列（冒泡排序）
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

// 16.在Lists中增加一个名称为ListName的空线性表
status AddList(LISTS &Lists, char ListName[]) {
    if (Lists.length >= 10) {
        return ERROR;
    }
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length++].L = NULL;
    return OK;
}

// 17.在Lists中查找一个名称为ListName的线性表，成功返回逻辑序号，否则返回0
status LocateList(LISTS &Lists,char ListName[]) {
    for (int i = 0; i < Lists.length; i++) {
        if (strcmp(Lists.elem[i].name, ListName) == 0) {
            return (i+1); 
        }        
    }
    return 0;
}

// 18.Lists中删除一个名称为ListName的线性表
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

// 19.如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
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

// 20. 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
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

// 21. 显示所有可操作表名称
status ShowAllLists(LISTS &Lists) {
    if (!Lists.length) {
        return INFEASIBLE;
    }
    printf("目前系统中可操作的线性表有：\n");
    for (int i = 0; i < Lists.length; i++) {
        printf("%d：%s ", i+1, Lists.elem[i].name);
        printf("(%s)\n", Lists.elem[i].L ? "已初始化，含有元素" : "未初始化");
    }
    return OK;
}