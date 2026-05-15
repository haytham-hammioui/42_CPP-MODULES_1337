#include "MutantStack.hpp"

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> copy(mstack);

std::cout << "\n===== MODIFY THROUGH ITERATOR =====" << std::endl;
for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
    *i += 10;

for (MutantStack<int>::iterator i = mstack.begin(); i != mstack.end(); ++i)
    std::cout << *i << std::endl;

std::cout << "\n===== STRING TEST =====" << std::endl;
MutantStack<std::string> strStack;
strStack.push("hello");
strStack.push("world");
strStack.push("42");
for (MutantStack<std::string>::iterator i = strStack.begin();
    i != strStack.end(); ++i)
{
    std::cout << *i << std::endl;
}

return 0;
}