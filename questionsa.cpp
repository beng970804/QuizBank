/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#include "questionsa.hpp"

#include <iostream>
using namespace std;

QuestionSA::QuestionSA()
{
    type = "SA";
    questionStatement = "NA";
    answer = "NA";
    score = 0;
}

QuestionSA::QuestionSA(const QuestionSA& aQuestionSA)
{
    type = aQuestionSA.type;
    questionStatement = aQuestionSA.questionStatement;
    answer = aQuestionSA.answer;
    score = aQuestionSA.score;
}

QuestionSA::QuestionSA(const string pType,const string pQuestion,const string pAnswer,const int pScore)
{
    type = pType;
    questionStatement = pQuestion;
    answer = pAnswer;
    score = pScore;
}

void QuestionSA::display(int questionNumber)const
{
    cout << "Question " << questionNumber << " (" << score << " points)" << endl;
    cout << questionStatement << endl;
}

QuestionSA::~QuestionSA()
{

}

