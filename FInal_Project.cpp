BSCS-2B Group 3
	Members: Jude Melvin Grutas
		 Kylan Heinrich Dimaiwat
		 Asher B. Caubang

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
        string Word;
        Node* Left;
        Node* Right;

        Node(string word) : Word(word), Left(NULL), Right(NULL) {}
    };
    
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// Binary Tree Class
class BinaryTree {
    Node* root;

    Node* BuildTreeHelper(const vector<string>& words, int& index) {
        if (index >= words.size()) {
            return NULL;
        }

        Node* newNode = new Node(words[index]);
        index++;
        newNode->Left = BuildTreeHelper(words, index);
        newNode->Right = BuildTreeHelper(words, index);

        return newNode;
    }

    Node* PruneTreeHelper(Node* node, const string& guess, const string& feedback) {
        if (!node) return NULL;

        string currentFeedback = "";
        CheckGuess(node->Word, guess, currentFeedback);

        if (currentFeedback != feedback) {
            return NULL;
        }

        node->Left = PruneTreeHelper(node->Left, guess, feedback);
        node->Right = PruneTreeHelper(node->Right, guess, feedback);

        return node;
    }

    void LevelOrderTraversalHelper(Node* node) const {
        if (!node) return;

        queue<Node*> q;
        q.push(node);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->Word << " ";

            if (current->Left) q.push(current->Left);
            if (current->Right) q.push(current->Right);
        }
        cout << endl;
    }

public:
    BinaryTree() : root(NULL) {}

    void BuildTree(const vector<string>& words) {
        int index = 0;
        root = BuildTreeHelper(words, index);
    }

    void LevelOrderTraversal() const {
        LevelOrderTraversalHelper(root);
    }

    void PruneTree(const string& guess, const string& feedback) {
        root = PruneTreeHelper(root, guess, feedback);
    }

    bool CheckGuess(const string& guess, const string& target, string& feedback) const {
        feedback = "";
        for (int i = 0; i < 5; ++i) {
            if (guess[i] == target[i]) {
                feedback += "G";
            } else if (target.find(guess[i]) != string::npos) {
                feedback += "Y";
            } else {
                feedback += "B";
            }
        }
        return feedback == "GGGGG";
    }
    
    void PlayGame(BinaryTree& tree, const string& TargetWord, int Chances) {
    string Guess, Feedback;

    cout << "\n--- Welcome to the Wordle-like game! ---" << endl;
    cout << "You have " << Chances << " chances to guess the 5-letter word." << endl;
    cout << "\nInstructions for feedback after each guess:" << endl;
    cout << "G = Correct letter in the correct position" << endl;
    cout << "Y = Correct letter but in the wrong position" << endl;
    cout << "B = Incorrect letter" << endl;

    while (Chances > 0) {
        cout << "\nEnter your guess (5-letter word): ";
        cin >> Guess;

        if (Guess.length() != 5) {
            cout << "Please enter a valid 5-letter word!" << endl;
            continue;
        }

        bool isCorrect = tree.CheckGuess(Guess, TargetWord, Feedback);
        cout << "Feedback: " << Feedback << endl;

        tree.PruneTree(Guess, Feedback);

        if (isCorrect) {
            cout << "Congratulations! You've guessed the word!" << endl;
            break;
        }

        Chances--;
        if (Chances == 0) {
            cout << "You've run out of chances! The correct word was: " << TargetWord << endl;
        } else {
            cout << "Possible words left: ";
            tree.LevelOrderTraversal();
        }
    }
}
    
    void btgame(){ 
        vector<string> WordList = {"apple", "grape", "peach", "plumb", "mango", "berry", "lemon", "melon", "cherry", "fruit"}; 
		BinaryTree tree; 
        tree.BuildTree(WordList); 
        
        string TargetWord = "peach"; 
        int Chances = 6; 
        int choice; 
        char answer;
        
        cout << "==============================\n";
        cout << "| Choose an option:          |\n";
		cout << "| 1. Play Wordle-like Game   |\n";
		cout << "| 2. Exit                    |\n";  
		cout << "==============================\n";
        cout << "Enter your choice: ";  
        cin >> choice; 
        
        switch (choice) { 
            case 1: 
            do{
                PlayGame(tree, TargetWord, Chances); 
                cout << "Would you like to play again?(Y/N): ";
                cin >> answer;
            }while (answer == 'Y' || answer == 'y');
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
    void bstgame(){
    BstNode *root = NULL; // Initialize the BST as an empty tree
    int choice, value, score = 0; // Add a score tracker for the game
    char answer;

    cout << "========================================================\n";
	cout << "||            Welcome to the BST Game!                 ||\n";
    cout << "===================================================== ==\n";
    cout << "|Instructions:                                         |\n";
    cout << "|1. Insert values to grow the tree.                    |\n";
    cout << "|2. Search for values to earn points.                  |\n";
    cout << "|3. Delete nodes strategically to maintain balance.    |\n";
    cout << "|4. Earn points for correct operations!                |\n";
    cout << "--------------------------------------------------------\n";

    while (true){
        cout << "| 1. Insert a node (Earn 5 points per node)            |\n";
        cout << "| 2. Search for a value (Earn 10 points if found)      |\n";
        cout << "| 3. Delete a node (Earn 15 points if deleted)         |\n";
        cout << "| 4. View Traversals (In-order, Pre-order, Post-order) |\n";
        cout << "| 5. View Current Score                                |\n";
        cout << "| 6. Exit the Game                                     |\n";
        cout << "========================================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Insert node
            do
            {
                cout << "Enter value to insert: ";
                cin >> value;
                root = Insert(root, value);
                score += 5; // Increment score
                cout << "Value " << value << " inserted! (+5 points)\n";
                cout << "Would you like to insert another node? (Y/N): ";
                cin >> answer;
            } while (answer == 'Y' || answer == 'y');
            break;

        case 2: // Search for a value
            cout << "Enter value to search: ";
            cin >> value;
            if (Search(root, value))
            {
                score += 10; // Increment score
                cout << "Value found! (+10 points)\n";
            }
            else
            {
                cout << "Value not found. Better luck next time!\n";
            }
            break;

        case 3: // Delete a node
            cout << "Enter value to delete: ";
            cin >> value;
            if (Search(root, value)) // Ensure value exists before deleting
            {
                root = Delete(root, value);
                score += 15; // Increment score
                cout << "Value deleted! (+15 points)\n";
            }
            else
            {
                cout << "Value not found, cannot delete.\n";
            }
            break;

        case 4: // Print Tree Traversals
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

        case 5: // View Score
            cout << "Current Score: " << score << " points\n";
            break;

        case 6: // Exit Game
            cout << "Exiting the BST Game. Final Score: " << score << " points\n";
            return;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
};

class HeapMountain {
private:
    vector<int> maxHeap; // Max-heap for storing largest elements at the top
    vector<int> minHeap; // Min-heap for storing smallest elements at the top
    int score; // Player's score

    // Generic heapify function to maintain heap property
    void heapify(vector<int>& heap, int index, bool isMaxHeap) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;  // Left child index
            int right = 2 * index + 2; // Right child index
            int target = index; // Index to potentially swap with

            // Compare left child with current target based on heap type (max or min)
            if (left < size && ((isMaxHeap && heap[left] > heap[target]) || (!isMaxHeap && heap[left] < heap[target]))) {
                target = left;
            }
            // Compare right child with current target based on heap type (max or min)
            if (right < size && ((isMaxHeap && heap[right] > heap[target]) || (!isMaxHeap && heap[right] < heap[target]))) {
                target = right;
            }
            // If no swap is needed, break the loop
            if (target == index) break;

            // Swap values to maintain heap property
            swap(heap[index], heap[target]);
            index = target; // Move to the target index for the next comparison
        }
    }

    // Insert value into the appropriate heap (max or min)
    void insertHeapValue(vector<int>& heap, int value, bool isMaxHeap) {
        heap.push_back(value); // Add new value to the heap
        int index = heap.size() - 1; // Index of the newly added element

        // Bubble up the new value to maintain heap property
        while (index > 0) {
            int parent = (index - 1) / 2; // Index of the parent
            // Compare with parent and swap if necessary based on heap type
            if ((isMaxHeap && heap[parent] >= heap[index]) || (!isMaxHeap && heap[parent] <= heap[index])) break;

            // Swap with parent to maintain heap property
            swap(heap[index], heap[parent]);
            index = parent; // Move to the parent's index for the next comparison
        }
    }

    // Validate if the input is a valid integer
    bool getValidInteger(int& value) {
        cin >> value; // Read input
        if (cin.fail()) { // Check if input is not a valid integer
            cin.clear(); // Clear the error state
            cin.ignore(10000, '\n'); // Ignore the rest of the input
            cout << "Invalid input. Please enter a valid integer.\n";
            return false;
        }
        return true;
    }

    // Display the heap as a sorted array (from highest to lowest or vice versa)
    void displayHeapSorted(const vector<int>& heap, bool isMaxHeap) {
        vector<int> tempHeap = heap, sorted;
        while (!tempHeap.empty()) {
            sorted.push_back(tempHeap[0]); // Add root to sorted
            swap(tempHeap[0], tempHeap.back()); // Swap root with last element
            tempHeap.pop_back(); // Remove last element
            heapify(tempHeap, 0, isMaxHeap); // Re-heapify the heap
        }

        cout << (isMaxHeap ? "Max-Heap (Highest to Lowest): " : "Min-Heap (Lowest to Highest): ");
        for (int value : sorted) {
            cout << value << " "; // Print sorted values
        }
        cout << endl;
    }

    // Display the heap in tree view (level by level)
    void displayHeapTree(const vector<int>& heap, bool isMaxHeap) {
        if (heap.empty()) {
            cout << (isMaxHeap ? "Max-Heap" : "Min-Heap") << " is empty.\n";
            return;
        }

        cout << (isMaxHeap ? "Max-Heap (Tree View):\n" : "Min-Heap (Tree View):\n");
        int level = 0, itemsInLevel = 1;
        for (size_t i = 0; i < heap.size(); ++i) {
            if (i == itemsInLevel - 1) { // Print level and its elements
                cout << "\nLevel " << level++ << ": ";
                itemsInLevel += 1 << level; // Double the number of items for the next level
            }
            cout << heap[i] << " "; // Print heap element
        }
        cout << "\n\n";
    }

public:
    // Constructor initializes the score to zero
    HeapMountain() : score(0) {}

    // Insert value into both heaps (max-heap and min-heap)
    void insertHeap(int value) {
        insertHeapValue(maxHeap, value, true); // Insert into max-heap
        insertHeapValue(minHeap, value, false); // Insert into min-heap
        cout << " " << value << " has been added to the Heap Mountain!\n";
        score += 5; // Reward for inserting
        cout << "Your current score: " << score << endl;
    }

    // Display both heaps
    void displayHeaps() {
        if (maxHeap.empty() && minHeap.empty()) {
            cout << "The Heap Mountain is empty! Start adding numbers to grow it.\n";
            return;
        }
        cout << "\n--- Heap Mountain View ---\n";
        displayHeapTree(maxHeap, true); // Display max-heap as tree
        displayHeapTree(minHeap, false); // Display min-heap as tree
    }

    // Display the game menu
    void displayMenu() {
        cout << "======================================================\n";
        cout << "||         ---Welcome to Heap Mountain ---          ||\n";
        cout << "======================================================\n";
        cout << "| 1. Add a number to the Heap                        |\n";
        cout << "| 2. View Heap Mountain                              |\n";
        cout << "| 3. Challenge: Find the Largest and Smallest Number |\n";
        cout << "| 4. Exit Heap Mountain                              |\n";
        cout << "======================================================\n";
    }

    // Run the game logic
    void heapgame() {
        int choice, value;
        char answer;

        while (true) {
            displayMenu(); // Show the menu
            cout << "Enter your choice: ";
            if (!getValidInteger(choice)) continue; // Validate choice

            switch (choice) {
                case 1:
                    do {
                        cout << "Enter an integer to add to the Heap Mountain: ";
                        if (!getValidInteger(value)) continue; // Validate value
                        insertHeap(value); // Insert value into both heaps

                        // Ask user if they want to add another value
                        cout << "Would you like to add another value? (Y/N): ";
                        cin >> answer;
                    } while (answer == 'Y' || answer == 'y'); // Repeat if user wants to add more
                    break;
                case 2:
                    displayHeaps(); // Show both heaps
                    break;
                case 3:
                    if (!maxHeap.empty() && !minHeap.empty()) {
                        cout << "\n--- Challenge: Guess the Peak and the Valley! ---\n";
                        int userGuessMax, userGuessMin;

                        // Ask the user to guess the largest number in the max-heap
                        cout << "Guess the Highest Number in the Heap Mountain (Max-Heap): ";
                        if (!getValidInteger(userGuessMax)) continue;
                        if (userGuessMax == maxHeap[0]) {
                            cout << " Correct! The Highest Number is indeed " << maxHeap[0] << ".\n";
                            score += 10; // Bonus points for correct guess
                        } else {
                            cout << " Wrong! The Highest Number was " << maxHeap[0] << ".\n";
                        }

                        // Ask the user to guess the smallest number in the min-heap
                        cout << "Guess the Lowest Number in the Heap Mountain (Min-Heap): ";
                        if (!getValidInteger(userGuessMin)) continue;
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
                    return; // Exit the game
                default:
                    cout << "Invalid choice. Try again!\n"; // Invalid input handling
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
        binaryTree.btgame();
        break;
      case 2:
        cout << "\n** Diving into the depths of Binary Search Trees! **\n";
        bst.bstgame();
        break;
      case 3:
        cout << "\n** Heap time! Let's heap some fun together! **\n";
        heap.heapgame();
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
