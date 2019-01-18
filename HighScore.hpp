/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#ifndef HIGHSCORE_HPP
#define HIGHSCORE_HPP

#include <string>
using namespace std;

class HighScore
{
    friend bool operator<= (const HighScore &a, const HighScore &b);
    friend bool operator>= (const HighScore &a, const HighScore &b);
    private:
        string name;
        double scoreByPercent;
    public:
        /**Default constructor*/
        HighScore();

        /**Copy constructor*/
        HighScore(const HighScore& otherHighScore);

        /**Overload constructor*/
        HighScore(const string name,const double scoreByPercent);

        /**Return name*/
        string getName()const;

        /**Set name with given parameter*/
        void setName(const string name);

        /**Return score by percentage*/
        double getScoreByPercent()const;

        /**Set score by percent with given parameter*/
        void setScoreByPercent(const double scoreByPercent);

        /**Destructor*/
        ~HighScore();
};
#endif // HIGHSCORE_HPP
