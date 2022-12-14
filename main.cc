#include <stdint.h>

#include <fstream>
#include <iostream>
int main(int argc, char const *argv[]) {
    std::ifstream ifs;
    ifs.open("dpi.dat", std::ios::binary);
    if (!ifs) {
        std::cout << "open error!" << std::endl;
    }
    uint64_t time;
    uint32_t type;
    uint32_t data[17];

    // !ifs.eof()
    while (ifs.peek() != EOF) {
        ifs.read((char *)&time, sizeof(uint64_t));
        ifs.read((char *)&type, sizeof(uint32_t));

        if (type == 0 || type == 3) {
            ifs.read((char *)data, sizeof(uint32_t) * 4);
            std::cout << "time:\t" << time << "\ttype:\t" << type << "\tdata:\t" << data[3] << data[2] << data[1] << data[0] << "\n";
        } else {
            ifs.read((char *)data, sizeof(uint32_t));
            std::cout << "time:\t" << time << "\ttype:\t" << type << "\tdata:\t" << data[0] << "\n";
        }
    }

    ifs.close();

    return 0;
}
