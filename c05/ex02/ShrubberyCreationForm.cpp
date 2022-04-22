/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:11:59 by eperaita          #+#    #+#             */
/*   Updated: 2022/03/14 19:32:55 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"
#include <stdexcept>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Unknown", "No target", 145, 137)
{
    std::cout << "     ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): Form("ShrubberyCreationForm", target , 145, 137) 
{
    std::cout << "     ShrubberyCreationForm parameter constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "     ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref): Form(ref)
{
    std::cout << "     ShrubberyCreationForm copy constructor called" << std::endl;
    *this = ref;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref)
{
    std::cout << "     ShrubberyCreationForm assignation operator called" << std::endl;

    this->_signed = ref.getSigned();
    return (*this);
}

///////////////////////////////////////////////////////////////

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeExe())
	{
        std::cout << "          > " << this->name << " has failed:";
		throw Form::GradeTooLowException();
	}
	if (!this->getSigned())
    {
        std::cout << "          > " << this->name << " has failed:"; 
        throw Form::NotSignedException();
    }
	else 
	{
		std::string new_file = this->getTarget();
		std::ofstream out(new_file.append("_shrubbery"));
		//Really an ASCII tree is an ASCIIart shubbery???
		out << "                                " << std::endl;
		out << "        /`-.   ,           " << std::endl;
		out << "        \\ \\ '-' \\      .-'{" << std::endl;
		out << "        _} .  | ,`\\   /  ' ;    .-;\\" << std::endl;
		out << "       {    \\ |    | / `/  '-.,/ ; |" << std::endl;
		out << "       { -- -.  '  '`-, .--._.' ;  \\__" << std::endl;
		out << "        \\     \\ | '  /  |`.    ;    _,`\\" << std::endl;
		out << "         '. '-     ' `_- '.`;  ; ,-`_.-'" << std::endl;
		out << "     ,--.  \\    `   /` '--'  `;.` (`  _" << std::endl;
		out << "  .--.\\  '._) '-. \\ \\ `-.    ;     `-';|" << std::endl;
		out << "  '. -. '         __ '.  ;  ;     _,-' /" << std::endl;
		out << "   { __'.\\  ' '-,/; `-'   ';`.- `   .-'" << std::endl;
		out << "    '-.  `-._'  | `;     ;`'   .-'`" << std::endl;
		out << "      <_ -'   ` .\\  `;  ;     (_.'`\\" << std::endl;
		out << "      _.;-\"``\"'-._'. `:;  ___, _.-' |" << std::endl;
		out << "  .-'\\'. '.` \\ \\_,_`\\ ;##`   `';  _.'" << std::endl;
		out << " /_'._\\ \\  \\__;#####./###.      \\`" << std::endl;
		out << " \\.' .'`/\"`/ (#######)###::.. _.'" << std::endl;
		out << "  '.' .'  ; , |:.  `|()##`\"\"\"` " << std::endl;
		out << "    `'-../__/_\\::   /O()()o" << std::endl;
		out << "             ()'._.'`()()'" << std::endl;

		out.close();
    	std::cout << "          > " << this->getTarget() << " created!" << std::endl;
	}
}


