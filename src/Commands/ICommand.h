//
// Created by omer on 1/12/23.
//

#ifndef A_OUT_ICOMMAND_H
#define A_OUT_ICOMMAND_H
#include "../Algorithim/Knn.h"
#include "../input.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include "../IO/DefaultIO.h"
#include <utility>
#include "../IO/DefaultIO.h"
#include "../IO/FileIO.h"
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>


class ICommand {
public:
    std::string description;
    DefaultIO& io;
    clientData * p_Data;

    ICommand(DefaultIO &io) : io(io) {

    }
    virtual ~ICommand() {

    }
    virtual void execute() = 0;
};

#endif //A_OUT_ICOMMAND_H
