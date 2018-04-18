// z88.cpp
// Better Header Comment Here
//

#include "includes.h"

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cerr << "Usage:  " << argv[0] << " object-file-name\n\n";
        exit(1);
    }

    cout << hex << setfill('0');

    try {
       make_connections();
       run_simulation(argv[1]);
    } catch (ArchLibError &err) {
        cout << endl
             << "Simulation aborted - ArchLib runtime error"
             << endl
             << "Cause:  " << err.what() << endl;
        return(1);
    }

    return(0); 
}
