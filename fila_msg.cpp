#include "fila_msg.h"

fila_msg::fila_msg(boost::mutex& mu):
    mu(mu)
{

}

void fila_msg::add_msg(string m)
{
    boost::mutex::scoped_lock lock(mu);
    mensagens.push(m);
}

void fila_msg::remove_msg()
{
    boost::mutex::scoped_lock lock(mu);
    mensagens.pop();
}

string fila_msg::proxima()
{
    return mensagens.front();
}

int fila_msg::qtd_itens()
{
    return mensagens.size();
}

