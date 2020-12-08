#ifndef __TRITRANSMTX_H__
#define __TRITRANSMTX_H__

#include <iostream>
template <class ElemType>
class Triple
{
public:
    int row, col;
    ElemType value;
    Triple()
    {
    }
    Triple(int r, int c, ElemType v)
    {
        row = r;
        col = c;
        value = v;
    }
};

template <class ElemType>
class triSparseMtx
{
private:
    Triple<ElemType> *triElem;
    int rows, cols, nums, size;

public:
    triSparseMtx(int r, int c, int s);
    ~triSparseMtx();
    void Display()
    {
        for (int i = 0; i < nums; i++)
        {
            std::cout << triElem[i].row << " " << triElem[i].col << " " << triElem[i].value << std::endl;
        }
    }
    bool SetElem(int r, int c, ElemType e);
    triSparseMtx<ElemType> Trans();
};

template <class ElemType>
triSparseMtx<ElemType>::triSparseMtx(int r, int c, int s)
{
    if (r < 1 || c < 1)
        std::cout << "Invalid rows and cols." << std::endl;
    else
    {
        rows = r;
        cols = c;
        size = s;
        nums = 0;
        triElem = new Triple<ElemType>[size];
    }
}

template <class ElemType>
triSparseMtx<ElemType>::~triSparseMtx()
{
    delete[] triElem;
}

template <class ElemType>
bool triSparseMtx<ElemType>::SetElem(int r, int c, ElemType value)
{
    if (r < 1 || c < 1 || r > rows || c > cols)
    {
        std::cout << "Invalid rows and cols." << std::endl;
        return false;
    }
    int i, posn = 0;
    for (posn = nums - 1; posn >= 0 && (r < triElem[posn].row || (r == triElem[posn].row && c < triElem[posn].col)); posn--)
        ;
    if (posn >= 0 && triElem[posn].row == r && triElem[posn].col == c)
    {
        if (value == 0)
        {
            for (i = posn + 1; i < nums; i++)
                triElem[i - 1] = triElem[i];
            nums--;
        }
        else
            triElem[posn].value = value;
        return true;
    }
    else if (value != 0)
    {
        if (nums >= size)
        {
            std::cout << "Invalid capacity." << std::endl;
            return false;
        }
        for (i = nums - 1; i > posn; i--)
            triElem[i + 1] = triElem[i];
        triElem[posn + 1].row = r;
        triElem[posn + 1].col = c;
        triElem[posn + 1].value = value;
        nums++;
        return true;
    }
    return false;
}

template <class ElemType>
triSparseMtx<ElemType> triSparseMtx<ElemType>::Trans()
{
    triSparseMtx<ElemType> dest(cols, rows, size);
    dest.nums = nums;
    int *cNum = new int[cols + 1]; //numbers of cols' elem
    int *cPos = new int[cols + 1]; //pos of the first not0 elem in every col
    int pos;
    for (int i = 1; i <= cols; i++)
        cNum[i] = 0;
    for (int i = 0; i < nums; i++)
        ++cNum[triElem[i].col];
    cPos[1] = 0;
    for (int i = 2; i <= cols; i++)
        cPos[i] = cPos[i - 1] + cNum[i - 1];
    for (int i = 0; i < nums; i++)
    {
        int j = cPos[triElem[i].col];
        dest.triElem[j].row = triElem[i].col;
        dest.triElem[j].col = triElem[i].row;
        dest.triElem[j].value = triElem[i].value;
        ++cPos[triElem[i].col]; //pos of the next not0 elem in current col
    }
    delete[] cNum;
    delete[] cPos;
    return dest;
}

#endif