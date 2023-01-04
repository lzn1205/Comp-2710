//
//  Long Nguyen
//  project4_Nguyen_lzn0025.cpp
//  Project 4
//
//  Created by Long Nguyen on 10/22/22.
//  My project based on the Project_hint that you provided.
//  I followed your guide in class on Thursday to finish the rest of project.

//Libary imports.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <assert.h>
#include <climits>

using namespace std;
//Structure for creating a linked list that holds a trivia question,answer and point
struct triva_node {
    string question;
    string answer;
    int point;
    triva_node* next;
};

//creates a pointer to triva_node.
typedef triva_node* ptr_node;
 
//Prototypes
void init_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int num_ask);
void Unit_Test();
//clear method for getline()
void clear() {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}

//Number of Triva question
int num_of_questions;

//creates two versions.
//#define UNIT_TESTING
#define triva_quiz
int main() {
    ptr_node node_list = new triva_node;
    //Creates a new trivia game /
    //Sets up three original  questions/
    //Sets up loop for user to input his or her own questions.
    //Quiz questions are stored in linked list.
    #ifdef triva_quiz
    init_question_list(node_list);
    string choice = "Yes";
    
    cout << "*** Welcome to Long's trivia quiz game ***" << endl;
    while (choice == "Yes") {
        add_question(node_list);
        cout << "Continue? (Yes/No): ";
        cin >> choice;
        clear();
    }

    //This is start of Trivia quiz game.
    ask_question(node_list, num_of_questions);
    cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
    #endif
    //Method for testing
    #ifdef UNIT_TESTING
    Unit_Test();
    #endif
    
    return 0;
 }
 
//initializes the quiz to have these three questions inputted into the linked list.
void init_question_list(ptr_node& q_list) {
    //ptr_node cur_ptr;
    //ptr_node cur_ptr;
    string bob;
    ptr_node cur_ptr = new triva_node;
    cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)?";
    cur_ptr->answer = "38";
    cur_ptr->point = 100;
    cur_ptr->next = new triva_node;
    
    q_list = cur_ptr;
    cur_ptr = q_list->next;
    cur_ptr->question = "What was Bank of America’s original name? (Hint: Bank of Italy or Bank of Germany)?";
    cur_ptr->answer = "Bank of Italy";
    cur_ptr->point = 50;
    cur_ptr->next = new triva_node;
    
    cur_ptr = cur_ptr->next;
    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
    cur_ptr->answer = "Wii Sports";
    cur_ptr->point = 20;
    cur_ptr->next = NULL;
    
    num_of_questions = 3;
}

//gives user the option to add a question to the linked list.
//question is added to the front of the linked list.
void add_question(ptr_node& q_list) {
    string answer;
    //gets data from user
    ptr_node new_ptr = new triva_node;
    cout << "Enter a new question: ";
    getline(cin, new_ptr->question);
    
    cout << "Enter an answer: ";
    getline(cin, new_ptr->answer);
    
    cout << "Enter award points: ";
    cin >> new_ptr->point;
    
    new_ptr->next = q_list;
    q_list = new_ptr;
    
    num_of_questions++;
}

//Checks for null value
//Ask the user trivia questions and starts the game
int ask_question(ptr_node q_list, int num_ask) {
    ptr_node cur_ptr;
    cur_ptr = q_list;
    string answers;
    int points = 0;
    
    if (q_list == NULL) {
        return 0;
    }
    if(num_ask < 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
    } else if(num_of_questions < num_ask) {
        cout << "Warning - There is only " << num_of_questions << " trivia in the list.";
    }
    else {
        for(int x = 0; x < num_ask; x++) {
            cout << "Question: " << cur_ptr->question << endl;
            cout << "Answer: ";
            getline(cin, answers);
            if (answers.compare(cur_ptr->answer) == 0) {//correct_answer) {
                cout << "Your answer is correct! You receive " << cur_ptr->point << " points." << endl;
                points += cur_ptr->point;
                cout << "Your total points: " << points << endl;
            }
            else {
                cout << "Your answer is wrong. The correct answer is: " << cur_ptr->answer << endl;
                cout << "Your total points: " << points << endl;
            }
            cur_ptr = cur_ptr->next;
            clear();
        }
        
        return 0;
    }
    
    return 0;
}
 
//Test cases to check whether the methods work.
void Unit_Test() {
    cout << "***This is a debugging version ***";
    
    ptr_node node_list = new triva_node;
    init_question_list(node_list);
    int test_case;
    
    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    test_case = ask_question(node_list, 0);
    assert(test_case == 0);
    cout << "\nCase 1 Passed\n\n";
 
    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    test_case = ask_question(node_list, 1);
    assert(test_case == 1);
    cout << "\nCase 2.1 Passed\n";
    
    cout << "Unit Test Case 2.2: Ask 1 question in the linked  list. The tester enters an incorrect answer." << endl;
    test_case = ask_question(node_list, 1);
    assert(test_case == 1);
    cout << "\nCase 2.2 Passed\n";
    
    cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
    test_case = ask_question(node_list, 3);
    assert(test_case == 1);
    cout << "\nCase 3 Passed\n";
    
    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    test_case = ask_question(node_list, 5);
    assert(test_case == 0);
    cout << "\nCase 4 Passed\n";
 
    cout << "\n\n*** End of the Debugging Version ***";
}

