alien_0 = {'color':'green', 'points':5}
alien_1 = {'color':'yellow', 'points':10}
alien_2 = {'color':'red', 'points':15}

aliens = [alien_0, alien_1, alien_2]

for alien in aliens:
    print(alien)

aliens = []
for alien_number in range(0, 5):
    new_alien = {'color':'green', 'points':5, 'speed':'slow'}
    aliens.append(new_alien)

print(aliens)

for alien in aliens[:3]:
    for key, value in alien.items():
        if key == 'color':
            alien[key] = 'what?'

print(aliens)

favorite_languages = {
    'jen' : ['python', 'ruby'],
    'sarah' : ['c'],
    'edward' : ['ruby', 'go'],
    'phil' : ['python', 'haskell'],
    }
for name, languages in favorite_languages.items():
    print(name + "'s favorite languages are:")
    for lan in languages:
        print("\t" + lan)
