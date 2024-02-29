#include <iostream>
#include <vector>

static void verificarAcerto(std::string palavraSecreta, int vidas) {
    std::vector<char>chutes{};
    char palpite{};
    int acertou{};
    bool ganhou{};

    while (vidas > 0 && !ganhou) {
        std::cout << "Chute uma letra:\n->";
        std::cin >> palpite;
        chutes.push_back(palpite);
        bool palpiteCerto{ false };
        
        // Verifica letra acertada
        for (char i{ 0 }; i < palavraSecreta.size(); i++) {
            if (std::find(chutes.begin(), chutes.end(), palavraSecreta[i]) != chutes.end()) {
                std::cout << palavraSecreta[i] << " ";
                if (palpite == palavraSecreta[i]) {
                    acertou++;
                    palpiteCerto = true;
                }
            }
            else {
                std::cout << "_ ";
                acertou--;
            }
        }

        if (!palpiteCerto) {
            vidas--;
        }

        std::cout << "\nVoce tem: " << vidas << " chances!\n";

        if (acertou == palavraSecreta.size()) {
            std::cout << "\nVoce acertou a palavra!!!";
            ganhou = true;
        }
        acertou = 0;
    }
    
    if (vidas == 0) {
        system("cls");
        std::cout << "\nPerdeu :(\n";
    }
}

static int selecaoDeficuldade(int vidas) {
    bool pronto{false};
    do{
        std::cout << "Selecione a dificuldade: Deficil(3), Media(2), Facil(1)\n->";
        std::cin >> vidas;
        switch (vidas) {
        case 1:
            vidas = 6; pronto = true; break;
        case 2:
            vidas = 4; pronto = true; break;
        case 3:
            vidas = 2; pronto = true; break;
        default:
            std::cout << "Opcao invalida!\n"; pronto = false;
        } 
    } while (!pronto);

    std::cout << "Voce possui: " << vidas << " chances\n";

    return vidas;
}

int main() {
    std::string palavraSecreta{};
    int vidas{};
    int dificuldade{};

    std::cout << "*****\nJogo da forca\n*****\n\n";
    std::cout << "Escolha uma palavra para ser adivinhada\n*sem caracteres especiais e acentos*\n->";
    std::cin >> palavraSecreta;
    std::system("cls");

    vidas = selecaoDeficuldade(vidas);
    verificarAcerto(palavraSecreta, vidas);

    return 0;
}
