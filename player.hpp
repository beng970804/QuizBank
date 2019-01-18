/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
using namespace std;

class Player
{
    private:
        string firstName;
        string lastName;
        int point;
    public:

        /**Default constructor*/
        Player();

        /**Copy constructor*/
        Player(const Player& aPlayer);

        /**Overload constructor*/
        Player(const string pFirstName,const string pLastName,const int pPoint);

        /**Return first name and last name*/
        string getName()const;

        /**Set first name with given parameter*/
        void setFirstName(const string& pFirstName);

        /**Set last name with given parameter*/
        void setLastName(const string& pLastName);

        /**Return point*/
        int getPoint()const;

        /**Set point with given parameter*/
        void setPoint(const int& pPoint);

        /**Increase the current by the parameter*/
        void addPoint(int pPoint);

        /**Decrease the current by the parameter*/
        void deductPoint(int pPoint);

        /**Display the player name and final score*/
        void finalDisplay(int accumulator, double percent);

        /**Reset the point to zero.*/
        void resetPoint();

        /**Destructor*/
        ~Player();
};


#endif // PLAYER_HPP
