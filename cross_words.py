#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'crosswordPuzzle' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING_ARRAY crossword
#  2. STRING words
#
def position_finder(crossword, word):

    n = len(crossword)
    m = len(crossword[0])
    for i in range(n):
        for j in range(m):
            if crossword[i][j] == word[0] or crossword[i][j] == '-': #either empty or filled
                l = len(word)
                does_it_fit = True
                for k in range(1, l): # first look horizontally
                    if j+k < m and (crossword[i][j+k] == '-' or crossword[i][j+k] ==word[k]):
                        continue
                    else:
                        does_it_fit = False
                
                if does_it_fit and j+l<=m:
                    return [i,j,'h']
                
                does_it_fit = True
                for k in range(1, l): # now vertically:
                    if i+k < n and (crossword[i+k][j] == '-' or crossword[i+k][j] == word[k]):
                        continue
                    else:
                        does_it_fit = False

                if does_it_fit  and i+l<=n:
                    return [i,j,'v']

    return [-1,-1,'n']

def is_filled(crossword):
    
    n = len(crossword)
    m = len(crossword[0])
    # print(crossword)
    for i in range(n):
        for j in range(m):
            if crossword[i][j] == '+':
                return False
    
    return True
def print_crossword(crossword):
    n = len(crossword)
    m = len(crossword[0])
    # print(crossword)
    for i in range(n):
        print(crossword[i])
    
def fill_the_puzzle(words, crossword, filled_words):

    print(filled_words)
    if len(filled_words) == len(words):
        print("x")
        return True
    else:
        for i in range(len(words)):
            if words[i] not in filled_words:
                x,y,direction = position_finder(crossword, words[i])
                print(x,y, direction)
                if x != -1:
                    
                    l = len(words[i])
                    prev = []
                    if direction == 'h':
                        for j in range(l):
                            prev.append(crossword[x][y+j])
                            crossword[x][y+j] = words[i][j]
                    else:
                        for j in range(l):
                            prev.append(crossword[x+j][y])
                            crossword[x+j][y] = words[i][j]
                    # print_crossword(crossword)
                    filled_words.append(words[i])
                    
                    if fill_the_puzzle(words, crossword, filled_words):
                        return True
                    
                    filled_words.pop()
                    
                    if direction == 'h':
                        for j in range(l):
                            crossword[x][y+j] = prev[j]
                    else:
                        for j in range(l):
                            crossword[x+j][y] = prev[j]
        return False

    
def crosswordPuzzle(crossword, words):
    # Write your code here
    
    # start from a word look for -'s up or down
    crossword = [list(crossword[i]) for i in range(len(crossword)) ]
    
    words = words.split(";")
    fill_the_puzzle(words, crossword, [])
    print_crossword(crossword)
    crossword = ["".join(crossword[i]) for i in range(len(crossword))]
    return crossword
# example 
# crossword = [list("+-++++++++"),
# list("+-++++++++"),
# list("+-++++++++"),
# list("+-----++++"),
# list("+-+++-++++"),
# list("+-+++-++++"),
# list("+++++-++++"),
# list("++------++"),
# list("+++++-++++"),
# list("+++++-++++")]
# words = "LONDON;DELHI;ICELAND;ANKARA".split(";")

# crosswordPuzzle(crossword, words)
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    crossword = []

    for _ in range(10):
        crossword_item = input()
        crossword.append(crossword_item)

    words = input()

    result = crosswordPuzzle(crossword, words)

    fptr.write('\n'.join(result))
    fptr.write('\n')

    fptr.close()
