#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::action() const
{
    std::ofstream ofs((target + "_shrubbery").c_str());
    if (!ofs)
    {
        std::cerr << "Error: Could not create file " << target + "_shrubbery" << std::endl;
        return;
    }
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠒⡄⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⠂⢿⠇⣨⠆⠀⣠⠋⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠣⢤⣇⠀⠀⠐⠤⢼⡿⡅⡠⠀⢀⠀⢡⣾⡅⠀⠀⠀⠀⢀⠀⣆⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠀⡤⢀⠀⠀⡀⠀⠀⠀⣇⣠⠄⠀⠀⣿⠀⠀⠀⠤⠴⢀⠼⠀⠀⠈⢉⠉⣹⡀⠀⠀⠀⠀⠀⠉⣹⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢲⣿⢾⣀⠀⡧⣶⠊⠀⠸⢿⠓⢤⣄⣹⣆⣠⠀⠀⠀⠀⡀⠀⡄⠀⠈⣽⠇⠀⠀⠀⡀⠀⣸⠋⠉⠒⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠰⣀⣔⠀⢀⣭⣅⣠⣷⠃⠈⢹⠏⠱⡴⠧⣶⣤⠔⠈⣟⣿⣿⡇⠀⠀⠀⠙⢼⣷⣠⣾⡟⠁⢠⣴⣏⠀⣸⣧⠀⢠⣤⠊⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠤⠤⠽⢻⠉⢳⠀⠀⠀⠀⠑⠲⠓⠄⡠⠃⠀⡸⠛⠳⣆⠈⠻⠮⠿⣦⡀⠓⠒⣩⣿⠟⠵⣋⡒⠉⢩⠃⠘⣏⠀⡟⠙⡟⢀⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠠⠀⠞⠒⠈⠀⠀⠀⠀⠀⠀⠀⢠⡀⠀⢰⣃⣀⠀⠿⣦⠀⠀⠐⢿⣷⣠⣞⣿⣿⠛⠛⠋⠉⠒⠊⠁⠈⠁⢀⠈⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠉⠒⠸⣵⡷⡄⠀⢘⡶⠘⣄⣖⡁⢈⠃⠩⠉⠋⠐⠑⠄⠀⠀⠀⠀⠀⢚⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣄⣦⡔⠁⠀⠰⣄⢀⣠⠋⠀⠰⡚⠉⣧⡄⠘⢻⠀⠙⡄⠀⠀⠀⠸⡀⣠⡄⠀⠀⡠⠄⡀⠈⠉⠀⠀⠀⡄⢀⠀⠀⠀⢠⣀⣤⡄⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠠⠤⣞⣑⠎⠀⠀⠀⠀⠈⠣⢤⠜⠀⠀⠹⢿⡤⡞⠉⡏⡇⠀⠀⠀⢀⣀⡝⠻⡤⠂⠱⣾⡄⠀⠀⠀⠓⠢⢯⡷⣀⠀⢀⡴⢆⣼⣃⡆" << std::endl;
    ofs << "⠀⢢⣧⠀⠀⠀⠀⣜⡑⠲⣿⢅⡠⠀⠀⠙⢷⣤⡀⠀⠰⢀⣦⡬⠂⠀⠀⠀⢯⣷⣀⠀⣷⣧⠄⠀⢀⠀⠈⠱⣎⠀⠈⠩⢠⡗⠂⠀⠀⠘⢤⣾⠀⣜⡴⠟⠁⠀⠀⠈⠀" << std::endl;
    ofs << "⠀⢨⠏⢰⠒⠖⣲⠙⣿⣾⠧⣼⣄⠀⠘⢆⣰⣟⣷⣖⠢⢤⠋⠡⠂⠀⠀⠀⢈⡾⣿⠷⣿⣿⣿⠁⠀⠀⠀⡰⢻⣶⣧⢠⡟⠀⡀⠀⠀⣠⣟⣿⡞⣋⡄⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠈⣻⠿⣈⣯⠒⢿⠯⢉⡟⡟⠛⠻⢟⣦⣤⣛⢣⠀⣻⣧⠀⠙⣷⡄⠀⠀⢈⠓⠀⢈⣷⢻⢿⣦⠂⠀⠀⠀⠣⠼⣟⣿⣟⡎⠀⢳⣻⢄⣠⣋⠿⢷⠘⠤⣶⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠑⠴⠃⠸⠓⠣⠤⠋⠉⠀⠀⠀⠘⠈⠙⠿⡏⠈⡻⠋⠁⣄⣈⣻⠟⠢⢼⣹⣏⠀⠉⢿⠸⣿⣷⠀⠀⡀⠀⢰⣿⠟⠁⣀⡏⠉⣹⡀⣹⠣⣀⠜⢩⠿⣡⡊⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢶⣳⡖⠺⡞⠯⢵⣀⣀⡔⠉⠈⡦⣴⠻⣷⣿⣷⣀⢸⣥⠄⠾⢇⣠⢞⣫⢿⣮⣭⣍⣀⣀⣠⣴⣯⡶⣏⡇⠀⠀⠀⠀" << std::endl;
    ofs << "⠠⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠄⠀⠀⠀⠒⠴⠊⠁⢀⣠⣶⣶⠿⠿⠷⠷⢤⣤⣷⡟⢧⠹⣿⡃⠈⡹⠋⢃⣀⣼⠕⠋⠉⠉⠀⠀⠀⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⡀⢸⢤⡄⠀⠀⠀⣠⣵⡶⠛⠋⠀⠀⠀⠀⠀⠀⠀⢫⣄⣷⣖⢓⢿⣿⣫⣧⣤⢼⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⡟⠙⣄⡠⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠤⢎⣨⡏⠘⣿⣿⡟⡵⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⠒⠺⣄⣀⡼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡄⣷⠀⣿⡿⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⣿⠀⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠀⡯⢀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⡸⠀⣼⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
    ofs << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣧⠃⣼⡟⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << std::endl;
}