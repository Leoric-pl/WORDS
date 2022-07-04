b1path='slowa/slowaBasedCharacter'
testpath='slownik'
cpath='s1.txt'
dpath='s2.txt'
epath='sequence'

letters=[]
def make_letters():
    for i in range(97,123):
        letters.append(chr(i))

def is_word(path):#is word in the file
    basic=open(path,'r')
    for line in basic:
        if(len(line)>1):
            basic.close()
            return True
    basic.close()
    return False

def find_most_front_first_letter(path):
    table=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    basic=open(path,'r')
    for line in basic:
        if len(line)>1:
            letter=line.lower()[0]
            table[letters.index(letter)]+=len(line)
    basic.close()
    return letters[table.index(max(table))]

def find_enchanced_most_front_first_letter(path):
    table=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    basic=open(path,'r')
    for line in basic:
        if len(line)>1:
            letter=line.lower()[0]
            table[letters.index(letter)]+=(len(line)*len(line))
    basic.close()
    return letters[table.index(max(table))]

def find_most_first_letter(path):
    table=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    basic=open(path,'r')
    for line in basic:
        if len(line)>1:
            letter=line.lower()[0]
            table[letters.index(letter)]+=1
    basic.close()
    return letters[table.index(max(table))]

def find_most_last_letter(path):
    table=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    basic=open(path,'r')
    for line in basic:
        if len(line)>1:
            letter=line.lower()[len(line)-2]
            table[letters.index(letter)]+=1
    basic.close()
    return letters[table.index(max(table))]