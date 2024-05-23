#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString{
    private:
        string m_str;
    public:
        myString(string s){
            m_str = s;
        }
};

class ReadClass{
    private:
    public:
        ReadClass(){

        }
        void showClass(){
            ifstream file("main.cpp");
            string classname[20];
            int n = 0;
            int class_num = 0;
            int m = 0;
            if(file.is_open()){
                char c;
                char s[6] = "class";
                while(file.get(c)){
                    if(s[n] == c){
                        n ++;
                    }else{
                        n = 0;
                    }
                    if(n == 4){
                        class_num ++;
                        n = 0;
                        m = 1;
                    }
                    if(m == 1){
                        classname[class_num] += c;
                        if(c == '('){
                            m = 0;
                        }
                    }
                }
            }else{
                cout << "Unable to open file" << endl;
            }
            cout << class_num << "class in main.cpp\n";
            for(int i = 0; i < class_num; i++){
                cout << "class " << classname[i] << endl;
            }
        }
};

int main(){
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
