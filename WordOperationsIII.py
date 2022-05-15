from AdvancedWordOperations import *

licznik=0

def analyzeString(path, many):
    seq=open(path,'r')
    i=0
    for line in seq:
        print('key '+str(i)+' :')
        table=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
        for j in range(len(line)-1):
            letter=line[j].lower()
            table[letters.index(letter)]+=1
        i+=1
        for j in range(26):
            if table[j]>many:
                print(letters[j]+str(table[j]))
        MyMax=max(table)
        print('max: '+letters[table.index(MyMax)]+' : '+str(MyMax))
        print(' ')
        MyMax=min(table)
        print('min: '+letters[table.index(MyMax)]+' : '+str(MyMax))
        print(' ')

    seq.close()
def searchsequence(path, sequence):
    bpath=path+'.txt'
    seq=open(bpath,'r')
    i=0
    for line in seq:
        counter=0
        actual=0
        for j in range(len(line)-1):
            letter=line[j].lower()
            if letter==sequence[actual]:
                actual+=1
                if actual==len(sequence):
                    actual=0
                    counter+=1
        i+=1
    seq.close()
    return counter
def checkall(number,text):
    if(number>0):
        for a in letters:
            checkall(number-1,text+a)
            num=searchsequence('sequence1',text+a)
            if(num*(len(text+a))>30):
                print(str(num)+' '+text+a)


####makeLetters() 
#makeFirstKey(b1path)
#makeFirstStrongLast(b1path)
#analyzeString('sequence1',0)
#analyzeString('sequence1',10)
#####makeXFirstStrong(b1path)
#checkall(5,'')
#pickBestKey(b1path)

def preparedict(path):
    bpath=path+'.txt'
    outpath=path+'Upgraded.txt'
    tempPath='temp.txt'
    seq=open(outpath,'a')
    basic=open(bpath,'r')
  #  for line in basic:
                
    seq.close()

def pointletters(longSequence, shortSequence):
    a=len(shortSequence)
    counter=0
    newseq=''
    for i in range(len(longSequence)):
        if longSequence[i]==shortSequence[counter]:
            counter+=1
            newseq+='^'
            if counter>=len(shortSequence):break
        else: newseq+=' '
  #  print (longSequence)
  #  print(newseq)
    if counter==len(shortSequence):
        #print('success')
        return True
    return False
def main14no(path):
    basic=open(path,'r')
    itWorked=True
    i=0
    for line in basic:
        print (line)
        i+=1
        short=line
        itWorked= itWorked and pointletters('neozwsomtaciboariwatyczdaolaicszahyiaejirpaifonsicoeunjyiahminyawitucneywayizhlmisuyoekizyfiamcuoizyebiyojniwcuasjonrieymidzbuenmwkoeiyirwezmuvicnmwhebmuaihomjaoicqamdwcnzjaipokhaigfsl\n',short) 
        if not itWorked:
            print('error before'+str(i))
            basic.close()
            return 1
    basic.close()
    return 0
#main14no('slowa/slowaBasedCharacter.txt')
def errorNumbers(path,key):
    i=0
    basic=open(path,'r')
    itWorked=True
    good=0
    bad=0
    for line in basic:
        i+=1
        #print (line)
        
        short=line
        res= pointletters(key,short) 
        if res:
            good+=1
        else: bad+=1
        if(i>1000000):#50k/s
            basic.close()
            print('rate: '+ str(good)+' / '+str(good+bad)+' :'+str(good/(good+bad)))
            return 1
    basic.close()
    #print('rate:'+ good+' / '+good+bad+' :'+good/(good+bad))
    return 0

#errorNumbers('slowa/slowaBasedCharacter.txt','neozsdolmurpcbsairoagtculozejnkwcyhiasmzepainweiyzfoigtdayijeykcozlnytimjeckwloiyechsmwyuedazimyaismycjhoezmaiyoemaeuzrgicsneyiojcietsyoaimrwioyemszgweymaheokmasweacyieaoiuhoneidwyeaiocweuckoyz\n')
#errorNumbers('slowa/slowaBasedCharacter.txt','neozwsomtaciboariwatyczdaolaicszahyiaejirpaifonsicoeunjyiahminyawitucneywayizhlmisuyoekizyfiamcuoizyebiyojniwcuasjonrieymidzbuenmwkoeiyirwezmuvicnmwhebmuaihomjaoicqamdwcnzjaipokhaigfsl\n')

def lettersInSeq(short,long):
    result=''
    currS=0
    for i in long:
        if(currS==len(short)):
            return result
        elif(short[currS]==i):
            result+=short[currS]
            currS+=1
            if(currS==len(short)):
                return result
    return result

def getAllcombinationsNEW2(word1,word2,long,lcomb):
    if lcomb=='': 
        ncomb=lettersInSeq(word1+word2,long)
        if ncomb==word1+word2: return ncomb
    #global licznik
    #licznik+=1    #print(word1+word2)
    for i in range(len(word2)):    
        if i==0:
            newseq=''
            for a in range(len(word2)):
                if a!=i:newseq+=word2[a]
            #print(word1+':  :'+newseq+':')
            ncomb=lettersInSeq(word1+newseq,long)
            if(len(lcomb)<len(ncomb)):
                lcomb=ncomb
            ncomb=getAllcombinationsNEW2(word1,newseq,long,lcomb)
            if(len((str)(ncomb))>len(lcomb)):
                lcomb=ncomb
        else:
            newseq1=word1
            newseq2=''
            for a in range(len( word2)):
                if a<i: 
                    newseq1+=word2[a]
                elif i<a: 
                    newseq2+=word2[a]
           # print(newseq1+':  :'+newseq2+':')
            ncomb=lettersInSeq(newseq1+newseq2,long)
            if(len(lcomb)<len(ncomb)):
                lcomb=ncomb
            ncomb=getAllcombinationsNEW2(newseq1,newseq2,long,lcomb)
            if(len((str)(ncomb))>len(lcomb)):
                lcomb=ncomb
    return lcomb

def getAllcombinationsNEW(word,long,lcomb):
    if lcomb=='': 
        ncomb=lettersInSeq(word,long)
        if ncomb==word: return ncomb
    for isNot in range(len(word)):    
        if isNot==0:
            newseq=''
            for a in range(len(word)):
                if a!=isNot:newseq+=word[a]
            ncomb=lettersInSeq(newseq,long)
            if(len(lcomb)<len(ncomb)):
                lcomb=ncomb
            ncomb=getAllcombinationsNEW(newseq,long,lcomb)
            if(len((str)(ncomb))>len(lcomb)):
                lcomb=ncomb
        else:
            newseq1=''
            newseq2=''
            for a in range(len( word)):
                if a<isNot: 
                    newseq1+=word[a]
                elif isNot<a: 
                    newseq2+=word[a]
            #print(newseq1+':  :'+newseq2+':')
            ncomb=lettersInSeq(newseq1+newseq2,long)
            if(len(lcomb)<len(ncomb)):
                lcomb=ncomb
            ncomb=getAllcombinationsNEW2(newseq1,newseq2,long,lcomb)
            if(len((str)(ncomb))>len(lcomb)):
                lcomb=ncomb
    return lcomb
                
   

def getAllcombinations(word,long,lcomb):
    if lcomb=='': 
        ncomb=lettersInSeq(word,long)
        if ncomb==word: return ncomb  
    if(len(word)>=2):
        for i in range(len(word)):
            newW=''
            for j in range(len(word)):
                if(i!=j):#only one for each i
                    newW+=word[j]
            ncomb=lettersInSeq(newW,long)
            if(len(lcomb)<len(ncomb)):
                lcomb=ncomb
            ncomb=getAllcombinations(newW,long,lcomb)
            if(len((str)(ncomb))>len(lcomb)):
                lcomb=ncomb
        return lcomb
    else:return ''

def mergeWords(short,long):
    commonPart=getAllcombinationsNEW(short,long,'')
    shortC=0
    longC=0
    CommonP=0
    result=''
    sum=len(short)+len(long)-len(commonPart)
    #print( short+(str)(len(short))+'  '+(str)(len(long))+long+'  '+(str)(len(commonPart))+commonPart+'  ' )
    for i in range(sum):
        if longC==len(long):
            return result
        if shortC==len(short) :
            result+=long[longC]
            longC+=1
        elif short[shortC]==long[longC]:
            result+=short[shortC]
            shortC+=1
            longC+=1
            CommonP+=1      
        elif CommonP==len(commonPart):
            result+=short[shortC]
            shortC+=1
        elif short[shortC]==commonPart[CommonP] and long[longC]!=commonPart[CommonP]:
            result+=long[longC]
            longC+=1
        else:
            result+=short[shortC]
            shortC+=1
    return result 
#print(getAllcombinations('aledsfisdfn','mbafuosfnljsufnpwldkaemo',''))
def makeaddingAtEndKey(path):
    key=''
    file=open(path,'r')
    for line in file:
        for i in range(len(lettersInSeq(line,key)),len(line)-1):
            key+=line[i]
    file.close()
    print('key: '+key)
#makeaddingAtEndKey("slownik.txt")

def makeMixedKey(path):
    key=' '
    countera=0
    counterb=0
    file=open(path,'r')
    for line in file:
        countera+=1
        if(countera%10000==0):
            counterb+=1
            print(counterb)

        #line1=''
       # for i in range(len(line)-1):
           # line1+=line[i]
        #key=mergeWords(line1,key)
        key=mergeWords(line,key)
    file.close()
    print('key: '+key)
makeMixedKey("slowa/slowaBasedCharacter.txt")



#getAllcombinationsNEW('makroprocesor')
#getAllcombinationsNEW('makroprocesor','','')
#print(licznik)
