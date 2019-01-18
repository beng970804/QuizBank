/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#ifndef QUESTIONMC_HPP
#define QUESTIONMC_HPP

#include "question.hpp"

#include <string>
#include <vector>
using namespace std;

class QuestionMC : public Question
{
    private:
        int numberOfChoice;
        vector<string> choice;
    public:
        /**Default constructor*/
        QuestionMC();

        /**Copy constructor*/
        QuestionMC(const QuestionMC& aQuestionMC);

        /**Overload constructor*/
        QuestionMC(const string pType,const string pQuestion,const string pAnswer,const int pScore,const int NumOfChoice,
                   const vector<string> pChoice);

        /**Return number of choice*/
        int getNumOfChoice()const;

        /**Set number of choice with given parameter*/
        void setNumOfChoice(const int numberOfChoice);

        /**Return vector of choices*/
        vector<string> getChoice()const;

        /**Set vector of choices with given parameter*/
        void setChoice(const int number, const string aChoice);

        /**Override virtual function*/
        virtual void display(int questionNumber)const;

        /**Destructor*/
        ~QuestionMC();
};


#endif //QUESTIONMC_HPP
