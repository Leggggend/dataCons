// 1.线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
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

// 2.如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
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

// 3.如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
status ClearList(SqList &L) {
    if (!L.elem) { 
        return INFEASIBLE;
    }
    L.length = 0;  
    return OK;
}

// 4.如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
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

// 5.如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
status ListLength(SqList L) {
    if (!L.elem) { 
        return INFEASIBLE;
    }
    return L.length;
}

// 6.如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
status GetElem(SqList &L, int i, ElemType& e) {
    if (!L.elem) {
        return INFEASIBLE;
    } else if (i <= 0 || i > L.length) {
        return FALSE;
    }
    e = L.elem[i-1];
    return OK;
}

// 7.如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
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

// 8.如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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

// 9.如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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

// 10.如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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

// 11.如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
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

// 12.如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
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

// 13.最大连续子数组和
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

// 14.和为 K 的子数组
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

// 15.顺序表排列
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

// 16.在Lists中增加一个名称为ListName的空线性表
status AddList(LISTS &Lists, char ListName[]) {
    if (Lists.length >= 10) {
        return ERROR;
    }
    strcpy(Lists.elem[Lists.length].name, ListName);
    Lists.elem[Lists.length++].L.elem = NULL;
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

// 19.如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
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

// 20. 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
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

// 21. 显示所有可操作表名称
status ShowAllLists(LISTS &Lists) {
    if (!Lists.length) {
        return INFEASIBLE;
    }
    for (int i = 0; i < Lists.length; i++) {
        printf("%d：%s\n", i+1, Lists.elem[i].name);
        printf("(%s)\n", Lists.elem[i].L.elem ? "已初始化，含有元素" : "未初始化");
    }
    return OK;
}