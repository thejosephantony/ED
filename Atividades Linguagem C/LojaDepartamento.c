#include <stdio.h>

/* Numa loja de departamento há 12
vendedores e 5 seções (perfumaria,
papelaria…). Os vendedores podem efetuar
vendas em quaisquer seção. Escrever um
programa em C para ler o total vendido por
cada vendedor em cada seção e exibir o
total por vendedor e o total de vendas da
loja. */


int main() {
	
	const int numeroVendedores = 12; // 12 vendedores
	const int numeroSecoes = 5;      // 5 seções
	
    float vendas[numeroVendedores][numeroSecoes];  // matriz: vendedores x seções
    float totalVendedor[numeroVendedores]; // total vendido por vendedor
    float totalLoja = 0; // total geral da loja
    char* secoes[5] = {"Frutaria", "Padaria", "Papelaria","Perfumaria","Lavanderia"};

    printf("=== Cadastro de vendas ===\n\n");

    // leitura das vendas de cada vendedor em cada seção
    for (int i = 0; i < numeroVendedores; i++) {
        printf("Vendedor %d:\n", i + 1);
        totalVendedor[i] = 0; // inicializa o total do vendedor

        for (int j = 0; j < numeroSecoes; j++) {
            printf("  Digite o total vendido na secao %s: ", secoes[j]);
            scanf("%f", &vendas[i][j]);

            totalVendedor[i] += vendas[i][j]; // soma para o vendedor
            totalLoja += vendas[i][j];        // soma para o total da loja
        }

        printf("\n");
    }

    // exibição dos resultados da loja
    printf("\n=== Totais por vendedor ===\n");
    for (int i = 0; i < numeroVendedores; i++) {
        printf("Vendedor %2d: R$ %.2f\n", i + 1, totalVendedor[i]);
    }

    printf("\nTotal geral da loja: R$ %.2f\n", totalLoja);

    return 0;
}


