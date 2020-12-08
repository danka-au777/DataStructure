#ifndef __BINLINKLIST_H__
#define __BINLINKLIST_H__

#include <fstream>
#include <iostream>
#include <stack>
template <class ElemType>
class BinNode
{
public:
    ElemType data;
    BinNode<ElemType> *left;
    BinNode<ElemType> *right;
    BinNode(ElemType d, BinNode<ElemType> *l = NULL, BinNode<ElemType> *r = NULL)
    {
        data = d;
        left = l;
        right = r;
    }
    void InsertChildren(BinNode<ElemType> *l, BinNode<ElemType> *r)
    {
        left = l;
        right = r;
    }
};

template <class ElemType>
class BinTree
{
private:
    BinNode<ElemType> *root;

public:
    BinTree(ElemType e)
    {
        root = new BinNode<ElemType>(e);
    }
    BinTree(BinNode<ElemType> *r)
    {
        root = r;
    }
    ~BinTree()
    {
        DestroyHandle(root);
    }
    void DestroyHandle(BinNode<ElemType> *cur);
    void SetElem(BinNode<ElemType> *cur, ElemType e);
    void InsertLeftChild(BinNode<ElemType> *cur, ElemType e);
    void InsertRightChild(BinNode<ElemType> *cur, ElemType e);
    BinNode<ElemType> *GetRoot()
    {
        return root;
    }
    BinNode<ElemType> *GetLeftChild(BinNode<ElemType> *cur)
    {
        return cur->left;
    }
    BinNode<ElemType> *GetRightChild(BinNode<ElemType> *cur)
    {
        return cur->right;
    }
    void InOrderHandle(BinNode<ElemType> *cur);
    void PostOrderHandle(BinNode<ElemType> *cur);
    void PreOrder(); //non-recursive
    void InOrder()
    { //recursive
        InOrderHandle(root);
        std::cout << std::endl;
    }
    void PostOrder()
    { //recursive
        PostOrderHandle(root);
        std::cout << std::endl;
    }
};

template <class ElemType>
void BinTree<ElemType>::PostOrderHandle(BinNode<ElemType> *cur)
{
    if (cur != NULL)
    {
        PostOrderHandle(cur->left);
        PostOrderHandle(cur->right);
        std::cout << cur->data << " ";
    }
}

template <class ElemType>
void BinTree<ElemType>::InOrderHandle(BinNode<ElemType> *cur)
{
    if (cur != NULL)
    {
        InOrderHandle(cur->left);
        std::cout << cur->data << " ";
        InOrderHandle(cur->right);
    }
}

template <class ElemType>
void BinTree<ElemType>::DestroyHandle(BinNode<ElemType> *cur)
{
    if (cur != NULL)
    {
        DestroyHandle(cur->left);
        DestroyHandle(cur->right);
        delete cur;
        cur = NULL;
    }
}

template <class ElemType>
void BinTree<ElemType>::SetElem(BinNode<ElemType> *cur, ElemType e)
{
    cur->data = e;
}

template <class ElemType>
void BinTree<ElemType>::InsertLeftChild(BinNode<ElemType> *cur, ElemType e)
{
    BinNode<ElemType> *leftchild = new BinNode<ElemType>(e);
    cur->left = leftchild;
}

template <class ElemType>
void BinTree<ElemType>::InsertRightChild(BinNode<ElemType> *cur, ElemType e)
{
    BinNode<ElemType> *rightchild = new BinNode<ElemType>(e);
    cur->right = rightchild;
}

template <class ElemType>
void BinTree<ElemType>::PreOrder()
{
    std::stack<BinNode<ElemType> *> stk;
    BinNode<ElemType> *cur = root;
    while (cur != NULL)
    {
        std::cout << cur->data;
        stk.push(cur);
        if (cur->left != NULL)
        {
            cur = cur->left;
        }
        else if (!stk.empty())
        {
            while (!stk.empty())
            {
                cur = stk.top();
                stk.pop();
                cur = cur->right;
                if (cur != NULL)
                    break;
            }
        }
        else
            cur = NULL;
    }
}

#endif