# Andy Tseng
# leetcode : https://leetcode.com/problems/accounts-merge/description/

class node:
    
    __init__(self, email, children):
        self.email = email
        self.children = children


def merge_accounts(self, accounts):
   email_to_name = {}
   email_graph = {}
   vertices = []

    for arecord in accounts:
        name = arecord[0]
        email_user_list = arecord[1:len(arecord)]
        for email in email_user_list:
            if email not in email_to_name:
                email_to_name[email] = name


        

