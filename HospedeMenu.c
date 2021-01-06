/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void menuHospede(){
    int opc, sair =0;
    while(sair ==0){
        printf("Digite a opção do hospede:\n");
        printf("1 - Cadastrar Hospede:\n");
        printf("2 - Visualizar Hospede:\n");
        printf("3 - Editar Hospede:\n");
        printf("4 - Excluir Hospede:\n");
        scanf("%d%*c",&opc);
        switch (opc) {
            case 1:
                // função cadastro de hospedes
                printf("***** CADASTRO DE HÓSPEDES ******\n");
                printf("Digite o código do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o Nome do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o Endereço Completo do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o CPF do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o Telefone do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o E-mail do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o Sexo do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o Estado Civil do Hóspede:\n");
                //scanf("%d%*c",);
                printf("Digite o Data de Nascimento do Hóspede:\n");
                //scanf("%d%*c",);
                //DPS DE LER TODOS OS DADOS, CHAMA O CONTROLE PARA VALIDAR
                //CadastrarControl();
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Valor Invalido!\n");
                
                break;
        }
    }
    
     
}