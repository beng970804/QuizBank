/**********|**********|**********|
Program: QUIZ BANK
Course: Bachelor of Computer Science
Subject: TCP1201 Object Oriented Programming and Data Structure
Year: 2016/17 Trimester 2
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
Copyright © 2016 Alfred Loo. All rights reserved.
**********|**********|**********/
#include "player.hpp"
#include "question.hpp"
#include "questiontf.hpp"
#include "questionsa.hpp"
#include "questionmc.hpp"
#include "LList.h"
#include "method.hpp"
#include "HighScore.hpp"

using namespace std;

int main()
{
    ListInterface<Question*> *listPtr = new LList<Question*>();
    Player newPlayer;
    char *fileName = new char;
    ListInterface<HighScore*> *hsPtr = new LList<HighScore*>();
    printOption(listPtr,newPlayer,fileName,hsPtr);
    return 0;
}


