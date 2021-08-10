# Write a Python function to print the fibonacci series using a generator.

# Input: 3
# Output: 0 1 1

# Input : 5
# Output : 0 1 1 2 3

# ip =2 op = 0 1
# a, b
# def fun(ip):
    
#     a = 0
#     b = 1
#     # a = b
#     # b  = a+b
#     for i in range(ip):
#         yield a
#         a,b = b, a+b

        

# for ele in fun(5):
#     print(ele)





# Write a Python Program to flatten the given list
# Original List [[1,[55, 34],3], [4,5,[1,2,3],6], 89]
# Transformed Flat List [1, 55, 34, 3, 4, 5, 1, 2, 3, 6, 89]
# [1, 55, 34, 3, 4, 5, 1, 2, 3, 6, 89]
# [1, 3, 4, 1, 3, 6, 89]

# op = []
# def fun (ip):
    
#     if len(ip) ==0:
#         return
#     for ele in ip:  # ele = 1 
#         if type(ele) == int:
#             op.append(ele) 
#             # ip.remove(ele) # ip = [[55,34],3]
#         elif type(ele) == list:
#             fun(ele)


# ip =  [[1,[55, 34],3], [4,5,[1,2,3],6], 89]

# fun(ip)

# print(op)



# Write a Python Program to reverse string without affecting the special character
# Input String : "a,b$c"
# Output String : "c,b$a"

# mohammed.a@brillio.com


ip_string = "a,b$c"
# c,b$a
ip = list(ip_string)
print(ip_string)
i = 0
j = len(ip)-1

while i<j:
    if (ip[i].isalpha() or ip[i].isdigit()) and (ip[j].isalpha() or ip[j].isdigit()):
        ip[i], ip[j] = ip[j], ip[i]
        i+=1
        j-=1
    elif ip[i].isalpha() or ip[i].isdigit():
        j -=1
    elif ip[j].isalpha() or ip[j].isdigit():
        i+=1
    else:
        i+=1
        j-=1

print(''.join(ip))




