#include <iostream>
#include <queue>
#define treeEntry int
using namespace std;
struct treeNode {
    treeEntry node;
    treeNode* Left;
    treeNode* Right;
};
struct tree
{
    treeNode* root;
    int size;
};
void createTree(tree* pt);
bool isImpty(tree* pt);
bool isFull(treeNode* pt);
void traverseInorder(treeNode* pt, void(*traverse)(treeEntry));
void traversePreorder(treeNode* pt, void(*traverse)(treeEntry));
void traversePostorder(treeNode* pt, void(*traverse)(treeEntry));
void BFS(treeNode* pt, void(*traverse)(treeEntry));
void insertNode(tree* pt, treeEntry item);
void display(treeEntry value);
void display(treeEntry value)
{
    cout << value << " ";
}

int main()
{
    tree tree1;
    createTree(&tree1);
    insertNode(&tree1, 50);
    insertNode(&tree1, 55);
    insertNode(&tree1, 45);
    traverseInorder(tree1.root, &display);
    cout << endl;
    traversePostorder(tree1.root, &display);
    cout << endl;
    traversePreorder(tree1.root, &display);
    cout << endl;
    BFS(tree1.root, &display);
}

/// <summary>
/// that function create the tree by intializing the root by NUll and the size to be zero
/// </summary>
/// <param name="pt">refrance type of struct tree</param>
void createTree(tree* pt)
{
    pt->root = nullptr;
    pt->size = 0;
}
/// <summary>
/// That function check if the tree is empty or not returning a bool type
/// 1 indecate the tree is empty
/// 0 indecate the tree isn't empty
/// </summary>
/// <param name="pt">refrance type of struct tree</param>
/// <returns>bool type</returns>
bool isImpty(tree* pt) {
    return (pt->root == nullptr);
}
/// <summary>
/// check if the tree is full by nodes or not
/// 1 indicate the tree is full 
/// 0 indecate the tree isn't full
/// </summary>
/// <param name="pt">refrance type of struct tree</param>
/// <returns></returns>
bool isFull(treeNode* pt) {
    return 0;
}
/// <summary>
/// traversing the tree is Inorder traversing 
/// left child come first then the node then the right child
/// </summary>
/// <param name="pt">pointer to the root of the tree</param>
/// <param name="traverse">refrance typr of function</param>
void traverseInorder(treeNode* pt, void(*traverse)(treeEntry))
{
    if (!pt)
        return;
    traverseInorder(pt->Left, traverse);
    traverse(pt->node);
    traverseInorder(pt->Right, traverse);
}
/// <summary>
/// traversing the tree is Preorder traversing
/// the node come first then the left child then the right child
/// </summary>
/// <param name="pt">>pointer to the root of the tree</param>
/// <param name="traverse">refrance typr of function</param>
void traversePreorder(treeNode* pt, void(*traverse)(treeEntry))
{
    if (!pt)
        return;
    traverse(pt->node);
    traversePreorder(pt->Left, traverse);
    traversePreorder(pt->Right, traverse);
}
/// <summary>
/// traversing the tree is Postorder traversing
/// left child come first then the right child then the node
/// </summary>
/// <param name="pt">pointer to the root of the tree</param>
/// <param name="traverse">refrance typr of function</param>
void traversePostorder(treeNode* pt, void(*traverse)(treeEntry)) {
    if (!pt)
        return;
    traversePostorder(pt->Left, traverse);
    traversePostorder(pt->Right, traverse);
    traverse(pt->node);
}
/// <summary>
/// Breadth First Search for the tree
/// traversing the tree level by level from left to right
/// </summary>
/// <param name="pt">pointer to the root of the tree</param>
/// <param name="traverse">refrance typr of function</param>
void BFS(treeNode* pt, void(*traverse)(treeEntry))
{
    if (!pt)
        return;
    std::queue<treeNode*>q;
    q.push(pt);
    while (q.size())
    {
        treeNode* curNode = q.front();
        traverse(curNode->node);
        if (curNode->Left)
            q.push(curNode->Left);
        if (curNode->Right)
            q.push(curNode->Right);
        q.pop();
    }
}
/// <summary>
/// insert new node in the tree ubon their value
/// the smallest value comes to the left 
/// the largest value comes to the right
/// </summary>
/// <param name="pt">refrance type of struct tree</param>
/// <param name="item">the value of type treeEntry to be inserted</param>
void insertNode(tree* pt, treeEntry item) {
    treeNode* newNode = new treeNode;
    newNode->node = item;
    newNode->Left = nullptr;
    newNode->Right = nullptr;
    treeNode* temp = pt->root, * temp2 = pt->root;
    while (temp) {
        temp2 = temp;
        if (temp->node >= item)
        {
            temp = temp->Left;
        }
        else
        {
            temp = temp->Right;
        }
    }
    if (temp2)
    {
        if (temp2->node >= item)
        {
            temp2->Left = newNode;
        }
        else
        {
            temp2->Right = newNode;
        }
    }
    else
    {
        pt->root = newNode;
    }
}

