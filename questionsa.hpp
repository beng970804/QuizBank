/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#ifndef QUESTIONSA_HPP
#define QUESTIONSA_HPP

#include "question.hpp"

#include <string>
using namespace std;

class QuestionSA : public Question
{
    public:
        /**Default constructor*/
        QuestionSA();

        /**Copy constructor*/
        QuestionSA(const QuestionSA& aQuestionSA);

        /**Overload constructor*/
        QuestionSA(const string pType,const string pQuestion,const string pAnswer,const int pScore);

        /**Override virtual function*/
        virtual void display(int questionNumber)const;

        /**Destructor*/
        ~QuestionSA();
};


#endif //QUESTIONSA_HPP
