#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <ctime>

void fread_fwrite() {

    FILE* input = fopen("tekst.txt", "r");
    FILE* output = fopen("przekopiowany_tekst.txt", "w");
    if(input == NULL) {
        puts("Blad otwarcia pliku do odczytu");
        exit(-1);
    }
    if(output == NULL) {
        puts("Blad otwarcia pliku do zapisu");
        exit(-1);
    }

    time_t start = clock();

    while(!feof(input)) {

        char word[1024];

        fread(word, 1, 1024, input);
        fwrite(word, 1, 1024, output);
    }

    time_t stop = clock();

    fclose(input);
    fclose(output);

    printf("Czas wykonania dla funkcji z C: %.2fsek\n", (stop-start)/(double)CLOCKS_PER_SEC);
}

void read_write() {

//  std::ios::sync_with_stdio(false);

    std::fstream input;
    input.open("tekst.txt", std::ios::in);
    std::fstream output;
    output.open("przekopiowany_tekst.txt", std::ios::out);
    if(input.good() == false) {
        std::cout << "Blad otwarcia pliku do odczytu" << std::endl;
        exit(-1);
    }
    if(output.good() == false) {
        std::cout << "Blad otwarcia pliku do zapisu" << std::endl;
        exit(-1);
    }

    char word[1024];

    time_t start = clock();

    while(!input.eof()) {
        input.read(word, 1024);
        output.write(word, 1024);
    }

    time_t stop = clock();

    std::cout << "Czas wykonania dla funkcji z C++: " << (stop-start)/(double)CLOCKS_PER_SEC << std::endl;

    input.close();
    output.close();
}

int main() {

    #ifdef C_FUNCTION
    fread_fwrite();
    #endif // C_FUNCTION

    #ifdef CPP_FUNCTION
    read_write();
    #endif // CPP_FUNCTION

    return 0;

}
