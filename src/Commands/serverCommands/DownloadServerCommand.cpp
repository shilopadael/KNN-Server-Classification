//
// Created by oem on 1/14/23.
//

#include "DownloadServerCommand.h"


DownloadServerCommand::DownloadServerCommand(DefaultIO &io) : ICommand(io){
    this->description = "5. download result\n";

}

DownloadServerCommand::~DownloadServerCommand() {

}

void DownloadServerCommand::execute(){
    std::stringstream message;
    //if not update files yet
    if (this->p_Data->testData.empty()) {
        message << "Please upload data\n";
    }
        //if not classified data yet
    else if ( this->p_Data->classifiedResult.empty()) {
        message << "Please classify the data\n";
    }
    //if we have one of the above problem, send the message and return.
    if (message.rdbuf()->in_avail() != 0) {
        io.write("-1");
        io.write(message.str());
        return;
    }

    //otherwise send data to print by cline line by line
    size_t classifiedDataSize = this->p_Data->classifiedResult.size();
    for (int i = 0; i < classifiedDataSize; ++i) {
        message.str("");
        message << i + 1 << this->p_Data->classifiedResult[i] << std::endl;
        io.write(message.str());
    }
    //symbol of end text
    io.write("#");

}