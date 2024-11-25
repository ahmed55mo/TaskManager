#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<fstream>
#include<cmath>
using namespace std;

class process{
public:
    string Iname;// ==> referes to image name
    int PID; // ==> referes to process ID
    string sessionName; // ==> referes to session name
    int sessionNo; // ==> referes to session number
    int memUse ;// ==> refers to memory usage

    // default constructor
    process(){}

    //parametrized constructor
    process(string is , int id , string s , int sn , int mem){
        Iname = is;
        sessionName = s;
        PID = id;
        memUse = mem;
        sessionNo = sn;
    }

    ~process(){}

    void displayProcess(){
        cout << setfill(' ') << left << setw(30) << Iname << right << setw(10) << PID << setw(20) << sessionName << setw(15) << sessionNo << setw(15) << memUse << " K" << endl;
    }
};

//function that converts string of integers into int
int toInt(string l) {
    int number = 0;
    for (char ch : l) {
        if (isdigit(ch)) {
            number = number * 10 + (ch - '0'); 
        }
    }
    return number;
}


class ProcessList{
private:
    vector<process> listOfProcess;// this is a vector that contains the processes of the task manager
    // function that returns vector of words to assign them to an object of process
    vector<string> readWords(string line) {
        vector<string> processProberties;// vector that will be returned
        string word = "";// word that will be pushed to the vector
        bool inQuotes = false;// boolean to check if the double qoutes are opened of not 
        //loop read character by character
        for (char ch : line) {
            if (ch == '"') {
                inQuotes = !inQuotes; 
            } else if (ch == ',' && !inQuotes) {
                processProberties.push_back(word);
                word = "";
            } else {
                word += ch; 
            }
        }
        if (!word.empty()) {
            processProberties.push_back(word); 
        }
        return processProberties;
    }

public:
    // function to add process manually
    void addProcess(process p){
        listOfProcess.push_back(p);
    }
    //function to display the list
    void displayList(){
        cout << left << setw(30) << "image name" << right << setw(10) << "ID" << setw(20) << "session name" << setw(15) << "session#" << setw(15) << "Memory usage" << endl;
        cout << setfill('-') << setw(92) << "-" << endl;
        for (auto it : listOfProcess)
        {
            it.displayProcess();
        }
    }

    void sortID(){
        // lampda function that takes two objects and return the smallest in ID to sort them ascendingly
        sort(listOfProcess.begin() , listOfProcess.end() , [](process pro1, process pro2){return pro1.PID < pro2.PID;});
    }

    void sortBySessionName(){
        // lampda function that takes two objects and return the smallest in asci number to sort them ascendingly by name
        sort(listOfProcess.begin() , listOfProcess.end() , [](process pro1, process pro2){return pro1.sessionName < pro2.sessionName;});
    }

    void sortMemory(){
        // lampda function that takes two objects and return the smallest in Memory usage to sort them ascendingly
        sort(listOfProcess.begin() , listOfProcess.end() , [](process pro1, process pro2){return pro1.memUse < pro2.memUse;});
    }

    void sortByImageName(){
        // lampda function that takes two objects and return the smallest in asci number to sort them ascendingly by image name
        sort(listOfProcess.begin() , listOfProcess.end() , [](process pro1, process pro2){return pro1.Iname < pro2.Iname;});
    }

    void sortBySessionNo(){
        // lampda function that takes two objects and return the smallest in session nuber to sort them ascendingly
        sort(listOfProcess.begin() , listOfProcess.end() , [](process pro1, process pro2){return pro1.sessionNo < pro2.sessionNo;});
    }
    // constructor
    ProcessList(){
        system("tasklist /FO CSV /NH  > processes.csv"); // read the tasklist and load the processes into a csv file
        ifstream ifs("processes.csv");// open the file to make operations
        string readLine;//read every line in the file
        while(getline(ifs , readLine)){
            vector<string> processManipulation =  readWords(readLine);// vector of proberties of the process 
            process assignProcess;// object where the proberties are assigned
            assignProcess.Iname = processManipulation[0].substr(0,24);// assign image name
            assignProcess.PID = toInt(processManipulation[1]);//assign process ID
            assignProcess.sessionName = processManipulation[2];// assign session name
            assignProcess.sessionNo = toInt(processManipulation[3]) ; // assign session number
            assignProcess.memUse = toInt(processManipulation[4]); // assign memory usage
            // push the process object to the vector
            listOfProcess.push_back(assignProcess);
        }
        //close the file
        ifs.close();
    }
};

// function to display a menu 
void displayMenu() {
    cout << "\nTask manager\n";
    cout << "1. add process to task manager\n";
    cout << "2. display manager\n";
    cout << "3. display manager sorted by image name\n";
    cout << "4. display manager sorted by id\n";
    cout << "5. display manager sorted by session name\n";
    cout << "6. display manager sorted by session number\n";
    cout << "7. display manager sorted by memory usage\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}


int main(){

    ProcessList pl;

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string imageString , sessionName;
                int id , sessionNum , memory;
                cout << "enter image name: " ;cin >> imageString;
                cout << "enter process ID: " ;cin >> id;
                cout << "enter session name: " ;cin >> sessionName;
                cout << "enter session number: " ;cin >> sessionNum;
                cout << "enter memory usage: " ;cin >> memory;
                process p(imageString , id , sessionName , sessionNum , memory);
                pl.addProcess(p);
                break;
            }
            case 2: {
                pl.displayList();
                break;
            }
            case 3: {
                pl.sortByImageName();
                pl.displayList();
                break;
            }
            case 4: {
                pl.sortID();
                pl.displayList();
                break;
            }
            case 5: {
                pl.sortBySessionName();
                pl.displayList();
                break;
            }
            case 6: {
                pl.sortBySessionNo();
                pl.displayList();
                break;
            }
            case 7: {
                pl.sortMemory();
                pl.displayList();
                break;
            }
            case 0: {
                running = false;
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }

    return 0;
}