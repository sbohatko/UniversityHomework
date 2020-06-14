#include <iostream>
#include <cmath>
using namespace std;
struct BinTree {
    int value; //содержит значение
    BinTree* left;//адрес левого поддерева
    BinTree* right;//адрес правого поддерева
    BinTree(int val) : left(NULL), right(NULL), value(-1) {}
};

void newBinTree(int val, BinTree** Tree) {
    if ((*Tree) == NULL)
    {
        (*Tree) = new BinTree(0);
        (*Tree)->value = val;
        (*Tree)->left = (*Tree)->right = NULL;
        return;
    }
    if (val > (*Tree)->value) newBinTree(val, &(*Tree)->right);
    else newBinTree(val, &(*Tree)->left);
}
void push(int a, BinTree **t)
{
    if ((*t) == NULL)
    {
        (*t) = new BinTree(0);
        (*t)->value = a;
        (*t)->left = (*t)->right = NULL;
        return;
    }
    if (a > (*t)->value) push(a, &(*t)->right);
    else push(a, &(*t)->left);
}

BinTree* DeleteNode(BinTree* node, int value){
    if(node == NULL)
        return node;
    if(value == node->value){
        BinTree* tmp;
        if(node->right == NULL)
            tmp = node->left;
        else {
            BinTree* ptr = node->right;
            if(ptr->left == NULL){
                ptr->left = node->left;
                tmp = ptr;
            } else {
                BinTree* pmin = ptr->left;
                while(pmin->left != NULL){
                    ptr  = pmin;
                    pmin = ptr->left;
                }
                ptr->left   = pmin->right;
                pmin->left  = node->left;
                pmin->right = node->right;
                tmp = pmin;
            }
        }
        delete node;
        return tmp;
    } else if(value < node->value)
        node->left  = DeleteNode(node->left, value);
    else
        node->right = DeleteNode(node->right, value);
    return node;
}
void Print(BinTree**Tree, int l)
{
    int i;

    if (*Tree != NULL)
    {
        Print(&((**Tree).right), l + 1);
        for (i = 1; i <= l; i++) cout << "   ";
        cout << (**Tree).value << endl;
        Print(&((**Tree).left), l + 1);
    }
}
BinTree * CopyTree(BinTree * node)
{
    if (node == NULL)
        return NULL;
    BinTree * newnode = new BinTree(node->value);
    newnode->left = CopyTree(node->left);
    newnode->right = CopyTree(node->right);

    return newnode;
}
void TreeTraversalAndPrint(BinTree* Root) {
    if (Root != NULL) {
        cout << Root->value << endl;
        TreeTraversalAndPrint(Root->left);
        TreeTraversalAndPrint(Root->right);

    }
}
void TreeTraversalAndPrint2(BinTree* Root) {
    if (Root != NULL) {
        TreeTraversalAndPrint2(Root->left);
        TreeTraversalAndPrint2(Root->right);
        cout << Root->value << endl;
    }
}
void TreeTraversalAndPrint3(BinTree* Root) {
    if (Root != NULL) {
        TreeTraversalAndPrint2(Root->left);
        cout << Root->value << endl;
        TreeTraversalAndPrint2(Root->right);
    }
}
BinTree* Search(BinTree* Tree, int key) {
    if (Tree == NULL) return NULL;
    if  (Tree->value == key) return Tree;
    if (key < Tree->value) return Search(Tree->left, key);
    else
        return Search(Tree->right, key);
}
void DestroyBTree(BinTree* Tree) {
    if (Tree != NULL) {
        DestroyBTree(Tree->left);
        DestroyBTree(Tree->right);
        delete(Tree);
    }
}
int main() {
    int command;
    BinTree* Tree = NULL;
    cout<<"Примітка: Дерево виводиться зліва направо\n"
          "1. Створення бінарного дерева.\n"
          "2. Видалення елемента з бінарного дерева.\n"
          "3. Видалення бінарного дерева.\n"
          "4. Перевірка бінарного дерева на пустоту.\n"
          "5. Знаходження та видобування даних.\n"
          "6. Копіювання бінарного дерева.\n"
          "7. Обхід бінарного дерева за трьома різними маршрутами.\n"
          "8. Виведення на консоль всіх елементів дерева.\n"
          "0. Вийти.\n";
    while(command!=0){
          cout<<"Введіть команду: ";
          cin>>command;
            switch(command){
                case 1:
                    int s,n;
                    cout << "Введіть кількість елементів: ";
                    cin >> n;
                    for (int i=0; i<n; ++i)
                    {
                        cout << "Введіть число:  ";
                        cin >> s;
                        push(s, &Tree);
                    }
                    Print(&Tree, 0);
                    break;
                case 2:
                    int el;
                    cout<<"Введіть елемент: ";
                    cin>>el;
                    DeleteNode(Tree, el);
                    cout<<"Елемент видалено.\n";
                    break;
                case 3:
                    DestroyBTree(Tree);
                    cout<<"Дерево видалено.\n";
                    break;
                case 4:
                    if(Tree == NULL)
                        cout<<"Дерево порожнє\n";
                  else cout<<"Дерево не порожнє\n";
                    break;
                case 5:
                int key;
                cout << "Введіть значення елемента для пошуку-> ";
                cin >> key;
                Search(Tree, key);
                    if (Tree == NULL)
                        cout << "Елемент не знайдено\n";
                    else
                        cout << "Ваш елемент->" << Tree->value<<"\n";
                    break;
                case 6:CopyTree(Tree);
                    cout<<"Дерево скопійовано.\n";
                    break;
                case 7:
                    int com;
                    cout<<"1.Прямий обхід дерева\n2.Зворотній обхід дерева\n"
                          "3.Симетричний обхід дерева\nВведіть команлу:";
                    cin>>com;
                switch(com){
                    case 1:
                        TreeTraversalAndPrint(Tree);
                        break;
                    case 2:
                        TreeTraversalAndPrint2(Tree);
                        break;
                    case 3:
                        TreeTraversalAndPrint3(Tree);
                        break;
                }
                    break;
                case 8:
                    Print(&Tree, 0);
                    break;
        }
    }
    return 0;
}