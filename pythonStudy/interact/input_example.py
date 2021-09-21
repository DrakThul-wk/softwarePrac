#name = input("please enter your name:")
#print("Hello, " + name + "!")

prompt = "If your tell us who your are, we can personalize the messages you see."
prompt += "\nwhat is your first name?"

name = input(prompt)
print("\nHello, " + name + "!")

age = input("How old are you?")
age = int(age)
if (age >= 18):
    print('you are a man!=.=')
else:
    print('you are a child!')

if age % 2 == 0:
    print('it is a even')
else:
    print('it is an odd')
