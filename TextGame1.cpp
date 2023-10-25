//File: Final.cpp
//Name: Uriah Foley & Brian Morales
//Date: 05/09/2022
//Course: CompSci 1
//Description: This program is a mystery game. User tries to solve a murder case
//Usage: This game is text based. It will display text describing what is happpening and when 
//The user can make a choice a numbered list will appear. To select a choice you input the 
//corresponding number.


#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

class MainGame {
public:

protected:

};

class StartingRoom : public MainGame { //Outputs choices while in starting room
public:
    int RoomChoices(int& locationTracker, string& choice, int& turnsLeft) {
        cout << "\nWhat will you do now?\n";
        cout << "1. Check the computer\n";
        cout << "2. Look out the window\n";
        cout << "3. Check the pictures\n";
        cout << "9. Go outside\n";
        cin >> choice;
        while (choice != "1" && choice != "2" && choice != "3" && choice != "9") {
            cout << "Invalid input. Enter a number";
            cin >> choice;
        }
        if (choice == "9") {
            locationTracker++;
            turnsLeft--;
        }
        return locationTracker;
    };
};
class OutsideRoom : public MainGame { //outputs choices while just outside the starting room
public:
    int OutsideChoices(int& locationTracker, string& choice, int& turnsLeft) {
        Sleep(2000);
        cout << "You are now just outside the room.\n";
        Sleep(2000);
        cout << "What will you do?\n";
        cout << "1. Look around\n";
        cout << "9. Keep walking down the path\n";
        cout << "0. Go back inside the room\n";

        cin >> choice;
        if (choice == "9") {
            locationTracker++;
            turnsLeft--;
        }
        else if (choice == "0") {
            locationTracker--;
            turnsLeft--;
        }
        else if (choice == "1") {
            OutsideView();
        }
        return locationTracker;
    };
    int TrueOutsideChoices(int& locationTracker, string& choice, int& turnsLeft, vector<string>& clueVec) { //used if a condition is met
        Sleep(1000);
        cout << "You are now just outside the room.\n";
        Sleep(1000);
        cout << "What will you do?\n";
        cout << "1. Look around\n";
        cout << "2. Check around the tree for clues\n";
        cout << "9. Keep walking down the path\n";
        cout << "0. Go back inside the room\n";

        cin >> choice;
        if (choice == "9") {
            locationTracker++;
            turnsLeft--;
        }
        else if (choice == "0") {
            locationTracker--;
            turnsLeft--;
        }
        else if (choice == "1") {
            OutsideView();
            Sleep(2000);
            cout << "However this time you notice something strange about the tall tree.\n";
        }
        else if (choice == "2") {
            Sleep(2000);
            cout << "Looking closer at the tall tree you notice something.\n";
            Sleep(2000);
            cout << "Hidden under a pile of leaves you see a purple object.\n";
            Sleep(2000);
            cout << "You uncover the object to find a purple baseball bat partially covered in blood.\n";
            Sleep(2000);
            cout << "Examining the bat you also see it has a yellow 'L' on the barrel.\n\n";
            clueVec.at(0) = "Purple bat with a yellow 'L' on the barrel";
        }
        return locationTracker;
    };
    void OutsideView() { //shows you what is outside
        cout << "      ^\n";
        cout << "     ^^^\n";
        cout << "    ^^^^^\n";
        cout << "   ^^^^^^^             *\n";
        cout << "  ^^^^^^^^^           ***\n";
        cout << " ^^^^^^^^^^^  / |    *****\n";
        cout << "     |W|     /  |     | |\n";
        cout << "   ~~~~~~   /   |     ~~~\n";
        Sleep(1000);
        cout << "You see a dense forest, and a dirt path ahead of you\n\n";
    }
};

class GameStart {
public:
    void StartGame();
    string MakeChoice();
private:
    int choice;
    int location;
};

void GameStart::StartGame() { //Beggining of the game. 
    string firstChoice;
    cout << "You are asleep... You can faintly hear the sound of someone saying 'hello?'...\n";
    Sleep(3000);
    cout << "'Is anyone there?'...'We are sending an officer to your location.'\n";
    Sleep(3000);
    cout << "Suddenly you wake up. You're lying on the floor of a room you've never seen before.\n";
    Sleep(3000);
    cout << "Looking around you see a person lying on the floor next to you with a telephone in their hand\n";
    Sleep(3000);
    cout << "That voice you heard wasn't a dream.\n\n";
    Sleep(3000);
    cout << "What will you do? Input a number for your choice\n";
    cout << "1. Check to see if the person is okay\n";
    cin >> firstChoice;

    while (firstChoice != "1") {
        cout << "Invalid input. Enter a number.\n";
        cin >> firstChoice;
    }
    Sleep(2000);
    cout << "You try to shake them awake but they are completely limp...\n";
    Sleep(3000);
    cout << "You notice that they aren't breathing and there is a small pool of blood under their head.\n";
    Sleep(3000);
}
string GameStart::MakeChoice() {
    string choice;
    cout << "What will you do now?\n";
    Sleep(1000);
    cout << "1. Look around the room\n";
    cout << "2. Check the body for clues\n";
    cin >> choice;
    while (choice != "1" && choice != "2") {
        cout << "Invalid input. Enter a number.\n";
        cin >> choice;
    }
    if (choice == "1") {
        Sleep(1000);
        cout << "Looking around you see a computer monitor that is turned on.\n";
        Sleep(3000);
        cout << "You also see pictures on the wall of a man with a red hat and a woman wearing a pink dress.\n";
        Sleep(3000);
        cout << "You notice there is one door leading outside as well as a closed window.\n";
        Sleep(3000);
        cout << "\n1. Check the body for clues?\n";
        cin >> choice;
        while (choice != "1") {
            "Invalid input. Enter a number.\n";
            cin >> choice;
        }
        if (choice == "1") {
            Sleep(1000);
            cout << "Looking at the man you see that he is wearing blue overalls with a red shirt and hat.\n";
            Sleep(3000);
            cout << "You can see the letter 'M' on the front of his hat.\n";
            Sleep(3000);
            cout << "He appears to have been struck in the head by something.";
        }
    }
    else if (choice == "2") {
        cout << "Looking at the man you see that he is wearing blue overalls with a red shirt and hat.\n";
        Sleep(3000);
        cout << "You can see the letter 'M' on the front of his hat.\n";
        Sleep(3000);
        cout << "He appears to have been struck in the head by something.\n";
        Sleep(3000);
        cout << "\n1. Look around the room?\n";
        cin >> choice;
        while (choice != "1") {
            "Invalid input. Enter a number.\n";
        }
        if (choice == "1") {
            cout << "Looking around you see a computer monitor that is turned on.\n";
            Sleep(3000);
            cout << "You also see pictures on the wall of a man with a red hat and a woman wearing a pink dress.\n";
            Sleep(3000);
            cout << "You notice there is one door leading outside as well as a closed window.\n";
            Sleep(3000);
        }

    }


    return choice;
}

class BeginningRoom { //class for the three viewable objects in the first room.
public:
    string ComputerScreen(vector<string>& clueVec);
    void Window();
    void Pictures();
private:
    string password;
};

string BeginningRoom::ComputerScreen(vector<string>& clueVec) { //user guesses the password
    string password;
    int attempts = 0;

    cout << " ______________________________" << endl;

    for (int i = 0; i < 10; i++) {

        cout << "|                              |" << endl;
        if (i == 4) {
            cout << "|       Enter Password:        |" << endl;
        }
        else if (i == 5) {
            cout << "|          _ _ _ _ _           |" << endl;
        }
    }
    cout << " ______________________________" << endl;

    cin >> password;
    Sleep(2000);

    while (password != "Mario" && password != "mario" && attempts != 2) {
        cout << " ______________________________" << endl;

        for (int i = 0; i < 10; i++) {

            cout << "|                              |" << endl;
            if (i == 3) {
                cout << "|       INCORRECT ENTRY        |" << endl;
            }
            if (i == 4) {
                cout << "|       Enter Password:        |" << endl;
            }
            else if (i == 5) {
                cout << "|          _ _ _ _ _           |" << endl;
            }
        }
        cout << " ______________________________" << endl;

        attempts++;
        cin >> password;
        Sleep(2000);

        if (attempts == 2) {
            cout << " ______________________________" << endl;

            for (int i = 0; i < 10; i++) {

                cout << "|                              |" << endl;
                if (i == 3) {
                    cout << "|         ACCESS DENIED        |" << endl;
                }
            }
            cout << " ______________________________" << endl;
        }

    }
    if (password == "Mario" || password == "mario") {
        cout << " ______________________________" << endl;

        for (int i = 0; i < 10; i++) {

            cout << "|                              |" << endl;
            if (i == 3) {
                cout << "|       ACCESS Granted         |" << endl;
            }
        }
        cout << " ______________________________" << endl;
        Sleep(2000);
        cout << "\nThere is one icon on the screen. It is a notepad. You open it" << endl;
        Sleep(2000);
        cout << "The notepad reads: If anyone finds this, know that Wa" << endl;
        Sleep(2000);
        cout << "\n Looks like he didnt get a chance to finish his thought.." << endl;
        clueVec.at(1) = "The dead man said 'know that Wa'.. might mean something";
    }

    return password;
}
void BeginningRoom::Window() { // shows you whats outside the window
    cout << "==================" << endl;
    cout << "||       || ~~~ ||" << endl;
    cout << "||   ^   ||  ~~ ||" << endl;
    cout << "==================" << endl;
    cout << "||  ^^^  ||     ||" << endl;
    cout << "|| ^^^^^ ||     ||" << endl;
    cout << "||^^^^^^^||    *||" << endl;
    cout << "||  |W|  ||   **||" << endl;
    cout << "==================" << endl;
    Sleep(1000);
    cout << "\nYou see a forest and some clouds in the sky.\n";
    Sleep(1000);
    cout << "You also notice a path leading further into the forest.\n";
}
void BeginningRoom::Pictures() { //awesome picture 
    cout << "__________________" << endl;
    cout << "|  o   o   o   o |" << endl;
    cout << "|    ^       >   |" << endl;
    cout << "|  ~~~~~   ----- |" << endl;
    cout << "|________________|" << endl;

    Sleep(1000);
    cout << "\nYou see a beautiful picture of the deceased man and a woman with blonde hair and a pink dress.\n";

}

class Fork { //branching decision left or right path
public:
    int ChoosePath(int& locationTracker, string& choice, int& turnsLeft);

};

int Fork::ChoosePath(int& locationTracker, string& choice, int& turnsLeft) { //choosing which path to take
    Sleep(2000);
    cout << "You have come to a fork in the road, what would you like to do?\n";
    cout << "1. Walk down the left path.\n";
    cout << "2. Walk down the right path.\n";
    cout << "3. Walk back to towards the room.\n";

    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3") {
        cout << "Invalid input. Enter a number.\n";
        cin >> choice;
    }
    if (choice == "1") {
        locationTracker++;
        turnsLeft--;
    }
    else if (choice == "2") {
        locationTracker = locationTracker + 2;
        turnsLeft--;
    }
    else if (choice == "3") {
        locationTracker--;
        turnsLeft--;
    }
    return locationTracker;
}
class LeftPath { //left path has an npc 
public:
    int LeftGuide(int& locationTracker, string& choice, int& turnsLeft, bool& treeClue1, bool& personClue1, vector<string>& clueVec);
};

int LeftPath::LeftGuide(int& locationTracker, string& choice, int& turnsLeft, bool& treeClue1, bool& personClue1, vector<string>& clueVec) { //the left path//
    if (personClue1) { //if you've already spoken w/ the npc and gotten all the clues he is no longer there. 
        cout << "You walk down the left path..\n";
        cout << "However, the man who was once sitting along the road is nowhere to be found..\n";
        locationTracker--;
        turnsLeft--;
    }
    else if (personClue1 == false) {
        Sleep(1000);
        cout << "You walk down the left path and come upon a man sitting on the side of the road.\n";
        Sleep(2000);
        cout << "You ask the man if he has seen anyone pass by.\n";
        Sleep(2000);
        cout << "He responds: I will help you if you can answer this riddle..";
        Sleep(2000);
        cout << "What is green, but is related to red?\n";    //riddle
        cout << "_ _ _ _ _\n";
        int attempts = 0;
        string riddleAnswer;
        cin >> riddleAnswer;
        attempts++;
        bool treeClue = false;
        bool personClue = false;
        personClue1 = personClue;
        treeClue1 = treeClue;

        while (treeClue == false) {  //answer
            if (riddleAnswer == "Luigi" || riddleAnswer == "luigi") {
                Sleep(2000);
                cout << "You are correct.\n";
                treeClue1 = true;
                clueVec.at(2) = "The answer to that riddle was 'Luigi'";
                Sleep(2000);
                cout << "For your first clue. Did you look carefully at the tree?\n"; //clue one
                Sleep(2000);
                cout << "There is something off about this tree. You should take a closer look.\n";
                cout << "==================" << endl;
                cout << "||       || ~~~ ||" << endl;
                cout << "||   ^   ||  ~~ ||" << endl;
                cout << "==================" << endl;
                cout << "||  ^^^  ||     ||" << endl;
                cout << "|| ^^^^^ ||     ||" << endl;
                cout << "||^^^^^^^||    *||" << endl;
                cout << "||  | |  ||   **||" << endl;
                cout << "==================" << endl;
                Sleep(2000);
                cout << "There is another bit of information I can give you if you like.\n";
                Sleep(2000);
                cout << "1. Hear what he has to say.\n";
                cout << "2. Leave for now.\n";
                string answer;

                cin >> choice;
                while (choice != "1" && choice != "2") {//answer
                    cout << "Invalid input. Enter a number.\n";
                    cin >> choice;

                }
                if (choice == "1") {
                    Sleep(2000);
                    cout << "Earlier I noticed a person running around frantically.\n";
                    Sleep(2000);
                    cout << "Perhaps you could try finding him.\n";
                    Sleep(2000);
                    personClue1 = true;
                    cout << "That's all the information I can give you. I hope you find it useful.\n\n";
                    Sleep(2000);
                    cout << "You walk back to the fork in the road\n";
                    Sleep(2000);
                    locationTracker--;
                    turnsLeft--;
                    break;
                    //send back to the fork
                }
                else if (choice == "2") {
                    Sleep(2000);
                    cout << "Goodbye. Hope I was of help.\n";
                    Sleep(2000);
                    cout << "You walk back to the fork in the road\n";
                    locationTracker--;
                    turnsLeft--;
                    break;
                    //send back to the fork
                }

            }
            else {
                cout << "That isn't correct. Take another guess.\n";
                cin >> riddleAnswer;
                attempts++;
                if (attempts == 3) {
                    cout << "No that isn't the correct answer.\n";
                    cout << "Maybe you should come back later.\n";
                    locationTracker--;
                    turnsLeft--;
                    break;
                }
            }
        }


    }




    return locationTracker;
}


class RightPath { //104 The right path.
public:
    int TrueRight(int& locationTracker, string& choice, int& turnsLeft, vector<string>& clueVec);
    int FalseRight(int& locationTracker, string& choice, int& turnsLeft);
};
int RightPath::TrueRight(int& locationTracker, string& choice, int& turnsLeft, vector<string>& clueVec) { //displayed if you got the clue from npc
    cout << "You walk down the right path.\n";
    Sleep(3000);
    cout << "You continue walking and you see a large sewer pipe just 100 feet off the path.\n";
    cout << "1. Enter the sewer?\n";
    cout << "0. Turn back\n";
    cin >> choice;
    while (choice != "1" && choice != "0") {
        cout << "Invalid input. Enter a number.";
    }
    if (choice == "1") {
        //EndGame(turnsLeft, choice, clueVec);
        turnsLeft--;
        locationTracker++;
    }
    else if (choice == "0") {
        locationTracker = locationTracker - 2;
        turnsLeft--;
    }
    return locationTracker;
}
int RightPath::FalseRight(int& locationTracker, string& choice, int& turnsLeft) { //displayed if you dont have the clue from npc
    cout << "You walk down the right path.\n";
    Sleep(1000);
    for (int i = 0; i < 3; i++) {
        cout << ".\n";
        Sleep(2000);
    }
    cout << "You continue walking..\n";
    Sleep(4000);
    cout << "You don't notice anything. You decide to turn back.\n";
    locationTracker = locationTracker - 2;
    turnsLeft--;
    return locationTracker;
}
class Sewer { //105 path to Lakitu bros. 
public:
    int EndGame(int& locationTracker, int& turnsLeft, string& choice, vector<string>& clueVec, bool& cameraEvidence);
};
int Sewer::EndGame(int& locationTracker, int& turnsLeft, string& choice, vector<string>& clueVec, bool& cameraEvidence) { //Lakitu bros interaction
    string attackerName;
    cameraEvidence = true;
    cout << "You enter the sewer and find a man cowering on the ground holding a video camera.\n";
    Sleep(2000);
    cout << "You ask him if he's okay\n";
    Sleep(2000);
    cout << "He responds: I can't believe he is dead.\n";
    Sleep(2000);
    cout << "You ask him what he saw.\n";
    Sleep(2000);
    cout << "'I saw everything. I have it on my camera as well.'\n";
    Sleep(2000);
    cout << "You ask if he knows the attacker.\n";
    Sleep(2000);
    cout << "'No I'm not sure who it was'\n";
    Sleep(2000);
    cout << "You ask if you can see the recording, and he agrees.\n";
    Sleep(2000);
    cout << "Watching the video you see the attacker is a man in a purple shirt and with a purple hat\n";
    cout << "you also notice he has a strange thin moustache.\n";
    clueVec.at(3) = "Recording with man wearing purple clothes and a purple hat";
    Sleep(5000);
    cout << "The man asks if you know who the attacker is\n";
    Sleep(2000);
    cout << "Enter the name of the attacker _ _ _ _ _ _ _\n";
    cin >> attackerName;
    int attempts = 0;
    while (attackerName != "Waluigi" && attackerName != "waluigi" && attempts < 3) {
        turnsLeft--;
        Sleep(2000);
        cout << "The man says 'hmm.. I don't think that's quite right\n";
        attempts--;
        Sleep(2000);
        cout << "1. Take another guess?\n";
        cout << "2. Take a look at your evidence.\n";
        cin >> choice;
        while (choice != "1" && choice != "2") {
            cout << "Invalid input. Enter a number.\n";
            cin >> choice;
        }
        if (choice == "1") {
            cout << "Enter the name of the attacker _ _ _ _ _ _ _\n";
            cin >> attackerName;
            attempts++;
        }
        else {
            for (int i = 0; i < 4; i++) {
                cout << clueVec.at(i) << endl;
            }
            cout << "'Any idea who it was?'";
            cout << "Enter the name of the attacker _ _ _ _ _ _ _\n";
            cin >> attackerName;
            attempts++;
        }
    }
    if (attackerName == "Waluigi" || attackerName == "waluigi") {
        Sleep(2000);
        cout << "'HEY, I think you are right!!\n";
        Sleep(2000);
        cout << "'uh-oh looks like the cops are coming you better tell them what you told me!\n";
        turnsLeft = 0;
    }
    if (attempts == 3) {
        locationTracker--;
        turnsLeft--;
    }
    return locationTracker;
}

class Cops {
public:
    void CopsArrive(string& choice, int& turnsLeft, bool& cameraEvidence, vector<string>& clueVec);
    void PrisonBars();
private:
    string attacker;
};
void Cops::PrisonBars() {
    cout << "================\n";
    for (int i = 0; i < 5; i++) {
        cout << "||   ||   ||  ||\n";
    }
    cout << "================\n";
}
void Cops::CopsArrive(string& choice, int& turnsLeft, bool& cameraEvidence, vector<string>& clueVec) {
    ofstream file;
    ifstream ifile("suspect.txt");
    vector<string> names;
    file.open("suspect.txt");
    file << "1.Wario\n" << "2.Bowser\n" << "3.Luigi\n" << "4.DonkeyKong\n" << "5.Waluigi\n" << "6.Toad";
    file.close();


    Sleep(2000);
    cout << "Police officers arrive on the scene.\n";
    Sleep(2000);
    cout << "'Look, we know that you were present during the attack.'\n";
    Sleep(2000);
    cout << "'Unless you can show us evidence proving your innocence we are bringing you in'\n";
    Sleep(2000);
    cout << "1. Comply\n";
    cout << "2. Run\n";
    cin >> choice;
    while (choice != "1" && choice != "2") {
        cout << "Invalid input. Enter a number.\n";
        cin >> choice;
    }
    if (choice == "1") {
        if (cameraEvidence) {
            Sleep(2000);
            cout << "You show the officers the recording.\n";
            Sleep(2000);
            cout << "'Well this proves you weren't the attacker..'\n";
            Sleep(2000);
            cout << "'Do you have any idea who the man in the video is?'\n";
            Sleep(2000);
            cout << "'Here is a list of our current suspects'\n";
            if (ifile.is_open()) {
                string input;
                while (ifile >> input) {
                    names.push_back(input);
                }
                for (int i = 0; i < 6; i++) {
                    cout << names.at(i) << endl;
                }
            }
            else {
                Sleep(2000);
                cout << "'Wait...'\n";
                Sleep(2000);
                cout << "'I know I put that list somewhere..'\n";
                Sleep(2000);
                cout << "'I must've lost it.. Sorry about that.'\n";
            }
            Sleep(2000);
            cout << "\n1. Tell them who the attacker was.\n";
            cout << "2. Review your evidence.\n";
            cin >> choice;
            while (choice != "1" && choice != "2") {
                cout << "Invalid input. Enter a number.\n";
                cin >> choice;
            }
            if (choice == "1") {
                cout << "Enter the name of the attacker: ";
                cin >> attacker;
                if (attacker == "Waluigi" || attacker == "waluigi") {
                    Sleep(2000);
                    cout << "'Okay we will begin our search for " << attacker << " thank you for your cooperation.\n";
                    Sleep(3000);
                    cout << "\n\nCONGRATULATIONS!!!\n";
                    cout << "You solved the case and helped put Waluigi behind bars for good.\n";
                }
            }
            else if (choice == "2") {
                for (int i = 0; i <= 3; i++) {
                    cout << clueVec.at(i) << endl;
                }
                Sleep(2000);
                cout << "'Okay, who do you think the attacker was?'\n";
                Sleep(2000);
                cout << "Enter the name of the attacker: ";
                cin >> attacker;
                if (attacker == "Waluigi" || attacker == "waluigi") {
                    Sleep(2000);
                    cout << "'Okay we will begin our search for " << attacker << " thank you for your cooperation.\n";
                    Sleep(3000);
                    cout << "\n\nCONGRATULATIONS!\n";
                    cout << "You solved the case and helped put Waluigi behind bars for good.\n";
                }
                else {
                    Sleep(2000);
                    cout << "'Okay we will begin our search for " << attacker << " thank you for your cooperation.'\n";
                    Sleep(2000);
                    cout << "\n\nGAME OVER.\n";
                    Sleep(3000);
                    cout << "You failed to discover the real attacker\n";
                    cout << "and an innocent man has been taken to prison\n";
                }
            }

            else {
                Sleep(2000);
                cout << "'Okay we will begin our search for " << attacker << " thank you for your cooperation.'\n";
                Sleep(2000);
                cout << "\n\nGAME OVER.\n";
                Sleep(3000);
                cout << "You failed to discover the real attacker\n";
                cout << "and an innocent man has been taken to prison\n";
            }
        }
        else {
            Sleep(2000);
            cout << "'Looks like you don't have an alibi'\n";
            Sleep(2000);
            cout << "'We're bringing you in'\n";
            Sleep(2000);
            cout << "\n\nGAME OVER.\n";
            Sleep(3000);
            cout << "You didn't find enough evidence.\n";
            cout << "And you have been thrown in prison.\n";
            PrisonBars();

        }
    }
    else if (choice == "2") {
        Sleep(2000);
        cout << "You attempt to run.\n";
        for (int i = 0; i < 3; i++) {
            cout << ".\n";
            Sleep(2000);
        }
        cout << "You only make it a short distance before being tackled and cuffed.\n";
        Sleep(2000);
        cout << "\n\nGAME OVER.\n";
        Sleep(2000);
        cout << "You've been thrown in prison.\n";
        PrisonBars();
    }
}

int main()
{
    string choice;
    int locationTracker = 100;
    int turnsLeft = 14;
    bool treeClue1 = false;
    bool personClue1 = false;
    bool cameraEvidence = false;
    vector<string> clueVec(4);
    string password;

    BeginningRoom room;

    StartingRoom SRoom;

    OutsideRoom OutRoom;

    Fork fork;

    LeftPath left;

    RightPath right;

    Sewer sewer;

    Cops cops;

    GameStart game;

    game.StartGame();
    game.MakeChoice();

    while (turnsLeft != 0) {
        while (locationTracker == 100 && turnsLeft != 0) {
            locationTracker = SRoom.RoomChoices(locationTracker, choice, turnsLeft);

            if (choice == "1") {
                password = room.ComputerScreen(clueVec);

            }
            else if (choice == "2") {
                room.Window();
            }
            else if (choice == "3") {
                room.Pictures();
            }
            while (locationTracker == 101 && turnsLeft != 0) {
                if (treeClue1)
                {
                    locationTracker = OutRoom.TrueOutsideChoices(locationTracker, choice, turnsLeft, clueVec);
                }
                else {
                    locationTracker = OutRoom.OutsideChoices(locationTracker, choice, turnsLeft);
                }

                while (locationTracker == 102 && turnsLeft != 0) {
                    locationTracker = fork.ChoosePath(locationTracker, choice, turnsLeft);
                    while (locationTracker == 103 && turnsLeft != 0) {
                        locationTracker = left.LeftGuide(locationTracker, choice, turnsLeft, treeClue1, personClue1, clueVec);
                    }
                    while (locationTracker == 104 && turnsLeft > 0) {
                        if (personClue1) {
                            right.TrueRight(locationTracker, choice, turnsLeft, clueVec);
                        }
                        else {
                            right.FalseRight(locationTracker, choice, turnsLeft);
                        }
                        while (locationTracker == 105 && turnsLeft > 0) {
                            sewer.EndGame(locationTracker, turnsLeft, choice, clueVec, cameraEvidence);
                        }
                    }
                }
            }
        }
    }
    if (turnsLeft <= 0) {
        cops.CopsArrive(choice, turnsLeft, cameraEvidence, clueVec);
    }

    return 0;
}

