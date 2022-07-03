#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//letters
const int   Aint30=0b011100101011011100011111110001,Bint30=0b111101001011111100011000111111,Cint30=0b111111000010000100001000011111,Dint30=0b111101001110001100011001111110,
            Eint30=0b111101000011100100001000011111,Fint30=0b111101000011100100001000010000,Gint30=0b111111000110000101111001011110,Hint30=0b100011000110001111111000110001,
            Iint30=0b011100010000100001000010001110,Jint30=0b111100001000010000101001011110,Kint30=0b100011001010100111001001010001,Lint30=0b100001000010000100001000011110,
            Mint30=0b100011101110101100011000110001,Nint30=0b100011100110101101011001110001,Oint30=0b011101101110001100011101101110,Pint30=0b111101001011110100001000010000,
            Qint30=0b111101001010010100101111000011,Rint30=0b111101001011110111001001010001,Sint30=0b111111000011111000010000111111,Tint30=0b111110010000100001000010000100,
            Uint30=0b100011000110001100011000111111,Wint30=0b100011000110001101011101110001,Vint30=0b100011000110001010100111000100,Xint30=0b100010101000100001000101010001,
            Yint30=0b100010101000100001000010000100,Zint30=0b111110000100010001000100011111;
            //other
const int   S1int30=0b001000110000100001000010001110,S2int30=0b001110100100010001000100001111,S3int30=0b001110100100001001100000101110,S4int30=0b000100011001010100101111100010,
            S5int30=0b011110100001110000010100100110,S6int30=0b001100100101000011110100100110,S7int30=0b011110000100010001000010000100,S8int30=0b001100100100110010010100100110,
            S9int30=0b001100100100111000010100100110,S0int30=0b001100100101001010010100100110,SIint30=0b001000010000100001000000000100,SQint30=0b001100100100010001000000000100,
            SSint30=0b000000000000100000000010001000,SDint30=0b000000000000100000000010000000,SFint30=0b000000000000000000000000000100,SHint30=0b010100101011111010101111101010,
            SMint30=0b011101000110101101111000001110;



int getLetter30(char letter)
{
    switch(letter)
    {
        case 'q':return Qint30;case 'w':return Wint30;case 'e':return Eint30;case 'r':return Rint30;case 't':return Tint30;case 'y':return Yint30;case 'u':return Uint30;
        case 'i':return Iint30;case 'o':return Oint30;case 'p':return Pint30;case 'a':return Aint30;case 's':return Sint30;case 'd':return Dint30;case 'f':return Fint30;
        case 'g':return Gint30;case 'h':return Hint30;case 'j':return Jint30;case 'k':return Kint30;case 'l':return Lint30;case 'z':return Zint30;case 'x':return Xint30;
        case 'c':return Cint30;case 'v':return Vint30;case 'b':return Bint30;case 'n':return Nint30;case 'm':return Mint30;        
        
        case '1':return S1int30;case '2':return S2int30;case '3':return S3int30;case '4':return S4int30;case '5':return S5int30;case '6':return S6int30;case '7':return S7int30;
        case '8':return S8int30;case '9':return S9int30;case '0':return S0int30;case '.':return SFint30;case '!':return SIint30;case '?':return SQint30;case ';':return SSint30;
        case '@':return SMint30;case '#':return SHint30;case ':':return SDint30;                    
        
        
        default:return 0;
    }
}

int countInString(string basic, string searched)//to count height --->scaleA
{
    int result=0;
    bool isNow=false;
    for(int a=0;a<basic.length()-searched.length()+1;a++)
        {
            for(int b=0;b<searched.length();b++)
            {
                isNow=true;
                if(basic[a+b]!=searched[b])
                    {isNow=false;}
            }
            if(isNow==true){result++;}
        }
        return result;}
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
string MakeSpace30(string word)//join space to string
{string res="";
    for(int a=0;a<6;a++)
    {
        for(int b=(word.length()/6)*a;word[b]!='\n';b++)res+=word[b];
        res+="      \n";
    }
    return res;
}
string ConnectStrings30(string firstPart,string secondPart)//connect 2 strings
{
    string res="";
    for(int a=0;a<6;a++)
    {
        for(int b=(firstPart.length()/6)*a;firstPart[b]!='\n';b++)
        res+=firstPart[b];
        res+=" ";
        for(int b=(secondPart.length()/6)*a;secondPart[b]!='\n';b++)
        res+=secondPart[b];
        res+="\n";
    }
    return res;
}

string scaleA(string image,int finHI,int finWI)//scale to given size
{
    int height=countInString(image,"\n");
    int width=image.length()/height-1;
    string res="";
    for(int a=0;a<finHI;a++)
    {
        for(int b=0;b<finWI;b++)res+=isLetter(image,((float)(a*height)/finHI),((float)(b*width)/finWI),(float)((1.0+a)*height/finHI),(float)((1.0+b)*width/finWI),height,width);
        res+="\n";
    }
    cout<<endl;
    cout<<res;
    return res;
}

string toString30(int num)//making string from bytes
{
    fstream output;
    output.open("A.txt,ios::out");

    string res="";
    int flag=0b100000000000000000000000000000;
    for(int a=6;a>0;a--)
    {for(int b=5;b>0;b--)
    {
        if((num&flag)==flag)res+="M";
        else res+=" ";
        flag=flag/2;
    }
    res+="\n";
    }
    output<<res;
    output.close();
    return res;
}
string generate30FullWritting(string tresc)
{
    string res=toString30(getLetter30(tresc[0]));
    for(int a=1;a<tresc.length();a++)
    {
        if(tresc[a]!=' ')
        res=ConnectStrings30(res,toString30(getLetter30(tresc[a])));//alawys have to connect N-1 times, dividing would not make it better
        else res=MakeSpace30(res);
    }
    
    scaleA(res,30,190);
    return res;
}
string generate30FullWritting(string tresc,int height)
{
    string res=toString30(getLetter30(tresc[0]));
    for(int a=1;a<tresc.length();a++)
    {
        if(tresc[a]!=' ')
        res=ConnectStrings30(res,toString30(getLetter30(tresc[a])));//alawys have to connect N-1 times, dividing would not make it better
        else res=MakeSpace30(res);
    }
    
    scaleA(res,height,62);
    return res;
}
void AutoScale(string tresc)
{
    
    int numberOfWords=countInString(tresc," ")+1;
    cout<<numberOfWords<<"\n";
    string word[5]={"","","","",""};
    int a=0,letter=0;
    for(int a=0;a<numberOfWords;a++)
    {
        while(tresc[letter]!=' '&&letter<tresc.length())
        {
            word[a]+=tresc[letter];
            letter++;
        }
        if(tresc[letter]==' '){letter++;}
    }
   for(int a=0;a<numberOfWords;a++)
    {
         generate30FullWritting(word[a],(int)(40/numberOfWords));
    }
    
}

int main()
{   
    AutoScale("put text here");
    return 0;
}