/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#include "question.hpp"

string Question::getQuestion()const
{
    return questionStatement;
}

void Question::setQuestion(const string questionStatement)
{
    this->questionStatement = questionStatement;
}

string Question::getAnswer()const
{
    return answer;
}

void Question::setAnswer(const string answer)
{
    this->answer = answer;
}

int Question::getScore()const
{
    return score;
}

void Question::setScore(const int score)
{
    this->score = score;
}

string Question::getType()const
{
    return type;
}

void Question::setType(const string type)
{
    this->type = type;
}

Question::~Question()
{

}
