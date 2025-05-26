// 基于链式存储结构的线性表实现
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include "def.h" // 数据类型的相关定义
#include "func.h" // 相关功能的实现

int main(void) {
    BiTree T = NULL;
    char currentTName[30]; // 当前操作树名    
    int curindex = 0;      // 当前操作编号
    strcpy(currentTName, "请添加或切换树！");

    BiForest F;    
    F = (BiForest)malloc(sizeof(Forest));
    F->length = 0;
    for (int i = 0; i < 10; i++) {
        F->elem[i].T = NULL;
    }

    KeyType e;
    char FileName[50];
    char TreeName[30];
    TElemType definition1[100];
    DEF definition2[100];

    int op = 1;
    while (op) {
        system("cls");	// 清屏
        printf("\n\n");
        printf("      Menu For Binary Tree On Binary Linked Structure \n");
        printf("-------------------------------------------------------------\n");
        printf("          1. CreateBiTree         2. DestroyBiTree\n");
        printf("          3. ClearBiTree          4. BiTreeEmpty\n");
        printf("          5. ListDepth            6. LocateNode\n");
        printf("          7. AssignNode           8. GetSibling\n");
        printf("          9. InsertNode          10. DeleteNode\n");
        printf("         11. PreOrderTraverse    12. InOrederTrabverse\n");
        printf("         13. PostOrderTraverse   14. LevelOrderTraverse\n");
        printf("         15. MaxPathSum          16. LowestCommonAncestor\n");
        printf("         17. InvertBiTree        18. SaveBiTree\n");
        printf("         19. LoadBiTree          20. AddBiTree\n");
        printf("         21. LocateBiTree        22. RemoveBiTree\n");
        printf("         23. TraverseBiForest    24. TurnToBiTree\n");
        printf("          0. Exit\n");
        printf("------------------------------------------------------------\n");
        printf("    当前操作二叉树：\n");
        printf("       序号：%d\n", curindex);
        printf("       树名：%s\n", currentTName);
        printf("    请选择您的操作 [0 ~ 24]: ");
        scanf("%d", &op);        
        printf("------------------------------------------------------------\n");

        switch (op) {
        case 1: {
            if (T) printf("当前树已包含数据！\n");
            else {
                int method;
                printf("请选择输入方式（1-带空结点(推荐)；2-满二叉树编号）：");
                scanf("%d", &method);
                if (method == 1) {
                    int i = 0;
                    printf("请输入结点序列：");
                    do {
                        scanf("%d %s", &definition1[i].key, definition1[i].others);
                    } while (definition1[i++].key != -1);
                    if (CreateBiTree1(T, definition1) != OK) printf("\n创建失败！\n");
                    else {
                        F->elem[curindex-1].T = T; // 森林记录， 避免丢失
                        printf("\n创建成功！\n"); 
                    }                     
                } else if (method == 2) {
                    int i = 0;
                    printf("请输入结点序列：");
                    do {
                        scanf("%d %d %s", &definition2[i].pos, &definition2[i].data.key, definition2[i].data.others);
                    } while (definition2[i++].pos);
                    if (CreateBiTree2(T, definition2, i) != OK) printf("\n创建失败！\n");
                    else {
                        printf("\n创建成功！\n"); 
                        F->elem[curindex-1].T = T; // 森林记录， 避免丢失
                    }
                } else {
                    printf("请输入1或者2！\n");
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 2: {
            if (!T) printf("树已为空！\n");
            else if (DestroyBiTree(T) != OK) 
                printf("\n摧毁失败！\n");
            else printf("\n摧毁成功！\n");                
            printf("按任意键继续...");
            getchar();getchar();
            break;            
        }

        case 3: {
            if (!T) printf("树已为空！\n");
            else if (ClearBiTree(T) != OK) 
                printf("\n清空失败！\n");
            else printf("\n清空成功！\n");                
            printf("按任意键继续...");
            getchar();getchar();
            break;            
        }

        case 4: {
            if (BiTreeEmpty(T) == TRUE) printf("树为空！\n");
            else printf("树非空！\n");
            printf("按任意键继续...");
            getchar();getchar();
            break;            
        }

        case 5: {
            if (!T) printf("树为空！\n");  
            else printf("树的深度为%d！\n", BiTreeDepth(T));                
            printf("按任意键继续...");
            getchar();getchar();
            break;            
        }

        case 6: {
            if (!T) printf("树为空！\n");
            else {
                printf("\n请输入要查找的结点关键字：");
                scanf("%d", &e);
                BiTree p = LocateNode(T, e);
                if (!p) printf("\n目标结点不存在！\n");
                else printf("\n目标结点为(%d,%s)！\n", p->data.key, p->data.others);                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;            
        }

        case 7: {
            if (!T) printf("树为空！\n");
            else {
                TElemType value;
                printf("\n请输入要赋值的结点关键字：");
                scanf("%d", &e);
                printf("\n请输入要赋的值：");
                scanf("%d %s", &value.key, value.others);
                if (AssignNode(T, e, value) != OK) 
                    printf("\n结点不存在或关键字重复！\n");
                else printf("\n赋值成功！\n");                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }
 
        case 8: {
            if (!T) printf("树为空！\n");
            else {
                printf("\n请输入要查询的关键字：");
                scanf("%d", &e);
                BiTree sib = GetSibling(T, e);
                if (!sib) printf("\n查询失败！\n");
                else 
                    printf("\n兄弟结点为(%d, %s)！\n", sib->data.key, sib->data.others);                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 9:{            
            if (!T) printf("树为空！\n");
            else {
                int LR;
                TElemType c;
                printf("\n请输入插入的方式：");
                scanf("%d", &LR); 
                if (LR != -1) {
                    printf("\n请输入插入位置的关键字：");
                    scanf("%d", &e);
                }       
                printf("\n请输入插入的结点：");
                scanf("%d %s", &c.key, c.others);
                if (InsertNode(T, e, LR, c) != OK) printf("\n插入失败！\n");
                else printf("\n插入成功！\n");                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 10:{
            if (!T) printf("树为空！\n");
            else {
                printf("请输入要删除节点的关键字：");
                scanf("%d", &e);
                if (DeleteNode(T, e) != OK) 
                    printf("\n目标结点不存在！\n");
                else printf("\n删除成功！\n");                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 11:{
            if (!T) printf("树为空！\n");
            else if (PreOrderTraverse(T, Visit) != OK) 
                printf("\n遍历失败！\n");               
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 12: {
            if (!T) printf("树为空！\n");
            else if (InOrderTraverse(T, Visit) != OK) 
                printf("\n遍历失败！\n");
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }
 
        case 13:{
            if (!T) printf("树为空！\n");
            else if (PostOrderTraverse(T, Visit) != OK) printf("\n遍历失败！\n");
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 14: {
            if (!T) printf("树为空！\n");
            else if (LevelOrderTraverse(T, Visit) != OK)
                printf("\n遍历失败！\n");
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 15:{
            if (!T) printf("树为空！\n");
            else printf("\n最大路径和为：%d！\n", MaxPathSum(T));
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 16:{
            if (!T) printf("树为空！\n");
            else {
                KeyType e1, e2;
                printf("\n请输入两个要查询结点的关键字：");
                scanf("%d %d", &e1, &e2);
                BiTree anc = LowestCommonAncestor(T, e1, e2);
                if (!anc) printf("\n不存在公共祖先！\n");
                else 
                    printf("\n最近公共祖先为：(%d, %s)！\n", anc->data.key, anc->data.others);                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 17:{
            if (!T) printf("树为空！\n");
            else if (InvertBiTree(T) != OK) printf("\n翻转失败！\n");
            else printf("\n翻转成功！\n");
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 18:{
            if (!T) printf("树为空！\n");
            else {
                printf("\n请输入文件名：");
                scanf("%s", FileName);
                if (SaveBiTree(T, FileName) != OK) printf("\n保存失败！\n");
                else {
                    F->elem[curindex-1].T = T; // 森林记录， 避免丢失
                    printf("\n保存成功！\n");                
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 19:{
            if (T) printf("树非空！\n");
            else {
                printf("\n请输入文件名：");
                scanf("%s", FileName);
                if (LoadBiTree(T, FileName) != OK) printf("\n读取失败！\n");
                else {
                    F->elem[curindex-1].T = T; // 森林记录， 避免丢失
                    printf("\n读取成功！\n");                
                    
                }
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;  
        }
 
        case 20:{
            if (F->length == 10) printf("森林已满！\n");
            else {
                printf("\n请输入要添加的树名：");
                scanf("%s", TreeName);
                printf("创建中\n");
                if (AddBiTree(F, TreeName) != OK) printf("\n树名重复！\n");
                else printf("\n添加成功！\n");                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;  
        }

        case 21:{
            if (!F->length) printf("森林为空！\n");
            else {
                printf("\n请输入树名：");
                scanf("%s", TreeName);
                int index;
                index = LocateBiTree(F, TreeName);
                if (!index) printf("\n树不在森林中！\n");
                else printf("\n是森林中第%d棵树！\n", index);                
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;   
        }

        case 22:{
            if (!F->length) printf("森林为空！\n");
            else {
                printf("\n请输入树名：");
                scanf("%s", TreeName);
                if (RemoveBiTree(F, TreeName) != OK) printf("\n树不在森林中！\n");
                else printf("\n移除成功！\n"); 
                if (!strcmp(TreeName, currentTName)) { // 如果移除当前树
                    curindex = 0;
                    T = NULL;
                    strcpy(currentTName, "请添加或切换树！");
                }          
            }
            printf("按任意键继续...");
            getchar();getchar();
            break;
        }

        case 23:{
            if (!F->length) printf("森林为空！\n");
            else if (TraverseBiForest(F) != OK) printf("\n遍历失败！\n");               
            printf("\n按任意键继续...");
            getchar();getchar();
            break;
        }

        case 24:{
            if (!F->length) printf("森林为空！\n");
            else {
                int order;
                printf("\n请输入要操作的树序号：");
                scanf("%d", &order);
                if (TurnToBiTree(F, T, curindex, currentTName, order) != OK) printf("\n序号非法！\n");
                else 
                    printf("\n已切换至树%s！\n", currentTName);                
            }
            printf("按任意键继续...");
            getchar();getchar();           
            break;
        }

        case 0:
            break;
        } // end of switch
    } // end of while
    printf("欢迎下次使用本系统!\n");
    getchar();getchar();
    return 0;
} // end of main()