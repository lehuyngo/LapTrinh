'''def chaythu():
  print("hello")
chaythu()
def cong(a,b):
    return a+b
print(cong(5,6))
num=3
def doiso(so):
    so=4
doiso(num)
print(num)
run=-1
if run: print(234)
def build_person(first_name, last_name, age=None):
  person = {'first': first_name, 'last': last_name}
  if age:
    person['age'] = age
  return person
musician = build_person('jimi', 'hendrix',)
print(musician)
def get_formatted_name(first_name, last_name):
  full_name = f"{first_name} {last_name}"
  return full_name.title()'''
'''
while True:
  print("\nPlease tell me your name:")
  f_name = input("First name: ")
  l_name = input("Last name: ")
  formatted_name = get_formatted_name(f_name, l_name)
  print(f"\nHello, {formatted_name}!") '''

'''
unprinted_designs = ['phone case', 'robot pendant', 'dodecahedron']
completed_models = []
# Simulate printing each design, until none are left.
# Move each design to completed_models after printing.
while unprinted_designs:
  current_design = unprinted_designs.pop()
  print(f"Printing model: {current_design}")
  completed_models.append(current_design)
# Display all completed models.
print("\nThe following models have been printed:")
for completed_model in completed_models:
  print(completed_model)'''
'''
def print_models(unprinted_designs, completed_models):

  while unprinted_designs:
    current_design = unprinted_designs.pop()
    print(f"Printing model: {current_design}")
    completed_models.append(current_design)
def show_completed_models(completed_models):
  print("\nThe following models have been printed:")
  for completed_model in completed_models:
    print(completed_model)
unprinted_designs = ['phone case', 'robot pendant', 'dodecahedron']
completed_models = []
print_models(unprinted_designs, completed_models)
show_completed_models(completed_models)
def make_pizza(*toppings):
  print(toppings)
make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')
def build_profile(first, last, **user_info):
  user_info['first_name'] = first
  user_info['last_name'] = last
  return user_info
user_profile = build_profile('albert', 'einstein',
location='princeton',
field='physics',sdt='0432')
print(user_profile)'''
'''
import pizza
pizza.make_pizza(16, 'pepperoni')
pizza.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese') '''
class NamesTestCase(unittest.TestCase):
  def test_first_last_name(self):
    --snip--
  def test_first_last_middle_name(self):
    formatted_name = get_formatted_name('wolfgang', 'mozart', 'amadeus')
    self.assertEqual(formatted_name, 'Wolfgang Amadeus Mozart')
if __name__ == '__main__':
  unittest.main()