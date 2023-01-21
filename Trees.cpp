#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

#ifndef ONLINE_JUDGE
#include "debugger.h"
#else
#define debug(...) 1;
#endif
struct Node
{
public:
    Node *left;
    Node *right;
    ll data;
    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};
class BinarySearchTree
{
public:
    Node *head;

public:
    BinarySearchTree()
    {
        head = NULL;
    }
    Node *Insert(Node *head, ll val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            return head;
        }
        if (head->data > val)
        {
            head->left = Insert(head->left, val);
        }
        else
        {
            head->right = Insert(head->right, val);
        }
        return head;
    }
    bool Search(Node *head, ll val)
    {
        if (head == NULL)
        {
            return false;
        }
        if (head->data == val)
        {
            return true;
        }
        if (head->data > val)
        {
            return Search(head->left, val);
        }
        else
        {
            return Search(head->right, val);
        }
    }
    void Preorder(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        cout << head->data << " ";
        Preorder(head->left);
        Preorder(head->right);
    }
    void Inorder(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        Inorder(head->left);
        cout << head->data << " ";
        Inorder(head->right);
    }
    void PostOrder(Node *head)
    {
        if (head == NULL)
        {
            return;
        }
        PostOrder(head->left);
        PostOrder(head->right);
        cout << head->data << "  ";
    }
    Node *DeleteElement(Node *head, ll val)
    {
        if (head == NULL)
        {
            return NULL;
        }
        if
            if (head->data == val)
            {
                Node *temp = head;
                if (temp->left == NULL && temp->right == NULL)
                {
                }
            }
    }
};
void solve()
{
    BinarySearchTree BST;
    BST.head = BST.Insert(BST.head, 5);
    BST.head = BST.Insert(BST.head, 7);
    BST.head = BST.Insert(BST.head, 9);
    BST.head = BST.Insert(BST.head, 2);
    BST.head = BST.Insert(BST.head, 1);
    BST.Inorder(BST.head);
    BST.Preorder(BST.head);
    BST.PostOrder(BST.head);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
