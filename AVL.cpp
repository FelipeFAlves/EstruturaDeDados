#include <bits/stdc++.h>
using namespace std;
struct AVL{
    AVL *left;
    AVL *right;
    int val;
    int balanceamento;
    int height;
    AVL() : left(NULL), right(NULL), val(0),balanceamento(0),height(0) {}
    AVL(int x): left(NULL), right(NULL), val(x),balanceamento(0),height(0) {}
};
AVL* rightRotate(AVL *root){
    auto filho = root->left;
    root->left = filho->right;
    filho->right = root;

    //Atualiza a altura
    root->height = max((root->left != NULL ? root->left->height : 0), (root->right != NULL ? root->right->height : 0)) + 1;
    filho->height = max((filho->left != NULL ? filho->left->height : 0), (filho->right != NULL ? filho->right->height : 0)) + 1;

    //Atualiza o fator de balanceamento
    root->balanceamento = (root->left != NULL ? root->left->height : 0) - (root->right != NULL ? root->right->height : 0);
    filho->balanceamento = (filho->left != NULL ? filho->left->height : 0) - (filho->right != NULL ? filho->right->height : 0);
    
    return filho;
}
AVL* leftRotate(AVL *root){
    auto filho = root->right;
    root->right = filho->left;
    filho->left = root;

    //Atualiza a altura
    root->height = max((root->left != NULL ? root->left->height : 0), (root->right != NULL ? root->right->height : 0)) + 1;
    filho->height = max((filho->left != NULL ? filho->left->height : 0), (filho->right != NULL ? filho->right->height : 0)) + 1;

    //Atualiza o fator de balanceamento
    root->balanceamento = (root->left != NULL ? root->left->height : 0) - (root->right != NULL ? root->right->height : 0);
    filho->balanceamento = (filho->left != NULL ? filho->left->height : 0) - (filho->right != NULL ? filho->right->height : 0);
    
    return filho;
}

AVL* addNode(int val, AVL *root){
    if(root == NULL){ // Caso seja vazio
        AVL *node = new AVL(val);
        return node;
    }
    else if(val < root->val){
        root->left = addNode(val,root->left);
    } else if (val > root->val){
        root->right = addNode(val,root->right);
    }
    //Atualiza a altura dos nós
    if(root->left != NULL && root->right != NULL) root->height = max(root->left->height,root->right->height) + 1;
    else root->height = root->height +1;
    //Atualiza Fator de balanceamento (altura da esq - altura da dir)
    root->balanceamento = (root->left != NULL ? root->left->height : 0) - (root->right != NULL ? root->right->height : 0);
    //Após atualizar, verifica se e qual rotação precisa fazer

    if(root->balanceamento == -2 && root->right->balanceamento == -1) root = leftRotate(root);
    else if(root->balanceamento == 2 && root->left->balanceamento == 1) root = rightRotate(root);
    else if(root->balanceamento == 2 && root->left->balanceamento == -1){
        root->left = leftRotate(root->left);
        root = rightRotate(root);
    } 
    else if(root->balanceamento == -2 && root->right->balanceamento == 1){
        root->right = rightRotate(root->right);
        root = leftRotate(root);
    } 
    return root;
}
AVL *search(AVL *root, int val){
    if(root == NULL) return NULL;
    if(root->val == val){
        return root;
    } else if(root->val < val){
        root = search(root->right,val);
    } else root = search(root->left,val);
    return root;
}
AVL* findMin(AVL* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

int getBalance(AVL* node) {
    if (node == NULL) return 0;
    return (node->left != NULL ? node->left->height : 0) - (node->right != NULL ? node->right->height : 0);
}
AVL* deletion(AVL* root, int val) {
    if (root == NULL) return root;

    if (val < root->val) {
        root->left = deletion(root->left, val);
    } else if (val > root->val) {
        root->right = deletion(root->right, val);
    } else {
        if ((root->left == NULL) || (root->right == NULL)) {
            AVL* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            AVL* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deletion(root->right, temp->val);
        }
    }

    if (root == NULL) return root;

    root->height = max((root->left != NULL ? root->left->height : 0), (root->right != NULL ? root->right->height : 0)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printAVL(AVL* root) {
    if (root != NULL) {
        printAVL(root->left);
        cout << root->val << " ";
        printAVL(root->right);
    }
}

int main(){
    AVL *raiz = new AVL(12);
    auto atual = raiz;
    atual = addNode(15,atual);
    atual = addNode(48,atual);
    atual = addNode(96,atual);
    atual = addNode(32,atual);
    atual = addNode(01,atual);

    printAVL(atual);
    cout << "\n";
    auto res = deletion(atual,01);
    printAVL(atual);
    
    return 0;
}