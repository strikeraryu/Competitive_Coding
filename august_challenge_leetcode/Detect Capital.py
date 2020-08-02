# Problem
  
# Given a word, you need to judge whether the usage of capitals in it is right or not.

# We define the usage of capitals in a word to be right when one of the following cases holds:

# All letters in this word are capitals, like "USA".
# All letters in this word are not capitals, like "leetcode".
# Only the first letter in this word is capital, like "Google".
# Otherwise, we define that this word doesn't use capitals in a right way.
  
# Example
  
# Input: "USA"
# Output: True

# Input: "FlaG"
# Output: False

  
  
# Constraints:
  
# The input will be a non-empty word consisting of uppercase and lowercase latin letters.
  
#-----------------------------------------------------------------------------------------------------
# Solution

class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.islower() or word.isupper():
            return True
        if word[0].isupper() and word[1:].islower():
            return True
        return False
        
        

