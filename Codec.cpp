#include<iostream>
#include<sstream>
using namespace std;
class Codec{
    private:
        string code;
        char A[26][26];
    public: 
        Codec(string str){
            code=str;
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    A[i][j]=((i+j)%26)+'a';
                }
            }
        }
        char ncode(char x,int &j){
            j++;
            return A[x - 'a'][(j - 1) % 26];
        }
        string Encode(){
            stringstream s1(code);
            stringstream s2;
            string word;
            char letter;
            int j=0;
            while(s1>>word){
                stringstream s3(word);
                while(s3>>letter){
                    s2<<ncode(letter,j);
                }
                s2<<" ";
            }
            return s2.str();
        }
        //write dcode and Decode functions...
        char dcode(char x,int &j){
            j++;
            return A[x-'a'][(27-j)%26];
        }
        string Decode(){
            stringstream s1(code);
            stringstream s2;
            string word;
            char letter;
            int j=0;
            while(s1>>word){
                stringstream s3(word);
                while(s3>>letter){
                    s2<<dcode(letter,j);
                }
                s2<<" ";
            }
            return s2.str();
        }
};
int main(){
    string code;
    getline (cin, code);
    Codec obj(code);
    Codec obj2(obj.Encode());
    cout<<obj2.Decode()<<endl;
    return 0;
}