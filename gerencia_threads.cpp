#include "gerencia_threads.h"

gerencia_threads::gerencia_threads() :
    fila(fila_msg(mu))
{
    
}

void gerencia_threads::inicia()
{
    thread(&gerencia_threads::thread_recebe_input, this).detach();
    thread(&gerencia_threads::thread_trata_input, this).join();
}

void gerencia_threads::thread_recebe_input()
{
    string user_input;
    while(true){
        this_thread::sleep_for(chrono::milliseconds(100));
        cout << "Escreva alguma coisa:" << endl;
        getline(cin, user_input);
        fila.add_msg(user_input);
    }
}

void gerencia_threads::thread_trata_input()
{
    while(true){
        this_thread::sleep_for(chrono::milliseconds(100));
        if(fila.qtd_itens() > 0){
            cout << "Nova mensagem recebida:" << endl;
            cout << fila.proxima() << endl;
            fila.remove_msg();
        }
    }
}