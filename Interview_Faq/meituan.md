//如何判断二个二插数是否相等,不能够用递归

//中序遍历比较
//S1,S2分别为两个栈，用来保存遍历root1,root2过程中的节点指针
//1-->相等
//0-->不相等
int centerTraverse(Tree root1, Tree roo2)
{
    Tree p1 = root1;
    Tree p2 = root2;

    do {
        while(p1 != NULL) {
            push(s1, p1);
            p1 = p1->lchild;
        }
        
        while(p2 != NULL) {
            push(s2, p2);
            p2 = p2->lchild;
        }
        
        if( isEmpty(s1) && isEmpty(s2) ) 
            return 1;
        else if( !isEmpty(s1) && !isEmpty(s2) ) {
            p1 = pop(s1);
            p2 = pop(s2);
            if( !doVisit(p1->data, p2->data))
                return 0;
            p1 = p1->lchild;
            p2 = p2->lchild;
        } else
            return false;
    }while(p1 != NULL && p2 != NULL)
    return 1;
}


int firstTraverse(Tree root1, Tree root1)
{
    Tree p1 = root1;
    Tree p2 = root2;
    
    do{
        while(p1 != NULL && p2 != NULL) {
            push(s1, p1);
            push(s2, p2);
            if( !doVisit(p1->data, p2->data))
                return 0;
            p1 = p1->lchild;
            p2 = p2->lchild;
        }
        if( isEmpty(s1) && isEmpty(s2) ) 
            return 1;
        else if( !isEmpty(s1) && !isEmpty(s2) ) {
            p1 = pop(s1);
            p2 = pop(s2);
            p1 = p1->lchild;
            p2 = p2->lchild;
        } else
            return false;
        
    }while(p1 !=NULL && p2 != NULL)
    
    return 1;
}

int compareTree(Tree roo1, Tree root2)
{
    if(centerTraverse(roo1, root2) && firstTraverse(root1, root2))
        return 1;
    else
        return 0;
}



一个栈，只有push和pop操作，时间复杂度为O(1)  

