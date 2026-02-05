#include <iostream>

bool backtracking_labirinto(int labirinto[20][20], int qtd_linhas, int qtd_colunas, int linha, int coluna){
    if (linha >= qtd_linhas || coluna >= qtd_colunas || linha < 0 || coluna < 0 || labirinto[linha][coluna] == 1){
        return false; // VERIFICA SE A CÉLULA É VÁLIDA
    }
    if (linha == qtd_linhas - 1 && coluna == qtd_colunas - 1){
        return true; // VERIFICA SE A CÉLULA É A SAÍDA
    }

    labirinto[linha][coluna] = 9; // marcar se a célula já foi passada 
    bool retorno = false;

    retorno = backtracking_labirinto(labirinto, qtd_linhas, qtd_colunas, linha+1, coluna); // COMEÇA TENTANDO ANDAR PARA BAIXO
    if (retorno == false){
        retorno = backtracking_labirinto(labirinto, qtd_linhas, qtd_colunas, linha, coluna+1); // SE NÃO CONSEGUIR IR PRA BAIXO, TENTA IR PARA A DIREITA
    }
    if (retorno == false){
        retorno = backtracking_labirinto(labirinto, qtd_linhas, qtd_colunas, linha, coluna-1); // SE NÃO CONSEGUIR IR PRA BAIXO, TENTA IR PARA A ESQUERDA
    }
    if (retorno == false){
        retorno = backtracking_labirinto(labirinto, qtd_linhas, qtd_colunas, linha-1, coluna); // SE NÃO CONSEGUIR IR PRA BAIXO, TENTA IR PARA CIMA
    }

    labirinto[linha][coluna] = 0; // MARCA AS CÉLULAS JÁ PASSADAS PRA QUE SE POSSA PASSAR DE NOVO SE NECESSÁRIO
    return retorno;

}

int main(){
    int linha, coluna, labirinto[20][20];
    std::cin >> linha >> coluna;
    for (int i=0 ; i<linha ; ++i)
        for (int j=0 ; j<coluna ; ++j)
            std:: cin >> labirinto[i][j];
    if (backtracking_labirinto(labirinto, linha, coluna, 0,0))
        std::cout << "Labirinto tem saída.\n";
    else
        std::cout << "Labirinto não tem saída.\n";
    return 0;
}