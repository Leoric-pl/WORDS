#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>

std::string WhichInSeq(std::string word1,std::string word2)
{
    int counterS=0;
    std::string res="";
    for (int conuterL=0;conuterL<word2.length();conuterL++)
    {
        if(word1[counterS]==word2[conuterL])
        {
            res+=word1[counterS];
        }
    }
    return res;
} 

void showAllSeq(std::string word1,std::string word2)
{
    for (int a=0;a<word2.length()-1;a++)
    {
        if(a==0)showAllSeq(word1,word2.substr(1,word2.length()-a));
        else showAllSeq(word1+word2.substr(0,a),word2.substr(a+1,word2.length()-a-1));   
    }
}

void showAllSeq(std::string word)
{
    for (int a=0;a<word.length()-1;a++)
    {
        if(a==0) showAllSeq(word.substr(1,word.length()-a));
        else showAllSeq(word.substr(0,a),word.substr(a+1,word.length()-a-1));
    }
}
std::string getAllSeq(std::string word1,std::string word2,std::string word3,std::string moist)
{
    std::string most=WhichInSeq(word1+word2,word3);
    if(most.length()>moist.length())moist=most;
    for (int a=0;a<word2.length()-1;a++)
    {
        if(a==0)most=getAllSeq(word1,word2.substr(1,word2.length()-a),word3,moist);
        else most=getAllSeq(word1+word2.substr(0,a),word2.substr(a+1,word2.length()-a-1),word3,moist); 
        if(most.length()>moist.length())moist=most;  
    }
    return moist;
}

std::string getAllSeq(std::string word,std::string word3,std::string moist)
{
    std::string most=WhichInSeq(word,word3);
    if(most.length()>moist.length())moist=most;
    for (int a=0;a<word.length()-1;a++)
    {
        if(a==0) most=getAllSeq(word.substr(1,word.length()-a),word3,moist);
        else most=getAllSeq(word.substr(0,a),word.substr(a+1,word.length()-a-1),word3,moist);
        if(most.length()>moist.length())moist=most;
    }
    return moist;
}

std::string mergeWords(std::string wordA, std::string wordB)
{
    std::string commonPart=getAllSeq(wordA,wordB,"");
    int shortC=0;
    int longC=0;
    int CommonP=0;
    std::string result="";
    int sum=wordA.length()+wordB.length()-commonPart.length();
    for (int i=0;i<sum;i++){
        if (longC==wordB.length())return result;
        if (shortC==wordA.length()) {
            result+=wordB[longC];
            longC+=1;
        }
        else if (wordA[shortC]==wordB[longC]){      result+=wordB[shortC];
            shortC+=1;
            longC+=1;
            CommonP+=1;      
            }
        else if (CommonP==commonPart.length()){
            result+=wordA[shortC];
            shortC+=1;}
        else if (wordA[shortC]==commonPart[CommonP] && wordB[longC]!=commonPart[CommonP]){
            result+=wordB[longC];
            longC+=1;}
        else
            {result+=wordA[shortC];
            shortC+=1;}
        }
    return result;
}


std::string makeMixedKey()
{
    printf("making key!\n");
    std::string key=" ";
    std::string napis;
    int countera=0;
    int counterb=0;
    std::fstream file;
    file.open("slowa/byLength.txt",std::ios::in);
    while(!file.eof())
        {  
            getline(file,napis);
        countera+=1;
        if(countera%10000==0)
        {
            counterb+=1;
            printf("%d\n",counterb);
        }
        key=mergeWords(napis,key);
        }
    file.close();
    std::cout<<"key"<<key<<"\n";
    std::fstream keyF;
    keyF.open("keys/key.txt", std::ios::app);
    keyF<<key;
    keyF.close();
    return key;
}
void sortdict()//makes dictionary sorted from longest to shortest words
{
    std::fstream in,out;
    std::string napis;
    int max=0;
    in.open("slowa/slowaBasedCharacter.txt",std::ios::in);
    out.open("slowa/byLength.txt",std::ios::out);
    while(!in.eof())
        {  
        getline(in,napis);
        if(napis.length()>max)max=napis.length();
        }
    in.close();
    for (int a=max;a>0;a--)
    {
        printf("%d\n",a);
        in.open("slowa/slowaBasedCharacter.txt",std::ios::in);
        while(!in.eof())
        {
            getline(in,napis);
            if(napis.length()==a)out<<napis<<"\n";
        }
        in.close();
    }

}
int main()
{

   sortdict();
   makeMixedKey();
   return 0;
}