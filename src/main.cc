#include <iostream>
#include <string>
#include <stdexcept>
#include<caltconfig.h>
std::string valid_ops = "+-*/";

bool isValidOperator(const char *c)
{
    return valid_ops.find(c) != std::string::npos;
}

int main(int argc, char *argv[])
{
    std::cerr << Project::PROJECT_NAME << " v" << Project::VERSION_STRING <<" "<<Project::COMPANY_NAME<< std::endl; // Placeholder for project name/version
    if (argc < 3)
    {
        std::cerr << "Example: (2+2)*(4*4)-(40+10) / 2" << std::endl;
        return 0;
    }

    long long int result = 0;
    char op = ' ';
    try
    {
        // Start with the first number
        result = std::stoi(argv[1]);

        for (int i = 2; i < argc; i += 2) // We process every other argument (operators at even indices)
        {
            // Check operator validity
            if ((i + 1 >= argc) || !isValidOperator(argv[i]))
            {
                std::cerr << "Invalid operator: " << argv[i] << std::endl;
                return 0;
            }

            op = argv[i][0]; // Operator is a single character

            // Get the next number
            int next_num = std::stoi(argv[i + 1]);

            // Perform calculation based on the operator
            switch (op)
            {
            case '+':
                result += next_num;
                break;
            case '-':
                result -= next_num;
                break;
            case '*':
                result *= next_num;
                break;
            case '/':
                if (next_num == 0)
                {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0;
                }
                result /= next_num;
                break;
            }
        }
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        return 0;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Out of range error: " << e.what() << std::endl;
        return 0;
    }

    std::cout << result << std::endl;
    return 0;
}
