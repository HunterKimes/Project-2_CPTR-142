# This file contains the main program which will asses the readability of a paragraph

import functions
debug = True
correctFormat = False
YorN = ""

# Loop for program
while YorN != "N":

# Colect information loop
    while correctFormat == False:
        correctFormat = True
    
        paragraphInput = input("Enter a paragraph for a readability test: ")

        if functions.spaceTest(paragraphInput, debug) == False:
            print ("Paragraph can not have consecutive spaces.")
            correctFormat = False

        if functions.periodTest(paragraphInput, debug) == False:
            print ("Paragraph can not have consecutive puntuations marks.")
            correctFormat = False

    # Initalize variables
    words = functions.countWords(paragraphInput, debug)
    sententces = functions.countSentences(paragraphInput, debug)
    complex_words = functions.complexWords(paragraphInput, debug)
    characters = functions.countCharacters(paragraphInput, debug)

    # Run Gunning fog index
    print("Gunning fog index:", end = " ")

    gunning_fog_index = (float(0.4*((words/sententces) + 100*(complex_words/words))))

    if gunning_fog_index > 17:
        print("College graduate level")
    elif gunning_fog_index > 16:
        print("College senior level")
    elif gunning_fog_index > 15:
        print("College junior level")
    elif gunning_fog_index > 14:
        print("College sophomore level")
    elif gunning_fog_index > 13:
        print("College freshman level")
    elif gunning_fog_index > 12:
        print("High school senior level")
    elif gunning_fog_index > 11:
        print("High school junior level")
    elif gunning_fog_index > 10:
        print("High school sophomore level")
    elif gunning_fog_index > 9:
        print("High school freshman level")
    elif gunning_fog_index > 8:
        print("Eighth grade level")
    elif gunning_fog_index > 7:
        print("Seventh grade level")
    elif gunning_fog_index > 6:
        print("Sixth grade level")
    else: print("Below sixth grade level")

    # Run Automated readability index
    print("Automated readability index:", end = " ")

    automated_readability_index = (float((4.71*(characters/words)) + (0.5*(words/sententces)) -21.42))

    if automated_readability_index > 14:
        print("College student level")
    elif automated_readability_index > 13:
        print("Twelfth Grade level")
    elif automated_readability_index > 12:
        print("Eleventh Grade level")
    elif automated_readability_index > 11:
        print("Tenth Grade level")
    elif automated_readability_index > 10:
        print("Ninth Grade level")
    elif automated_readability_index > 9:
        print("Eighth Grade level")
    elif automated_readability_index > 8:
        print("Seventh Grade level")
    elif automated_readability_index > 7:
        print("Sixth Grade level")
    elif automated_readability_index > 6:
        print("Fifth Grade level")
    elif automated_readability_index > 5:
        print("Fourth Grade level")
    elif automated_readability_index > 4:
        print("Third Grade level")
    elif automated_readability_index > 3:
        print("Second Grade level")
    elif automated_readability_index > 2:
        print("First Grade level")
    else: print("Kindergarten level")

    print("General readability:", end = " ")

    generalReadability = (automated_readability_index + gunning_fog_index)/2

    if generalReadability > 14:
        print("Hard")
    elif generalReadability > 7:
        print("Medium")
    else: print("Easy")

    print("Asses another paragraph? Y or N")

    # Reset flags
    correctFormat = False

    # Repeat loop?
    YorN = input()