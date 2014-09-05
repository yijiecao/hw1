#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argv, char* argc[]) {
    int num;
    int* count=NULL;
    string word,temp;
    stringstream ss;
    //READ THE FILE
    fstream myfile (argc[1]);
    getline (myfile, temp);
    //GET THE NUMBER OF LINES NEED TO BE READ
    ss<<temp;
    ss>>num;
    count = new int[num];
    ss.clear();
    for (int i=0; i<num; i++) {
        getline (myfile, temp);
        ss<<temp;
        //READ THE WORD UNTIL THERE IS NOTHING TO READ
        while(true) {
            ss>>word;
            if ( ss.fail() ) {
                break;
            }
        //COUNT THE NUMBER OF WORD EACH LINE CONTAIN
            count[i]++;
        }
        ss.clear();
    }
    
    for (int i=0; i<num; i++) {
         cout<<count[num-1-i]<<endl;
    }
    delete [] count;
    return 0;
}




