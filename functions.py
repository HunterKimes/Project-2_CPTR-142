# This file contaions all fuctions for the readability test

def spaceTest(paragraph, debug):
    if debug == True:
        print("*Checking pargraph format")
    if "  " in paragraph:
        return False
    else:
        return True

def periodTest(paragraph, debug):
    if debug == True:
        print("*Checking pargraph format")

    if ".." in paragraph:
        return False
    elif "??" in paragraph:
        return False
    elif "!!" in paragraph:
        return False
    elif ("." not in paragraph) and ("!" not in paragraph) and ("?" not in paragraph):
        return False
    else:
        return True

def countSentences(paragraph, debug):
    if debug == True:
        print("*Counting sentences")
    sentenceCount = 0

    for temp in paragraph:
        if temp in "?!.":
            sentenceCount += 1

    return sentenceCount

def countWords(paragraph, debug):
    wordCount = 1
    if debug == True:
        print("*Counting words")

    for temp in paragraph:
        if temp in " ":
            wordCount += 1  

    return wordCount

def complexWords(paragraph, debug):
    if debug == True:
        print("*Counting complex words")

    paragraph = paragraph.lower()
    vowel = 0
    cword = 0
    for temp in paragraph:
        if temp in "aeiou":
            vowel += 1
        elif temp == " " or ".":
            if vowel >= 3:
                cword += 1
            vowel = 0

    return cword
        
def countCharacters(paragraph, debug):
    if debug == True:
        print("*Counting characters")
    
    characterCount = 0

    for temp in paragraph:
        if temp not in ".?! ":
            characterCount += 1  
    
    return characterCount
