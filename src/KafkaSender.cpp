//
// Created by mykhailo on 18.05.24.
//

#include "../include/KafkaSender.hpp"


KafkaSender::KafkaSender() {
    kafka = new KafkaController(BROKERS, TOPIC, ADDRESS, ERROR_ADDRESS);
    kafka->initKafka();
}

void KafkaSender::sendData(std::string data) const {
    kafka->sendMessage(data);
}
