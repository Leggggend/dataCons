// 1.���Ա�L�����ڣ�����һ���յ����Ա�����OK�����򷵻�INFEASIBLE��
status InitList(SqList &L) {
    if (L.elem) {
        return INFEASIBLE;
    } 
    L.elem = (ElemType *)malloc(sizeof(ElemType) * LIST_INIT_SIZE);
    if (!L.elem) {
        return ERROR;
    }  
    L.listsize = LIST_INIT_SIZE;
    L.length = 0;
    return OK;
}

// 2.������Ա�L���ڣ��������Ա�L���ͷ�����Ԫ�صĿռ䣬����OK�����򷵻�INFEASIBLE��
status DestroyList(SqList &L) {
    if (!L.elem) { 
        return INFEASIBLE;
    } 
    L.listsize = LIST_INIT_SIZE;
    L.length = 0;
    free(L.elem);
    L.elem = NULL;
    return OK;
}

// 3.������Ա�L���ڣ�ɾ�����Ա�L�е�����Ԫ�أ�����OK�����򷵻�INFEASIBLE��
status ClearList(SqList &L) {
    if (!L.elem) { 
        return INFEASIBLE;
    }
    L.length = 0;  
    return OK;
}

// 4.������Ա�L���ڣ��ж����Ա�L�Ƿ�Ϊ�գ��վͷ���TRUE�����򷵻�FALSE��������Ա�L�����ڣ�����INFEASIBLE��
status ListEmpty(SqList &L) {
    if (!L.elem) {
        return INFEASIBLE;
    }
    if (L.length) {
        return FALSE;
    } else {
        return TRUE;
    }
}

// 5.������Ա�L���ڣ��������Ա�L�ĳ��ȣ����򷵻�INFEASIBLE��
status ListLength(SqList L) {
    if (!L.elem) { 
        return INFEASIBLE;
    }
    return L.length;
}

// 6.������Ա�L���ڣ���ȡ���Ա�L�ĵ�i��Ԫ�أ�������e�У�����OK�����i���Ϸ�������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status GetElem(SqList &L, int i, ElemType& e) {
    if (!L.elem) {
        return INFEASIBLE;
    } else if (i <= 0 || i > L.length) {
        return FALSE;
    }
    e = L.elem[i-1];
    return OK;
}

// 7.������Ա�L���ڣ�����Ԫ��e�����Ա�L�е�λ����Ų����ظ���ţ����e�����ڣ�����0�������Ա�L������ʱ������INFEASIBLE����-1����
status LocateElem(SqList &L, ElemType e) {
    if (!L.elem) { 
        return INFEASIBLE;
    } 
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e) {
            return (i+1);
        }
    }
    return 0; 
}

// 8.������Ա�L���ڣ���ȡ���Ա�L��Ԫ��e��ǰ����������pre�У�����OK�����û��ǰ��������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status PriorElem(SqList &L, ElemType cur, ElemType &pre_e) {
    if (!L.elem) { 
        return INFEASIBLE;
    } 
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == cur) {
            if (i == 0) {
                return ERROR;
            } else {
                pre_e = L.elem[i-1];
                return OK;
            }
        }
    }
    return ERROR;
}

// 9.������Ա�L���ڣ���ȡ���Ա�LԪ��e�ĺ�̣�������next�У�����OK�����û�к�̣�����ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status NextElem(SqList &L, ElemType cur, ElemType &next_e) {
    if (!L.elem) { 
        return INFEASIBLE;
    } 
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == cur) {
            if (i == L.length-1) { 
                return ERROR;
            } else {
                next_e = L.elem[i+1];
                return OK;
            }
        }
    }
    return ERROR;
}

// 10.������Ա�L���ڣ���Ԫ��e���뵽���Ա�L�ĵ�i��Ԫ��֮ǰ������OK��������λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListInsert(SqList &L, int i, ElemType e) {
    if (!L.elem) { 
        return INFEASIBLE;
    } else if (i <= 0 || i > L.length+1) {
        return 2;
    } else if (L.length == L.listsize || i > L.length) { 
        L.elem = (ElemType *)realloc(L.elem, sizeof(ElemType)*(LIST_INIT_SIZE+10));
        if (!L.elem) {
            return ERROR;
        }
    }
    int j;
    for (j = L.length; j > i-1; j--) {
        L.elem[j] = L.elem[j-1];
    }
    L.elem[j] = e;
    L.length++;
    return OK;
}

// 11.������Ա�L���ڣ�ɾ�����Ա�L�ĵ�i��Ԫ�أ���������e�У�����OK����ɾ��λ�ò���ȷʱ������ERROR��������Ա�L�����ڣ�����INFEASIBLE��
status ListDelete(SqList &L, int i, ElemType &e) {
    if (!L.elem) {
        return INFEASIBLE;
    } else if (L.length == 0 || i < 1 || i > L.length) { 
        return ERROR;
    }
    e = L.elem[i-1];
    int j;
    for (j = i-1; j < L.length; j++) { 
        L.elem[j] = L.elem[j+1];
    }
    L.length--;
    return OK;
}

// 12.������Ա�L���ڣ�������ʾ���Ա��е�Ԫ�أ�ÿ��Ԫ�ؼ��һ�񣬷���OK��������Ա�L�����ڣ�����INFEASIBLE��
status ListTrabverse(SqList &L) {
    if (!L.elem) { 
        return INFEASIBLE;
    } 
    if (L.length > 0) {
        int i;
        for (i = 0; i < L.length-1; i++) {
            printf("%d ", L.elem[i]);
        }    
        printf("%d", L.elem[i]);    
    }
    return OK;
}

// 13.��������������
status MaxSubArray(SqList &L) {
    if (L.elem == NULL) {
        return INFEASIBLE;
    } else if (L.length == 0) return ERROR; 
    int maxSum = 0; 
    for (int i = 0; i < L.length; i++) {
        int sum = 0;
        for (int j = i; j < L.length; j++) {
            sum += L.elem[j];
            if (sum > maxSum) {
                maxSum = sum;
            }
        }
    }
    return maxSum;
}

// 14.��Ϊ K ��������
status SubArrayNum(SqList &L, int k)  {
    if (L.elem == NULL) {
        return INFEASIBLE;
    } else if (L.length == 0) return ERROR;
    int count = 0; 
    for (int i = 0; i < L.length; i++) {
        int sum = 0;
        for (int j = i; j < L.length; j++) {
            sum += L.elem[j];
            if (sum == k) {
                count++;
            }
        }
    }
    return count; 
}

// 15.˳�������
status SortList(SqList &L) {
    if (L.elem == NULL) {
        return INFEASIBLE;
    } else {
        for (int i = 0; i < L.length; i++) {
            for (int j = 0; j < L.length - i - 1; j++) {
                if (L.elem[j] > L.elem[j + 1]) {
                    ElemType temp = L.elem[j];
                    L.elem[j] = L.elem[j + 1];
                    L.elem[j + 1] = temp;
                }
            }
        }
        return OK;
    }
}

// 16.��Lists������һ������ΪListName�Ŀ����Ա�
status AddList(LISTS &Lists, char ListName[]) {
    if (Lists.length >= 10) {
        return ERROR;
    }
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length++].L.elem = NULL;
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
        // ???????????????
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
status  SaveList(SqList &L,char FileName[]) {
    if (!L.elem) {
        return INFEASIBLE;
    }
    FILE* fp = fopen(FileName, "wb");
    if (!fp) {
        return INFEASIBLE;
    }
    fwrite(&L.length, sizeof(L.length), 1, fp);
    for (int i = 0; i < L.length; i++) {
        fwrite(&L.elem[i], sizeof(ElemType), 1, fp);
    }
    fclose(fp);
    return OK;
}

// 20. ������Ա�L�����ڣ���FileName�ļ��е����ݶ��뵽���Ա�L�У�����OK�����򷵻�INFEASIBLE��
status  LoadList(SqList &L,char FileName[]) {
    if (L.elem) {
        return INFEASIBLE;
    } 
    L.elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    FILE* fp = fopen(FileName, "rb");
    if (!fp) {
        free(L.elem);
        L.elem = NULL;
        return INFEASIBLE; 
    }
    fread(&L.length, sizeof(L.length), 1, fp);
    if (L.length > L.listsize) {
        L.listsize = L.length;
        L.elem = (ElemType*)realloc(L.elem, sizeof(ElemType) * L.listsize);
        if (!L.elem) {
            fclose(fp);
            return INFEASIBLE; 
        }
    }
    for (int i = 0; i < L.length; i++) {
        fread(&L.elem[i], sizeof(ElemType), 1, fp);
    }
    fclose(fp);
    return OK;
}

// 21. ��ʾ���пɲ���������
status ShowAllLists(LISTS &Lists) {
    if (!Lists.length) {
        return INFEASIBLE;
    }
    for (int i = 0; i < Lists.length; i++) {
        printf("%d��%s\n", i+1, Lists.elem[i].name);
        printf("(%s)\n", Lists.elem[i].L.elem ? "�ѳ�ʼ��������Ԫ��" : "δ��ʼ��");
    }
    return OK;
}