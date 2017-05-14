#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>

#define TESTCHAR '0'

using namespace std;

class algoritma{

public:
    algoritma() {

    }

    void findAliBruteForce(){
        for (int i = 0; i <getHeight() ; ++i) {
            for (int j = 0; j <getWidth() ; ++j) {
               if( isAli(getFileData(i).at(j),i,j) == -1)
                   return;
            }
        }
    }


    /* Algroitma dosyanın ortasından başlayarak
   * giderek büyüyen dikdörtgenler  çizerek kontrol edicek
   * vision kısmından gelen onay komutu ile işlemi sonlandıracak
   * */


    void findAli(){

        int staticVariable = 1;

        //mid point belirle
        int w = getWidth()  - 1;
        int h = getHeight() - 1;
        int hMid = h /2 ,wWith= w/2  ;

        int positionH = hMid ,positionW = wWith;

        //cout <<hMid << endl;
        //cout << wWith << endl;

        int counter = 0;
                //ilk parametre satır
                //2.parametre sütün

          //  cout << getFileData(11).at(12)<< endl;

        isAli(getFileData(positionH).at(positionW),positionH,positionW);

        while (1){

            ++staticVariable;


            //sağ üst 1 satır
            --positionH;
            ++positionW;

            if(positionW < h  && positionW < w && positionW > 0  && positionW > 0){
                cout << "sınırlardayız "<<endl;
                break;
            }
            cout << "Static Variable " << staticVariable << endl;


            //sağ dan sola

            for (int i = 0; i < staticVariable ; ++i){

                cout << "comiic soon --> Left "<< endl;
                cout << positionH << endl;
                cout << positionW<< endl;
                cout << getFileData(positionH).at(positionW)<< endl;

                isAli(getFileData(positionH).at(positionW),positionH,positionW);

                //FileData[positionH][positionW]= 'X';

                --positionW;
            }




            //yukar  -> aşağı


            for (int j = 0; j <staticVariable ; ++j) {

                cout << "comiic soon --> Down "<< endl;
                cout << positionH << endl;
                cout << positionW<< endl;
                cout << getFileData(positionH).at(positionW)<< endl;

                isAli(getFileData(positionH).at(positionW),positionH,positionW);
                //FileData[positionH][positionW]= 'X';

                ++positionH;

            }

            //soldan sağa


            for (int k = 0; k < staticVariable; ++k) {

                cout << "comiic soon --> Right "<< endl;
                cout << positionH << endl;
                cout << positionW<< endl;
                cout << getFileData(positionH).at(positionW)<< endl;

                ++positionW;
                isAli(getFileData(positionH).at(positionW),positionH,positionW);
                //FileData[positionH][positionW]= 'X';

            }

            //yukarı
            for (int l = 0; l < staticVariable; ++l) {

                cout << "comiic soon --> Up "<< endl;
                cout << positionH << endl;
                cout << positionW<< endl;
                cout << getFileData(positionH).at(positionW)<< endl;
                --positionH;
                isAli(getFileData(positionH).at(positionW),positionH,positionW);
              //  FileData[positionH][positionW]= 'X';

            }

        }


    }
    void clearData(){
        // erase all elements:
        FileData.erase (FileData.begin(),FileData.end());
    }
    int isAli(char c,int h,int w ){
        if(getFileData(h).at(w) == TESTCHAR){
            cout << "Ali Found at row " << h+1 << "  and  column "<< w+1 <<endl;
            return -1;

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
                setWidth(line.size());

            }
            myfile.close();

            setHeight(FileData.size());
        }

        else cout << "Unable to open file";
    }
    //print data
    void printData(){
        for (int i = 0; i < FileData.size() ; ++i) {
            cout << FileData[i]<<endl;
        }

    }


    void testingAlgorithm(char* filename){

        readTestfile(filename);
        std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

        findAliBruteForce();
        chrono::steady_clock::time_point end= std::chrono::steady_clock::now();

        cout << "(nanoseconds ) Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count()<<"\n" <<std::endl;
        clearData();
    }



    int getWidth() const {
        return Width;
    }

    void setWidth(int Width) {
        algoritma::Width = Width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        algoritma::height = height;
    }

    const string getFileData(int index) const {
        return FileData[index];
    }


private:
    int Width ;
    int height ;
    vector <string> FileData;



};



int main() {

    char* myfile ("test.txt");
    char* myfile1 ("test1.txt");

    algoritma a;

    a.testingAlgorithm(myfile);

    a.testingAlgorithm(myfile1);

   // a.printData();

    return 0;
}