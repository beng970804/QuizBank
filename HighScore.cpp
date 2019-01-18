/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#include "HighScore.hpp"

HighScore::HighScore()
:name("Default Player"),scoreByPercent(0)
{

}

HighScore::HighScore(const HighScore& otherHighScore)
{
    name = otherHighScore.name;
    scoreByPercent = otherHighScore.scoreByPercent;
}

HighScore::HighScore(const string name,const double scoreByPercent)
:name(name),scoreByPercent(scoreByPercent)
{

}

string HighScore::getName()const
{
    return name;
}

void HighScore::setName(const string name)
{
    this->name = name;
}

double HighScore::getScoreByPercent()const
{
    return scoreByPercent;
}

void HighScore::setScoreByPercent(const double scoreByPercent)
{
    this->scoreByPercent = scoreByPercent;
}

bool operator<= (const HighScore &a, const HighScore &b)
{
    return a.getScoreByPercent() <= b.getScoreByPercent();
}

bool operator>= (const HighScore &a, const HighScore &b)
{
    return a.getScoreByPercent() >= b.getScoreByPercent();
}

HighScore::~HighScore()
{

}
