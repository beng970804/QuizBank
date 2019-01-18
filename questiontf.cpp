/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#include "questiontf.hpp"

#include <iostream>
using namespace std;

QuestionTF::QuestionTF()
{
    type = "TF";
    questionStatement = "NA";
    answer = "NA";
    score = 0;
}

QuestionTF::QuestionTF(const QuestionTF& aQuestionTF)
{
    type = aQuestionTF.type;
    questionStatement = aQuestionTF.questionStatement;
    answer = aQuestionTF.answer;
    score = aQuestionTF.score;
}

QuestionTF::QuestionTF(const string pType,const string pQuestion,const string pAnswer,const int pScore)
{
    type = pType;
    questionStatement = pQuestion;
    answer = pAnswer;
    score = pScore;
}

void QuestionTF::display(int questionNumber)const
{
    cout << "Question " << questionNumber << " (" << score << " points)" << endl;
    cout << questionStatement << endl;
}

QuestionTF::~QuestionTF()
{

}
