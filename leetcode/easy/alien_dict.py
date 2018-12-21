# leetcode: https://leetcode.com/problems/verifying-an-alien-dictionary/description/
# Andy Tseng


def alien_cmp(word1, word2, alphabet):
    for i in range(0, len(word1)):
        if i >= len(word2):
            return 1
        if alphabet[word1[i]] < alphabet[word2[i]]:
            return -1
        elif alphabet[word1[i]] > alphabet[word2[i]]:
            return 1
    return -1 if len(word2) > len(word1) else 0
    

def alien_dict(words, order):
    alphabet = {}
    place = 0
    for letter in order:
        alphabet[letter] = place
        place += 1
    for i in range(1, len(words)):
        if alien_cmp(words[i], words[i-1], alphabet) == -1:
            return False
    return True
        
            

alien_dict(["words", "whale", "wood"], "worldabcefghijkmnpqstuvxyz")

