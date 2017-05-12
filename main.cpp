#include <iostream>
#include <vector>
#include <fstream>


using namespace std;



class algoritma{

public:
    algoritma() {

    }

    void findAli(){

        //mid point belirle
        int w = getWeight();
        int h = getHeight();
        int xMid = 0,yMid= 0 ;

        if(h %2 == 0 ){

        }else{

        }
        if(w %2 == 0 ){

        }else{

        }



    }


    //read from file write FileData variable
    void readTestfile( char* filename){

        string line;
        fstream myfile;

        myfile.open(filename);

        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                //cout << line << '\n';
                FileData.push_back(line);
            }
            myfile.close();

            setHeight(FileData.size());
            setWeight(line.size());
        }

        else cout << "Unable to open file";
    }
    //print data
    void printData(){
        for (int i = 0; i < FileData.size() ; ++i) {
            cout << FileData[i]<<endl;
        }

    }


private:
    vector <string> FileData;
    int weight ;
public:
    int getWeight() const {
        return weight;
    }

    void setWeight(int weight) {
        algoritma::weight = weight;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        algoritma::height = height;
    }

private:
    int height ;



};



int main() {

    char* myfile ("test.txt");
    algoritma a;

    a.readTestfile(myfile);
    a.printData();

    return 0;
}