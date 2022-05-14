import time
from BasicWordOperations import *

def removeFirst(basicpath, newpath, DLetter):
    modify=open(newpath,'w')
    base=open(basicpath,'r')
    for line in base:
        letter=line.lower()[0]
        if letter==DLetter:
            modify.write(line[1:])
        else: modify.write(line)
    modify.close()
    base.close()

def removeLast(basicpath, newpath, DLetter):
    modify=open(newpath,'w')
    base=open(basicpath,'r')
    for line in base:
        letter=line.lower()[len(line)-2]
        if letter==DLetter:
            modify.write(line[0:len(line)-2])
        else: modify.write(line)
    modify.close()
    base.close()


def makeFirstKey(path):
    bpath=path+'.txt'
    outpath=path+'FirstKey.txt'
    seq=open(outpath,'a')
    best=findMostFirstletter(bpath)
    seq.write(best)
    removeFirst(bpath,cpath,best)
    for a in range(200):
        best=findMostFirstletter(cpath)
        seq.write(best)
        removeFirst(cpath,dpath,best)
        if not isWord(dpath):
            break
        best=findMostFirstletter(dpath)
        seq.write(best)
        removeFirst(dpath,cpath,best)
        if a%50==0: print('processing...'+str(a/2)+'%')
        if not isWord(cpath):
            break
    seq.close()

def makeFirstStrong(path):
    bpath=path+'.txt'
    outpath=path+'FirstStrongKey.txt'
    seq=open(outpath,'w')
    best=findMostFrontFirstletter(bpath)
    seq.write(best)
    removeFirst(bpath,cpath,best)
    for a in range(200):
        best=findMostFrontFirstletter(cpath)
        seq.write(best)
        removeFirst(cpath,dpath,best)
        if not isWord(dpath):
            break
        best=findMostFrontFirstletter(dpath)
        seq.write(best)
        removeFirst(dpath,cpath,best)
        if a%2==0: print('processing...'+str(a/2)+'%')
        if not isWord(cpath):
            break
    seq.close()

def mainFL(path):
    bpath=path+'.txt'
    outpath=path+'FirstLastKey.txt'
    seq=open(outpath,'w')
    best=findMostFirstletter(bpath)
    keyF=best
    keyL=''
    removeFirst(bpath,cpath,best)
    for a in range(200):
        best=findMostLastletter(cpath)
        keyL=best+keyL
        removeLast(cpath,dpath,best)
        if not isWord(dpath):
            break
        best=findMostFirstletter(dpath)
        keyF+=best
        removeFirst(dpath,cpath,best)
        if a%2==0: print('processing...'+str(a/2)+'%')
        if not isWord(cpath):
            break        
    print('done')    
    seq.write(keyF+keyL)
    seq.close()

def makeFirstStrongLast(path):
    bpath=path+'.txt'
    outpath=path+'FirstStrongLastKey.txt'
    seq=open(outpath,'w')
    best=findMostFrontFirstletter(bpath)
    keyF=best
    keyL=''
    removeFirst(bpath,cpath,best)
    for a in range(200):
        best=findMostLastletter(cpath)
        keyL=best+keyL
        removeLast(cpath,dpath,best)
        if not isWord(dpath):
            break
        best=findMostFrontFirstletter(dpath)
        keyF+=best
        removeFirst(dpath,cpath,best)
        if a%2==0: print('processing...'+str(a/2)+'%')
        if not isWord(cpath):
            break        
    print('done')    
    seq.write(keyF+keyL)
    seq.close()

def makeXFirstStrong(path):
    sTime=time.time()
    print('Time start!')
    bpath=path+'.txt'
    outpath=path+'FirstStrongKey.txt'
    seq=open(outpath,'w')
    best=findXMostFrontFirstletter(bpath)
    seq.write(best)
    removeFirst(bpath,cpath,best)
    for a in range(200):

        best=findXMostFrontFirstletter(cpath)
        seq.write(best)
        removeFirst(cpath,dpath,best)
        if not isWord(dpath):
            break
        
        best=findXMostFrontFirstletter(dpath)
        seq.write(best)
        removeFirst(dpath,cpath,best)
        eTime=time.time()
        if a%2==0: print('processing...'+str(a/2)+'%')

        if(a%20==1):print('estimated time: '+str((eTime-sTime)*(200-a)/(2*a)))
        if not isWord(cpath):
            break
    print('done')
    seq.close()

def pickBestKey(b1path):
    Fpath=b1path+'FirstKey.txt'
    FSpath=b1path+'FirstStrongKey.txt'
    FSLpath=b1path+'FirstStrongLastKey.txt'
    FLpath=b1path+'FirstLastKey.txt'
    FSLkey=0
    FSkey=0
    Fkey=0
    FLkey=0
    FXkey=0

    Fdo=open(Fpath,'r')
    for line in Fdo:
        if(len(line)>1):
            Fkey=len(line)
        else: Fkey=10000
    Fdo.close()

    Fdo=open(FSpath,'r')
    for line in Fdo:
        if(len(line)>1):
            FXkey=len(line)
        else: FXkey=10000
    Fdo.close()

    Fdo=open(FSLpath,'r')
    for line in Fdo:
        if(len(line)>1):
            FSLkey=len(line)
        else: FSLkey=10000
    Fdo.close()

    Fdo=open(FLpath,'r')
    for line in Fdo:
        if(len(line)>1):
            FLkey=len(line)
        else: FLkey=10000
    Fdo.close()
    Fdo=open(FLpath,'r')
    for line in Fdo:
        if(len(line)>1):
            FLkey=len(line)
        else: FLkey=10000
    Fdo.close()

    bkey=min(Fkey, FLkey,FSkey,FSLkey,FXkey)
    print('najkrotszy klucz wynosi:'+str(bkey))
    if(bkey==Fkey):print('First-key jest najkrotszy')
    if(bkey==FSkey):print('First-strong-key jest najkrotszy')
    if(bkey==FSLkey):print('First-strong-lastkey jest najkrotszy')
    if(bkey==FLkey):print('First-last-key jest najkrotszy')
    
    print('Fkey:'+str(Fkey))
    print('FSkey:'+str(FSkey))
    print('FSLkey:'+str(FSLkey))
    print('FLkey:'+str(FLkey))


