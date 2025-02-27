#include <iostream>
#include <limits> // Para usar numeric_limits
using namespace std;

// Tabuleiro do jogo
char tabuleiro[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
};

// Função para exibir o tabuleiro
void exibirTabuleiro() {
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j];
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "  -----" << endl;
    }
}

// Função para verificar se há um vencedor
bool verificarVencedor(char jogador) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true; // Linha
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return true; // Coluna
    }
    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return true; // Diagonal principal
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return true; // Diagonal secundária
    return false;
}

// Função para verificar empate
bool verificarEmpate() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ')
                return false; // Ainda há espaços vazios
        }
    }
    return true; // Tabuleiro cheio
}

// Função principal
int main() {
    int linha, coluna;
    char jogadorAtual = 'X';
    bool jogoAtivo = true;

    while (jogoAtivo) {
        exibirTabuleiro();
        cout << "Jogador " << jogadorAtual << ", é sua vez!" << endl;
        cout << "Digite a linha e a coluna (0-2): ";

        // Limpar o buffer de entrada
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Ler a entrada do usuário
        cin >> linha >> coluna;

        // Mensagem de depuração
        cout << "Você digitou: linha = " << linha << ", coluna = " << coluna << endl;

        // Verificar se a jogada é válida
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabuleiro[linha][coluna] != ' ') {
            cout << "Jogada inválida! Tente novamente." << endl;
            continue;
        }

        // Fazer a jogada
        tabuleiro[linha][coluna] = jogadorAtual;

        // Verificar se há um vencedor
        if (verificarVencedor(jogadorAtual)) {
            exibirTabuleiro();
            cout << "Jogador " << jogadorAtual << " venceu!" << endl;
            jogoAtivo = false;
        }
        // Verificar empate
        else if (verificarEmpate()) {
            exibirTabuleiro();
            cout << "Empate!" << endl;
            jogoAtivo = false;
        }

        // Alternar jogadores
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    // Pausar o console antes de fechar (apenas para Windows)
    system("pause");
    return 0;
}