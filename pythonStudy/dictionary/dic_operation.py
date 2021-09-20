alien = {}
alien['color'] = 'green' # key -> value
alien['points'] = 5
print(alien)
alien['color'] = 'yellow'
print(alien)
record = alien.pop('color') # here we get the value
print(alien) # record is yellow
alien[record] = 'green'
print(alien)
del alien[record]
print(alien)

favorite_languages = {
        'jen' : 'python',
        'sarah' : 'C',
        'edward' : 'ruby',
        'phil' : 'python',
        }
print(favorite_languages)
for name, language in favorite_languages.items():
    print(name.title() + "'s favorite laguage is " + language)

for name in favorite_languages.keys():
    print(name.title())

for name in sorted(favorite_languages.keys()):
    print(name.upper())

for language in favorite_languages.values():
    print('language is ' + language.upper())

for language in set(favorite_languages.values()):
    print('language is ' + language.upper())
