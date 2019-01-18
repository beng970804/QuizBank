/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/
#include "player.hpp"

#include <iostream>
#include <iomanip>
using namespace std;

Player::Player()
:firstName("Default"),lastName("Player"),point(0)
{

}

Player::Player(const Player& aPlayer)
{
    firstName = aPlayer.firstName;
    lastName = aPlayer.lastName;
    point = aPlayer.point;
}

Player::Player(const string pFirstName,const string pLastName,const int pPoint)
:firstName(pFirstName),lastName(pLastName),point(pPoint)
{

}

string Player::getName()const
{
    return firstName + " " + lastName;
}

void Player::setFirstName(const string& pFirstName)
{
    this->firstName = pFirstName;
}

void Player::setLastName(const string& pLastName)
{
    this->lastName = pLastName;
}

int Player::getPoint() const
{
    return point;
}

void Player::setPoint(const int& pPoint)
{
    this->point = pPoint;
}

void Player::addPoint(int pPoint)
{
    point += pPoint;
}

void Player::deductPoint(int pPoint)
{
    point -= pPoint;
}

void Player::finalDisplay(int accumulator, double percent)
{
    //Display message with the accumulated points
    cout << getName() << ", your game is over!" << endl;
    cout << "Your final score is " << point << " points out of " << accumulator << " points." << endl;
    cout << "You get " << fixed << setprecision(2) << percent << "%" << " for the quiz." << endl;
    if (point == accumulator)
    {
        cout << "Congratulations! You scored full marks!" << endl;
    }
    else if ((point>0)&&(point<accumulator))
    {
        cout << "Well done! Try more to achieve better score!" << endl;
    }
    else
    {
        cout << "Better luck next time! Keep on improving!" << endl;
    }
    resetPoint();
}

void Player::resetPoint()
{
    point = 0;
}

Player::~Player()
{

}
