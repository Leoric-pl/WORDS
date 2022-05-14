#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
int locznik=0;
void showAllSeq(std::string word1,std::string word2)
{
    locznik++;
    for (int a=0;a<word2.length()-1;a++)
    {
        if(a==0)
            {
            showAllSeq(word1,word2.substr(1,word2.length()-a));
            }
        else{
            showAllSeq(word1+word2.substr(0,a),word2.substr(a+1,word2.length()-a-1));
            }
    }
}

void showAllSeq(std::string word)
{
    locznik++;
    //std::string newSeq1;
    //std::cout<<word<<"\n";
    for (int a=0;a<word.length()-1;a++)
    {
        if(a==0)
            {
            showAllSeq(word.substr(1,word.length()-a));
            }
        else{
            showAllSeq(word.substr(0,a),word.substr(a+1,word.length()-a-1));
        
    }
    //std::cout<<newSeq1<<"\n";
    }
}
void showAllSeqb(std::string napis)
{
    std::string newSeq1;
    //std::string newSeq1;
    for (int a=0;a<napis.length()-1;a++)
    {
        if(a==0)
            {
            newSeq1=napis.substr(1,napis.length()-a);
            }
        else{
            newSeq1=napis.substr(0,a)+napis.substr(a+1,napis.length()-a-1);
        showAllSeqb(newSeq1);
    }
    //std::cout<<newSeq1<<"\n";
    }
}

int main()
{
    //std::fstream reader;
    //reader.open("slownik.txt",std::ios::in);
    std::string napis;
    /*if( reader.good())
    {
        printf("Uzyskano dostep do pliku!\n");
        while(!reader.eof())
        {
            getline( reader, napis );
            std::cout<<napis<<" "<<napis.length()<<"\n";//napis i jego dlugosc
            std::cout<<napis.substr(0,2)<<"\n";//substring o starcie w 0 i dlugosci 2
            */
           //showAllSeqb("makroprocesor");printf("done");
            showAllSeq("makroprocesor");
            std::cout<<locznik<<"\n";
        /*}
        reader.close();
    } 
    else printf("Dostep do pliku zostal zabroniony!\n");
    */return 0;
}