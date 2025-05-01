#include <cstdio>
#include <cstdlib>

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

// Function to find minimum node in a tree
Node* FindMin(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

// Function to delete a node
Node* Delete(Node* root, int data) {
	if (root == NULL) return root;

	if (data < root->data)
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	else {
		// Node found
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			free(temp);
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			free(temp);
		}
		else {
			Node* temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

// Function to insert a node
Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = (Node*)malloc(sizeof(Node));
		root->data = data;
		root->left = root->right = NULL;
	}
	else if (data <= root->data)
		root->left = Insert(root->left, data);
	else
		root->right = Insert(root->right, data);
	return root;
}

// Inorder traversal
void Inorder(Node* root) {
	if (root == NULL) return;
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}

int main() {
	Node* root = NULL;
	int choice, value;

	printf("Binary Search Tree Menu\n");
	printf("------------------------\n");

	while (1) {
		printf("\n1. Insert\n2. Delete\n3. Display (Inorder)\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value to insert: ");
				scanf("%d", &value);
				root = Insert(root, value);
				break;

			case 2:
				printf("Enter value to delete: ");
				scanf("%d", &value);
				root = Delete(root, value);
				break;

			case 3:
				printf("Inorder traversal: ");
				Inorder(root);
				printf("\n");
				break;

			case 4:
				printf("Exiting...\n");
				return 0;

			default:
				printf("Invalid choice. Please try again.\n");
		}
	}
}
