bicycles=['trek', 'cannondale', 'redline', 'specialized']

print(bicycles)

print(bicycles[0])

print(bicycles[0].title())

print(bicycles[3].upper())
# modification
bicycles[0] = 'name'
print(bicycles)

# add to tail
bicycles.append('ducati')
print(bicycles)

# insert to specific place
bicycles.insert(0, 'wangkang')
print(bicycles)

bicycles.insert(1, 'wangkang')
print(bicycles)

del bicycles[0]
print(bicycles)
test_char = bicycles.pop(2)
print(bicycles)

bicycles.remove('redline')
print(bicycles)
