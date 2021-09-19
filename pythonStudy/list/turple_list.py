# 列表非常适合于存储在程序运行期间可能变化的数据集，列表是可以修改的； 
# 然而有时候需要创建一系列不可修改的元素，元组可以满足这种需求，python将不能修改的值称为不可变的，
# 而不可变的列表被称为元组。

dimensions = (200, 50)
print(type(dimensions))
print(dimensions[0])
print(dimensions[1])
# dimensions[0] = 55 # not correct

for dimension in dimensions:
    print(dimension)

dimensions = (400, 1000) # this one is ok for tuple
print(dimensions)

