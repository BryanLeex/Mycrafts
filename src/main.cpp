/// src/main.cpp

#include "common/common.hpp"

#include "GL/GL.hpp"

int main(int argc, char **argv) {
    try {
        logger->addDistinationFile("data.log");
        logger->enableConsoleOutput();

        init();

        for_range(i, argc) {
            logger->info("Arg {} : {}", i, argv[i]);
        }

    } catch (const std::exception &e) {
        logger->fatal("{}", e.what());
    }

    return 0;
}
