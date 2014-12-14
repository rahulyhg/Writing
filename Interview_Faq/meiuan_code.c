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





//一个整数数组，无重复元素，先递增，后递减，写出最高效的代码找出该数组的最大值。
//例如数组[0,2,4,6,8,7,5,3,1]，先是递增到8后递减到1，最大值为8

//这个时间复杂度On,我在想想
int getMax(int *arr, int num)
{
    
    int i,index;
    index = 0;
    
    if(num == 0)
        return -1;
        
    for(i=1; i<num; i++) {
        if(arr[index] < arr[i])
            index = i;
        else
            break;
    }
    
    return arr[index];
}


int getMaxByBinary(int *arr, int num)
{
    if(num == 0)
        return -1;
    int start = 0;
    int end = num -1;
    int center = (start+end)/2;
    
    while(center >0 && center < num -1) {
        
        if( arr[center] > arr[center+1] && 
            arr[center] > arr[center-1] )
            return arr[center];
        else if( arr[center] < arr[center+1]) {
            start = center + 1;
            center = (start + begin)/2;
        } else {
            end = center - 1;
            center = (start + end)/2
        }
    }

    return center;
}

//实现power(x, n)：x是浮点数，n是整数，返回x的n次方。希望算法尽可能优化。

double power(double x, int n)
{
    if(n < 0) {
        n = -n;
        x = 1/ x;
    }
    
    if(n == 0)
        return 1;
        
    if(n == 1)
        return x;
    
    return x*power(x, n-1);
}


