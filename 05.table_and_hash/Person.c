#include "Person.h"

Person	*MakePerson(char *name, int age)
{
	Person	*person = (Person *) malloc(sizeof(Person));

	strcpy(person->name, name);
	person->age = age;
	return (person);
}
