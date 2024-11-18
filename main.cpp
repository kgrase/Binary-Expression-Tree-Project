#include "binaryExpressionTree.h"
#include <fstream>

int main() {
    binaryExpressionTree binexptree;
    std::ifstream ifs("RpnData.txt");
    std::ofstream ofs("RpnOutput.txt");

    if (!ifs.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;  // Return with an error code if the file can't be opened
    }
    if (!ofs.is_open()) {
        std::cerr << "Error opening file to write answers." << std::endl;
        return 1;  // Return with an error code if the file can't be opened
    }

    std::string line;
    // Read the file line by line
    while (std::getline(ifs, line)) {
        // Process the line (e.g., print it)
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        binexptree.buildExpressionTree(line);
        ofs << "--------------------------------------------" << std::endl;
        ofs << line << " = " << binexptree.evaluateExpressionTree() << std::endl;
        binexptree.destroyTree();
    }

    ifs.close();
    ofs.close();
}

