import time
from BasicWordOperations import *

def remove_first(basicpath, newpath, DLetter):
    modify=open(newpath,'w')
    base=open(basicpath,'r')
    for line in base:
        letter=line.lower()[0]
        if letter==DLetter:
            modify.write(line[1:])
        else: modify.write(line)
    modify.close()
    base.close()

def remove_last(basicpath, newpath, DLetter):
    modify=open(newpath,'w')
    base=open(basicpath,'r')
    for line in base:
        letter=line.lower()[len(line)-2]
        if letter==DLetter:
            modify.write(line[0:len(line)-2])
        else: modify.write(line)
    modify.close()
    base.close()


def make_first_key(path):
    bpath=path+'.txt'
    outpath=path+'FirstKey.txt'
    seq=open(outpath,'a')
    best=find_most_first_letter(bpath)
    seq.write(best)
    remove_first(bpath,cpath,best)
    for a in range(200):
        best=find_most_first_letter(cpath)
        seq.write(best)
        remove_first(cpath,dpath,best)
        if not is_word(dpath):
            break
        best=find_most_first_letter(dpath)
        seq.write(best)
        remove_first(dpath,cpath,best)
        if a%50==0: print('processing...'+str(a/2)+'%')
        if not is_word(cpath):
            break
    seq.close()

def make_first_strong(path):
    bpath=path+'.txt'
    outpath=path+'FirstStrongKey.txt'
    seq=open(outpath,'w')
    best=find_most_front_first_letter(bpath)
    seq.write(best)
    remove_first(bpath,cpath,best)
    for a in range(200):
        best=find_most_front_first_letter(cpath)
        seq.write(best)
        remove_first(cpath,dpath,best)
        if not is_word(dpath):
            break
        best=find_most_front_first_letter(dpath)
        seq.write(best)
        remove_first(dpath,cpath,best)
        if a%2==0: print('processing...'+str(a/2)+'%')
        if not is_word(cpath):
            break
    seq.close()

def mainFL(path):
    bpath=path+'.txt'
    outpath=path+'FirstLastKey.txt'
    seq=open(outpath,'w')
    best=find_most_first_letter(bpath)
    keyF=best
    keyL=''
    remove_first(bpath,cpath,best)
    for a in range(200):
        best=find_most_last_letter(cpath)
        keyL=best+keyL
        remove_last(cpath,dpath,best)
        if not is_word(dpath):
            break
        best=find_most_first_letter(dpath)
        keyF+=best
        remove_first(dpath,cpath,best)
        if a%2==0: print('processing...'+str(a/2)+'%')
        if not is_word(cpath):
            break        
    print('done')    
    seq.write(keyF+keyL)
    seq.close()

def make_first_strong_last(path):
    bpath=path+'.txt'
    outpath=path+'FirstStrongLastKey.txt'
    seq=open(outpath,'w')
    best=find_most_front_first_letter(bpath)
    keyF=best
    keyL=''
    remove_first(bpath,cpath,best)
    for a in range(200):
        best=find_most_last_letter(cpath)
        keyL=best+keyL
        remove_last(cpath,dpath,best)
        if not is_word(dpath):
            break
        best=find_most_front_first_letter(dpath)
        keyF+=best
        remove_first(dpath,cpath,best)
        if a%2==0: print('processing...'+str(a/2)+'%')
        if not is_word(cpath):
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
    best=find_enchanced_most_front_first_letter(bpath)
    seq.write(best)
    remove_first(bpath,cpath,best)
    for a in range(200):

        best=find_enchanced_most_front_first_letter(cpath)
        seq.write(best)
        remove_first(cpath,dpath,best)
        if not is_word(dpath):
            break
        
        best=find_enchanced_most_front_first_letter(dpath)
        seq.write(best)
        remove_first(dpath,cpath,best)
        eTime=time.time()
        if a%2==0: print('processing...'+str(a/2)+'%')

        if(a%20==1):print('estimated time: '+str((eTime-sTime)*(200-a)/(2*a)))
        if not is_word(cpath):
            break
    print('done')
    seq.close()

def pickBestKey(b1path):
    Fpath=b1path+'FirstKey.txt'
    FSpath=b1path+'FirstStrongKey.txt'
    FSLpath=b1path+'FirstStrongLastKey.txt'
    FLpath=b1path+'FirstLastKey.txt'
    first_strong_last_key=0
    first_strong_key=0
    first_key=0
    first_last_key=0
    FXkey=0

    Fdo=open(Fpath,'r')
    for line in Fdo:
        if(len(line)>1):
            first_key=len(line)
        else: first_key=10000
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
            first_strong_last_key=len(line)
        else: first_strong_last_key=10000
    Fdo.close()

    Fdo=open(FLpath,'r')
    for line in Fdo:
        if(len(line)>1):
            first_last_key=len(line)
        else: first_last_key=10000
    Fdo.close()
    Fdo=open(FLpath,'r')
    for line in Fdo:
        if(len(line)>1):
            first_last_key=len(line)
        else: first_last_key=10000
    Fdo.close()

    bkey=min(first_key, first_last_key,first_strong_key,first_strong_last_key,FXkey)
    print('najkrotszy klucz wynosi:'+str(bkey))
    if(bkey==first_key):print('First-key jest najkrotszy')
    if(bkey==first_strong_key):print('First-strong-key jest najkrotszy')
    if(bkey==first_strong_last_key):print('First-strong-lastkey jest najkrotszy')
    if(bkey==first_last_key):print('First-last-key jest najkrotszy')
    
    print('first_key:'+str(first_key))
    print('first_strong_key:'+str(first_strong_key))
    print('first_strong_last_key:'+str(first_strong_last_key))
    print('first_last_key:'+str(first_last_key))


