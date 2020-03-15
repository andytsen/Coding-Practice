# O(NlogN)

def largest_multiple_of_three(digits):
    numbers_to_use = []
    numbers_mod_one = []
    numbers_mod_two = []
    for number in digits:
        if number % 3 == 0:
            numbers_to_use.append(number)
        if number % 3 == 1:
            numbers_mod_one.append(number)
        if number % 3 == 2:
            numbers_mod_two.append(number) 
    numbers_mod_one = sorted(numbers_mod_one, reverse=True)
    numbers_mod_two = sorted(numbers_mod_two, reverse=True)
    for i in range(0, min(len(numbers_mod_one), len(numbers_mod_two))):
        numbers_to_use.append(numbers_mod_one[i])
        numbers_to_use.append(numbers_mod_two[i])
    numbers_to_use = sorted(numbers_to_use, reverse=True)
    res = ""
    for n in numbers_to_use:
        res += str(n)
    return res


print("[8,1,9] = ", largest_multiple_of_three([8,1,9]))
print("[3,0,0] = ", largest_multiple_of_three([3,0,0]))
print(largest_multiple_of_three([3,0,0,8,7,1]))
