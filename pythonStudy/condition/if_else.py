age = 20
banned_users = ['andrew', 'carolina', 'david']
user = 'marie'
if user not in banned_users:
    if age <= 20:
        print('do something? test 1')
        banned_users.append(user)
    elif age <= 25:
        print('do something test2')
    else:
        print('else branch')
else:
    print('marie is in banned_users')

for name in banned_users:
    if name == 'marie':
        print('marie already in banned_users')
    else:
        print(name)

if banned_users:
    print(banned_users)
else:
    print('banned_users is empty')
