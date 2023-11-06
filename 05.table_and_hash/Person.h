#ifndef PERSON_H
# define PERSON_H

# define NAME_MAX	30

# include <stdlib.h>
# include <string.h>

typedef struct	Person
{
	char	name[NAME_MAX];
	int		age;
}	Person;

Person	*MakePerson(char *name, int age);

#endif
