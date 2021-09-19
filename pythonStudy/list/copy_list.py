my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:] #如果想要副本，必须使用：

print('My favorite foods are:')
print(my_foods)

print('My friend favorite foods are:')
print(friend_foods)

my_foods.append('cannoli')
friend_foods.append('ice cream')

print('My favorite foods are:')
print(my_foods)

print('My friend favorite foods are:')
print(friend_foods)

friend_foods = my_foods #如果是＝号赋值，则相当于别名，不是copy
my_foods.append('test1')
friend_foods.append('test2')

print('My favorite foods are:')
print(my_foods)

print('My friend favorite foods are:')
print(friend_foods)

