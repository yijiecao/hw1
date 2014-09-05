#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argv, char* argc[]) {
    //the dynamic array used to save thenumber for each bucket
    int** bucket=NULL;
    //the bool array used to check whether each bcket is full or empty
    bool* bucket_status=NULL;
    //the int array used to save the number of integer each bucket contain
    int* integer=NULL;
    int num,step,bck;
    string temp,command;
    stringstream ss;
    //open the file
    ifstream myfile( argc[1] );
    if (myfile.fail() ) {
        cout<<"WRONG FILE"<<endl;
        return 1;
    }
    getline (myfile, temp);
    ss<<temp;
    //get the number of buckets and the number of steps
    ss>>num
      >>step;
    ss.str();
    ss.clear();
    //get the size of dynamic array based on the number of buckets
    bucket = new int*[num];
    bucket_status = new bool[num];
    integer= new int [num];
    //initialize each bucket's status to empty
    for (int i=0; i<num; i++) {
        bucket_status[i]=false;
        bucket[i]=NULL;
    }
    for (int i=0; i<step; i++) {
        getline ( myfile, temp);
        ss<<temp;
        ss>>command
          >>bck;
        bck=bck-1;
        if (command == "PUT") {
            //check if the bucket s empty
            if (!bucket_status[bck]) {
                ss>>integer[bck];
                //get the size for the particular bucket
                bucket[bck] = new int[integer[bck]];
                //set the bucket to not empty
                bucket_status[bck]=true;
                for (int j=0; j<integer[bck]; j++) {
                    ss>>bucket[bck][j];
                }
            }
            else {
                cout<<"Error - bucket "<<bck+1<<" is not empty"<<endl;
            }
        }
        else if (command == "OUTPUT") {
            //check if the bucket exsits
            if (bck<0 || bck>num) {
                cout<<"Error - bucket "<<bck+1<<" does not exist"<<endl;
            }
            //if the bucket is not empty, output the integer in it
            else if (bucket_status[bck]) {
                for (int j=0; j<integer[bck]; j++) {
                    cout<<bucket[bck][j]<<" ";
                }
                cout<<endl;
            }
            //if the bucket is empty, output empty
            else if (!bucket_status[bck]) {
                cout<<"empty"<<endl;
            }
        }
        else if (command == "EMPTY") {
            if (bck<0 || bck>=num) {
                cout<<"Error - bucket "<<bck+1<<" does not exist"<<endl;
            }
            //if the bucket is not empty, empty it
            if (bucket_status[bck]) {
                bucket_status[bck]=false;
                integer[bck]=0;
                //free the memory
                delete [] bucket[bck];
            }
            //if the bucket is already empty, output the result
            else if (!bucket_status[bck]) {
                  cout<<"The bucket is already empty"<<endl;
            }

        }
        ss.str(string());
        ss.clear();
    }
    //free the memory
    for (int i=0; i<num; i++) {
        delete [] bucket[i];
    }
    delete [] bucket;
    delete [] integer;
    delete [] bucket_status;
    return 0;
}
