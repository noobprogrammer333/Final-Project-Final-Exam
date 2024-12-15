# Final-Project-Final-Exam
Members: 
Jude Melvin Grutas,
Kylan Heinrich Dimaiwat,
Asher B. Caubang
BSCS-2B

## Project Overview
This project integrates three key data structures: **Binary Trees, Binary Search Trees (BST), and Heaps (Min-Heap and Max-Heap)**, with interactive functionalities that are educational and entertaining. It includes:

1. **Binary Tree**: A Wordle-like game where players guess a target word and the binary tree dynamically updates based on the guesses and feedback.
2. **Binary Search Tree (BST)**: A system to insert, search, delete, and perform traversals on a BST, complete with a game to test searching skills.
3. **Heaps**: A game-based system utilizing Max-Heap and Min-Heap structures to teach heap operations, such as inserting values, displaying the heap, and solving challenges.

The main menu integrates these three systems, providing users with an engaging way to interact with the data structures.

## How to Run the Code
1. Setup:
   - Ensure you have installed a C++ compiler (e.g., GCC or any IDE like Code::Blocks or Visual Studio).
   - Copy the code into a `.cpp` file.

2. Compile and Run

3. Menu Navigation:
    Upon execution, you'll be presented with a main menu offering three options:
     - Binary Tree
     - Binary Search Tree (BST)
     - Heap (Min and Max)
   - Choose an option to interact with the respective functionality.

## Description of Each Functionality

 1. **Binary Tree**
Purpose: Simulates a Wordle-like game.
Features:
  - Builds a binary tree from a predefined list of words.
  - Feedback system (`G` = correct position, `Y` = correct letter wrong position, `B` = incorrect letter).
  - Dynamically prunes the tree to reduce the number of possible words based on guesses.
How It Works:
  - Players guess a 5-letter word.
  - Feedback is provided based on whether it matches the target word.
  - The tree updates to show only possible remaining words.

2. **Binary Search Tree (BST)**
Purpose: Offers a comprehensive exploration of BST operations.
Features:
  - Insert values into the BST: Following BST rules, add nodes to the tree. Earn 5 points per insertion.
  - Search for specific values: Search for a value. Earn 10 points for a successful find.
  - Delete nodes (leaf, single child, or two children): Earn 15 points for successful deletion.
  - Traverse the BST using Pre-order, In-order, and Post-order techniques: View the tree in In-order, Pre-order, or Post-order.
  - Play a game to guess values in the BST.
How It Works:
  - Players can:
      Insert nodes into the tree.
      Search for specific values.
      Delete nodes.
      View different tree traversals.
      Earn points for each operation:
      5 points for insertion.
      10 points for a successful search.
      15 points for node deletion.

3. Heap Mountain
Purpose: Introduces Max-Heap and Min-Heap operations in an interactive format.
Features:
  - Insert values into both Max-Heap and Min-Heap simultaneously.
  - Display heaps as sorted arrays.
  - Engage in challenges to guess the Max-Heap and Min-Heap order.
How It Works:
  - Add Numbers:
      Players add integers to both heaps.
      Numbers are also stored in their original order.
      Earn 5 points per number added.
   -Challenge:
      Players guess:
      The largest number (max-heap root).
      The smallest number (min-heap root).
      Earn 10 points for each correct guess.
      Displays original numbers and correct heap values if requested.

Example Walkthrough

1. **Binary Tree**:
   - Build a tree with words like "apple", "grape", and "peach".
   - Target word: peach
   - User guesses "apple" → Feedback: `YBBBY`.
   - Tree updates to reflect possible matches.

2. **BST**:
   - Insert values: 10, 5, 20. (Earns Points)
   - Perform In-order traversal: 5 10 20.
   - Delete value: 10 → New root is 20.
   - Search for 5: Found.

3. **Heap**:
   - Insert values: 10, 20, 30, 5, 15
   - Challenge:
    - Displays the user input order of the values
      --- Original Order of Numbers Added to Heap Mountain ---
10 5 8

--- Challenge: Guess the Peak and the Valley! ---
Guess the Max-Heap in the Heap Mountain: 10
Correct! The Max-Heap is indeed 10.
Guess the Min-Heap in the Heap Mountain: 5
Correct! The Min-Heap is indeed 5.
Your total score after the challenge: 25


This project is a fun, interactive way to explore key data structures, making it perfect for learning and practical demonstration!
