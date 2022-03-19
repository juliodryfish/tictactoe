#include <iostream>
#include <array>

constexpr int DIM  = 3;

using tabuleiro = std::array<std::array<char,DIM>,DIM>;


bool verificaEmpate(const tabuleiro& t) {
    for(int linha = 0; linha < DIM; ++linha) {
        for(int coluna = 0; coluna < DIM; ++coluna) {
            if(t[linha][coluna] == '_') return false;
        }
    }
    return true;
}

bool verificaVitoria(const tabuleiro& t, int linha, int coluna, char jogador) {
    
    if( (t[linha][(coluna + 0) %DIM] == t[linha][(coluna + 1) %DIM]) &&
        (t[linha][(coluna + 0) %DIM] == t[linha][(coluna + 2) %DIM])) {
        return true; // linha
    }
    else if( (t[(linha + 0) %DIM][coluna] == t[(linha + 1) %DIM][coluna]) && 
             (t[(linha + 0) %DIM][coluna] == t[(linha + 2) %DIM][coluna])) {
        return true; // coluna
    }
    else if( linha == coluna &&
        (t[(linha + 0) %DIM][(coluna + 0) %DIM] == t[(linha + 1) %DIM][(coluna + 1) %DIM]) && 
        (t[(linha + 0) %DIM][(coluna + 0) %DIM] == t[(linha + 2) %DIM][(coluna + 2) %DIM])) {
        return true; // diagonal
    }
    else if( linha + coluna == 2 &&
        (t[(linha + 0) %DIM][(coluna + 0) %DIM] == t[(linha + 1) %DIM][(coluna + 2) %DIM]) && 
        (t[(linha + 0) %DIM][(coluna + 0) %DIM] == t[(linha + 2) %DIM][(coluna + 1) %DIM])) {
        return true; // diagonal inversa
    }

    return false;
}

void preencheTabuleiro(tabuleiro& t) {
    for(int linha = 0; linha < DIM; ++linha) {
        for(int coluna = 0; coluna < DIM; ++coluna) {
            t[linha][coluna] = '_';
        }
    }
}

void registaJogada(tabuleiro& t, char valor, int linha, int coluna) {
    
    if(linha >= DIM || coluna >= DIM) return; // falha
    if(linha < 0    ||    coluna < 0) return; // falha

    t[linha][coluna] = valor;
}

void desenhaTabuleiro(const tabuleiro& t) {

    for(int linha = 0; linha < DIM; ++linha) {
        for(int coluna = 0; coluna < DIM; ++coluna) {
            std::cout << t[linha][coluna] << "  ";   
        }
        std::cout << std::endl;
    }
}


int main() {

    tabuleiro t;
    preencheTabuleiro(t);
    desenhaTabuleiro(t);

    char jogador[2] = {'X', 'O'};

    int contador_jogadas = 0;

    int linha, coluna;
    do {
        std::cout << "Vez do jogador " << jogador[contador_jogadas % 2] << ":" << std::endl;
        std::cin >> linha >> coluna;
        registaJogada(t, jogador[contador_jogadas % 2], linha, coluna);
        desenhaTabuleiro(t);
        contador_jogadas++;
    } while(!verificaVitoria(t, linha, coluna , jogador[contador_jogadas%2]) && !verificaEmpate(t));

    return 0;
}
