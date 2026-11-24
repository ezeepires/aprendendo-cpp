// std::filesystem: listar, criar e remover.
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

int main() {
    fs::path pasta = fs::temp_directory_path() / "aprendendo_cpp_fs";

    fs::create_directories(pasta);
    std::ofstream(pasta / "a.txt") << "conteúdo A\n";
    std::ofstream(pasta / "b.txt") << "conteúdo B\n";

    std::cout << "pasta: " << pasta << "\n";
    for (const auto& item : fs::directory_iterator(pasta)) {
        std::cout << "  " << item.path().filename() << " ("
                  << fs::file_size(item.path()) << " bytes)\n";
    }

    fs::remove_all(pasta);
    std::cout << "pasta removida: " << std::boolalpha << !fs::exists(pasta) << "\n";
    return 0;
}
