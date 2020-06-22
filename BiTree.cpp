//
//  BiTree.cpp
//  WordBound iOS
//
//  Created by liuyi on 2020/6/21.
//

#include <stdlib.h>
#include <stdio.h>

typedef struct BiNode{
    char ch;
    BiNode* lChild;
    BiNode* rChild;
}BiNode, BiTree;

BiTree* CreateBiTree(int lvl)
{

    printf("Create lvl = %d\n", lvl);
    
    BiTree* tree = nullptr;
    char ch;
    scanf("%c",&ch);
    getchar();
    
    if(ch == ' ')
    {
        printf("Create lvl = %d && node is null\n", lvl);
        tree = nullptr;
    }
    else
    {
        printf("Create lvl = %d && node is ch = %d\n", lvl, ch);
        tree = (BiTree*) malloc(sizeof(BiNode));
        tree->ch = ch;
        printf("Create lvl = %d && lchild\n", lvl);
        tree->lChild = CreateBiTree(lvl + 1);
        printf("Create lvl = %d && rChild\n", lvl);
        tree->rChild = CreateBiTree(lvl + 1);
    }
    printf("Create lvl = %d finished && node = %p\n ", lvl, tree);
    return tree;
}

int PreOrderTraverse(BiTree* tree)
{
    if(tree == nullptr){
        return 0;
    }else{
        printf("%c", tree->ch); //输出根
        PreOrderTraverse(tree->lChild);
        PreOrderTraverse(tree->rChild);
    }
    return 0;
}

int InOrderTraverse(BiTree* tree)
{
    if(tree == nullptr){
        return 0;
    }else{
        InOrderTraverse(tree->lChild);
        printf("%c", tree->ch); //输出根
        InOrderTraverse(tree->rChild);
    }
    return 0;
}

int PostOrderTraverse(BiTree* tree)
{
    if(tree == nullptr){
        return 0;
    }else{
        PostOrderTraverse(tree->lChild);
        PostOrderTraverse(tree->rChild);
        printf("%c", tree->ch); //输出根
    }
    return 0;
}
int main(int argc, char *argv[]) {
    BiTree* tree = CreateBiTree(0);
    PreOrderTraverse(tree);
    printf("\n");
    InOrderTraverse(tree);
    printf("\n");
    PostOrderTraverse(tree);
    printf("\n");
    return 0;
}
