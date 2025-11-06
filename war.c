// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

#include <stdio.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_STRING 20

struct Territorio {
    char nome[TAM_STRING];
    char cor[TAM_STRING];
    int tropas;
};

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio war[MAX_TERRITORIOS];
    int totalTerritorios = 0;
    int opcao;
   
    do {
        printf("==================================================\n");
        printf("         TERRITORIOS - MAPA\n");
        printf("==================================================\n");
        printf("1 - Cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("0 - Sair\n");
        printf("--------------------------------------------------\n");
        printf("Escolha uma opcao: "); 

        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: //CADASTRO DE TERRITÓRIO
                printf("--- Cadastro de Novo Território ---\n\n");

                if (totalTerritorios < MAX_TERRITORIOS) {
                    printf("Digite o nome do território: ");
                    fgets(war[totalTerritorios].nome, TAM_STRING, stdin);

                    printf("Digite a cor do territorio: ");
                    fgets(war[totalTerritorios].cor, TAM_STRING, stdin);

                    war[totalTerritorios].nome[strcspn(war[totalTerritorios].nome, "\n")] = '\n';
                    war[totalTerritorios].cor[strcspn(war[totalTerritorios].cor, "\n")] = '\n';
                
                    printf("Digite a quantidade de tropas: ");
                    scanf("%d", &war[totalTerritorios].tropas);
                    limparBufferEntrada();
        
                    totalTerritorios++;
    
                    printf("\nTerritório cadastrado com sucesso!\n");
                } else {
                    printf("Mapa Completo! Nao eh possivel cadastrar mais territorios.\n");
                }

                printf("\nPressione Enter para continuar...");
                getchar(); //Pausa para o usuario ler a mensagem antes de voltar ao menu.
                break;

            case 2: //LISTAGEM DE TERRITORIOS
                printf("---Lista de Territorios Cadastrados---\n\n");
        
                if (totalTerritorios == 0) {
                    printf("Nenhum território cadastrado ainda. \n");
                } else {
                    for (int i = 0; i < totalTerritorios; i++) {
                        printf("----------------------------------\n");  
                        printf("TERRITÓRIO %d\n", i + 1);
                        printf("Nome: %s\n", war[i].nome);
                        printf("Cor: %s\n", war[i].cor);
                        printf("Tropas: %d\n", war[i].tropas);
                    }
                    printf("----------------------------------\n");
                }
        
            
                printf("\nPressione Enter para continuar...");
                getchar();
                break;

            case 0: //sair
                printf("\nSaindo do sistema...\n");
                break;

            default: //OPCAO INVALIDA
                printf("\nOpcao Invalida! tente Novamente.\n");
                printf("\nPressione Enter para continuar...");
                getchar();
                break;
        }
    
    } while (opcao != 0);
    

    return 0;
}

// --- Implementação das Funções ---

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
