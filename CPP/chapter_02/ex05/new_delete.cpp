#include <iostream>

int		ft_strlen(char *string);
void	copy_string(char *duplicated_string, char *string);

void	leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	char	string[10] = "abcdefg";
	int		string_size;
	char	*duplicated_string;

	atexit(leaks);
	string_size = ft_strlen(string);
	duplicated_string = new char[string_size];
	if (duplicated_string == (void *) 0)
		perror("");
	copy_string(duplicated_string, string);
	std::cout << "string: " << string << std::endl;
	std::cout << "duplicated_string: " << duplicated_string << std::endl;
	delete duplicated_string;
	return (0);
}

int	ft_strlen(char *string)
{
	int	size;
	int	i;

	i = 0;
	while (string[i] != '\0')
		i++;
	size = i;
	return (size);
}

void	copy_string(char *duplicated_string, char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		duplicated_string[i] = string[i];
		i++;
	}
	duplicated_string[i] = '\0';
}
