

def del_col2(words):
    """
    type(words) : list
    rtype       : int
    """
    word_len = len(words[0])
    word_grid = [list(w) for w in words]
    D = 0
    for i in range(word_len):
        row_list = [w[i] for w in word_grid] 
        for i in range(1,len(row_list)):
            if row_list[i] < row_list[i-1]:
                D += 1
                break
    return D


if del_col2(["abc", "def", "ghi"]) == 0:
    print("pass")

if del_col2(["zyx","wvu","tsr"]) == 3:
    print("pass")
