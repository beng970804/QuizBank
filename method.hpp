/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#ifndef METHOD_HPP
#define METHOD_HPP

#include "LList.h"
#include "question.hpp"
#include "player.hpp"
#include "HighScore.hpp"

/**Display the main menu of program*/
void printMenu();

/**Allow the user to choose their option and carry out the specific function*/
void printOption(ListInterface<Question*> *listPtr,Player& newPlayer,char *fileName,ListInterface<HighScore*> *hsPtr);

/**Check password for admin use. Return true if the password is correct*/
bool getPassword();

/**Display the admin menu of the program*/
void adminMenu();

/**Allow the user to choose their option and carry out the specific function*/
void adminOption(ListInterface<Question*> *listPtr,char *fileName,ListInterface<HighScore*> *hsPtr);

/**Store questions from .txt file*/
void startup(ListInterface<Question*> *listPtr,bool& isFileRead,char *fileName);

/**Initialize the game and track player's score*/
void startGame(ListInterface<Question*> *listPtr,Player& newPlayer,ListInterface<HighScore*> *hsPtr);

/**Read the .txt file*/
void readQuestionFromFile(ifstream& readFromFile,ListInterface<Question*> *listPtr);

/**Allow user to choose the number of question to try. Return that number*/
int askQuestionToTry(const int numberOfQuestion);

/**Check the input of user choosing number of question. Return true if input is correct*/
bool checkInput(int questionToTry, int numberOfQuestion);

/**Generate a sequence to randomize the question*/
void generateRandomSequence(int randNum[],const int questionToTry, const int maxQuestion);

/**Display question and get answer from user. Display user final score as well.*/
void questionAndAnswer(ListInterface<Question*> *listPtr,int randNum[],Player& newPlayer,const int questionToTry,ListInterface<HighScore*> *hsPtr);

/**Insert function for admin. Update the contents of .txt file accordingly*/
void adminInsert(ListInterface<Question*> *listPtr,char *fileName);

/**Edit function for admin. Update the contents of .txt file accordingly*/
void adminEdit(ListInterface<Question*> *listPtr,char *fileName);

/**Delete function for admin. Update the contents of .txt file accordingly*/
void adminDelete(ListInterface<Question*> *listPtr,char *fileName);

/**Display all question*/
void adminViewAll(ListInterface<Question*> *listPtr);

/**Randomize the order of question*/
void adminRandomize(ListInterface<Question*> *listPtr,char *fileName);

/**Update the contents of .txt file*/
void writeQuestionToFile(ListInterface<Question*> *listPtr, char *fileName);

/**Display the leaderboard and top scores*/
void viewLeaderboard(ListInterface<HighScore*> *hsPtr);

/**Display the guide for program*/
void readGuide(const string type);

#endif // METHOD_HPP
