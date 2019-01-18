/***************************************************
Name: Alfred Loo Wee How
ID: 1151100653
Email: alfred97620@gmail.com
Phone: 019-779 6758
***************************************************/

#include "method.hpp"
#include "questiontf.hpp"
#include "questionsa.hpp"
#include "questionmc.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <windows.h>
#include <iomanip>

void printMenu()
{
    cout << "**********************************"<< endl;
    cout << "*  Welcome to Quiz Bank Program  *" << endl;
    cout << "**********************************\n"<< endl;
    cout << "-------------" << endl;
    cout << "| Main Menu |" << endl;
    cout << "-------------" << endl;
    cout << "1. Startup." << endl;
    cout << "2. Start Game." << endl;
    cout << "3. Administration." << endl;
    cout << "4. Menu Guide." << endl;
    cout << "100. Quit game." << endl;
    return;
}

void printOption(ListInterface<Question*> *listPtr,Player& newPlayer,char *fileName,ListInterface<HighScore*> *hsPtr)
{
    int option;
    bool isFileRead = false;
    bool done = false;
    bool isAdmin = false;
    do
    {
        system("cls");
        printMenu();
        cout << "\nEnter your option: ";
        cin >> option;

        //Check input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Invalid input." << endl;
            cout << "Enter your option again: ";
            cin >> option;
        }
        //End check input

        switch(option)
        {
            case 1:
                system("cls");
                startup(listPtr, isFileRead,fileName);
                break;
            case 2:
                system("cls");
                startGame(listPtr, newPlayer, hsPtr);
                break;
            case 3:

                //Get password, will go to admin option if password correct
                cout << "Only admin can choose this option." << endl;
                cout << "(The password is obtainable at \"4. Menu Guide.\")" << endl;
                isAdmin = getPassword();
                if (isAdmin)
                {
                    adminOption(listPtr,fileName, hsPtr);
                }
                else
                {
                    cout << "Reminder: Only admin can choose this option." << endl;
                    cout << "(The password is obtainable at \"4. Menu Guide\".)" << endl;
                }
                //End get password

                break;
            case 4:
                system("cls");

                //pass "M" for menu
                readGuide("M");

                break;
            case 100:
                done = true;
                break;
            default:
                cerr << "Invalid option. Select above options only. " << endl;
        }
        cout << endl;
        system("pause");
    } while (!done);

    cout << "\nThank you for playing." << endl;
    return;
}

bool getPassword()
{
    string defaultPassword = "password";
    string password;
    string reply;
    bool isAdmin = false;
    do
    {
        cout << "Please enter your password(case sensitive): ";
        cin.ignore(1000,'\n');
        getline(cin,password);
        if (password==defaultPassword)
        {
            isAdmin=true;
            return isAdmin;
        }
        else
        {

            //If wrong password, ask user to try again
            cout << "Wrong password." << endl;
            cout << "Do you want to try again? Enter y(yes) or n(no): ";
            cin >> reply;
            for (unsigned int i=0;i<reply.size();i++)
            {
                reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
            }
            while ((reply!="y")&&(reply!="n"))
            {
                cerr << "Invalid choice. Enter y(yes) or n(no) only: ";
                cin >> reply;
                for (unsigned int i=0;i<reply.size();i++)
                {
                    reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
                }
            }
            //End check to try again

        }
    } while (reply=="y");
    return isAdmin;
}

void adminMenu()
{
    cout << "-----------------------" << endl;
    cout << "| Administration Menu |" << endl;
    cout << "-----------------------" << endl;
    cout << "1. Insert new question." << endl;
    cout << "2. Edit existing question." << endl;
    cout << "3. Delete existing question." << endl;
    cout << "4. View all question." << endl;
    cout << "5. Randomize question." << endl;
    cout << "6. View leader board." << endl;
    cout << "7. Admin Guide." << endl;
    cout << "100. Return to Main Menu." << endl;
    return;
}

void adminOption(ListInterface<Question*> *listPtr,char *fileName,ListInterface<HighScore*> *hsPtr)
{
    int option;
    bool done = false;
    do
    {
        system("cls");
        adminMenu();
        cout << "\nEnter your option: ";
        cin >> option;

        //check input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Invalid input." << endl;
            cout << "Enter your option again: ";
            cin >> option;
        }
        //End check input

        switch(option)
        {
            case 1:
                system("cls");
                adminInsert(listPtr,fileName);
                cout << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                adminEdit(listPtr,fileName);
                cout << endl;
                system("pause");
                break;
            case 3:
                system("cls");
                adminDelete(listPtr,fileName);
                cout << endl;
                system("pause");
                break;
            case 4:
                system("cls");
                adminViewAll(listPtr);
                cout << endl;
                system("pause");
                break;
            case 5:
                system("cls");
                adminRandomize(listPtr,fileName);
                cout << endl;
                system("pause");
                break;
            case 6:
                system("cls");
                viewLeaderboard(hsPtr);
                cout << endl;
                system("pause");
                break;
            case 7:
                system("cls");

                //pass "A"for admin
                readGuide("A");

                cout << endl;
                system("pause");
                break;
            case 100:
                done = true;
                break;
            default:
                cerr << "Invalid option. Select above options only. " << endl;
        }
    } while (!done);
    return;
}

void startup(ListInterface<Question*> *listPtr,bool& isFileRead,char *fileName)
{
    //if no file read before
    if (!isFileRead)
    {
        cin.ignore(1000,'\n');
        cout << "Startup in process...." << endl;

        ifstream readFromFile;
        do
        {
            //Ask for file name
            cout << "What file stores your questions?" << endl;
            cin >> fileName;
            readFromFile.open(fileName);
            if (readFromFile.fail())
            {
                cerr << "Input file opening failed." << endl;
            }
            //end ask for file name

        } while(readFromFile.fail());

        readQuestionFromFile(readFromFile,listPtr);
        isFileRead=true;
        readFromFile.close();
    }

    //if a file is read before
    else
    {
        string reply;

        //ask if user will delete current question to read other file
        cout << "Do you want to delete current questions and read another file? Enter y(yes)or n(no): " << endl;
        cin >> reply;
        for (unsigned int i=0;i<reply.size();i++)
        {
            reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
        }
        while ((reply!="y")&&(reply!="n"))
        {
            cerr << "Invalid choice. Enter y(yes) or n(no) only: ";
            cin >> reply;
            for (unsigned int i=0;i<reply.size();i++)
            {
                reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
            }
        }
        //end ask

        if (reply=="y")
        {
            listPtr->clear();
            if (listPtr->isEmpty())
                cout << "The list is now cleared. Start to read file.";
            isFileRead=false;
            cin.clear();
            cin.ignore(1000,'\n');
            startup(listPtr,isFileRead,fileName);
        }
        else
        {
            cout << "The questions are not changed. You may start your game." << endl;
        }
    }
    return;
}

void startGame(ListInterface<Question*> *listPtr,Player& newPlayer,ListInterface<HighScore*> *hsPtr)
{
    //if question list is not empty
    if (!listPtr->isEmpty())
    {
        //ask for name
        cin.ignore(1000,'\n');
        string tempFirstName;
        string tempLastName;
        cout << "What is your first name?" << endl;
        getline(cin,tempFirstName);
        cout << "What is your last name?" << endl;
        getline(cin,tempLastName);
        newPlayer.setFirstName(tempFirstName);
        newPlayer.setLastName(tempLastName);
        //end ask for name

        int questionToTry = 0;

        string reply;
        do
        {
            //get question to try
            questionToTry = askQuestionToTry(listPtr->getLength());
            cout << "\nAre you sure you want to try " << questionToTry << " question(s)? Enter y(yes) or n(no):" << endl;
            cin >> reply;
            for (unsigned int i=0;i<reply.size();i++)
            {
                reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
            }
            while ((reply!="y")&&(reply!="n"))
            {
                cerr << "Invalid choice. Enter y(yes) or n(no) only: ";
                cin >> reply;
                for (unsigned int i=0;i<reply.size();i++)
                {
                    reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
                }
            }
            //end get
        } while (reply=="n");

        int* randNum = new int[questionToTry];
        //generate random number
        generateRandomSequence(randNum,questionToTry,listPtr->getLength());
        system("cls");
        //start q&a
        questionAndAnswer(listPtr,randNum,newPlayer,questionToTry,hsPtr);
        delete[] randNum;
        randNum = nullptr;
    }

    //if question list is empty, as player to choose startup first
    else
    {
        cout << "Question list is empty. Please choose \"1.Startup\" first before start game." << endl;
    }
    return;
}

void readQuestionFromFile(ifstream& readFromFile,ListInterface<Question*> *listPtr)
{
    string line; //create line(to read from file use)
    getline(readFromFile,line); //read line from text file

    while (!readFromFile.eof()) //when not end of file
    {
        readFromFile >> line;//read line
        if (line=="TF") //when line is TF
        {
            string* pLine = new string[3]; //create new string
            int c=0;
            while (c<3) //loop three times(to read score, question and answer)
            {
                getline(readFromFile,line);
                int f = c%3;
                pLine[f]=line;
                if (c%3==2)
                {
                    for (unsigned int i=0;i<pLine[2].size();i++)
                    {
                        pLine[2].at(i)=tolower(pLine[2].at(i)); //convert the answer to lower case
                    }
                    string type = "TF";
                    Question *questionTF = new QuestionTF(type,pLine[1],pLine[2],atoi(pLine[0].c_str())); //create object of QuestionTF
                    if(listPtr->insert(listPtr->getLength()+1,questionTF))
                        cout << "Question of type TF inserted successfully." << endl;
                }
                c++;
            }
        }
        if (line=="SA") //when line is SA
        {
            string* pLine = new string[3]; //create new string
            int c=0;
            while (c<3) //loop three times(to read score, question and answer)
            {
                getline(readFromFile,line);
                int f = c%3;
                pLine[f]=line;
                if (c%3==2)
                {
                    for (unsigned int i=0;i<pLine[2].size();i++)
                    {
                        pLine[2].at(i)=tolower(pLine[2].at(i)); //convert the answer to lower case
                    }
                    string type = "SA";
                    Question *questionSA = new QuestionSA(type,pLine[1],pLine[2],atoi(pLine[0].c_str())); //create object of QuestionSA
                    if (listPtr->insert(listPtr->getLength()+1,questionSA))
                        cout << "Question of type SA inserted successfully." << endl;
                }
                c++;
            }
        }
        if (line=="MC") //when line is MC
        {
            string* pLine = new string[3]; //create new string
            int c=0;
            while (c<2) //loop twice(to read score, question)
            {
                getline(readFromFile,line);
                pLine[c]=line;
                c++;
            }
            getline(readFromFile,line); //get number of choice
            int no_c = atoi(line.c_str()); //store number of choice
            vector<string> pChoice; //create vector for choice
            pChoice.reserve(no_c); //with size of number of choice
            for (int i=0;i<no_c;i++)
            {
                getline(readFromFile,line);
                pChoice.push_back(line); //add element to vector of choice
            }
            getline(readFromFile,line); //read line for answer
            pLine[2] = line;
            for (unsigned int i=0;i<pLine[2].size();i++)
            {
                pLine[2].at(i)=tolower(pLine[2].at(i)); //convert the answer to lower case
            }
            string type = "MC";
            Question *questionMC = new QuestionMC(type,pLine[1],pLine[2],atoi(pLine[0].c_str()),no_c,pChoice); //create object of QuestionMC
            if (listPtr->insert(listPtr->getLength()+1,questionMC))
                cout << "Question of type MC inserted successfully." << endl;
        }
    }
    return;
}

int askQuestionToTry(const int numberOfQuestion)
{
    int questionToTry;
    bool isValid = false;
    while (!isValid)
    {
        cout << "How many question would you like to try (out of " << numberOfQuestion << ")?" << endl;
        cin >> questionToTry;
        isValid = checkInput(questionToTry,numberOfQuestion);
    }

    return questionToTry;
}

bool checkInput(int questionToTry, int numberOfQuestion)
{
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(256,'\n');
        cerr << "Sorry that is not valid" << endl;
        return false;
    }
    else if (questionToTry<1)
    {
        cerr << "Sorry that is too less" << endl;
        return false;
    }
    else if (questionToTry>numberOfQuestion)
    {
        cerr << "Sorry that is too many" << endl;
        return false;
    }
    else
    {
        return true;
    }
}

void generateRandomSequence(int randNum[],const int questionToTry, const int maxQuestion)
{
    srand(time(NULL));

    //get random number
    for (int i=0;i<questionToTry;i++)
    {
        bool check;
        int value;
        do
        {
            value = rand()%maxQuestion;
            check = true;
            for (int j=0;j<i;j++)
            {
                //if number repeated, don't store the number
                if (value==randNum[j])
                {
                    check=false;
                    break;
                }
            }
        } while (!check);
        randNum[i]=value;
    }
}

void questionAndAnswer(ListInterface<Question*> *listPtr,int randNum[],Player& newPlayer, const int questionToTry,ListInterface<HighScore*> *hsPtr)
{
    double accumulator=0;
    int temp=1;
    string answer;
    string type;
    int no_of_choice;
    for (int i=0;i<questionToTry;i++,temp++)
    {
        (listPtr->retrieve(randNum[i]+1))->display(temp);
        cout << "\nAnswer: ";
        cin >> answer;
        for (unsigned int i=0;i<answer.size();i++)
        {
            answer.at(i)=tolower(answer.at(i));  //convert answer to lower case
        }
        type = (listPtr->retrieve(randNum[i]+1))->getType();
        if (type=="TF")
        {
            while ((answer!="true")&&(answer!="false"))
            {
                cout << "Wrong input. Choose \"true\" or \"false\" only.\nAnswer: ";
                cin >> answer;
                for (unsigned int i=0;i<answer.size();i++)
                {
                    answer.at(i)=tolower(answer.at(i));  //convert answer to lower case
                }
            }
        }
        if (type=="MC")
        {
            QuestionMC *copyMC = (QuestionMC *)(listPtr->retrieve(randNum[i]+1));
            no_of_choice = copyMC->getNumOfChoice();
            string a_to_z = "abcdefghijklmnopqrstuvwxyz";
            bool inChoice=false;
            do
            {
                for (int i=0;i<no_of_choice;i++)
                {
                    if (answer==(a_to_z.substr(i,1)))
                    {
                        inChoice = true;
                        break;
                    }
                }
                if(!inChoice)
                {
                    cout << "Wrong input. Choose ";
                    char alpha = 'a';
                    for (int i=0;i<no_of_choice;i++,alpha++)
                    {
                        cout << "\"" << alpha << "\" ";
                    }
                    cout << "only.\nAnswer: ";
                    cin >> answer;
                    for (unsigned int i=0;i<answer.size();i++)
                    {
                        answer.at(i)=tolower(answer.at(i));  //convert answer to lower case
                    }
                }
            }while(!inChoice);
        }
        if (answer==((listPtr->retrieve(randNum[i]+1))->getAnswer()))
        {
            cout << "Correct! You get " << (listPtr->retrieve(randNum[i]+1))->getScore() << " points." << endl;
            accumulator += (listPtr->retrieve(randNum[i]+1))->getScore();
            newPlayer.addPoint((listPtr->retrieve(randNum[i]+1))->getScore());
            cout << "Your current score is " << newPlayer.getPoint() << " out of " << accumulator << ".\n" << endl;
        }
        else
        {
            cout << "Incorrect! The answer was " << (listPtr->retrieve(randNum[i]+1))->getAnswer() << ". You loss "
             << (listPtr->retrieve(randNum[i]+1))->getScore() << " points." << endl;
            accumulator += (listPtr->retrieve(randNum[i]+1))->getScore();
            newPlayer.deductPoint((listPtr->retrieve(randNum[i]+1))->getScore());
            cout << "Your current score is " << newPlayer.getPoint() << " out of " << accumulator << ".\n" << endl;
        }
    }
    double scoreByPercent;
    double castedPoint = static_cast<double>(newPlayer.getPoint());
    scoreByPercent = (castedPoint+accumulator)/(accumulator*2)*100;
    newPlayer.finalDisplay(accumulator,scoreByPercent);
    HighScore *hs = new HighScore(newPlayer.getName(),scoreByPercent);
    hsPtr->insert(hsPtr->getLength()+1,hs);

    ofstream writeToFile;
    writeToFile.open("HighScore.txt",ios::app);

    if(writeToFile.fail())
    {
        cerr << "HighScore.txt opening fail." << endl;
    }
    else
    {
        //keep result into text file
        for (int i=0;i<hsPtr->getLength();i++)
        {
            writeToFile << (hsPtr->retrieve(i+1))->getName() << "|" << (hsPtr->retrieve(i+1))->getScoreByPercent() << "|" << endl;
        }
    }
    writeToFile.close();
    return;
}

void adminInsert(ListInterface<Question*> *listPtr,char *fileName)
{
    ifstream readFromFile;
    readFromFile.open(fileName);
    if(readFromFile.fail())
    {
        //if no file read, return to menu
        cerr << "No input file detected. Please choose \"1.Startup\" at the main menu first." << endl;
        return;
    }
    string reply;
    do
    {
        string questionType;
        cout << "Enter the question type: ";
        cin.ignore(1000,'\n');
        getline(cin,questionType);
        for (unsigned int i=0;i<questionType.size();i++)
        {
            questionType.at(i)=toupper(questionType.at(i)); //convert the answer to lower case
        }
        string statement, answer;
        int score;
        if (questionType=="TF")
        {
            cout << "Enter the new question score: ";
            cin >> score;

            //check input
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cerr << "Input Fail. Enter the new question score: ";
                cin >> score;
            }
            //end check

            cout << "Enter the new question statement: ";
            cin.ignore(1000,'\n');
            getline(cin,statement);
            cout << "Enter the new question answer: ";
            getline(cin,answer);
            for (unsigned int i=0;i<answer.size();i++)
            {
                answer.at(i)=tolower(answer.at(i)); //convert the answer to lower case
            }
            Question *questionTF = new QuestionTF(questionType,statement,answer,score);
            if(listPtr->insert(listPtr->getLength()+1,questionTF))
                cout << "Question of type TF inserted successfully." << endl;
        }
        else if (questionType=="SA")
        {
            cout << "Enter the new question score: ";
            cin >> score;

            //check input
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cerr << "Input Fail. Enter the new question score: ";
                cin >> score;
            }
            //end check

            cout << "Enter the new question statement: ";
            cin.ignore(1000,'\n');
            getline(cin,statement);
            cout << "Enter the new question answer: ";
            getline(cin,answer);
            for (unsigned int i=0;i<answer.size();i++)
            {
                answer.at(i)=tolower(answer.at(i)); //convert the answer to lower case
            }
            Question *questionSA = new QuestionSA(questionType,statement,answer,score);
            if(listPtr->insert(listPtr->getLength()+1,questionSA))
                cout << "Question of type SA inserted successfully." << endl;
        }
        else if (questionType=="MC")
        {
            int numberOfChoice;
            vector<string> choice;
            cout << "Enter the new question score: ";
            cin >> score;

            //check input
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cerr << "Input Fail. Enter the new question score: ";
                cin >> score;
            }
            //end check

            cout << "Enter the new question statement: ";
            cin.ignore(1000,'\n');
            getline(cin,statement);
            cout << "Enter the number of choices: ";
            cin >> numberOfChoice;

            //check input
            while(cin.fail())
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cerr << "Input Fail. Enter the new question choice: ";
                cin >> score;
            }
            //end check

            choice.resize(numberOfChoice);
            char alpha = 'A';
            cin.ignore(1000,'\n');
            for (int i=0;i<numberOfChoice;i++,alpha++)
            {
                cout << "Enter choice " << alpha << ": ";
                getline(cin,choice[i]);
            }
            cout << "Enter the new question answer: ";
            getline(cin,answer);
            for (unsigned int i=0;i<answer.size();i++)
            {
                answer.at(i)=tolower(answer.at(i)); //convert the answer to lower case
            }
            Question *questionMC = new QuestionMC(questionType,statement,answer,score,numberOfChoice,choice);
            if(listPtr->insert(listPtr->getLength()+1,questionMC))
                cout << "Question of type MC inserted successfully." << endl;
        }
        else
        {
            cerr << "Invalid question type. Only type \"TF\", \"MC\" and \"SA\" are allowed." << endl;
        }

        writeQuestionToFile(listPtr,fileName);

        //ask if want to insert new question
        cout << "Do you want to add another question? Enter y(yes) or n(no):";
        cin >> reply;
        for (unsigned int i=0;i<reply.size();i++)
        {
            reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
        }
        while ((reply!="y")&&(reply!="n"))
        {
            cerr << "Invalid choice. Enter y(yes) or n(no) only: ";
            cin >> reply;
            for (unsigned int i=0;i<reply.size();i++)
            {
                reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
            }
        }
        //end ask
    }while (reply=="y");
    return;
}

void adminEdit(ListInterface<Question*> *listPtr,char *fileName)
{
    ifstream readFromFile;
    readFromFile.open(fileName);
    if(readFromFile.fail())
    {
        //if no file read, return to menu
        cerr << "No input file detected. Please choose \"1.Startup\" at the main menu first." << endl;
        return;
    }
    else
    {
        string line, search;
        vector<int> numberFound;
        int counter=0;
        cout << "Please enter the term to search: ";
        cin.ignore(1000,'\n');
        getline(cin,search);

        //search for keyword inside the question list
        while(counter<listPtr->getLength())
        {
            if(((listPtr->retrieve(counter+1))->getQuestion()).find(search)!=string::npos)
            {
                numberFound.push_back(counter+1);
            }
            counter++;
        }
        //end search

        //display question with the particular keyword
        for (unsigned int i=0;i<numberFound.size();i++)
        {
            cout << "\nQuestion " << numberFound[i] << " : "
                 << (listPtr->retrieve(numberFound[i]))->getQuestion() << endl;
            cout << "Type: " << (listPtr->retrieve(numberFound[i]))->getType() << endl;
            cout << "Answer: " << (listPtr->retrieve(numberFound[i]))->getAnswer() << endl;
            cout << "Score: " << (listPtr->retrieve(numberFound[i]))->getScore() << endl;
        }
        //end display
        int questionToEdit;
        bool done = false;
        bool found = false;
        do
        {
            cout << "\nWhich question would you like to edit? ";
            cin >> questionToEdit;
            //check input
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(1000,'\n');
                cerr << "Invalid input." << endl;
                cout << "Which question would you like to edit?";
                cin >> questionToEdit;
            }
            //end check

            //check if number chosen is same to question number display
            for(unsigned int i=0;i<numberFound.size();i++)
            {
                if (questionToEdit==numberFound[i])
                {
                    found = true;
                    break;
                }
            }
            if (found)
            {
                done = true;
            }
            else
            {
                //if number chose not matched, ask to choose again
                cout << "Invalid question to edit.\nChoose ";
                for(unsigned int i=0;i<numberFound.size();i++)
                {
                    cout << "\"" << numberFound[i] << "\" ";
                }
                cout << "only.";
            }
        } while(!done);

        string cont;
        cout << "\nWarning** You will need to edit all information of the question." << endl;
        cout << "Do you still want to edit?" << endl;
        cin >> cont;
        for (unsigned int i=0;i<cont.size();i++)
        {
            cont.at(i)=tolower(cont.at(i)); //convert the answer to lower case
        }
        while ((cont!="y")&&(cont!="n"))
        {
            cerr << "Invalid choice. Enter y(yes) or n(no) only: ";
            cin >> cont;
            for (unsigned int i=0;i<cont.size();i++)
            {
                cont.at(i)=tolower(cont.at(i)); //convert the answer to lower case
            }
        }
        //if user want to edit all
        if (cont=="y")
        {
            string statement, answer;
            int score;
            string type = (listPtr->retrieve(questionToEdit))->getType();
            if (type=="MC")
            {
                int numberOfChoice;
                vector<string> choice;
                cout << "Enter the new question score: ";
                cin >> score;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cerr << "Input Fail. Enter the new question score: ";
                    cin >> score;
                }
                cout << "Enter the new question statement: ";
                cin.ignore(1000,'\n');
                getline(cin,statement);
                cout << "Enter the number of choices: ";
                cin >> numberOfChoice;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cerr << "Input Fail. Enter the new question choice: ";
                    cin >> score;
                }
                choice.resize(numberOfChoice);
                char alpha = 'A';
                cin.ignore(1000,'\n');
                for (int i=0;i<numberOfChoice;i++,alpha++)
                {
                    cout << "Enter choice " << alpha << ": ";
                    getline(cin,choice[i]);
                }
                cout << "Enter the new question answer: ";
                getline(cin,answer);
                for (unsigned int i=0;i<answer.size();i++)
                {
                    answer.at(i)=tolower(answer.at(i)); //convert the answer to lower case
                }
                Question *questionMC = new QuestionMC(type,statement,answer,score,numberOfChoice,choice);
                listPtr->setEntry(questionToEdit,questionMC);
            }
            if (type=="TF")
            {
                cout << "Enter the new question score: ";
                cin >> score;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cerr << "Input Fail. Enter the new question score: ";
                    cin >> score;
                }
                cout << "Enter the new question statement: ";
                cin.ignore(1000,'\n');
                getline(cin,statement);
                cout << "Enter the new question answer: ";
                getline(cin,answer);
                for (unsigned int i=0;i<answer.size();i++)
                {
                    answer.at(i)=tolower(answer.at(i)); //convert the answer to lower case
                }
                Question *questionTF = new QuestionTF(type,statement,answer,score);
                listPtr->setEntry(questionToEdit,questionTF);
            }
            if (type=="SA")
            {
                cout << "Enter the new question score: ";
                cin >> score;
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000,'\n');
                    cerr << "Input Fail. Enter the new question score: ";
                    cin >> score;
                }
                cout << "Enter the new question statement: ";
                cin.ignore(1000,'\n');
                getline(cin,statement);
                cout << "Enter the new question answer: ";
                getline(cin,answer);
                for (unsigned int i=0;i<answer.size();i++)
                {
                    answer.at(i)=tolower(answer.at(i)); //convert the answer to lower case
                }
                Question *questionSA = new QuestionSA(type,statement,answer,score);
                listPtr->setEntry(questionToEdit,questionSA);
            }
        }
        //if user don't want to edit
        else
        {
            cout << "This question is not edited." << endl;
        }
    }
    writeQuestionToFile(listPtr,fileName);

    readFromFile.close();
    return;
}

void adminDelete(ListInterface<Question*> *listPtr,char *fileName)
{
    ifstream readFromFile;
    readFromFile.open(fileName);
    if(readFromFile.fail())
    {
        //if no file read, return to menu
        cerr << "No input file detected. Please choose \"1.Startup\" at the main menu first." << endl;
        return;
    }
    string reply;
    do
    {
        int questionToDelete;
        for (int i=0;i<listPtr->getLength();i++)
        {
            cout << "Question " << i+1 << ": " << endl;
            cout << "Statement-> " << (listPtr->retrieve(i+1))->getQuestion() << "(Type: " << (listPtr->retrieve(i+1))->getType() << ")" << endl;
            cout << "Score-> " << (listPtr->retrieve(i+1))->getScore() << endl;
            cout << "Answer-> " << (listPtr->retrieve(i+1))->getAnswer() << endl;
        }
        cout << "\nWhich question do you want to delete?";
        cin >> questionToDelete;
        if (listPtr->erase(questionToDelete))
            cout << "Question " << questionToDelete << " deleted successfully." << endl;

        writeQuestionToFile(listPtr,fileName);

        //ask if user want to delete other question
        cout << "Do you want to delete another question? Enter y(yes) or n(no):";
        cin >> reply;
        for (unsigned int i=0;i<reply.size();i++)
        {
            reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
        }
        while ((reply!="y")&&(reply!="n"))
        {
            cerr << "Invalid choice. Enter y(yes) or n(no) only: ";
            cin >> reply;
            for (unsigned int i=0;i<reply.size();i++)
            {
                reply.at(i)=tolower(reply.at(i)); //convert the answer to lower case
            }
        }
        //end ask
    }while (reply=="y");
    return;
}

void adminViewAll(ListInterface<Question*> *listPtr)
{
    for (int i=0;i<listPtr->getLength();i++)
    {
        if ((listPtr->retrieve(i+1))->getType()=="MC")
        {
            cout << "Question " << i+1 << ": " << endl;
            cout << "Statement-> " << (listPtr->retrieve(i+1))->getQuestion() << endl;
            cout << "Score-> " << (listPtr->retrieve(i+1))->getScore() << endl;
            char alpha = 'A';
            QuestionMC *copyMC = (QuestionMC *)(listPtr->retrieve(i+1)); //question*
            vector<string> choice = copyMC->getChoice();
            for (unsigned int j=0;j<choice.size();j++,alpha++)
            {
                cout << "Choice " << alpha << " -> " << choice[j] << endl;
            }
            cout << "Answer-> " << (listPtr->retrieve(i+1))->getAnswer() << endl << endl;;
        }
        else
        {
            cout << "Question " << i+1 << ": " << endl;
            cout << "Statement-> " << (listPtr->retrieve(i+1))->getQuestion() << endl;
            cout << "Score-> " << (listPtr->retrieve(i+1))->getScore() << endl;
            cout << "Answer-> " << (listPtr->retrieve(i+1))->getAnswer() << endl << endl;
        }
    }
    return;
}

void adminRandomize(ListInterface<Question*> *listPtr,char *fileName)
{
    ifstream readFromFile;
    readFromFile.open(fileName);
    if(readFromFile.fail())
    {
        //if no file is read, return to menu
        cerr << "No input file detected. Please choose \"1.Startup\" at the main menu first." << endl;
        return;
    }
    cout << "Before randomize: " << endl;
    adminViewAll(listPtr);
    system("pause");
    cout << "After randomize:" << endl;
    listPtr->randomize();
    adminViewAll(listPtr);
    return;
}

void writeQuestionToFile(ListInterface<Question*> *listPtr,char *fileName)
{
    ofstream writeToFile;
    writeToFile.open(fileName,ios::trunc);
    if (writeToFile.is_open())
    {
        writeToFile << listPtr->getLength();
        for (int i=0;i<listPtr->getLength();i++)
        {
            if ((listPtr->retrieve(i+1))->getType()=="MC")
            {
                QuestionMC *copyMC = (QuestionMC *)(listPtr->retrieve(i+1));
                writeToFile << endl << copyMC->getType() << " " << copyMC->getScore() << endl;
                writeToFile << copyMC->getQuestion() << endl;
                writeToFile << copyMC->getNumOfChoice() << endl;
                vector<string> choice = copyMC->getChoice();
                for (unsigned int i=0;i<choice.size();i++)
                {
                    writeToFile << choice[i] << endl;
                }
                writeToFile << copyMC->getAnswer();
            }
            else
            {
                writeToFile << endl << (listPtr->retrieve(i+1))->getType() << " " << (listPtr->retrieve(i+1))->getScore() << endl;
                writeToFile << (listPtr->retrieve(i+1))->getQuestion() << endl;
                writeToFile << (listPtr->retrieve(i+1))->getAnswer();
            }
        }
    }
    else
    {
        cerr << "Output file opening failed." << endl;
    }
    writeToFile.close();
    return;
}

void viewLeaderboard(ListInterface<HighScore*> *hsPtr)
{
    LList<HighScore> hsDisplay;
    string line;
    double scoreByPercentage;

    ifstream readFromFile;

    readFromFile.open("HighScore.txt");
    if(readFromFile.fail())
    {
        cerr << "HighScore.txt opening fail." << endl;
    }
    else
    {
        HighScore hs;
        while(getline(readFromFile,line)&&(*line.c_str()!='\0'))
        {
            string delimiter = "|";
            size_t pos = 0;
            string *temp = new string[2];
            int counter = 0;
            while((pos = line.find(delimiter))!=string::npos)
            {
                if (counter==0)
                {
                    temp[counter] = line.substr(0,pos);
                    hs.setName(temp[counter]);
                    line.erase(0,pos+1);
                }
                if (counter==1)
                {
                    temp[counter] = line.substr(0,pos);
                    scoreByPercentage = atof(temp[counter].c_str());
                    hs.setScoreByPercent(scoreByPercentage);
                    line.erase(0,pos+1);
                }
                counter++;
            }
            hsDisplay.sortedInsertDesc(hs);
        }
        readFromFile.close();
    }

    cout << "***************************************" << endl;
    cout << "*             Leaderboard             *" << endl;
    cout << "***************************************\n" << endl;
    cout << "Ranking  Name                  Score(%)" << endl;
    cout << "-------  --------------------  --------" << endl;
    for (int i=0;i<hsDisplay.getLength();i++)
    {
        //display 10 records
        if(i<10)
        {
            cout << setw(7) << i+1 << setw(22) << (hsDisplay.retrieve(i+1)).getName() << setw(10)
                 << fixed << setprecision(2) << (hsDisplay.retrieve(i+1)).getScoreByPercent() << endl;
        }
    }
    return;
}

void readGuide(const string type)
{
    if (type=="M")
    {
        ifstream readMenuGuide;
        readMenuGuide.open("MenuGuide.txt");
        if(readMenuGuide.fail())
        {
            cout << "Input file opening fail." << endl;
            return;
        }
        else
        {
            cin.ignore(1000,'\n');
            string next;
            while(!readMenuGuide.eof())
            {
                getline(readMenuGuide,next);
                cout << next << endl;
            }
        }
        readMenuGuide.close();
    }
    if (type=="A")
    {
        ifstream readAdminGuide;
        readAdminGuide.open("AdminGuide.txt");
        if(readAdminGuide.fail())
        {
            cout << "Input file opening fail." << endl;
            return;
        }
        else
        {
            cin.ignore(1000,'\n');
            string next;
            while(!readAdminGuide.eof())
            {
                getline(readAdminGuide,next);
                cout << next << endl;
            }
        }
        readAdminGuide.close();
    }
}
