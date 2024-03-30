#ifndef STRING_CLASS_HPP
# define STRING_CLASS_HPP

# include <cstring>
# include <iostream>

class	String
{
	private:
		char	*string;
	public:
		String(void);
		String(const char *str);
		String	operator+(const char *str);
		String	operator+(const String &object);
		void	operator=(const char *str);
		void	operator=(const String &object);
		void	operator+=(const char *str);
		void	operator+=(const String &object);
		bool	operator==(const char *str);
		bool	operator==(const String &object);
		char	*return_string(void);
		char	return_character(int index);
		friend std::ostream	&operator<<(std::ostream &os, const String &object);
		friend std::istream	&operator>>(std::istream &is, String &object);
		~String(void);
};

std::ostream	&operator<<(std::ostream &os, const String &object);
std::istream	&operator>>(std::istream &is, String &object);

#endif
