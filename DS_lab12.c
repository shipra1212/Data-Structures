#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode* right;
    struct treeNode* left;
    int height;
};

struct treeNode* createNewNode(int rootValue) {
    struct treeNode* tree = (struct treeNode*) malloc(sizeof(struct treeNode));
    tree->data = rootValue;
    tree->left = NULL;
    tree->right = NULL;
    tree->height = 0;

    return tree;
}

int max(int n1, int n2) {
    return n1 > n2 ? n1 : n2;
}

int findHeight(struct treeNode* node) {
    if (node == NULL) {
        return 0;
    }

    return 1 + max(findHeight(node->left), findHeight(node->right));
}

int getBalance(struct treeNode* node) {
    if (node == NULL) {
        return 0;
    }

    int leftHeight = node->left == NULL ? 0 : node->left->height;
    int rightHeight = node->right == NULL ? 0 : node->right->height;

    return leftHeight - rightHeight;
}

/*
A                B
  B      => 
    C         A     C
*/
struct treeNode* rrRotate(struct treeNode* node) {
    struct treeNode* root = node->right;
    struct treeNode* lChild = root->left;
    root->left = node;
    node->right = lChild;

    node->height = findHeight(node);

    if (root->right != NULL) {
        root->right->height = findHeight(root->right);
    }

    return root;
}

/*
      A            B
   B       => 
C              C     A
*/
struct treeNode* llRotate(struct treeNode* node) {
    struct treeNode* root = node->left;
    struct treeNode* rChild = root->right;
    root->right = node;
    node->left = rChild;

    node->height = findHeight(node);

    if (root->left != NULL) {
        root->left->height = findHeight(root->left);
    }

    return root;
}

struct treeNode* lrRotate(struct treeNode* node) {

}

struct treeNode* insertNode(struct treeNode* node, int data) {
    if (node == NULL) {
        return createNewNode(data);
    }

    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else {
        node->right = insertNode(node->right, data);
    }

    node->height = findHeight(node);

    int balance = getBalance(node);
    
    // LL rotate
    if (balance > 1 && data < node->left->data) {
        return llRotate(node);
    } 

    // RR rotate
    if (balance < -1 && data > node->right->data) {
        return rrRotate(node);
    }

    // LR rotate
    if (balance > 1 && data > node->left->data) {
        node->left = rrRotate(node->left);
        return llRotate(node);
    }

    // RL rotate
    if (balance < -1 && data < node->right->data) {
        node->right = llRotate(node->right);
        return rrRotate(node);
    }

    return node;
}

void inorder(struct treeNode* node) {
    if (node == NULL) {
        return;
    }

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct treeNode* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct treeNode* node) {
    if (node == NULL) {
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n,i, data, key;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    struct treeNode* root = NULL;

    for (i = 0; i < n; i++) 
	{
        printf("Enter node %d: ", i + 1);
        scanf("%d", &data);

        root = insertNode(root, data);
    }
    
    printf("Inorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\n");

    return 0;
}
