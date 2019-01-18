/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <string>
using namespace std;

class Question
{
    protected:
        string questionStatement;
        string answer;
        int score;
        string type;
    public:
        /**Return question statement*/
        string getQuestion()const;

        /**Set question statement with given parameter*/
        void setQuestion(const string questionStatement);

        /**Return answer*/
        string getAnswer()const;

        /**Set answer with given parameter*/
        void setAnswer(const string answer);

        /**Return score*/
        int getScore()const;

        /**Set score with given parameter*/
        void setScore(const int score);

        /**Return question type*/
        string getType()const;

        /**Set question type with given parameter*/
        void setType(const string type);

        /**Virtual function to display question with their score and question statement. To be overridden*/
        virtual void display(int questionNumber)const = 0;

        /**Virtual Destructor*/
        virtual ~Question();
};


#endif // QUESTION_HPP
