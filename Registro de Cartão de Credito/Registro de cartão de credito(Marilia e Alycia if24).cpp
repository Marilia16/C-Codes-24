#include<iostream>
using namespace std;
struct registrodeCartao{
  int id;
  int senhaCartao;
  float limite;
  
};
struct registrodeConta{
  double cpf;
  string nome;
  int nC=0;
  registrodeCartao cartao[5];
  int senha;
  
  
};
int main(){
	//Trabalho de Marilia e Alycia if24
  int op, fim=0, ind, testarId, indpe, testarSenha, altSenha, opcc;
  bool cpfExiste=false, idExiste=false, flag=0;;
  double testarCpf;
  char son, desistir=0;
  int nC=0;
  
  registrodeConta conta[100];
  do{
  	
    cout<<"\n\t     BEM VINDO AO MENU DO BANCO";
    cout<<"\n\t\t\t   MENU PRINCIPAL\n";
    cout<<"\n\t-----------------------------------";
    cout<<"\n\t| 1 - INCLUIR UMA CONTA           |";   
    cout<<"\n\t| 2 - ADICIONAR NOVO CARTAO(MAX.5)|";
    cout<<"\n\t| 3 - MOSTRAR CARTOES CADASTRADOS |";
    cout<<"\n\t| 4 - EXCLUIR CARTAO              |";
    cout<<"\n\t| 5 - BUSCAR CONTA                |";
    cout<<"\n\t| 6 - ALTERAR CONTA E CARTOES     |";
    cout<<"\n\t| 7 - EXCLUIR CONTA               |";
    cout<<"\n\t| 8 - LISTAR CONTAS EXISTENTES    |";
    cout<<"\n\t| 9 - SAIR DO SISTEMA             |";
    cout<<"\n\t-----------------------------------";
    cout<<"\n\tQual a opcao desejada? ";
    cin>>op;
    switch(op){
      case 1:
        cout<<"\n\tAdicionando conta..";
        do{
          cout<<"\n\tvoce tem certeza?(s para sim e n para nao) ";
          cin>>son;
        }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
        if(son=='s'||son=='S'){
          do{
            cout<<"\n\tAdicione seu cpf: ";
            cin>>testarCpf;
            cpfExiste=false;
            for(int i=0;i<=fim;i++){
              if(testarCpf==conta[i].cpf){
                cpfExiste=true;
              }
            }
            if(cpfExiste==true){
            cout<<"\n\tCpf ja cadastrado\n\tTente novamente";
            }else{
              conta[fim].cpf=testarCpf;
              getchar();
              cout<<"\n\tAdicione seu nome: ";
              getline(cin,conta[fim].nome);
              cout<<"\n\tAdicione a senha da sua conta: ";
              cin>>conta[fim].senha;
              cout<<"\n\tAdicionando o cartao numero "<<(conta[fim].nC+1);
              nC=conta[fim].nC;
              cout<<"\n\tAdicione seu id: ";
              cin>>conta[fim].cartao[nC].id;
              cout<<"\n\tAdicione sua senha: ";
              cin>>conta[fim].cartao[nC].senhaCartao;
              do{
                cout<<"\n\tAdicone o limite do cartao(min-1000, max-10000: ";
                cin>>conta[fim].cartao[nC].limite;
              }while(conta[fim].cartao[nC].limite<1000||conta[fim].cartao[nC].limite>10000);
              conta[fim].nC++;
              fim++;
            }
          }while(cpfExiste==true);
        }else{
          cout<<"\n\tAcao cancelada\n";
        }
      break;
      case 2:
        cout<<"\n\tAdicionando cartoes..";
        if(fim!=0){
          do{
            cout<<"\n\tvoce tem certeza?(s para sim e n para nao)";
            cin>>son;
          }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
          if(son=='s'||son=='S'){
            cout<<"\n\tAdicone seu cpf: ";
            cin>>testarCpf;
            cpfExiste=false;
            for(int i=0;i<fim;i++){
              if(testarCpf==conta[i].cpf){
                cpfExiste=true;
                ind=i;
              }
            }
            if(cpfExiste==true){
              desistir=0;
              do{
                cout<<"\n\tAdicione sua senha: ";
                cin>>testarSenha;
                desistir++;
                if(desistir<=3){
                  if(testarSenha==conta[ind].senha){
                    do{
                      nC=conta[ind].nC;
                      if(nC<5){
                        cout<<"\n\tAdicionando cartao numero "<<(conta[ind].nC+1);
                        cout<<"\n\tAdicione seu id: ";
                        cin>>testarId;
                        idExiste=false;
                        for(int i=0;i<=nC;i++){
                          if(testarId==conta[ind].cartao[i].id){
                            idExiste=true;
                          }
                        }
                        if(idExiste==true){
                          cout<<"\n\tId cadastrado\n\tTente novamente\n";
                        }else{
                          conta[ind].cartao[nC].id=testarId;
                          cout<<"\n\tAdicione sua senha: ";
                          cin>>conta[ind].cartao[nC].senhaCartao;
                          do{
                            cout<<"\n\tAdicone o limite do cartao(min-1000, max-10000: ";
                            cin>>conta[ind].cartao[nC].limite;
                          }while(conta[ind].cartao[nC].limite<1000||conta[ind].cartao[nC].limite>10000);
                          cout<<"\n\tCartao cadastrado com sucesso!\n";
                          conta[ind].nC++;
                        }
                      }
                      if(conta[ind].nC<5){
                        cout<<"\n\tVoce deseja cadastrar outro(s para sim e n para nao)?";
                        cin>>son;
                      }else{
                        cout<<"\n\tVoce chegou no numero maximo de cartoes\n";
                      }
                    }while((son=='s'||son=='S')&&(conta[ind].nC<5));
                  }else{
                  cout<<"\n\tSenha incorreta\n\tTente novamente\n";
                  }
                }else{
                  cout<<"\n\tVoce ja testou a senha muitas vezes\n\tTente novamente mais tarde\n";
                }
              }while((testarSenha!=conta[ind].senha)&&(desistir<=3));
            }else{
              cout<<"\n\tCpf nao cadastrado\n";
            }
          }else{
          cout<<"\n\tAcao cancelada\n";
          }
        }else{
          cout<<"\n\tNao tem nenhuma conta cadastrada..\n";
        }
      break;
      case 3: 
        cout<<"\n\tLista de cartões cadastrados..";
        if(fim!=0){
          do{
            cout<<"\n\tvoce tem certeza?(s para sim e n para nao) ";
            cin>>son;
          }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
          if(son=='s'||son=='S'){
            cout<<"\n\tAdicione seu cpf: ";
            cin>>testarCpf;
            cpfExiste=false;
            for(int i=0;i<fim;i++){
              if(testarCpf==conta[i].cpf){
                cpfExiste=true;
                ind=i;
              }
            }
            if(cpfExiste==true){
              desistir=0;
              do{ 
                cout<<"\n\tAdicione sua senha: ";
                cin>>testarSenha;
                desistir++;
                if(desistir<=3){
                  if(testarSenha==conta[ind].senha){
                    nC=conta[ind].nC;
                      for(int i=0;i<nC;i++){
                      cout<<"\n\tId: "<<conta[ind].cartao[i].id;
                      cout<<"\n\tsenha: "<<conta[ind].cartao[i].senhaCartao;
                      cout<<"\n\tLimite: "<<conta[ind].cartao[i].limite;
                    }
                  }else{
                    cout<<"\n\tSenha incorreta\n\tTente novamente\n";
                  }
                }else{
                  cout<<"\n\tVoce ja tentou adicionar sua senha muitas vezes\n\tTente novamente mais tarde\n";
                }
              }while((testarSenha!=conta[ind].senha)&&desistir<=3);
            }else{
              cout<<"\n\tcpf nao cadastrado\n";
            }
          }else{
            cout<<"\n\tAcao cancelada\n";
          }
        }else{
          cout<<"\n\tNao tem nenhuma conta cadastrada..\n";
        }
      break;
      case 4:
        cout<<"\n\tExcluindo cartao..";
        if(fim!=0){
          do{
            cout<<"\n\tvoce tem certeza?(s para sim e n para nao)";
            cin>>son;
          }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
          if(son=='s'||son=='S'){
            cout<<"\n\tAdicione seu cpf: ";
            cin>>testarCpf;
            cpfExiste=false;
            for(int i=0;i<fim;i++){
              if(testarCpf==conta[i].cpf){
                cpfExiste=true;
                ind=i;
              }
            }
            if(cpfExiste==true){
              desistir=0;
              do{
                cout<<"\n\tAdicione sua senha: ";
                cin>>testarSenha;
                desistir++;
                if(desistir<=3){
                  if(testarSenha==conta[ind].senha){
                  if(conta[ind].nC!=0){
                      cout<<"\n\tAdicione id que deseja excluir: ";
                      cin>>testarId;
                      idExiste=false;
                      for(int i=0;i<=nC;i++){
                        if(testarId==conta[ind].cartao[i].id){
                          idExiste=true;
                          indpe=i;
                        }
                      }
                      nC=conta[ind].nC;
                      if(idExiste==true){
                        for(int i=indpe;i<=nC;i++){
                          conta[ind].cartao[i].id=conta[ind].cartao[i+1].id;
                          conta[ind].cartao[i].senhaCartao=conta[ind].cartao[i+1].senhaCartao;
                          conta[ind].cartao[i].limite=conta[ind].cartao[i+1].limite;
                        }  
                        conta[ind].nC--;
                      }else{
                        cout<<"\n\tId não existe\n";
                      }
                    }else{
                    cout<<"\n\tVoce nao possui cartoes para excluir..\n";
                    }
                  }else{
                    cout<<"\n\tSenha incorreta\n\tTente novamente\n";
                  }
                }else{
                  cout<<"\n\tVoce ja tentou adicionar sua senha muitas vezes\n\tTente novamente mais tarde\n";
                }
              }while((testarSenha!=conta[ind].senha)&&(desistir<=3));
            }else{
              cout<<"\n\tCpf não cadastrado\n";
            }
          }else{
            cout<<"\n\tAcao cancelada\n";
          }
        }else{
          cout<<"\n\tNao tem nenhuma conta cadastrada..\n";
        }
      break;
      case 5:
      cout<<"\n\tBuscando conta..";
      if(fim!=0){
        do{
          cout<<"\n\tvoce tem certeza?(s para sim e n para nao)";
          cin>>son;
        }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
        if(son=='s'||son=='S'){
          cout<<"\n\tAdicone seu cpf: ";
          cin>>testarCpf;
          cpfExiste=false;
          for(int i=0;i<fim;i++){
            if(testarCpf==conta[i].cpf){
              cpfExiste=true;
              ind=i;
            }
          }
          if(cpfExiste==true){
            cout<<"\n\tcpf: "<<conta[ind].cpf;
            cout<<"\n\tNome: "<<conta[ind].nome;
            cout<<"\n\tSenha da conta: "<<conta[ind].senha;
            cout<<"\n\tNumero de cartoes: "<<conta[ind].nC;
          
          }else{
            cout<<"\n\tCpf nao cadastrado\n";
          }
        }else{
          cout<<"\n\tacao cancelada\n";
        }
      }else{
        cout<<"\n\tNao tem nenhuma conta cadastrada..\n";
      }
      break;
      case 6:
        cout<<"\n\tAlterando conta ou cartoes...";
        if(fim!=0){
          do{
            cout<<"\n\tvoce tem certeza?(s para sim e n para nao) ";
            cin>>son;
          }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
          if(son=='s'||son=='S'){
            cout<<"\n\tAdicione seu cpf: ";
            cin>>testarCpf;
            cpfExiste=false;
            for(int i=0;i<fim;i++){
              if(testarCpf==conta[i].cpf){
                cpfExiste=true;
                ind=i;
              }
            }
            if(cpfExiste==true){
              desistir=0;
              do{
                cout<<"\n\tAdicione sua senha atual: ";
                cin>>testarSenha;
                desistir++;
                if(desistir<=3){
                  if(testarSenha==conta[ind].senha){
                    do{
                      cout<<"\n\tVoce quer Alterar uma conta ou um cartao(1 para conta e 2 para cartao)?";
                      cin>>opcc;
                    }while(opcc!=1&&opcc!=2);
                    if(opcc==1){
                      do{
                        cout<<"\n\tvoce quer alterar sua senha(s para sim e n para nao): ";
                        cin>>son;
                      }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
                      if(son=='s'||son=='S'){
                        do{
                          flag=0;
                          cout<<"\n\tAdicione sua nova senha: ";
                          cin>>altSenha;
                          if(altSenha!=conta[ind].senha){
                            conta[ind].senha=altSenha;
                          }else{
                            cout<<"\n\tVoce nao pode usar a mesma senha..";
                            flag=1;
                          }
                        }while(flag==1);
                      }else{
                        cout<<"\n\tVoce escolheu nao alterar a senha..";
                      }
                      getchar();
                      cout<<"\n\tAdicione seu novo nome: ";
                      getline(cin,conta[ind].nome);
                      break;
                    }else{
                      cout<<"\n\tAdicione o id que deseja alterar: ";
                      cin>>testarId;
                      idExiste=false;
                      for(int i=0;i<=nC;i++){
                        if(testarId==conta[ind].cartao[i].id){
                          idExiste=true;
                          indpe=i;
                        }
                      }
                      if(idExiste==true){
                        cout<<"\n\tAdicione sua nova senha: ";
                        cin>>conta[ind].cartao[indpe].senhaCartao;
                        do{
                          cout<<"\n\tAdicone o  novo limite do cartao(min-1000, max-10000: ";
                          cin>>conta[ind].cartao[indpe].limite;
                        }while(conta[ind].cartao[indpe].limite<1000||conta[ind].cartao[indpe].limite>10000);
                      }else{
                        cout<<"\n\tId nao cadastrado\n";
                      }
                    }
                  }else{
                    cout<<"\n\tSenha incorreta\n\tTente novamente\n";
                  }
                }else{
                  cout<<"\n\tVoce ja tentou adicionar sua senha muitas vezes\n\tTente novamente mais tarde\n";
                }
              }while((testarSenha!=conta[ind].senha)&&(desistir<=3));
            }
          }else{
            cout<<"\n\tAcao cancelada\n";
          }
        }else{
          cout<<"\n\tNao tem nenhuma conta cadastrada..\n";
        }
      break;
      case 7:
        cout<<"\n\tExcluindo conta..";
        if(fim!=0){
          do{
            cout<<"\n\tvoce tem certeza?(s para sim e n para nao) ";
            cin>>son;
          }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
          if(son=='s'||son=='S'){
            cout<<"\n\tAdicione o cpf que deseja excluir: ";
            cin>>testarCpf;
            cpfExiste=false;
            for(int i=0;i<fim;i++){
              if(testarCpf==conta[i].cpf){
                cpfExiste=true;
                ind=i;
              }
            }
            if(cpfExiste==true){
              desistir=0;
              do{
                cout<<"\n\tAdicione sua senha para comprovacao: ";
                cin>>testarSenha;
                desistir++;
                if(testarSenha==conta[ind].senha){
                  for (int i=ind;i<fim;i++) {
                    conta[i] = conta[i + 1];
                  }
                  fim--;
                  cout<<"\n\tConta excluida com sucesso";
                  desistir=5;
                }else{
                  cout<<"\n\tSenha incorreta\n\tTente novamente\n";
                } 
              }while(desistir<=3);
              if(desistir>3&&testarSenha!=conta[ind].senha&&desistir!=5){
                cout<<"\n\tNumero maximo de tentativas atingido.\n\tTente novamente mais tarde.";
              }
            }else{
              cout<<"\n\tCpf nao cadastrado\n";
            }
          }else{
            cout<<"\n\tAcao cancelada\n";
          }
        }else{
          cout<<"\n\tNao tem nenhuma conta cadastrada..\n";
        }
      break;
      case 8: 
        cout<<"\n\tlistando contas existentes..";
        if(fim!=0){
          do{
            cout<<"\n\tvoce tem certeza?(s para sim e n para nao) ";
            cin>>son;
          }while(son!='s'&&son!='S'&&son!='n'&&son!='N');
          if(son=='s'||son=='S'){
            for(int i=0;i<fim;i++){
              cout<<"\n\tcpf: "<<conta[i].cpf;
              cout<<"\n\tNome: "<<conta[i].nome;
              cout<<"\n\tSenha da conta: "<<conta[i].senha;
              cout<<"\n\tNumero de cartoes: "<<conta[i].nC;
            }
          }else{
            cout<<"\n\tAcao cancelada\n";
          }
        }else{
          cout<<"\n\tNao tem contas cadastradas\n";
        }
      break;
      case 9: 
      cout<<"\n\tSaindo do sistema\n";
      break;
      default: 
      cout<<"\n\tOpcao invalida\n";
    }
  }while(op!=9);
}
