#ifndef FILA_MSG_H
#define FILA_MSG_H

#include "comum.h"
#include <queue>
#include <boost/thread/mutex.hpp>

class fila_msg
{
public:
    fila_msg(boost::mutex& mu);
    void add_msg(string m);
    void remove_msg();
    string proxima();
    int qtd_itens();
private:
    boost::mutex& mu;
    queue<string> mensagens;

};

#endif // FILA_MSG_H
