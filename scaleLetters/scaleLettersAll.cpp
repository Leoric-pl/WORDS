#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;
const int   
Aint30=0b011100101011011100011111110001,Bint30=0b111101001011111100011000111111,Cint30=0b111111000010000100001000011111,Dint30=0b111101001110001100011001111110,Eint30=0b111101000011100100001000011111,Fint30=0b111101000011100100001000010000,Gint30=0b111111000110000101111001011110,Hint30=0b100011000110001111111000110001,
Iint30=0b011100010000100001000010001110,Jint30=0b111100001000010000101001011110,Kint30=0b100011001010100111001001010001,Lint30=0b100001000010000100001000011110,Mint30=0b100011101110101100011000110001,Nint30=0b100011100110101101011001110001,Oint30=0b011101101110001100011101101110,Pint30=0b111101001011110100001000010000,
Qint30=0b111101001010010100101111000011,Rint30=0b111101001011110111001001010001,Sint30=0b111111000011111000010000111111,Tint30=0b111110010000100001000010000100,Uint30=0b100011000110001100011000111111,Wint30=0b100011000110001101011101110001,Vint30=0b100011000110001010100111000100,Xint30=0b100010101000100001000101010001,
Yint30=0b100010101000100001000010000100,Zint30=0b111110000100010001000100011111,
S1int30=0b001000110000100001000010001110,S2int30=0b001110100100010001000100001111,S3int30=0b001110100100001001100000101110,S4int30=0b000100011001010100101111100010,S5int30=0b011110100001110000010100100110,S6int30=0b001100100101000011110100100110,S7int30=0b011110000100010001000010000100,S8int30=0b001100100100110010010100100110,
S9int30=0b001100100100111000010100100110,S0int30=0b001100100101001010010100100110,SIint30=0b001000010000100001000000000100,SQint30=0b001100100100010001000000000100,SSint30=0b000000000000100000000010001000,SDint30=0b000000000000100000000010000000,SFint30=0b000000000000000000000000000100,SHint30=0b010100101011111010101111101010,
SMint30=0b011101000110101101111000001110,SPint30=0b001000010000100001000111001110;

const unsigned long long 
Aint56=0b00010000011100011011001000101100011111111110000011000001,Bint56=0b11111001000010100001011111001000011100000110000011111110,Cint56=0b11111101000000100000010000001000000100000010000001111111,Dint56=0b11111101000001100000110000011000001100000110000011111111,
Eint56=0b11111101000000100000011111001000000100000010000001111111,Fint56=0b11111101000000100000011111001000000100000010000001000000,Gint56=0b11111101000001100000010000001000000100111010001001111100,Hint56=0b10000011000001100000111111111000001100000110000011000001,
Iint56=0b00111000001000000100000010000001000000100000010000011100,Jint56=0b11111110000001000000100000010000001010000110000101111100,Kint56=0b10000011000010100010011010001111000100010010000101000001,Lint56=0b10000001000000100000010000001000000100000010000001111111,
Mint56=0b10000011100011101010110010011000001100000110000011000001,Nint56=0b10000011100001101000110010011000101100001110000011000001,Oint56=0b01111101100011100000110000011000001100000111000110111110,Pint56=0b11111101000011100000111111111000000100000010000001000000,
Qint56=0b01111101100011100000110000011000001110001101111100000011,Rint56=0b11111101000011100000111111111001000100010010000101000001,Sint56=0b01111111000000100000001111100000001000000100000011111110,Tint56=0b11111110001000000100000010000001000000100000010000001000,
Uint56=0b10000011000001100000110000011000001100000110000010111110,Wint56=0b10000011000001100000101000100100010010101001101100010100,Vint56=0b10000011000001100000101000100100010001010000101000001000,Xint56=0b10000010100010001010000010000001000001010001000101000001,
Yint56=0b10000010100010001010000010000001000000100000010000001000,Zint56=0b11111110000010000010000010000010000010000010000001111111,S1int56=0b00010000011000010100000010000001000000100000010000111110,S2int56=0b00111000100010000001000001000001000001000001000001111110,
S3int56=0b00111000100010000001000111000000010000001001000100011100,S4int56=0b00000000000100000110000101000100100100010011111100000100,S5int56=0b11111101000000111110010000100000010000001001000100011100,S6int56=0b01111101000001100000010110001100100100001010000100111100,
S7int56=0b11111110000001000001000001000001000001000001000001000000,S8int56=0b01111001000010100001001111001000010100001010000100111100,S9int56=0b01111101000010100011001110100000010000001001000100011100,S0int56=0b01111001000010100001010000101000010100001010000100111100,
SFint56=0b00000000000000000000000000000000000000000000000000001000,SIint56=0b00010000001000000100000010000001000000100000000000001000,SQint56=0b00111000100010000001000001000001000001000000000000010000,SSint56=0b00000000000000000000000010000000000000000000010000010000,
SHint56=0b00010100010010111111100101000010100111111101001000101000,SDint56=0b00000000000000000000000010000000000000000000010000000000,SMint56=0b01111101000001100000110111011010101101111010000000111110,SPint56=0b00010000001000000100000010000001000000100000010000111110,SBint56=0;
const unsigned long long all56[45]={Aint56,Bint56,Cint56,Dint56,Eint56,Fint56,Gint56,Hint56,Iint56,Jint56,Kint56,Lint56,Mint56,Nint56,Oint56,Pint56,Qint56,Rint56,Sint56,Tint56,Uint56,Wint56,Vint56,Xint56,Yint56,Zint56,S1int56,S2int56,S3int56,S4int56,S5int56,S6int56,S7int56,S8int56,S9int56,S0int56,SFint56,SIint56,SQint56,SSint56,SHint56,SDint56,SMint56,SPint56,SBint56};

int getLetter30(char letter){
    switch(letter){
        case 'q':return Qint30;case 'w':return Wint30;case 'e':return Eint30;case 'r':return Rint30;case 't':return Tint30;case 'y':return Yint30;case 'u':return Uint30;
        case 'i':return Iint30;case 'o':return Oint30;case 'p':return Pint30;case 'a':return Aint30;case 's':return Sint30;case 'd':return Dint30;case 'f':return Fint30;
        case 'g':return Gint30;case 'h':return Hint30;case 'j':return Jint30;case 'k':return Kint30;case 'l':return Lint30;case 'z':return Zint30;case 'x':return Xint30;
        case 'c':return Cint30;case 'v':return Vint30;case 'b':return Bint30;case 'n':return Nint30;case 'm':return Mint30;          
        case '1':return S1int30;case '2':return S2int30;case '3':return S3int30;case '4':return S4int30;case '5':return S5int30;case '6':return S6int30;case '7':return S7int30;
        case '8':return S8int30;case '9':return S9int30;case '0':return S0int30;case '.':return SFint30;case '!':return SIint30;case '?':return SQint30;case ';':return SSint30;
        case '@':return SMint30;case '#':return SHint30;case ':':return SDint30;case 'Q':return SPint30;
        default:return 0;
    }
}
unsigned long long getLetter56(char letter){
    switch(letter){
        case 'q':return Qint56;case 'w':return Wint56;case 'e':return Eint56;case 'r':return Rint56;case 't':return Tint56;case 'y':return Yint56;case 'u':return Uint56;
        case 'i':return Iint56;case 'o':return Oint56;case 'p':return Pint56;case 'a':return Aint56;case 's':return Sint56;case 'd':return Dint56;case 'f':return Fint56;
        case 'g':return Gint56;case 'h':return Hint56;case 'j':return Jint56;case 'k':return Kint56;case 'l':return Lint56;case 'z':return Zint56;case 'x':return Xint56;
        case 'c':return Cint56;case 'v':return Vint56;case 'b':return Bint56;case 'n':return Nint56;case 'm':return Mint56;        
        case '1':return S1int56;case '2':return S2int56;case '3':return S3int56;case '4':return S4int56;case '5':return S5int56;case '6':return S6int56;case '7':return S7int56;
        case '8':return S8int56;case '9':return S9int56;case '0':return S0int56;case '.':return SFint56;case '!':return SIint56;case '?':return SQint56;case ';':return SSint56;
        case '@':return SMint56;case '#':return SHint56;case ':':return SDint56;case 'Q':return SPint56;
        default:return 0;
    }
}
int countInString(string basic, string searched){//to count height --->scaleA
    int result=0;
    bool isNow=false;
    for(int a=0;a<basic.length()-searched.length()+1;a++){
            for(int b=0;b<searched.length();b++){
                isNow=true;
                if(basic[a+b]!=searched[b])isNow=false;
            }
            if(isNow==true)result++;
        }
    return result;
}
int getletter(int high,int width,int finwidth){return high*(finwidth+1)+width;}//->isletter
char isLetter(string basic,float startH,float startW,float endH,float endW,int height,int width)//scaleA
{//jeżeli w polu, o które pytamy jest jakakolwiek część litery, to będziemy w nim stawiać literę, dlatego musimy wiedzieć, czy stoi tu coś
    char tempC;
    tempC=basic[getletter(startH,startW,width)];
    if(tempC!=' '&&tempC!='\n'){return tempC;}
    else for(int a=startH;a<endH;a++)
    {
        for(int b=startW;b<endW;b++)
        {
            tempC=basic[getletter(a,b,width)];
            if(tempC!=' '&&tempC!='\n')return tempC;
        }
    }
    return ' ';
}
string MakeSpace(string word,int height){//join space to string//to 30 is 6, to 56 is 8
string res="";
    for(int a=0;a<height;a++){
        for(int b=(word.length()/height)*a;word[b]!='\n';b++)res+=word[b];
        res+="      \n";
    }
    return res;
}
string ConnectStrings(string firstPart,string secondPart,int height){//connect 2 strings, to 30 is 6, to 56 is 8
    string res="";
    for(int a=0;a<height;a++){
        for(int b=(firstPart.length()/height)*a;firstPart[b]!='\n';b++)
        res+=firstPart[b];
        res+=" ";
        for(int b=(secondPart.length()/height)*a;secondPart[b]!='\n';b++)
        res+=secondPart[b];
        res+="\n";
    }
    return res;
}
string scaleA(string image,int finHI,int finWI){//scale to given size
    int height=countInString(image,"\n");//+1(mod)
    int width=image.length()/height-1;//mod->(-1)
    string res="";
    for(int a=0;a<finHI;a++){
        for(int b=0;b<finWI;b++)res+=isLetter(image,((float)(a*height)/finHI),((float)(b*width)/finWI),(float)((1.0+a)*height/finHI),(float)((1.0+b)*width/finWI),height,width);
        res+="\n";
    }
    cout<<'\n'<<res;
    return res;
}
unsigned long long scale_to_long_int(string image){
    string scaled=scaleA(image,8,7);
    int len=scaled.length();
    unsigned long long res=0;
    for(int i=0;i<len;++i)
    {
        if(scaled[i]!='\n')
        {
            res*=2;
            if(scaled[i]!=' ')
            res+=1;
        }
    }
    return res;
}
double compare_56_int(unsigned long long first, unsigned long long second){
    unsigned long long res=first^second;
    int num0=0,num1=0;
    for(int i=0;i<56;i++)
    {
        if(res%2==0)num0++;
        else {num1++;res--;}
        res/=2;
    }
    if(num1>num0)return double(num1/56.0);
    else return double(num0/56.0);
}
string toString30(int num){//making string from bytes
    string res="";
    int flag=0b100000000000000000000000000000;
    for(int a=6;a>0;a--){
        for(int b=5;b>0;b--){
        if((num&flag)==flag)res+="M";
        else res+=" ";
        flag=flag/2;
    }
    res+="\n";
    }
    return res;
}
string toString56(unsigned long long num){//making string from bytes
    fstream output;
    string res="";
    long long flag=0b10000000000000000000000000000000000000000000000000000000;
    for(int a=8;a>0;a--)
    {for(int b=7;b>0;b--)
    {
        if((num&flag)==flag)res+="M";
        else res+=" ";
        flag=flag/2;
    }
    res+="\n";
    }
    return res;
}
unsigned long long compare_all(unsigned long long num){
    double best_apx=0;
    unsigned long long best_pointer=0;
    for(int i=0;i<45;i++){
        if(compare_56_int(num,all56[i])>best_apx){
        best_pointer=all56[i];
        best_apx=compare_56_int(num,all56[i]);
        }
    }
    cout<<100*best_apx<<'\n'<<toString56(best_pointer)<<'\n';
    return best_pointer;
}
string generate30FullWritting(string tresc){
    string res=toString30(getLetter30(tresc[0]));
    for(int a=1;a<tresc.length();a++){
        if(tresc[a]!=' ')res=ConnectStrings(res,toString30(getLetter30(tresc[a])),6);//alawys have to connect N-1 times, dividing would not make it better
        else res=MakeSpace(res,6);
    }
    scaleA(res,30,190);
    return res;
}
string generate56FullWritting(string tresc){
    string res=toString56(getLetter56(tresc[0]));
    for(int a=1;a<tresc.length();a++){
        if(tresc[a]!=' ')
        res=ConnectStrings(res,toString56(getLetter56(tresc[a])),8);//alawys have to connect N-1 times, dividing would not make it better
        else res=MakeSpace(res,8);
    }
    scaleA(res,30,190);
    return res;
}
string generate30FullWritting(string tresc,int height){
    string res=toString30(getLetter30(tresc[0]));
    for(int a=1;a<tresc.length();a++){
        if(tresc[a]!=' ')
        res=ConnectStrings(res,toString30(getLetter30(tresc[a])),6);//alawys have to connect N-1 times, dividing would not make it better
        else res=MakeSpace(res,6);
    }
    scaleA(res,height,170);
    return res;
}
string generate56FullWritting(string tresc,int height){
    string res=toString56(getLetter56(tresc[0]));
    for(int a=1;a<tresc.length();a++){
        if(tresc[a]!=' ')
        res=ConnectStrings(res,toString56(getLetter56(tresc[a])),8);//alawys have to connect N-1 times, dividing would not make it better
        else res=MakeSpace(res,8);
    }
    scaleA(res,height,170);
    return res;
}
string AutoScale30(string tresc){
    string res;
    int numberOfWords=countInString(tresc," ")+1;
    string word[5]={"","","","",""};
    int a=0,letter=0;
    for(int a=0;a<numberOfWords;a++){
        while(tresc[letter]!=' '&&letter<tresc.length()){
            word[a]+=tresc[letter];
            letter++;
        }
        if(tresc[letter]==' ')letter++;
    }
   for(int a=0;a<numberOfWords;a++)res=generate30FullWritting(word[a],(int)(40/numberOfWords));
   return res;
}
string AutoScale56(string tresc){
    string res;
    int numberOfWords=countInString(tresc," ")+1;
    string word[5]={"","","","",""};
    int a=0,letter=0;
    for(int a=0;a<numberOfWords;a++){
        while(tresc[letter]!=' '&&letter<tresc.length()){
            word[a]+=tresc[letter];
            letter++;
        }
        if(tresc[letter]==' ')letter++;
    }
   for(int a=0;a<numberOfWords;a++)res=generate56FullWritting(word[a],(int)(40/numberOfWords));
   return res;
}

void checksimilar()
{for(int i=0;i<44;i++)
        for(int j=i+1;j<45;++j)
            if (compare_56_int(all56[i],all56[j])>0.85)
                cout<<"close to each other: \n"<<toString56(all56[i])<<"\n\n"<<toString56(all56[j])<<'\n';}
int main()
{
    string napis="put text here!";
    AutoScale56(napis);
    return 0;
}