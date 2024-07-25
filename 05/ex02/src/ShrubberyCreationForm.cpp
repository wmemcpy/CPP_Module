#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", false, 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Creation Form", false, 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), _target(src._target)
{
    if (this != &src)
        *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
    if (this != &src)
        _target = src._target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw NotSignedException();
    if (executor.getGrade() > getToExec())
        throw GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.good())
    {
        throw std::runtime_error("Failed to create file: " + _target + "_shrubbery");
    }
    file << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
    file << "             {/{/\\}{/{/\\}(}{/{/\\} _" << std::endl;
    file << "            {/{/\\}{/{/\\}(_)}/{/{/\\}  _" << std::endl;
    file << "         {\\{/(/\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
    file << "        {/{/(_)/}{\\{/)/}{\\(_){/}/}/}/}" << std::endl;
    file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
    file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
    file << "      _{\\{/{\\{/(_)/}{/{/{/\\}\\})\\}{/{/\\}" << std::endl;
    file << "     {/{/{\\{\\(/}{/{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
    file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
    file << "       {/{\\{\\/}{/{\\{\\/}/}{\\{\\/}/}\\}(_)_" << std::endl;
    file << "      {/{\\{\\/}{/){\\{\\/}/}{\\{\\(/}/}/}/}" << std::endl;
    file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
    file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
    file << "          (_)\\/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
    file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
    file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
    file << "              {){/ {\\/}{\\/} }\\}" << std::endl;
    file << "              (_)  \\.-'.-/" << std::endl;
    file << "          __...--- |'-.-'| --...__" << std::endl;
    file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
    file << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
    file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
    file << "          ' ..     |'-_.-|" << std::endl;
    file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
    file << "              .'   |'- .-|   '." << std::endl;
    file << "  ..-'   ' .  '.   `-._.-'   .'  '  - ." << std::endl;
    file << "   .-' '        '-._______.-'     '  ." << std::endl;
    file << "        .      ~," << std::endl;
    file << "    .       .   |\\   .    ' '-." << std::endl;
    file << "    ___________/  \\____________" << std::endl;
    file << "   /  Why is it, when you want \\" << std::endl;
    file << "  |  something, it is so damn   |" << std::endl;
    file << "  |    much work to get it?     |" << std::endl;
    file << "   \\___________________________/" << std::endl;

    file.close();
}