#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
    //MENU OPTION: Vote
    //1. DisplayParticipants
    //2. Preferences
    //MENU OPTION: View Leaderboard
    //1. Display Leaderboard

struct Candidate {

    string name, party;
    int voteCount = 0;
    int points = 0;
};

struct Candidate CandidateA = {"CandidateA", "BJP"};
struct Candidate CandidateB = {"CandidateB", "Congress"};
struct Candidate CandidateC = {"CandidateC", "Republic"};
struct Candidate CandidateD = {"CandidateD", "AAP"};
struct Candidate CandidateE = {"CandidateE", "Democratic"};

void DisplayLeaderBoard(){
    cout<<" CANDIDATE NAME\t PARTY NAME\tNO OF VOTES\tPOINTS";
    cout<<"\n -----------------------------------------------------";
    cout<<"\n "<<CandidateA.name<<"\t  "<<CandidateA.party<<"\t\t   "<<CandidateA.voteCount<<"\t\t "<<CandidateA.points;
    cout<<"\n "<<CandidateB.name<<"\t  "<<CandidateB.party<<"\t   "<<CandidateB.voteCount<<"\t\t "<<CandidateB.points;
    cout<<"\n "<<CandidateC.name<<"\t  "<<CandidateC.party<<"\t   "<<CandidateC.voteCount<<"\t\t "<<CandidateC.points;
    cout<<"\n "<<CandidateD.name<<"\t  "<<CandidateD.party<<"\t\t   "<<CandidateD.voteCount<<"\t\t "<<CandidateD.points;
    cout<<"\n "<<CandidateE.name<<"\t  "<<CandidateE.party<<"\t   "<<CandidateE.voteCount<<"\t\t "<<CandidateE.points;
}

void VotePreference(int voteChoice, int point){
    switch(voteChoice){
        case 1: //CandidateA
                CandidateA.voteCount++;
                CandidateA.points += point; //CandidateA.points = CandidateA.points +5;
                break;
        case 2: //CandidateB
                CandidateB.voteCount++;
                CandidateB.points += point;
                break;
        case 3: //CandidateC
                CandidateC.voteCount++;
                CandidateC.points += point;
                break;
        case 4: //A.A.P
                CandidateD.voteCount++;
                CandidateD.points += point;
                break;
        case 5: //Democratic_State
                CandidateE.voteCount++;
                CandidateE.points += point;
                break;
    }
}

void DisplayAdmin(int& f)
{
        string password = "Admin"; //  can make this dynamic by maintaining an array of id passwords of new users
        cout<<"Are You an Admin ??\n\n";
        cout<<"Press 1 for Yes and 2 to go back\n";
        int input;
        cin>>input;
        if(input == 2)
                f = 1;
        else
        {
                cout<<"Enter Password:";
                string inp;
                cin>>inp;
                if(inp == password)
                {
                       system("cls");
                        cout<<"VIEW LEADERBOARD\n\n";

                        DisplayLeaderBoard();
                }
                else
                {
                        cout<<"Incorrect Password\n\n";
                        cout<<"Press Enter to C1ontinue";
                }
        }
}


void DisplayMenu(){
    int menuChoice, voteChoice,f=0;

    system("cls");

    cout<<"VOTING SYSTEM\n\n";
    cout<<"MENU:\n1. Vote for Candidate\n2. View Leaderboard\n3. Exit\n\n";
    cout<<"-> ";
    cin>>menuChoice;
    switch(menuChoice){
        case 1: //Vote for Candidate
                system("cls");
                cout<<"VOTE FOR CANDIDATE\n\n";
                cout<<"LIST OF CANDIDATES: \n";
                cout<<"1. CandidateA\n2. CandidateB\n3. CandidateC\n4. CandidateD\n5. CandidateE\n";
                cout<<"PREFERENCE 1 -> ";
                cin>> voteChoice;
                VotePreference(voteChoice,5);
                cout<<"PREFERENCE 2 -> ";
                cin>> voteChoice;
                VotePreference(voteChoice,3);
                cout<<"PREFERENCE 3 -> ";
                cin>> voteChoice;
                VotePreference(voteChoice,1);
                //Congrats you have voted for __
                getch();
                DisplayMenu();
                break;

        case 2: //View Leaderboard
                system("cls");
                //cout<<"VIEW LEADERBOARD\n\n";
                DisplayAdmin(f);
                if(f == 1)
                {
                    DisplayMenu();
                }
                getch();
                DisplayMenu();
                break;

        case 3: //Exit
                exit(1);
        default: exit(1);
    }
    //DisplaySubMenu(&menuChoice,&CandidateA,&CandidateB);
}

int main() {
    //MENU
    DisplayMenu();

    return 0;
}
