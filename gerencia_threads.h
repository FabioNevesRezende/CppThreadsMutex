#ifndef GERENCIA_THREADS_H
#define GERENCIA_THREADS_H

#include <thread>
#include <boost/thread/mutex.hpp>
#include <chrono>

#include "comum.h"
#include "fila_msg.h"

class gerencia_threads
{
public:
    gerencia_threads();
    void inicia();
private:
    boost::mutex mu;
    fila_msg fila;

    void thread_recebe_input();
    void thread_trata_input();
};

#endif // GERENCIA_THREADS_H
