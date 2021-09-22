def greet_user():
    """ this is a function """
    print("hello!")

greet_user()


def greet_user_variable(user_name):
    print("hello!" + user_name.title() + "!")

greet_user_variable('jessica')


def describe_pet(animal_type, pet_name):
    print("I have a " + animal_type + ".")
    print("my" + animal_type + "'s name is " + pet_name)

describe_pet('hamster', 'dog')
describe_pet(animal_type = 'hamster', pet_name = 'dog')


def describe_pet_default(animal_type = 'dog', pet_name)
    print("I have a " + animal_type + ".")
    print("my" + animal_type + "'s name is " + pet_name)

describe_pet_default(pet_name = 'willie')
describe_pet_default('willie')