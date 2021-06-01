
class Trie:
    def __init__(self):
        self.pointers = [None for i in range(26)]
        self.is_end = False
        

def insert_product(product, root): 
    
    '''normal insertion of a string in the trie'''
    cur_node = root
    for letter in product:
        
        if not cur_node.pointers[ord(letter)-97]:
            cur_node.pointers[ord(letter)-97] = Trie()
            
        cur_node = cur_node.pointers[ord(letter)-97]
    cur_node.is_end = True
        
def build_trie(products):
    '''helper function for building a trie'''
    root = Trie()
    for product in products:
        insert_product(product, root)
    return root
        
def build_words_from_subtree(root, words, word, prefix):
    '''it gets 3  words from the given trie'''
    if root and len(words)<3 :
        if root.is_end:
            words.append(prefix+word)
        for i,node in enumerate(root.pointers):
            build_words_from_subtree(node, words, word+chr(ord('a')+i), prefix)
                
def print_all_the_words(root, word):
    
    '''helper function for printing all the words in the trie and to confirm whether words 
    have been inserted correctly'''
    if root :
        if root.is_end:
            print(word)
        for i,node in enumerate(root.pointers):
            print_all_the_words(node, word+chr(97+i))

def get_the_suggestions(search_word, root):
    
    prefix = ""
    suggestions_for_search_word = []
    i = 0
    while i<len(search_word) :
        letter = search_word[i]
        suggestions_for_search_letter = []
        if root.pointers[ord(letter)-97]: #there is a matching letter for the search word
            prefix += letter
            root = root.pointers[ord(letter)-97]
            build_words_from_subtree(root, suggestions_for_search_letter, "", prefix)
            suggestions_for_search_word.append(suggestions_for_search_letter[:])
        else : # if in abcd, a b are found and c is not but the next root has d then it is not valid
            #if not for this condition then the code would have not worked for the edge case
            while i<len(search_word):
                suggestions_for_search_word.append([])
                i += 1
        i += 1
       
            
    return suggestions_for_search_word
            
class Solution:
    def suggestedProducts(self, products, searchWord):
        products.sort()
        #first build the trie
        root = build_trie(products)
        # print_all_the_words(root, "")
        return get_the_suggestions(searchWord, root)
        

sol = Solution()     
print(sol.suggestedProducts(["mobile","mouse","moneypot","monitor","mousepad"],"mouse"))