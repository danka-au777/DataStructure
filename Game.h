#ifndef __GAME_H__
#define __GAME_H__

#define CURPATH "./expert.txt"
#include <string>
#include "BinLinkList.h"

using namespace std;

class Game
{
private:
    BinTree<string> *CognitionTree;
    bool isQuestion(string e);
    void AddRuleToFile(ofstream &out); //write into file in preorder
public:
    Game();
    ~Game(){};
    void Run();
};

Game::Game()
{
    ifstream file(CURPATH);
    if (!file.good())
        throw "file error";
    string tmpstr;
    stack<BinNode<string> *> stk;
    BinNode<string> *r, *p1, *p2;
    while (getline(file, tmpstr))
    {
        r = new BinNode<string>(tmpstr);
        if (isQuestion(tmpstr))
        {
            p1 = stk.top();
            stk.pop();
            p2 = stk.top();
            stk.pop();
            r->InsertChildren(p2, p1);
            stk.push(r);
        }
        else
        {
            stk.push(r);
        }
    }
    r = stk.top();
    CognitionTree = new BinTree<string>(r);
    file.close();
}

void Game::Run()
{
    cout << "Welcome!" << endl;
    int exitchoice = 0;
    int anschoice;
    while (exitchoice == 0)
    {
        cout << "Picture an animal in your mind and Ready! " << endl;
        BinNode<string> *r = CognitionTree->GetRoot();
        string str = r->data;
        int ans;
        while (isQuestion(str))
        {
            cout << "Please answer(0 for yes ,1 for no) " << str << endl;
            cin >> ans;
            if (ans == 0)
            {
                r = CognitionTree->GetLeftChild(r);
            }
            else
            {
                r = CognitionTree->GetRightChild(r);
            }
            str = r->data;
        }
        cout << "Is the animal " << str << "? 0 for yes ,1 for no:" << endl;
        cin >> anschoice;
        string newanimal, newrule, oldanimal = str;
        if (anschoice == 1)
        {
            cout << "Please answer what is the aniaml? \n";
            cin>>newanimal;
            cout << "Please help the expert:(1.must contain '?' 2.no space)\n Given a question that the positive answer is "
            << oldanimal << " while negtive answer is " << newanimal<<"\n";
            cin>>newrule;
            CognitionTree->SetElem(r,newrule);
            CognitionTree->InsertLeftChild(r, oldanimal);
            CognitionTree->InsertRightChild(r, newanimal);
        }
        cout << "Do you want to continue? 0 for yes ,1 for no: ";
        cin >> exitchoice;
    }
    ofstream file(CURPATH);
    AddRuleToFile(file);
}

void Game::AddRuleToFile(ofstream &out)
{
    //preorder:root left right --> root right left -->(stack) left right root
    stack<BinNode<string> *> stk, res;
    BinNode<string> *cur = CognitionTree->GetRoot();
    while (cur != NULL)
    {
        stk.push(cur);
        res.push(cur);
        if (cur->right != NULL)
        {
            cur = cur->right;
        }
        else if (!stk.empty())
        {
            while (!stk.empty())
            {
                cur = stk.top();
                stk.pop();
                cur = cur->left;
                if (cur != NULL)
                    break;
            }
        }
        else
            cur = NULL;
    }
    while (!res.empty())
    {
        cur = res.top();
        res.pop();
        out << cur->data << endl;
    }
    out.close();
}

bool Game::isQuestion(string e)
{
    if (e.find('?') == -1)
        return false;
    else
        return true;
}
#endif