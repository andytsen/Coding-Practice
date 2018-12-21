

def prison_in_N(arr, n):
    print("Summary of prison in {} days\n".format(n))
    for i in range(0,n + 1):
        tmp = [0] * len(arr)
        print("Day {}: {}".format(i,arr))
        tmp[0] = 0
        tmp[len(arr) - 1] = 0
        for j in range(1,len(arr) - 1):
            if arr[j - 1] == arr[j + 1]:
                tmp[j] = 1
            else:
                tmp[j] = 0
        arr = tmp

          

prison_in_N([0,1,0,1,1,0,0,1], 7)        
