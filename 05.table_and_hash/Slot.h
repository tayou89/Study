#ifndef SLOT_H
# define SLOT_H

# include "Person.h"

typedef char *  Key;
typedef Person * Value;

typedef struct Slot
{
	Key		key;
	Value	value;
}	Slot;

#endif
