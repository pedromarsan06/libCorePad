#ifndef COREPAD_H
#define COREPAD_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <limits>

class CorePad {
private:
    std::string currentFile;

public:
    // Cria um arquivo vazio com o nome fornecido pelo usuário
    void makeFile() {
        std::cout << "Digite o nome do arquivo que deseja criar:\n";
        std::getline(std::cin, currentFile);

        // Valida o nome do arquivo
        if (currentFile.empty() || currentFile.find_first_of("\\/:*?\"<>|") != std::string::npos) {
            std::cerr << "Erro: Nome de arquivo inválido.\n";
            return;
        }

        std::ofstream file(currentFile);
        if (!file) {
            std::cerr << "Erro ao criar o arquivo.\n";
            return;
        }

        std::cout << "Arquivo '" << currentFile << "' criado com sucesso.\n";
    }

    // Abre um arquivo existente e adiciona texto a ele
    void selectFileAdd() {
        if (currentFile.empty()) {
            std::cerr << "Nenhum arquivo selecionado. Use makeFile() antes.\n";
            return;
        }

        std::ofstream file(currentFile, std::ios::app);
        if (!file) {
            std::cerr << "Erro ao abrir o arquivo '" << currentFile << "'.\n";
            return;
        }

        std::cout << "Digite o texto que deseja adicionar ao arquivo:\n";
        std::string value;
        std::getline(std::cin, value);

        file << value << "\n";
        file.close();
        std::cout << "Texto adicionado ao arquivo '" << currentFile << "'.\n";
    }

    // Exibe o conteúdo de um arquivo
    void returnFile() {
        std::cout << "Digite o nome do arquivo que deseja visualizar:\n";
        std::string fileName;
        std::getline(std::cin, fileName);

        // Valida o nome do arquivo
        if (!std::filesystem::exists(fileName)) {
            std::cerr << "Erro: O arquivo '" << fileName << "' não existe.\n";
            return;
        }

        std::ifstream file(fileName);
        if (!file) {
            std::cerr << "Erro ao abrir o arquivo '" << fileName << "'.\n";
            return;
        }

        std::cout << "Conteúdo do arquivo '" << fileName << "':\n";
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }

        file.close();
    }

    // Remove um arquivo
    void removeFile() {
        std::cout << "Digite o nome do arquivo que deseja remover:\n";
        std::string fileName;
        std::getline(std::cin, fileName);

        // Valida o nome do arquivo
        if (!std::filesystem::exists(fileName)) {
            std::cerr << "Erro: O arquivo '" << fileName << "' não existe.\n";
            return;
        }

        if (std::filesystem::remove(fileName)) {
            std::cout << "Arquivo '" << fileName << "' removido com sucesso.\n";
        } else {
            std::cerr << "Erro ao remover o arquivo '" << fileName << "'.\n";
        }
    }

    // Exibe a versão atual do CorePad
    void coreVersion() const {
        std::cout << "Versão: {1.1}, Última Versão: {N/A}\n";
    }

    // Lista os comandos disponíveis
    void coreCommands() const {
        std::cout << "Comandos disponíveis:\n"
                  << "  - makeFile(): Cria um arquivo vazio\n"
                  << "  - selectFileAdd(): Adiciona texto ao arquivo selecionado\n"
                  << "  - returnFile(): Exibe o conteúdo de um arquivo\n"
                  << "  - removeFile(): Remove um arquivo\n"
                  << "  - coreVersion(): Exibe a versão do CorePad\n"
                  << "  - coreCommands(): Lista os comandos disponíveis\n";
    }
};

#endif // COREPAD_H
