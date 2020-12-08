#ifndef __GRAPH_H
#define __GRAPH_H

#include <queue>
#include <stack>
#include "list.h"
template <class ElemType>
class GraphNode
{
public:
    ElemType data;
    LinkList<int> *adjLink;
    GraphNode()
    {
        adjLink = NULL;
    }
    GraphNode(ElemType d, LinkList<int> *lk = NULL)
    {
        data = d;
        adjLink = lk;
    }
};

template <class ElemType>
class UndirGraph
{
private:
    int vNum, eNum;
    GraphNode<ElemType> *vArray;
    bool *visited;
    int FindV2IndexofV1adjLink(int v1, int v2);
    std::queue<int> BFSqueue;
    std::stack<int> DFSstack;

public:
    UndirGraph(ElemType ed[], int v);
    UndirGraph(int v);
    ~UndirGraph();
    void InsertEdge(int v1, int v2);
    void DeleteEdge(int v1, int v2);
    void BreadFS();
    void DepthFS();
};

template <class ElemType>
UndirGraph<ElemType>::UndirGraph(int v)
{
    if (v < 0)
        std::cout << "Invalid vex num" << std::endl;
    else
    {
        vNum = v;
        eNum = 0;
        vArray = new GraphNode<ElemType>[v];
        visited = new bool[v];
        for (int i = 0; i < v; i++)
        {
            visited[i] = false;
        }
    }
}

template <class ElemType>
UndirGraph<ElemType>::UndirGraph(ElemType ed[], int v)
{
    if (v < 0)
        std::cout << "Invalid vex num" << std::endl;
    else
    {
        vNum = v;
        eNum = 0;
        vArray = new GraphNode<ElemType>[v];
        for (int i = 0; i < v; i++)
        {
            vArray[i].data = ed[i];
        }
    }
}

template <class ElemType>
UndirGraph<ElemType>::~UndirGraph()
{
    for (int i = 0; i < vNum; i++)
    {
        if (vArray[i].adjLink != NULL)
            delete vArray[i].adjLink;
    }
    delete[] vArray;
}

template <class ElemType>
int UndirGraph<ElemType>::FindV2IndexofV1adjLink(int v1, int v2)
{
    if (vArray[v1].adjLink == NULL)
    {
        return -1;
    }
    else
    {
        LinkList<int> *v1Link = vArray[v1].adjLink;
        for (int i = 1; i <= v1Link->Length(); i++)
        {
            if (v1Link->GetElem(i) == v2)
                return i;
        }
        return -1;
    }
}

template <class ElemType>
void UndirGraph<ElemType>::InsertEdge(int v1, int v2)
{
    if (v1 < vNum && v1 >= 0 && v1 < vNum && v1 >= 0)
    {
        if (vArray[v1].adjLink == NULL)
            vArray[v1].adjLink = new LinkList<int>;
        if (FindV2IndexofV1adjLink(v1, v2) == -1)
        {
            LinkList<int> *adjlk = vArray[v1].adjLink;
            adjlk->Insert(adjlk->Length() + 1, v2);
            eNum++;
        }
        if (vArray[v2].adjLink == NULL)
            vArray[v2].adjLink = new LinkList<int>;
        if (FindV2IndexofV1adjLink(v2, v1) == -1)
        {
            LinkList<int> *adjlk = vArray[v2].adjLink;
            adjlk->Insert(adjlk->Length() + 1, v1);
        }
    }
    else
        std::cout << "Invalid vexNum" << std::endl;
}

template <class ElemType>
void UndirGraph<ElemType>::DeleteEdge(int v1, int v2)
{
    if (v1 < vNum && v1 >= 0 && v1 < vNum && v1 >= 0)
    {
        int index = FindV2IndexofV1adjLink(v1, v2);
        if (index != -1)
        {
            LinkList<int> *adjlk = vArray[v1].adjLink;
            adjlk->Delete(index);
            eNum--;
        }
        index = FindV2IndexofV1adjLink(v2, v1);
        if (index != -1)
        {
            LinkList<int> *adjlk = vArray[v2].adjLink;
            adjlk->Delete(index);
        }
    }
    else
        std::cout << "Invalid vexNum" << std::endl;
}

template <class ElemType>
void UndirGraph<ElemType>::BreadFS()
{
    GraphNode<ElemType> *vtx;
    Node<int> *curVindexPtr;
    int first, vindex;
    for (int i = 0; i < vNum; i++)
    {
        if (!visited[i])
        {
            vtx = &vArray[i];
            visited[i] = true;
            std::cout << "v" << i << "->";
            BFSqueue.push(i);
            while (!BFSqueue.empty())
            {
                first=BFSqueue.front() ;
                BFSqueue.pop();
                vtx = &vArray[first];
                curVindexPtr= vtx->adjLink->head->next;
                while (curVindexPtr != NULL)
                {
                    vindex = curVindexPtr->data;
                    if (!visited[vindex])
                    {
                        std::cout << "v" << vindex << "->";
                        visited[vindex] = true;
                        BFSqueue.push(vindex);
                    }
                    curVindexPtr = curVindexPtr->next;
                }
            }
        }
    }
}

template <class ElemType>
void UndirGraph<ElemType>::DepthFS()
{
    GraphNode<ElemType> *vtx;
    Node<int> *curVindexPtr;
    int first, vindex;
    for (int i = 0; i < vNum; i++)
    {
        if (!visited[i])
        {
            vtx = &vArray[i];
            visited[i] = true;
            std::cout << "v" << i << "->";
            DFSstack.push(i);
            while (!DFSstack.empty())
            {
                first=DFSstack.top();
                vtx = &vArray[first];
                curVindexPtr= vtx->adjLink->head->next;
                while (curVindexPtr != NULL)
                {
                    vindex = curVindexPtr->data;
                    if (!visited[vindex])
                    {
                        std::cout << "v" << vindex << "->";
                        visited[vindex] = true;
                        DFSstack.push(vindex);
                        break;
                    }
                    curVindexPtr = curVindexPtr->next;
                }
                if(curVindexPtr==NULL)
                    DFSstack.pop();
            }
        }
    }


}

#endif