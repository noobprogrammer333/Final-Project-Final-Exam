# Final-Project-Final-Exam
Members: 
Jude Melvin Grutas,
Kylan Heinrich Dimaiwat,
Asher B. Caubang
BSCS-2B


## **Project Overview**
This project combines three key data structures: **Binary Trees**, **Binary Search Trees (BST)**, and **Heaps (Min-Heap and Max-Heap)**, offering interactive and educational functionalities in an engaging format. The program features:

1. **Binary Tree**: A Wordle-inspired game where players guess a target word, dynamically updating a binary tree based on feedback.
2. **Binary Search Tree (BST)**: A system for inserting, searching, deleting, and traversing nodes, with an added game to test search skills.
3. **Heaps**: A game-based system that teaches heap operations through Max-Heap and Min-Heap interactions, challenges, and visualizations.

The **main menu** integrates these systems, offering a unified interface to explore data structures interactively.


## **How to Run the Code**

1. **Setup**:
   - Install a C++ compiler (e.g., GCC) or an IDE (e.g., Code::Blocks, Visual Studio).
   - Copy the code into a `.cpp` file.

2. **Compile and Run**:
   - Compile the code and execute it from the terminal or IDE.

3. **Menu Navigation**:
   - Upon execution, a menu is displayed with options:
     - Binary Tree
     - Binary Search Tree (BST)
     - Heap (Min-Heap and Max-Heap)
   - Choose an option to explore the respective functionality.


## **Description of Features**

### 1. **Binary Tree**
- **Purpose**: Simulates a Wordle-like guessing game.
- **Features**:
  - Builds a binary tree from a predefined word list.
  - Feedback system:  
    - `G` = Correct letter in the correct position.  
    - `Y` = Correct letter in the wrong position.  
    - `B` = Incorrect letter.
  - Dynamically prunes the tree based on guesses.
- **How It Works**:
  - Players guess a 5-letter target word.
  - Feedback narrows down possible matches, and the tree updates accordingly.



### 2. **Binary Search Tree (BST)**
- **Purpose**: Explore and manipulate BST operations.
- **Features**:
  - Insert nodes into the BST.
  - Search for specific values.
  - Delete nodes (leaf, single child, or two children).
  - Traverse the tree in **In-order**, **Pre-order**, and **Post-order**.
  - Play a game to guess values in the tree.
- **How It Works**:
  - Earn points for actions:  
    - **5 points** for insertion.  
    - **10 points** for successful searches.  
    - **15 points** for deletions.
  - Players can view the tree's structure and explore its properties.



### 3. **Heap Mountain**
- **Purpose**: Teach heap operations interactively using Max-Heap and Min-Heap structures.
- **Features**:
  - Insert numbers into both heaps simultaneously.
  - Display heaps as sorted arrays or tree structures.
  - Solve challenges to guess heap properties.
- **How It Works**:
  - **Add Numbers**:  
    - Players add integers to the heaps.  
    - Numbers are stored in their original order.  
    - Earn **5 points** per number added.
  - **Challenge**:
    - Guess the largest (Max-Heap root) and smallest (Min-Heap root) values.  
    - Earn **10 points** per correct guess.  
    - View the original input order and heap structure upon request.



## **Example Walkthrough**

1. **Binary Tree**:
   - Words: `"apple"`, `"grape"`, `"peach"`.
   - Target: `"peach"`.  
   - Guess: `"apple"` → Feedback: `YBBBY`.  
   - The tree updates to narrow down matches.

2. **Binary Search Tree (BST)**:
   - Insert: `10`, `5`, `20` → Earn points.
   - Traverse (In-order): `5 10 20`.
   - Delete: `10` → Root becomes `20`.
   - Search: `5` → Found.

3. **Heap Mountain**:
   - Insert: `10`, `5`, `8`.
   - Original input:  
   
     --- Original Order of Numbers Added to Heap Mountain ---
     10 5 8
     
   - Challenge:  
     - Max-Heap guess: `10` → Correct!  
     - Min-Heap guess: `5` → Correct!  
   - Score after challenge: `25`.



## **Conclusion**
This project offers a **fun and interactive way** to learn key data structures like Binary Trees, BSTs, and Heaps. With practical applications and games, it’s perfect for educational purposes and showcasing data structure concepts in an engaging manner.
