//
// Created by mykhailo on 18.05.24.
//

#ifndef LAB4_CONSOLESENDER_HPP
#define LAB4_CONSOLESENDER_HPP
#include "Sender.hpp"
#include <iostream>
class ConsoleSender : Sender {
public:
    void sendData(std::string data) const override;

};


#endif//LAB4_CONSOLESENDER_HPP
