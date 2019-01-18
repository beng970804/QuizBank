/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#ifndef QUESTIONTF_HPP
#define QUESTIONTF_HPP

#include "question.hpp"

#include <string>
using namespace std;

class QuestionTF : public Question
{
    public:
        /**Default constructor*/
        QuestionTF();

        /**Copy constructor*/
        QuestionTF(const QuestionTF& aQuestionTF);

        /**Overload constructor*/
        QuestionTF(const string pType, const string pQuestion,const string pAnswer,const int pScore);

        /**Override virtual function*/
        virtual void display(int questionNumber)const;

        /**Destructor*/
        ~QuestionTF();
};


#endif //QUESTIONTF_HPP
