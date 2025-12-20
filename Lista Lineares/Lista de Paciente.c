#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura PacienteEspera
typedef struct {
    int senha;              // Chave única
    char nome[20];          // Nome do paciente
    char horarioChegada[5]; // Horário de chegada HH:MM
} PacienteEspera;

// Variáveis globais do sistema
PacienteEspera lista[20];   // Vetor de pacientes (capacidade máxima: 20)
int tamanhoAtual = 0;       // Quantos slots ocupados (inicialmente 0)
int proximaSenha = 1001;    // Controle de senhas sequenciais (inicia em 1001)

// Protótipos das funções
void inicializarSistema();
void exibirMenu();
void adicionarPaciente();
void atenderProximo();
void exibirFila();
void buscarPaciente();
void cancelarAtendimento();
void estatisticas();
void obterHorarioAtual(char* buffer);
int buscarPorSenha(int senha);

int main() {
    inicializarSistema();

    int opcao;
    do {
        exibirMenu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer

        switch(opcao) {
            case 1: adicionarPaciente(); break;
            case 2: atenderProximo(); break;
            case 3: exibirFila(); break;
            case 4: buscarPaciente(); break;
            case 5: cancelarAtendimento(); break;
            case 6: estatisticas(); break;
            case 0: printf("Sistema encerrado.\n"); break;
            default: printf("Opcao invalida!\n");
        }

        if (opcao != 0) {
            printf("\nPressione Enter para continuar...");
            getchar();
        }
    } while (opcao != 0);

    return 0;
}

// Inicializa o sistema
void inicializarSistema() {
    printf("=================================\n");
    printf("  SISTEMA DE FILA DE ESPERA\n");
    printf("    CLINICA MEDICA\n");
    printf("=================================\n");
    printf("Sistema inicializado com sucesso!\n");
    printf("Capacidade maxima: 20 pacientes\n");
    printf("Senha inicial: %d\n", proximaSenha);
}

// Exibe o menu principal
void exibirMenu() {
    printf("\n========== MENU PRINCIPAL ==========\n");
    printf("1. Adicionar paciente a fila\n");
    printf("2. Atender proximo paciente\n");
    printf("3. Exibir fila de espera\n");
    printf("4. Buscar paciente por senha\n");
    printf("5. Cancelar atendimento\n");
    printf("6. Estatisticas do sistema\n");
    printf("0. Sair do sistema\n");
    printf("===================================\n");
}

// Obtém o horário atual no formato HH:MM
void obterHorarioAtual(char* buffer) {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    strftime(buffer, 6, "%H:%M", tm_info);
}

// Adiciona um novo paciente à fila
void adicionarPaciente() {
    if (tamanhoAtual >= 20) {
        printf("\n[ERRO] Fila lotada! Nao e possivel adicionar mais pacientes.\n");
        return;
    }

    PacienteEspera novo;

    // Gerar senha automaticamente
    novo.senha = proximaSenha++;

    // Ler nome do paciente
    printf("\n--- NOVO PACIENTE ---\n");
    printf("Senha gerada: %d\n", novo.senha);
    printf("Nome do paciente: ");
    fgets(novo.nome, 20, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // Remover \n

    // Obter horário atual
    obterHorarioAtual(novo.horarioChegada);

    // Adicionar à lista (no final da fila)
    lista[tamanhoAtual] = novo;
    tamanhoAtual++;

    printf("\n[SUCESSO] Paciente adicionado!\n");
    printf("Senha: %d | Nome: %s | Chegada: %s\n",
           novo.senha, novo.nome, novo.horarioChegada);
    printf("Posicao na fila: %d\n", tamanhoAtual);
}

// Busca paciente por senha (retorna índice ou -1 se não encontrado)
int buscarPorSenha(int senha) {
    for (int i = 0; i < tamanhoAtual; i++) {
        if (lista[i].senha == senha) {
            return i;
        }
    }
    return -1;
}

// Atende o próximo paciente (primeiro da fila)
void atenderProximo() {
    if (tamanhoAtual == 0) {
        printf("\n[INFO] Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    PacienteEspera atendido = lista[0];

    printf("\n--- ATENDIMENTO ---\n");
    printf("CHAMANDO PACIENTE:\n");
    printf("Senha: %d\n", atendido.senha);
    printf("Nome: %s\n", atendido.nome);
    printf("Horario de chegada: %s\n", atendido.horarioChegada);

    // Remover o primeiro paciente (deslocar todos para frente)
    for (int i = 0; i < tamanhoAtual - 1; i++) {
        lista[i] = lista[i + 1];
    }

    tamanhoAtual--;

    printf("\n[SUCESSO] Paciente atendido e removido da fila.\n");
    printf("Pacientes restantes na fila: %d\n", tamanhoAtual);
}

// Exibe todos os pacientes na fila
void exibirFila() {
    if (tamanhoAtual == 0) {
        printf("\n[INFO] Fila vazia! Nenhum paciente aguardando.\n");
        return;
    }

    printf("\n--- FILA DE ESPERA ---\n");
    printf("Total de pacientes: %d/20\n\n", tamanhoAtual);
    printf("POS | SENHA | NOME              | CHEGADA | TEMPO ESPERA\n");
    printf("----|-------|-------------------|---------|--------------\n");

    char horarioAtual[6];
    obterHorarioAtual(horarioAtual);

    for (int i = 0; i < tamanhoAtual; i++) {
        // Calcular tempo de espera aproximado (simplificado)
        int horaChegada, minChegada;
        int horaAtual, minAtual;

        sscanf(lista[i].horarioChegada, "%d:%d", &horaChegada, &minChegada);
        sscanf(horarioAtual, "%d:%d", &horaAtual, &minAtual);

        int esperaMinutos = (horaAtual - horaChegada) * 60 +
                           (minAtual - minChegada);

        printf("%3d | %5d | %-17s | %7s | %4d minutos\n",
               i + 1,
               lista[i].senha,
               lista[i].nome,
               lista[i].horarioChegada,
               esperaMinutos > 0 ? esperaMinutos : 0);
    }
}

// Busca um paciente específico por senha
void buscarPaciente() {
    if (tamanhoAtual == 0) {
        printf("\n[INFO] Fila vazia! Nenhum paciente para buscar.\n");
        return;
    }

    int senha;
    printf("\n--- BUSCA DE PACIENTE ---\n");
    printf("Digite a senha do paciente: ");
    scanf("%d", &senha);

    int posicao = buscarPorSenha(senha);

    if (posicao == -1) {
        printf("\n[ERRO] Paciente nao encontrado! Verifique a senha.\n");
    } else {
        printf("\n--- PACIENTE ENCONTRADO ---\n");
        printf("Posicao na fila: %d\n", posicao + 1);
        printf("Senha: %d\n", lista[posicao].senha);
        printf("Nome: %s\n", lista[posicao].nome);
        printf("Horario de chegada: %s\n", lista[posicao].horarioChegada);

        // Calcular tempo de espera
        char horarioAtual[6];
        obterHorarioAtual(horarioAtual);

        int horaChegada, minChegada;
        int horaAtual, minAtual;

        sscanf(lista[posicao].horarioChegada, "%d:%d", &horaChegada, &minChegada);
        sscanf(horarioAtual, "%d:%d", &horaAtual, &minAtual);

        int esperaMinutos = (horaAtual - horaChegada) * 60 +
                           (minAtual - minChegada);

        printf("Tempo de espera: %d minutos\n", esperaMinutos > 0 ? esperaMinutos : 0);

        // Estimativa de atendimento
        if (posicao == 0) {
            printf("Situacao: PROXIMO A SER ATENDIDO\n");
        } else {
            printf("Estimativa: %d pacientes a frente\n", posicao);
            printf("Tempo estimado: ~%d minutos\n", posicao * 15); // Supondo 15 min por paciente
        }
    }
}

// Cancela o atendimento de um paciente
void cancelarAtendimento() {
    if (tamanhoAtual == 0) {
        printf("\n[INFO] Fila vazia! Nenhum paciente para cancelar.\n");
        return;
    }

    int senha;
    printf("\n--- CANCELAR ATENDIMENTO ---\n");
    printf("Digite a senha do paciente a ser removido: ");
    scanf("%d", &senha);

    int posicao = buscarPorSenha(senha);

    if (posicao == -1) {
        printf("\n[ERRO] Paciente nao encontrado!\n");
        return;
    }

    printf("\n--- CONFIRMAR CANCELAMENTO ---\n");
    printf("Paciente encontrado:\n");
    printf("Senha: %d | Nome: %s | Posicao: %d\n",
           lista[posicao].senha, lista[posicao].nome, posicao + 1);

    char confirmacao;
    printf("\nTem certeza que deseja remover este paciente? (S/N): ");
    scanf(" %c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        // Remover paciente (deslocar elementos)
        for (int i = posicao; i < tamanhoAtual - 1; i++) {
            lista[i] = lista[i + 1];
        }

        tamanhoAtual--;
        printf("\n[SUCESSO] Paciente removido da fila!\n");
    } else {
        printf("\n[INFO] Operacao cancelada pelo usuario.\n");
    }
}

// Exibe estatísticas do sistema
void estatisticas() {
    printf("\n--- ESTATISTICAS DO SISTEMA ---\n");
    printf("Capacidade total: 20 pacientes\n");
    printf("Pacientes na fila: %d\n", tamanhoAtual);
    printf("Vagas disponiveis: %d\n", 20 - tamanhoAtual);
    printf("Proxima senha disponivel: %d\n", proximaSenha);
    printf("Total de senhas emitidas: %d\n", proximaSenha - 1001);

    if (tamanhoAtual > 0) {
        // Tempo médio de espera
        char horarioAtual[6];
        obterHorarioAtual(horarioAtual);

        int horaAtual, minAtual;
        sscanf(horarioAtual, "%d:%d", &horaAtual, &minAtual);

        int tempoTotal = 0;
        char maisAntigoNome[20];
        char maisAntigoHorario[6];
        int maisAntigoPos = 0;

        // Encontrar paciente mais antigo
        strcpy(maisAntigoNome, lista[0].nome);
        strcpy(maisAntigoHorario, lista[0].horarioChegada);

        for (int i = 0; i < tamanhoAtual; i++) {
            int horaChegada, minChegada;
            sscanf(lista[i].horarioChegada, "%d:%d", &horaChegada, &minChegada);

            int esperaMinutos = (horaAtual - horaChegada) * 60 +
                               (minAtual - minChegada);
            tempoTotal += esperaMinutos > 0 ? esperaMinutos : 0;

            // Verificar se é o mais antigo (comparar strings HH:MM)
            if (strcmp(lista[i].horarioChegada, maisAntigoHorario) < 0) {
                strcpy(maisAntigoNome, lista[i].nome);
                strcpy(maisAntigoHorario, lista[i].horarioChegada);
                maisAntigoPos = i;
            }
        }

        float tempoMedio = (float)tempoTotal / tamanhoAtual;

        printf("\n--- METRICAS DE ESPERA ---\n");
        printf("Tempo medio de espera: %.1f minutos\n", tempoMedio);
        printf("Paciente ha mais tempo na fila:\n");
        printf("  Nome: %s (Senha: %d)\n",
               lista[maisAntigoPos].nome, lista[maisAntigoPos].senha);
        printf("  Chegada: %s\n", lista[maisAntigoPos].horarioChegada);
        printf("  Posicao atual: %d\n", maisAntigoPos + 1);

        // Estimativa para novos pacientes
        printf("\n--- PREVISAO ---\n");
        printf("Tempo estimado para novo paciente: %d minutos\n",
               tamanhoAtual * 15); // 15 minutos por paciente
    }

    printf("\n--- HISTORICO ---\n");
    printf("Senhas utilizadas: %d a %d\n",
           1001, proximaSenha - 1);
}
