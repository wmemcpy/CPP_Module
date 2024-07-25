#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    Bureaucrat chief("Chief", 1);
    Form taxForm("Tax Form", false, 25, 25);

    std::cout << chief << std::endl;
    std::cout << taxForm << std::endl;

    try {
        taxForm.beSigned(chief);
        std::cout << taxForm << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
