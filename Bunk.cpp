#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float atn, total, bunk, per; //atn = attended classes, total = total classes, bunk = number of classes you can bunk, per = percentage attendence
    int targetAtd, extAtn; // rem = remaining classes, extAtn = number of classes you need to attend more 
    char query;
    bunk = 0;
    extAtn = 0;
    
    cout << "A for Advanced and B for Basic: ";
    cin >> query;
    cout << "\nEnter the number of lectures attended: ";
    cin >> atn;
    cout << "\nEnter the number of Lectures Taken: ";
    cin >> total;
    int moreBunk = 0;
    per = (atn*100.0 / total);

    // Advanced Version
    if (query == 'A' || query == 'a'){ 
        cout << "\nHow much attendence you would like to maintain?: " ;
        cin >> targetAtd;
        cout << "\nHow many classes you would like to bunk?: ";
        cin >> moreBunk;
        
        total = total + moreBunk;
        per = (atn*100.0 / total);
        cout << "After Bunking " << moreBunk << " classes your attendence will be " << setprecision(4) << per;
        if (per >=targetAtd){
            
            while (per >=targetAtd){
                bunk++;
                total++;
                per = (atn / total)*100;
            }
            
            if (per >= targetAtd){
                cout << "\nYou can bunk " <<  bunk << " classes" << endl;
                cout << "\nAnd Your Attendence will be: " << setprecision(4) << per << " %"<< endl;
                cout << "You will need to attend " << extAtn << " classes" << endl;
            }
            else if (per < targetAtd){
                per = (atn*100) / (total-1);
                cout << "\nYou can bunk " <<  bunk-1 << " classes" << endl;
                cout << "And Your Attendence will be: " << setprecision(4) << per << " %"<< endl;
            }
            
            
        }
        //Agar 75% se kam ho to attendence
        else {
            while (per < targetAtd){
                atn++;
                extAtn++;
                total++;
                per = (atn / total)*100;
            }
            cout << extAtn << " lagani padengi " << endl;
        }
        
        
    }

    //Basic Version
    else{
        if (per >=75){
            while (per >=75){
                bunk++;
                total++;
                per = (atn / total)*100;
            }
            
            if (per >= 75){
                cout << "You can bunk " <<  bunk << " classes" << endl;
                cout << "And Your Attendence will be: " << setprecision(4) << per << " %"<< endl;
            }
            else if (per < 75){
                per = (atn*100) / (total-1);
                cout << "You can bunk " <<  bunk-1 << " classes" << endl;
                cout << "And Your Attendence will be: " << setprecision(4) << per << " %"<< endl;
            }
        }
        //Agar 75% se kam ho to attendence
        else {
            while (per < 75){
                atn++;
                extAtn++;
                total++;
                per = (atn / total)*100;
            }
            cout << extAtn << " lagani padengi" << endl;
        }
    }
}