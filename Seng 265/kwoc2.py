#!/opt/rh/rh-python36/root/usr/bin/python3



 

"""

Assignment 2

Name: Gurik Manshahia

Student ID: V00863509

Class:Seng265

Date: 26/02/2020

"""

import sys

import fileinput

 

#determines if a non-exclusion word is repeated more than once.

#returns the number of time the a keyword is repeated

def num_occurrences(sentence_line,final_text):

        num_occurs =0

        j = 0

        buff = sentence_line.split()

        while j < len(buff):

                if(buff[j].upper() == final_text.upper()):

                       num_occurs += 1

                j += 1

        return num_occurs -1

#compares the words in the sentence and the word that is not excluded

#returns 1 if the word is in the sentence otherwise it will return 0

def word_compare(sentence_lines,final_text):

        i = 0

        buff = sentence_lines.split()

       

        while i < len(buff):

                if(buff[i] == final_text.upper()):

                       return True

                       break

                if(buff[i] == final_text.lower()):

                       return True

                       return

                else:

                       i+=1

        return False

#Finds the longest word. Used for output formating

def longest_word(word_size):

        i = 0

        longest = 0

        for i in range(0,len(word_size)):

                if(len(word_size[i]) >= longest):

                       longest = len(word_size)

        return longest

 

 

#main.

def main():

        num_exclusion_words = 0

        num_words = 0

        num_lines = 0

        num_occur = 0

        final_text = []

       

        #The code below determines whether there is a -e in the

        #input and exits if there is no -e.

        if(sys.argv[1] == "-e"):

                with open(sys.argv[2],'r') as f2:

                       english_text = f2.read()

                with open(sys.argv[3], 'r') as f1:

                       text_file = f1.read()

                with open(sys.argv[3], 'r') as f3:

                       sentence_lines = f3.readlines()

 

        if(sys.argv[2] == "-e"):

                with open(sys.argv[3],'r') as f2:

                       english_text = f2.read()

                with open(sys.argv[1], 'r') as f1:

                       text_file = f1.read()

                with open(sys.argv[1], 'r') as f3:

                       sentence_lines = f3.readlines()

 

        #If -e is not found display the output below.

        if(sys.argv[1] != "-e" and sys.argv[2] != "-e" or len(sys.argv) < 3):

                print("You either forgot the -e or did not type 3 inputs.")

                exit()

 

        text_tokens = text_file.split()

        exclusion_words_token = english_text.split()

       

        in_eng = 0

        r = 0

        x =0

        new_text = []

        """Adds all the words to a new

           list (new_text) that is not

           in the exclusion words."""

        while x < len(text_tokens):

                y = 0

                while y<len(exclusion_words_token):

                       uppercase_text = text_tokens[x].upper()

                       uppercase_exclusion = exclusion_words_token[y].upper()

                       if (uppercase_text == uppercase_exclusion):

                               in_eng = 1;

                       y+=1

                if in_eng == 0:

                       new_text.append(text_tokens[x].upper())

                       r+=1

                x+=1

                in_eng = 0

    #sort the list of words.

        new_text.sort()

        counter1 = 0

        z = 0

        x = 0

        #removes all duplicates of words in the list final_text.

        final_text.append(new_text[0])

        while z < len(new_text):

                if final_text[x] != new_text[z]:

                       final_text.append(new_text[z])

                       x += 1

                       counter1 += 1

                z += 1

        m = 0

        temp = 0

        #The for loop below gets the longest keyword

        for m in range(0,len(final_text)):

                longest_words = longest_word(final_text[m]) + 1

                if(temp < longest_words):

                       temp = longest_words

                if(longest_words < temp):

                       longest_words = temp

 

    #displays the final output.

        for i in range(0,len(final_text)):

                for j in range(0,len(sentence_lines)):

                       if (word_compare(sentence_lines[j].upper(),final_text[i]) == True):

                               num_occur = num_occurrences(sentence_lines[j],final_text[i])

                               if num_occur >= 1:

                                       print("%s" %final_text[i].upper().ljust(longest_words," "), (sentence_lines[j].rstrip('\n')),"({}*)".format(j+1))

                               else:

                                       print("%s" %final_text[i].upper().ljust(longest_words," "), (sentence_lines[j].rstrip('\n')),"({})".format(j+1))

 

if __name__ == "__main__":

        main()
