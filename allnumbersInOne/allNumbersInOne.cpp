#include <iostream>
#include <cmath>
using namespace std;
const long SIZE=10000;
int tab[SIZE];
int dift[10];
int getInt(char sign){switch (sign){
case '1':return 1;break;case '2':return 2;break;case '3':return 3;break;case '4':return 4;break;
case '5':return 5;break;case '6':return 6;break;case '7':return 7;break;case '8':return 8;break;
case '9':return 9;break;default :return 0;break;}
}
char getChar(int num){switch(num){
        case 1:return'1';break;case 2:return'2';break;case 3:return'3';break;case 4:return'4';break;
        case 5:return'5';break;case 6:return'6';break;case 7:return'7';break;case 8:return'8';break;
        case 9:return'9';break;default:return'0';}
}
int letterNow(string seq,int diff)
{
    for(int a=0;a<10;a++)tab[a]=0;
    int onenum=0,zeronum=0;
    for(int a=0;a<seq.length();a++)dift[getInt(seq[a])]++;
    int min=0;
    for(int a=0;a<diff;a++)
    if(dift[min]>dift[a])min=a;
    return min;
}
bool isGood(string seq, int len,int diff)
{
    //cout<<seq<<" , "<<len<<'\n';
    int num=0;
    for(int a=0;a<SIZE;a++)tab[a]=0;
    for(int a=0;a<pow(diff,len);a++)
    {
        num=0;
        for(int b=0;b<len;b++)
        {
            num*=diff;
            num+=getInt(seq[(a+b)%seq.length()]);
        }
        tab[num]++;
    } 
    for(int a=0;a<pow(diff,len);a++)if(tab[a]!=1)return false;
    return true;
}
string deleteLastSign(string seq,char sign)
{
    while(seq[seq.length()-1]==sign)seq=seq.substr(0,seq.length()-1);
    return seq;
}
string generatenextSequence(string seq, int system,int len)
{
    //cout<<seq+'\n';
    while(seq[seq.length()-1]==getChar(system-1))seq=seq.substr(0,seq.length()-1);//usuniecie zbednej czesci
    if(seq.length()>=1){int last=getInt(seq[seq.length()-1])+1;seq[seq.length()-1]=getChar(last);}//zwiekszenie ostatniego znaku
    for(;seq.length()<pow(system,len)-2*len;seq+='0');//uzupelnienie o zera, 2 bo ustalone sa 2 ciagi stale(poczatkowy i koncowy)
    return seq;
}
string generateByteSequence(int len,int diff)
{
    for(int a=0;a<SIZE;a++)tab[a]=0;//tablica wyzerowana
    string res0="",res1="",resm="";//zmienne do poszukiwanego ciagu
    for(int a=0;a<len;a++){res0+="0";res1+="1";}//ustawnienie warto??ci 2 z 3 ciagow
    while(!isGood(res0+resm+res1,len,diff)){resm=generatenextSequence(resm,diff,len);/*cout<<res0+resm+res1+'\n';*/}//ustawienie srodkowej czesci ciagu
    return res0+resm+res1;//zwrot calosci
}

string generateByteSequenceUP(int len,int diff)
{
    for(int a=0;a<SIZE;a++)tab[a]=0;
    string res0="",res1="",resm="";
    for(int a=0;a<len;a++)
    {res0+="0";res1+="1";}
    //if(len>diff){res0+="1";res1="0"+res1;}
    cout<<"going in loop\n";
    while(!isGood(res0+resm+res1,len,diff))
    {
        resm=deleteLastSign(resm,resm.length()-1);//
        if(resm.length()>=1)resm[resm.length()-1]=getChar(getInt(resm[resm.length()-1])+1);
        for(;resm.length()<pow(diff,len)-diff*(len+1);)resm+=getChar(letterNow(res0+res1+resm,diff));
        cout<<res0+res1+"r:"+resm+'\n';
    }
    return res0+resm+res1;
}

int main()
{
    cout<<generateByteSequence(2,2)+" 2,2 \n";//0011->0,1,3,2-->0,3
    cout<<generateByteSequence(3,2)+" 3,2 \n";//00010111->0,1,2,5,3,7,6,4-->0,5,6*/0,23
    cout<<generateByteSequence(4,2)+" 4,2 \n";//0000100110101111->0,1,2,4,9,3,6,13,10,5,11,7,15,14,12,8--->0,9,10,15
    cout<<generateByteSequence(5,2)+" 5,2 \n";//00000100011001010011101011011111->0,1,2,4,8,17,3,6,12,25,18,5,10,20,9,19,7,14,29,26,21,11,22,13,27,23,15,31,30,28,24,16-->0,17,18,19,21,23,24*
    cout<<generateByteSequence(2,3)+" 2,3 \n";//001202211->0,1,5,6,2,8,7,4,3
    //cout<<generateByteSequence(3,3)+" 3,3 \n";//nn
    //cout<<generateByteSequence(4,3)+" 4,3 \n";//nn
    string se2q10="0012030405060708090213141516171819223242526272829334353637383944546474849556575859667686977879889911";
    string se2q9="001203040506070802131415161718223242526272833435363738445464748556575876686778811";
    string se2q8="0011020304050607131415161721223242526273343536374454647556576677";//0012030405060702131415161722324252627334353637445464755657667711
    string se8q2="000000001001000010000011000100000101000110000111001011001100001101001110001111010001010010011010100010101010110010111011011100011101011110011111100100101100110100111101101110101111110110111111";
    //not certain
    cout<<se2q8<<'\n';
    cout<<isGood(se2q8,2,8)<<'\n';
    

    system("pause"); 
    return 0;
}
