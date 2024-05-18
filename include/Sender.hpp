//
// Created by mykhailo on 18.05.24.
//

#ifndef LAB4_ABSTRACTSENDER_HPP
#define LAB4_ABSTRACTSENDER_HPP

#include <string>

class  Sender {
public:
    virtual void sendData(std::string data) const = 0;
};


#endif//LAB4_ABSTRACTSENDER_HPP
