#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
	private:
		const	std::string	name;
		int			grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		void	setName(std::string name);
		const	std::string	getName();
		void	setGrade(int grade);
		int	getGrade();
};
#endif
