/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#include "questionmc.hpp"

#include <iostream>
using namespace std;

QuestionMC::QuestionMC()
{
    type = "MC";
    questionStatement = "NA";
    answer = "A";
    score = 0;
    numberOfChoice = 0;
    choice.resize(numberOfChoice);
}

QuestionMC::QuestionMC(const QuestionMC& aQuestionMC)
{
    type = aQuestionMC.type;
    questionStatement = aQuestionMC.questionStatement;
    answer = aQuestionMC.answer;
    score = aQuestionMC.score;
    numberOfChoice = aQuestionMC.numberOfChoice;
    choice = aQuestionMC.choice;
}

QuestionMC::QuestionMC(const string pType,const string pQuestion,const string pAnswer,const int pScore,const int NumOfChoice,
                       const vector<string> pChoice)
{
    type = pType;
    questionStatement = pQuestion;
    answer = pAnswer;
    score = pScore;
    numberOfChoice = NumOfChoice;
    choice.resize(numberOfChoice);
    for (int i=0;i<numberOfChoice;i++)
    {
        choice[i] = pChoice[i];
    }
}

int QuestionMC::getNumOfChoice()const
{
    return numberOfChoice;
}

void QuestionMC::setNumOfChoice(const int numberOfChoice)
{
    this->numberOfChoice = numberOfChoice;
}

vector<string> QuestionMC::getChoice()const
{
    return choice;
}

void QuestionMC::setChoice(const int number, const string aChoice)
{
    choice[number] = aChoice;
}

void QuestionMC::display(int questionNumber)const
{
    cout << "Question " << questionNumber << " (" << score << " points)" << endl;
    cout << questionStatement << endl;
    char alpha = 'A';
    for (int i=0 ;i<numberOfChoice;i++,alpha++)
    {
        cout << alpha << ") " << choice[i] << endl;
    }
}

QuestionMC::~QuestionMC()
{

}
