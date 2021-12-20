///////////////////////////////////////////////////////////////////////////////
///                                                                         ///
///               Universidade Federal do Rio Grande do Norte               ///
///                   Centro de Ensino Superior do Seridó                   ///
///                 Departamento de Computação e Tecnologia                 ///
///                    Disciplina DCT1106 -- Programação                    ///
///                  Projeto Sistema de Controle de Estoque                 ///
///            Developed by @ana678 and @daviddevolin - Out, 2021           ///
///                                                                         ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "departamentos.h"
#include "util.h"
#include "auxiliar.h"

void moduloDepartamentos(void) {
    char opcao;
    do {
        opcao = telaDepartamentos();
        switch (opcao){
            case '1':
                cadastrarDepartamento();
                break;
            case '2':
                telaListarDepartamento();
                break;
            case '3':
                pesquisarDepartamento();
                break;
            case '4':
                atualizarDepartamento();
                break;
            case '5':
                excluirDepartamento();
                break;
        }		
    } while (opcao != '0');
}
/////


void cadastrarDepartamento(void) {
	Departamento* dep;

	dep = telaCadastrarDepartamento();
	free(dep);
}

void pesquisarDepartamento(void) {
	/* funcao em desenvolvimento
    
    Departamento* dep;
	char* cpf;

	cpf = telaPesquisarDepartamento();*/
    telaPesquisarDepartamento();
}

void atualizarDepartamento(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
    telaEditarDepartamento();
}

void excluirDepartamento(void) {
	// função ainda em desenvolvimento
	// exibe a tela apenas para testes
    telaExcluirDepartamentos();
}

/////
// Funcoes Relacionadas ao Modulo Fornecedores

char telaDepartamentos(void) {
    system("clear||cls");
    char escolha;

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         - Modulo Departamentos -                        ///\n");
    printf("///                                                                         ///\n");  
    printf("///            1. Cadastrar Novo Departamento                               ///\n");
    printf("///            2. Listar Departamentos                                      ///\n");
    printf("///            3. Pesquisar Departamento                                    ///\n");
    printf("///            4. Editar Departamento                                       ///\n");
    printf("///            5. Excluir Departamento                                      ///\n");
    printf("///            0. Voltar para Tela Principal                                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n               # Deseja executar qual acao? ");
    scanf("%c", &escolha);
    getchar();
    
    return escolha;
}

Departamento* telaCadastrarDepartamento(void) {  
    system("clear||cls");
    Departamento* dep;
	dep = (Departamento*) malloc(sizeof(Departamento));

    int *vet;

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                      - Cadastro de Departamentos -                      ///\n");
    printf("///                                                                         ///\n"); 

    do{ 
        printf("///            # Insira o nome do novo departamento: ");
        scanf("%[^\n]", dep->nome);
        getchar();
        
    }while(!validaNome(dep->nome));

    vet = (int*) malloc(11*sizeof(int));
    
    printf("///                                                                         ///\n");
    do{
        printf("///            # Qual o CPF do responsavel pelo departamento? ");
        scanf("%[^\n]", dep->cpf);
        getchar();
        int tamArray = 11;
        cpftoi(dep->cpf,vet,tamArray);

    }while(!validaCpf(vet));
    free(vet);
    
    printf("///                                                                         ///\n");
    do{
        printf("///            # Qual o nome do responsavel pelo departamento? ");
        scanf("%[^\n]", dep->nome_responsavel);
        getchar();

    }while(!validaNome(dep->nome_responsavel));
    dep->status = 'a';

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              # Pressione ENTER para voltar para Menu de Departamentos ... ");
    getchar();
   
   return dep;
}

void telaVerProdutosDepartamento(void) {  
    system("clear||cls");
    
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                       - Produtos do Departamento -                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            | Codigo do Produto |   Nome      | Quantidade |             ///\n");
    printf("///                                                                         ///\n");
    printf("///            | 0193467745875     |   Sapato    |     6      |             ///\n");
    printf("///            | 0193467364524     |   Chinelo   |     11     |             ///\n");
    printf("///            | 0193345786242     |   Meias     |     8      |             ///\n");
    printf("///            | 1343494863725     |   Camisas   |     20     |             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              # Pressione ENTER para voltar para Menu de Departamentos ... ");
    getchar();

}

void telaModificarDepartamento(void) {  
    system("clear||cls");
    char editar[2];
    char escolha_editar[2];
    int opMaxima = 3;
    
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         - Editar Departamento -                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Nome do Departamento: Vestuario                           ///\n");
    printf("///            2. Nome Do Responsavel: Julio                                ///\n");
    printf("///            3. Cpf do Responsavel: 111.111.111-11                        ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");

    do{
        printf("///            # Deseja editar algum parametro(s/n)? ");
        scanf("%[^\n]", editar);
        getchar();

    }while(!validaOpcao(editar));

    printf("///                                                                         ///\n");  
    do{
        printf("///              . Qual parametro deseja editar? ");
        scanf("%[^\n]", escolha_editar);
        getchar();

    }while (!validaParametro(escolha_editar,opMaxima));
    

    printf("\n///              . Nome do Departamento: Roupas                             ///\n");
    printf("///                                                                         ///\n");

    do{
        printf("///            # Deseja editar algum parametro(s/n)? ");
        scanf("%[^\n]", editar);
        getchar();

    }while(!validaOpcao(editar));

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              # Pressione ENTER para voltar para Menu de Departamentos ... ");
    getchar();
}

void telaListarDepartamento(void) {
    system("clear||cls");
    int escolha;

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                       - Lista de Departamentos -                        ///\n");
    printf("///                                                                         ///\n");    
    printf("///            1. Frios e Laticineos                                        ///\n");
    printf("///            2. Produtos de Limpeza                                       ///\n");
    printf("///            3. Produtos Higienicos                                       ///\n");
    printf("///            4. Padaria e Confeitaria                                     ///\n");
    printf("///            5. Condimentos                                               ///\n");    
    printf("///            6. Enlatados                                                 ///\n");  
    printf("///            7. Bebidas                                                   ///\n");
    printf("///            8. Vestuario                                                 ///\n"); 
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              # Pressione ENTER para voltar para Menu de Departamentos ... ");
    getchar();

}

void telaExcluirDepartamentos(void) {
    system("clear||cls");
    char cpf[14];
    int *vet;
    
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                        - Excluir Departamento -                         ///\n");
    printf("///                                                                         ///\n");
      
    vet = (int*) malloc(11*sizeof(int));
    
    printf("///                                                                         ///\n");
    do{
        printf("///            # Insira o CPF do responsavel pelo departamento:  ");
        scanf("%[^\n]", cpf);
        getchar();
        int tamArray = 11;
        cpftoi(cpf,vet,tamArray);

    }while(!validaCpf(vet));
    free(vet);
    
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              # Pressione ENTER para voltar para Menu de Departamentos ... ");
    getchar();
}

void telaEditarDepartamento(void) {
    system("clear||cls");
    char cpf[14];
    int *vet;
    
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                         - Editar Departamento -                         ///\n");
    printf("///                                                                         ///\n");  

    vet = (int*) malloc(11*sizeof(int));
    printf("///                                                                         ///\n");
    do{
         printf("///            # Insira o CPF do responsavel pelo departamento:  ");
        scanf("%[^\n]", cpf);
        getchar();
        int tamArray = 11;
        cpftoi(cpf,vet,tamArray);

    }while(!validaCpf(vet));
    free(vet);

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              . Voce sera redirecionado para tela de edicao ... ");
    sleep(1);
    telaModificarDepartamento();
}


void telaPesquisarDepartamento(void) {
    system("clear||cls");
    char cpf[14];
    int *vet;
    
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                        - Pesquisar Departamento -                       ///\n");
    printf("///                                                                         ///\n");  

    vet = (int*) malloc(11*sizeof(int));
    printf("///                                                                         ///\n");
    do{
         printf("///            # Insira o CPF do responsavel pelo departamento:  ");
        scanf("%[^\n]", cpf);
        getchar();
        int tamArray = 11;
        cpftoi(cpf,vet,tamArray);

    }while(!validaCpf(vet));
    free(vet);

    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              . Voce sera redirecionado para os detalhes desse departamento ... ");
    sleep(1);
    telaExibirDepartamento();
}

void telaExibirDepartamento(void) {  
    system("clear||cls");

    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///               Universidade Federal do Rio Grande do Norte               ///\n");
    printf("///                   Centro de Ensino Superior do Serido                   ///\n");
    printf("///                 Departamento de Computacao e Tecnologia                 ///\n");
    printf("///                    Disciplina DCT1106 -- Programacao                    ///\n");
    printf("///                  Projeto Sistema de Controle de Estoque                 ///\n");
    printf("///            Developed by @ana678 and @daviddevolin - Out, 2021           ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///           = = = = = Sistema de Controle de Estoques = = = = =           ///\n");
    printf("///                                                                         ///\n");
    printf("///                             - Departamento -                            ///\n");
    printf("///                                                                         ///\n");
    printf("///            -> Informacoes do Departamento                               ///\n");
    printf("///                                                                         ///\n");
    printf("///            . Nome do Departamento: Vestuario                           ///\n");
    printf("///            . Nome Do Responsavel: Julio                                ///\n");
    printf("///            . Cpf do Responsavel: 111.111.111-11                        ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n              # Pressione ENTER para voltar para Menu de Departamentos ... ");
    getchar();

}