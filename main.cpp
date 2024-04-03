#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

float quizCalculator(int examQuant, float stuScore){
    float finalScore;

    finalScore = (stuScore / examQuant) * 100;
    return finalScore;
}

float midtermCalculator(float cStanding, float mScore){
    float cCS_Final;
    float cME_Final;
    float mExamAv;

    cCS_Final = (60 * cStanding) / 100;
    cME_Final = (40 * mScore) / 100;

    mExamAv = cCS_Final + cME_Final;
    return mExamAv;
}

float finalsCalculator(float fStanding, float fME, float fScore){
    float fCS_Final;
    float fME_Final;
    float fFE_Final;
    float fExamAv;

    fCS_Final = (60 * fStanding) / 100;
    fME_Final = (15 * fME) / 100;
    fFE_Final = (25 * fScore) / 100;

    fExamAv = fCS_Final + fME_Final + fFE_Final;
    return fExamAv;
}

int main(){

    string studentName;
    float q_grade, m_grade, f_grade, gradePoint;
    char pref;
    char op;

    // For Q
    string qName;
    int quantity;
    float q_Score;

    // For M
    string mSubject;
    float classStanding;
    float mExamScore;

    // For F
    string fSubject;
    float fClassStanding;
    float fMScore;
    float finalsScore;

    // For G
    string desc;
    float scoreRaw;

    // Startup Intro
    cout<<"X==================================X"<<endl;
    cout<<"X            Welcome to            X"<<endl;
    cout<<"X    Grading Calculator System     X"<<endl;
    cout<<"X==================================X"<<endl;
    cout<<"XxX Created by BMA-AM12 Students XxX"<<endl;
    cout<<endl<<endl;

    // Do-while

    do{
        // Execute options
        cout<<"XX XX XX Please choose any options you would like to use: XX XX XX"<<endl;
        cout<<endl<<endl;
        // Options initiated
        cout<<"XX:: [Q] Calculate Quiz/Exam Grade"<<endl;
        cout<<"XX:: [M] Calculate Midterms Grade"<<endl;
        cout<<"XX:: [F] Calculate Finals Grade"<<endl;
        cout<<"XX:: [G] Check possible grade if..."<<endl;
        cout<<"XX:: [X] Exit Program\n\n";
        cout<<"[XX Your option XX] = >    ";

        cin>>op;

        // Option choice
        switch (op) {
            case 'Q':
            case 'q':

                cout<<"[ YOUR OPTION IS Q ]"<<endl;
                cout<<endl;
                cout<<"[XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]\n\n";
                cout<<"XX: Enter student name: ";
                cin>>studentName; /*Put data on studentName string*/
                cout<<"XX: Enter quiz/exam name: ";
                cin>>qName;
                cout<<"XX: Enter quiz/exam's quantity/question amount: ";
                cin>>quantity;
                cout<<"XX: Enter the examinee's answers written correctly (scores): ";
                cin>>q_Score;

                q_grade = quizCalculator(quantity, q_Score);
                cout<<fixed<<setprecision(2);
                cout<<"\n\nYour student "<<studentName<<" got a score of "<<q_grade<<" percent on your quiz/exam "<<qName<<".\n\n";
                cout<<"[XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]\n\n"<<endl;

                break;

            case 'M':
            case 'm':
                cout<<"[ YOUR OPTION IS M ]"<<endl;
                cout<<endl;
                cout<<"[XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]\n\n";
                cout<<"XX: Enter student name: ";
                cin>>studentName; /*Put data on studentName string*/
                cout<<"XX: Enter subject: ";
                cin>>mSubject;
                cout<<"XX: Enter your student's class standing (in percentage)\nFor reference, 60 percent is the contribution of class standing: ";
                cin>>classStanding;
                cout<<"XX: Enter the student's midterm examination grade (in percentage)\n(For reference, 40 percent is the contribution of midterm exam): ";
                cin>>mExamScore;

                if (classStanding > 100 || mExamScore > 100) {
                    cout<<"\nXX: ERROR ! ERROR ! ERROR !\nXX: Overall average is higher than expected!\nXX: Please try again. Exiting option...\n";
                } else {
                    m_grade = midtermCalculator(classStanding, mExamScore);

                    if (m_grade <= 79) {
                        gradePoint = 0.5;
                    } else if (m_grade >= 100) {
                        gradePoint = 4.0;
                        desc = "Bruh";
                    } else if (m_grade >= 97) {
                        gradePoint = 4.0;
                        desc = "Excellent";
                    } else if (m_grade >= 93) {
                        gradePoint = 3.5;
                        desc = "Superior";
                    } else if (m_grade >= 89) {
                        gradePoint = 3.0;
                        desc = "Very Good";
                    } else if (m_grade >= 85) {
                        gradePoint = 2.5;
                        desc = "Good";
                    } else if (m_grade >= 80) {
                        gradePoint = 2.0;
                        desc = "Satisfactory";
                    }

                    cout<<"\n\nYour student "<<studentName<<" got a final score of "<<m_grade<<" percent or "<<gradePoint<<"  on your subject "<<mSubject<<".\n\n";
                    cout<<"[XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]\n\n"<<endl;
                }

                break;

            case 'F':
            case 'f':

                cout<<"[ YOUR OPTION IS F ]"<<endl;
                cout<<endl;
                cout<<"[XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]\n\n";
                cout<<"XX: Enter student name: ";
                cin>>studentName; /*Put data on studentName string*/
                cout<<"XX: Enter subject: ";
                cin>>fSubject;
                cout<<"XX: Enter your student's class standing (in percentage)\nFor reference, 60 percent is the contribution of class standing: ";
                cin>>fClassStanding;
                cout<<"XX: Enter the student's midterm examination grade (in percentage)\n(For reference, 15 percent is the contribution of midterm exam): ";
                cin>>fMScore;
                cout<<"XX: Enter the student's final examination grade (in percentage)\n(For reference, 25 percent is the contribution of final exam): ";
                cin>>finalsScore;

                if (fClassStanding > 100 || fMScore > 100 || finalsScore > 100) {
                    cout<<"\nXX: ERROR ! ERROR ! ERROR !\nXX: Overall average is higher than expected!\nXX: Please try again. Exiting option...\n";
                } else {
                    f_grade = finalsCalculator(fClassStanding, fMScore, finalsScore);

                    if (f_grade <= 79) {
                        gradePoint = 0.5;
                    } else if (f_grade >= 100) {
                        gradePoint = 4.0;
                        desc = "Bruh";
                    } else if (f_grade >= 97) {
                        gradePoint = 4.0;
                        desc = "Excellent";
                    } else if (f_grade >= 93) {
                        gradePoint = 3.5;
                        desc = "Superior";
                    } else if (f_grade >= 89) {
                        gradePoint = 3.0;
                        desc = "Very Good";
                    } else if (f_grade >= 85) {
                        gradePoint = 2.5;
                        desc = "Good";
                    } else if (f_grade >= 80) {
                        gradePoint = 2.0;
                        desc = "Satisfactory";
                    }

                    cout<<"\n\nYour student "<<studentName<<" got a final score of "<<f_grade<<" percent or "<<gradePoint<<"  on your subject "<<fSubject<<".\n\n";
                    cout<<"[XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]\n\n"<<endl;
                }

                break;
            
            case 'G':
            case 'g':

                cout<<"[ YOUR OPTION IS G ]"<<endl;
                cout<<endl;
                cout<<"[XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX]\n\n";
                cout<<"XX: Enter student name: ";
                cin>>studentName; /*Put data on studentName string*/
                cout<<"XX: Enter raw grade (in percentage): ";
                cin>>scoreRaw;

                if (scoreRaw <= 79) {
                    gradePoint = 0.5;
                } else if (scoreRaw >= 100) {
                    gradePoint = 4.0;
                    desc = "Bruh";
                } else if (scoreRaw >= 97) {
                    gradePoint = 4.0;
                    desc = "Excellent";
                } else if (scoreRaw >= 93) {
                    gradePoint = 3.5;
                    desc = "Superior";
                } else if (scoreRaw >= 89) {
                    gradePoint = 3.0;
                    desc = "Very Good";
                } else if (scoreRaw >= 85) {
                    gradePoint = 2.5;
                    desc = "Good";
                } else if (scoreRaw >= 80) {
                    gradePoint = 2.0;
                    desc = "Satisfactory";
                }

                cout<<"\n\nYour student "<<studentName<<" got a grading point of "<<gradePoint<<" - "<<desc;

                break;

            case 'X':
            case 'x':
                return 0;
                break;
        }

        // Initiate when calculations are done
        cout<<"\nXX: Press any key to continue...\n\n\n";
        _getch();

    } while (op != 'X' && op != 'x');
    cout<<"\n Thank you for using the program!";

    return 0;
}