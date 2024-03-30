#include "string_class.hpp"

String::String(void)
{
	string = NULL;
}

String::String(const char *str)
{
	int	string_size;

	string_size = strlen(str);
	string = new char[string_size + 1];
	strcpy(string, str);
}

char	*String::return_string(void)
{
	return (string);
}

char	String::return_character(int index)
{
	return (string[index]);
}

String	String::operator+(const String &object)
{
	char	*new_string;
	int		string_size;

	string_size = strlen(string) + strlen(object.string);
	new_string = new char[string_size + 1];
	strcpy(new_string, string);
	strcat(new_string, object.string);
	String	new_object(new_string);
	delete []new_string;
	return (new_object);
}

String	String::operator+(const char *str)
{
	char	*new_string;
	int		string_size;

	string_size = strlen(string) + strlen(str);
	new_string = new char[string_size + 1];
	strcpy(new_string, string);
	strcat(new_string, str);
	String	new_object(new_string);
	delete []new_string;
	return (new_object);
}

void	String::operator=(const char *str)
{
	int	string_size;

	string_size = strlen(str);
	if (string != (void *) 0)
		delete []string;
	string = new char[string_size + 1];
	strcpy(string, str);
}

void	String::operator=(const String &object)
{
	int	string_size;

	string_size = strlen(object.string);
	if (string != (void *) 0)
		delete []string;
	string = new char[string_size + 1];
	strcpy(string, object.string);
}

void	String::operator+=(const String &object)
{
	char	*new_string;
	int		string_size;

	string_size = strlen(string) + strlen(object.string);
	new_string = new char[string_size + 1];
	strcpy(new_string, string);
	strcat(new_string, object.string);
	if (string != (void* ) 0)
		delete []string;
	string = new_string;
}

void	String::operator+=(const char *str)
{
	char	*new_string;
	int		string_size;

	string_size = strlen(string) + strlen(str);
	new_string = new char[string_size + 1];
	strcpy(new_string, string);
	strcat(new_string, str);
	if (string != (void *) 0)
		delete []string;
	string = new_string;
}

bool	String::operator==(const char *str)
{
	for (int i = 0; string[i] != '\0' || str[i] != '\0'; i++)
	{
		if (string[i] != str[i])
			return (false);
	}
	return (true);
}

bool	String::operator==(const String &object)
{
	for (int i = 0; string[i] != '\0' || object.string[i] != '\0'; i++)
	{
		if (string[i] != object.string[i])
			return (false);
	}
	return (true);
}

std::ostream &operator<<(std::ostream &os, const String &object)
{
	os << object.string;
	return (os);
}

std::istream &operator>>(std::istream &is, String &object)
{
	char	str[100];

	is >> str;
	object = String(str);
	return is;
}

String::~String(void)
{
	if (string != (void *) 0)
		delete []string;
}
