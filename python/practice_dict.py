# Python stuf
# check if the string is valid [] () {}
def valid_paren(ss):
    mappings = {}
    mappings['('] = ')';
    mappings['['] = ']';
    mappings['{'] = '}';
    
    stk = []
    for c in ss:
        if c in mappings.keys():
            stk.append(c)
        else:
            if len(stk) == 0:
                return False
            t = stk[len(stk) - 1] 
            stk.pop()
            if(mappings[t] != c): 
                return False
    return True if len(stk) == 0 else False


print(valid_paren('[][]{}()(){}') == True)
print(valid_paren('[({})][]') == True)
print(valid_paren('[({})][())]') == False)
print(valid_paren('[({})](') == False)


some = []
some.append('bolbaggan4')
some.append('HEIZE')
print(some)
