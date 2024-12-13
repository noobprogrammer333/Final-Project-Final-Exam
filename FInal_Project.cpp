BSCS-2B Group 3
	Members: Jude Melvin Grutas
		 Kylan Heinrich Dimaiwat
		 Asher B. Caubang

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure to represent a Node in the binary tree
struct Node {
    string Word;  // Word stored in the node
    Node* Left;   // Pointer to the left child
    Node* Right;  // Pointer to the right child

    // Constructor to initialize a node with a word
    Node(string word) : Word(word), Left(NULL), Right(NULL) {}
};

// Structure to represent a Node in a Binary Search Tree (not used here)
struct BstNode {
    int data;       // Data stored in the node
    BstNode* left;  // Pointer to the left child
    BstNode* right; // Pointer to the right child
};

// BinaryTree Class
class BinaryTree {
    Node* root;  // Root of the binary tree

    // Helper function to build the tree from a vector of words
    Node* BuildTreeHelper(const vector<string>& words, int& index) {
        if (index >= words.size()) {
            return NULL;  // Return NULL if index exceeds the vector size
        }

        // Create a new node with the current word
        Node* newNode = new Node(words[index]);
        index++;  // Move to the next word

        // Recursively build the left and right subtrees
        newNode->Left = BuildTreeHelper(words, index);
        newNode->Right = BuildTreeHelper(words, index);

        return newNode;  // Return the newly created node
    }

    // Helper function to prune the tree based on feedback from the game
    Node* PruneTreeHelper(Node* node, const string& guess, const string& feedback) {
        if (!node) return NULL;  // Return NULL if the node is NULL

        string currentFeedback = "";
        CheckGuess(node->Word, guess, currentFeedback);

        // If feedback doesn't match, prune this branch
        if (currentFeedback != feedback) {
            return NULL;
        }

        // Recursively prune the left and right subtrees
        node->Left = PruneTreeHelper(node->Left, guess, feedback);
        node->Right = PruneTreeHelper(node->Right, guess, feedback);

        return node;  // Return the node after pruning
    }

    // Helper function for level-order traversal of the tree
    void LevelOrderTraversalHelper(Node* node) const {
        if (!node) return;  // If the tree is empty, return

        queue<Node*> q;  // Queue to hold nodes during traversal
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->Word << " ";  // Print the current node's word

            if (current->Left) q.push(current->Left);   // Add left child to queue
            if (current->Right) q.push(current->Right); // Add right child to queue
        }
        cout << endl;  // Print a newline after traversal
    }

public:
    // Constructor to initialize the BinaryTree with a NULL root
    BinaryTree() : root(NULL) {}

    // Public function to build the tree using a vector of words
    void BuildTree(const vector<string>& words) {
        int index = 0;
        root = BuildTreeHelper(words, index);
    }

    // Public function to perform level-order traversal
    void LevelOrderTraversal() const {
        LevelOrderTraversalHelper(root);
    }

    // Public function to prune the tree based on a guess and feedback
    void PruneTree(const string& guess, const string& feedback) {
        root = PruneTreeHelper(root, guess, feedback);
    }

    // Function to check the guess and generate feedback
    bool CheckGuess(const string& guess, const string& target, string& feedback) const {
        feedback = "";  // Initialize feedback as an empty string
        for (int i = 0; i < 5; ++i) {
            if (guess[i] == target[i]) {
                feedback += "G";  // 'G' for correct letter in correct position
            } else if (target.find(guess[i]) != string::npos) {
                feedback += "Y";  // 'Y' for correct letter in wrong position
            } else {
                feedback += "B";  // 'B' for incorrect letter
            }
        }
        return feedback == "GGGGG";  // Return true if the guess is correct
    }

    // Function to play the Wordle-like game
    void PlayGame(BinaryTree& tree, const string& TargetWord, int Chances) {
        string Guess, Feedback;

        // Display game instructions
        cout << "\n--- Welcome to the Wordle-like game! ---" << endl;
        cout << "You have " << Chances << " chances to guess the 5-letter word." << endl;
        cout << "\nInstructions for feedback after each guess:" << endl;
        cout << "G = Correct letter in the correct position" << endl;
        cout << "Y = Correct letter but in the wrong position" << endl;
        cout << "B = Incorrect letter" << endl;

        // Loop for the number of chances
        while (Chances > 0) {
            cout << "\nEnter your guess (5-letter word): ";
            cin >> Guess;

            if (Guess.length() != 5) {
                cout << "Please enter a valid 5-letter word!" << endl;
                continue;  // Ask for another guess if input is invalid
            }

            // Check the guess and provide feedback
            bool isCorrect = tree.CheckGuess(Guess, TargetWord, Feedback);
            cout << "Feedback: " << Feedback << endl;

            tree.PruneTree(Guess, Feedback);  // Prune the tree based on feedback

            if (isCorrect) {
                cout << "Congratulations! You've guessed the word!" << endl;
                break;
            }

            Chances--;  // Decrease the number of chances
            if (Chances == 0) {
                cout << "You've run out of chances! The correct word was: " << TargetWord << endl;
            } else {
                cout << "Possible words left: ";
                tree.LevelOrderTraversal();  // Show possible words
            }
        }
    }

    // Main function to run the game
    void run() {
        vector<string> WordList = {"apple", "grape", "peach", "plumb", "mango", "berry", "lemon", "melon", "cherry", "fruit"};
        BinaryTree tree;
        tree.BuildTree(WordList);

        string TargetWord = "peach";  // The target word to guess
        int Chances = 6;  // Number of chances allowed
        int choice;
        char answer;

        // Display menu options
        cout << "\nChoose an option:\n1. Play Wordle-like Game\n2. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle menu choices
        switch (choice) {
            case 1:
                do {
                    PlayGame(tree, TargetWord, Chances);
                    cout << "Would you like to play again?(Y/N): ";
                    cin >> answer;
                } while (answer == 'Y' || answer == 'y');
                break;
            case 2:
                cout << "Exiting the game. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Exiting..." << endl;
                break;
        }
    }
};


// Binary Search Tree Class
class BST {
public:
    // Function to create a new node with given data
    BstNode* GetNewNode(int data) {
        BstNode* newNode = new BstNode();
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    // Function to insert data into the BST, returns the root node
    BstNode* Insert(BstNode* root, int data) {
        if (root == NULL) {
            root = GetNewNode(data);
            cout << data << " inserted into the BST!\n";
        
        } else if (data <= root->data) {
            root->left = Insert(root->left, data);
        } else {
            root->right = Insert(root->right, data);
        }
        return root;
    }

    // Function to print the BST in a pre-order traversal
    void PrintPreOrder(BstNode* root) {
  if (root == NULL) return;
  cout << root->data << " ";  // Visit root
  PrintPreOrder(root->left);   // Recursively visit left subtree
  PrintPreOrder(root->right);  // Recursively visit right subtree
}

void PrintInOrder(BstNode* root) {
  if (root == NULL) return;
  PrintInOrder(root->left);    // Recursively visit left subtree
  cout << root->data << " ";  // Visit root
  PrintInOrder(root->right);   // Recursively visit right subtree
}

void PrintPostOrder(BstNode* root) {
  if (root == NULL) return;
  PrintPostOrder(root->left);   // Recursively visit left subtree
  PrintPostOrder(root->right);  // Recursively visit right subtree
  cout << root->data << " ";  // Visit root
}

    // Function to search for a specific value in the BST
    bool Search(BstNode* root, int data) {
        if (root == NULL) {
            cout << "The BST is empty!\n";
            return false;
        } else if (root->data == data) {
            cout << "Value " << data << " found in the BST!\n";
            return true;
        } else if (data < root->data) {
            return Search(root->left, data);
        } else {
            return Search(root->right, data);
        }
    }

    // Function to find the minimum node in a subtree
    BstNode* FindMin(BstNode* root) {
        while (root->left != NULL)
            root = root->left;
        return root;
    }

    // Function to delete a node from the BST
    BstNode* Delete(BstNode* root, int data) {
        if (root == NULL) return root;

        if (data < root->data)
            root->left = Delete(root->left, data);
        else if (data > root->data)
            root->right = Delete(root->right, data);
        else {
            // Case 1: No child (Leaf node)
            if (root->left == NULL && root->right == NULL) {
                cout << "Deleting leaf node with value " << data << ". Goodbye!\n";
                delete root;
                root = NULL;
            }
            // Case 2: Node with only one child (right)
            else if (root->left == NULL) {
                BstNode* temp = root;
                root = root->right;
                cout << "Deleting node with value " << data << " and moving its right child up.\n";
                delete temp;
            }
            // Case 2: Node with only one child (left)
            else if (root->right == NULL) {
                BstNode* temp = root;
                root = root->left;
                cout << "Deleting node with value " << data << " and moving its left child up.\n";
                delete temp;
            }
            // Case 3: Node with two children
            else {
                BstNode* temp = FindMin(root->right);
                cout << "Deleting node with value " << data << " and replacing it with minimum value " << temp->data << " from the right subtree.\n";
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }

    // Game: Search for a value in the BST
    void searchGame(BstNode* root) {
        int value;
        cout << "Enter the value to search: ";
        cin >> value;
        if (Search(root, value)) {
            cout << "Congratulations! The value " << value << " was found in the BST.\n";
        } else {
            cout << "Oops! The value " << value << " is not in the BST.\n";
        }
    }

    // Main Menu
    void run() {
        BstNode* root = NULL; // Initialize the BST as an empty tree
        int choice, value;
        char answer;

        while (true) {
            cout << "============================================\n";
        cout << "||--- Welcome to the Binary Search Tree ---||\n";
        cout << "============================================\n";
        cout << "| 1. Insert a node (Let's grow our tree!)  |\n";
        cout << "| 2. Search for a value (Seek and you shall find!) |\n";
        cout << "| 3. Delete a node (Time to say goodbye!)   |\n";
        cout << "| 4. Print Tree Traversals                  |\n";
        cout << "| 5. Play Search Game (Can you find the value?) |\n";
        cout << "| 6. Exit the program (Come back soon!)     |\n";
        cout << "============================================\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                do{
                    cout << "Enter value to insert: ";
                    cin >> value;
                    root = Insert(root, value);
                    cout << "Value " << value << " inserted into the tree. It's growing strong!" << endl;
                    cout << "Would you like to insert another node?(Y/N): ";
                    cin >> answer;
                }while (answer == 'Y' || answer == 'y');
                    break;
                case 2:
                    cout << "Enter value to search: ";
                    cin >> value;
                    if (Search(root, value))
                        cout << "Value found!" << endl;
                    else
                        cout << "Value not found." << endl;
                    break;
                case 3:
                    cout << "Enter value to delete: ";
                    cin >> value;
                    root = Delete(root, value);
                    cout << "Value " << value << " deleted from the tree. Nature's way!" << endl;
                    break;
                case 4:
                    cout << "In-order Traversal: ";
                    PrintInOrder(root);
                    cout << endl;

                    cout << "Pre-order Traversal: ";
                    PrintPreOrder(root);
                    cout << endl;

                    cout << "Post-order Traversal: ";
                    PrintPostOrder(root);
                    cout << endl;
                    break;
                case 5:
                    searchGame(root);
                    break;
                case 6:
                    cout << "Exiting program. Thank you for nurturing the BST garden!" << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};


class HeapMountain {
private:
    vector<int> maxHeap;
    vector<int> minHeap;
    int score; // Player's score

    // Helper to heapify a max-heap
    void heapifyForMax(vector<int>& heap, int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) break;

            swap(heap[index], heap[largest]);
            index = largest;
        }
    }

    // Helper to heapify a min-heap
    void heapifyForMin(vector<int>& heap, int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest == index) break;

            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }

    // Insert into max-heap
    void insertMaxHeap(vector<int>& heap, int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] >= heap[index]) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    // Insert into min-heap
    void insertMinHeap(vector<int>& heap, int value) {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] <= heap[index]) break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    // Display the heap as a sorted array
    void displayHeap(vector<int> heap, bool isMaxHeap) {
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(heap[0]);
            swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            if (isMaxHeap) {
                heapifyForMax(heap, 0);
            } else {
                heapifyForMin(heap, 0);
            }
        }
        if (isMaxHeap) {
            cout << "Max-Heap (Highest to Lowest): ";
        } else {
            cout << "Min-Heap (Lowest to Highest): ";
        }
        for (int val : sorted) {
            cout << val << " ";
        }
        cout << endl;
    }

public:
    // Constructor
    HeapMountain() : score(0) {}

    // Insert value into both heaps
    void insertHeap(int value) {
        insertMaxHeap(maxHeap, value);
        insertMinHeap(minHeap, value);
        cout << " " << value << " has been added to the Heap Mountain!" << endl;
        score += 5; // Reward for inserting
        cout << "Your current score: " << score << endl;
    }

    // Display the heaps
    void displayHeaps() {
        if (maxHeap.empty() && minHeap.empty()) {
            cout << "The Heap Mountain is empty! Start adding numbers to grow it.\n";
            return;
        }
        cout << "\n--- Heap Mountain View ---\n";
        displayHeap(maxHeap, true); // Display max-heap
        displayHeap(minHeap, false); // Display min-heap
    }

    // Display menu
    void displayMenu() {
        cout << "============================================\n";
    cout << "||--- Welcome to Heap Mountain ---||\n";
    cout << "============================================\n";
    cout << "| 1. Add a number to the Heap            |\n";
    cout << "| 2. View Heap Mountain                 |\n";
    cout << "| 3. Challenge: Find the Largest and Smallest Number |\n";
    cout << "| 4. Exit Heap Mountain                 |\n";
    cout << "============================================\n";
    }

    // Run the Heap Mountain gameplay
    void run() {
        int choice, value;
        char answer;

        while (true) {
            displayMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    do{
                    cout << "Enter an integer to add to the Heap Mountain: ";
                    cin >> value;
                    insertHeap(value);
                    
                    cout << "Would you like to add another value? (Y/N): ";
                        cin >> answer;
                    } while (answer == 'Y' || answer == 'y');
                    break;
                case 2:
                    displayHeaps();
                    break;
                case 3:
                    if (!maxHeap.empty() && !minHeap.empty()) {
                        cout << "\n--- Challenge: Guess the Peak and the Valley! ---\n";
                    int userGuessMax, userGuessMin;

                    // Ask the user to guess the largest number
                    cout << "Guess the Highest Number in the Heap Mountain (Max-Heap): ";
                    cin >> userGuessMax;
                    if (userGuessMax == maxHeap[0]) {
                        cout << " Correct! The Highest Number is indeed " << maxHeap[0] << ".\n";
                            score += 10; // Bonus points for correct guess
                    } else {
                        cout << " Wrong! The Highest Number was " << maxHeap[0] << ".\n";
                    }

                    // Ask the user to guess the smallest number
                    cout << "Guess the Lowest Number in the Heap Mountain (Min-Heap): ";
                    cin >> userGuessMin;
                    if (userGuessMin == minHeap[0]) {
                        cout << " Correct! The Lowest Number is indeed " << minHeap[0] << ".\n";
                        score += 10; // Bonus points for correct guess
                    } else {
                        cout << " Wrong! The Lowest Number was " << minHeap[0] << ".\n";
                    }

                    // Display total score after the challenge
                        cout << "Your total score after the challenge: " << score << endl;
                    } else {
                        cout << "The Heap Mountain is empty! Add numbers to start the challenge.\n";
                    }
                    break;
                case 4:
                    cout << "Exiting Heap Mountain. Your final score: " << score << endl;
                    return;
                default:
                    cout << "Invalid choice. Try again!\n";
            }
        }
    }
};

// Main Menu System
void menu(){
  BinaryTree binaryTree;
  BST bst;
  HeapMountain heap;
  int choice, value;

  while (true) {
    cout << "============================================";
    cout << "\n||--- Fun Binary Tree and Heaps System ---||\n";
    cout << "============================================\n";
    cout << "| 1. Binary Tree                           |\n";   
    cout << "| 2. Binary Search Tree                    |\n";  
    cout << "| 3. Heaps (Min and Max)                   |\n";
    cout << "| 4. Exit                                  |\n";
    cout << "============================================\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "\n** Binary Trees are branching out! **\n";
        binaryTree.run();
        break;
      case 2:
        cout << "\n** Diving into the depths of Binary Search Trees! **\n";
        bst.run();
        break;
      case 3:
        cout << "\n** Heap time! Let's heap some fun together! **\n";
        heap.run();
        break;
      case 4:
        cout << "\nExiting... We hope you had fun with Trees and Heaps! Come back soon!\n";
        return;
      default:
        cout << "\n** Oops! That wasn't a valid choice. Give it another go! **\n";
    }
  }
}

int main(){
	menu();
	
	return 0;
}
