magicians = ['alice', 'david', 'carolina'] # 字符列表
for mag in magicians:
    print(mag)

for val in range(0, 5):
    print(val)

data = range(0,4)
print(data)
dataList = list(range(0,4)) # 数字列表
print(dataList)
for dataTmp in data:
    print(dataTmp)

dataListEven = list(range(0, 10, 2)) # generate number list with range step
print(dataListEven)
print('min value:' + str(min(dataListEven)))
print('max value:' + str(max(dataListEven)))
print('sum value:' + str(sum(dataListEven)))

dataSquare = [value ** 2 for value in range(0, 4)]
print(dataSquare)

players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players)
print(players[0:3])
print(players[2:])
print(players[:4])
for player in players[:3]:
    print(player)
