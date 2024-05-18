//
// Created by mykhailo on 18.05.24.
//

#ifndef LAB4_KAFKASENDER_HPP
#define LAB4_KAFKASENDER_HPP
#include "KafkaController.hpp"
#include "Sender.hpp"
#include "../config.hpp"

class KafkaSender : Sender {
private:
    KafkaController* kafka = nullptr;

public:
    KafkaSender();
    void sendData(std::string data) const override;
};


#endif//LAB4_KAFKASENDER_HPP
