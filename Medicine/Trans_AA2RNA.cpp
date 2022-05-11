#include <bits/stdc++.h>
using namespace std;

void Trans(string target,int index,string out);

int main(int argc, char const *argv[])
{
    string target;
    cin >> target;
    Trans(target,0,"");
    return 0;
}

void Trans(string target,int index,string out){
        vector<vector<string>> table={
        {"UUU","UUC"},                          //Phe 0 F
        {"UUA","UUG","CUU","CUC","CUA","CUG"},  //Leu 1 L
        {"AUU","AUC","AUA"},                    //Ile 2 I
        {"AUG"},                                //Met 3 M
        {"GUU","GUC","GUA","GUG"},              //Val 4 V
        {"UCU","UCC","UCA","UCG","AGU","AGC"},  //Ser 5 S
        {"CCU","CCC","CCA","CCG"},              //Pro 6 P
        {"ACU","ACC","ACA","ACG"},              //Thr 7 T
        {"GCU","GCC","GCA","GCG"},              //Ala 8 A
        {"UAU","UAC"},                          //Tyr 9 Y
        {"UAA"},                                //Stop 10
        {"CAU","CAC"},                          //His 11 H
        {"CAA","CAG"},                          //Gln 12 Q
        {"AAU","AAC"},                          //Asn 13 N
        {"AAA","AAG"},                          //Lys 14 K
        {"GAU","GAA"},                          //Asp 15 D
        {"GAA","GAG"},                          //Glu 16 E
        {"UGU","UGC"},                          //Cys 17 C
        {"UGG"},                                //Trp 18 W
        {"CGU","CGC","CGA","CGG","AGA","AGG"},  //Arg 19 R
        {"GGU","GGC","GGA","GGG"},              //Gly 20 G
        {"UGA"},                                //Sec 21 U
        {"UAG"},                                //Pyl 22 O
        {"AAU","AAC","GAU","GAA"},              //Asx 23 B
        {"CAA","CAG","GAA","GAG"},              //Glx 24 Z
        {"UUA","UUG","CUU","CUC","CUA","CUG","AUU","AUC","AUA"}//Xle 25 J
    };
    map<char,int> dict{
        {'F',0},{'L',1},{'I',2},{'M',3},{'V',4},{'S',5},
        {'P',6},{'T',7},{'A',8},{'Y',9},{'H',11},{'Q',12},{'N',13},{'K',14},{'D',15},
        {'E',16},{'C',17},{'W',18},{'R',19},{'G',20},{'U',21},{'O',22},{'B',23},{'Z',24},{'J',25}
    };
    string tout = out;
    for(int i = 0;i < table[dict[target[index]]].size();i++){
        tout = tout + table[dict[target[index]]][i];
        if(index < target.length()-1){
            Trans(target,index+1,tout);
            tout.assign(tout,0,tout.length()-3);
        }else{
            cout << tout << endl;
            tout.assign(tout,0,tout.length()-3);
        }
    }
    return;
}

