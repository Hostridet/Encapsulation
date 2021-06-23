#include <iostream>
#include "src/Method.h"

int main() {

    Person* goodguy = new Person();
    goodguy->Name = "Leonyd";

    PersonName* noname = new PersonName();
    noname->SetName("Lenonyd");
    cout << noname->GetName() << endl;

    PersonAge* oldguy = new PersonAge();
    oldguy->aged();
    oldguy->getValue();

    Worker* badman  = new WorkerOnFactory();
    badman->setSalary(20000);
    badman->setSpent(30000);
    badman->getResult();
    badman->print();


    return 0;
}
