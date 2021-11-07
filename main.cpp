#include "gerencia_threads.h"

int main(int argc, char *argv[])
{
    try{
        gerencia_threads g;
        g.inicia();
        return 0;
    }catch(exception& e){
        cerr << e.what() << endl;
        return 1;
    }
}
