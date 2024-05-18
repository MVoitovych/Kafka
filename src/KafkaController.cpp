//
// Created by mykhailo on 18.05.24.
//

#include "../include/KafkaController.hpp"



int KafkaController::initKafka() {
    producer = RdKafka::Producer::create(conf, errstr);

    if (!producer) {
        std::cerr << "Failed to create producer: " << errstr << std::endl;
        return 1;
    }

    topic = RdKafka::Topic::create(producer, topic_str, tconf, errstr);
    if (!topic) {
        std::cerr << "Failed to create topic: " << errstr << std::endl;
        return 2;
    }
    return 0;
}
int KafkaController::sendMessage(std::string message_str) {
    // Produce message
    RdKafka::ErrorCode resp = producer->produce(topic, RdKafka::Topic::PARTITION_UA,
                                                RdKafka::Producer::RK_MSG_COPY,
                                                const_cast<char *>(message_str.c_str()), message_str.size(),
                                                nullptr, nullptr);
    if (resp != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Failed to produce message: " << RdKafka::err2str(resp) << std::endl;
        return 1;
    }

    producer->poll(0);
    producer->flush(1000);
}

KafkaController::KafkaController(std::string brokers_, std::string topic_str_, std::string adress_, std::string error_name_) {
    brokers = brokers_;
    topic_str = topic_str_;
    adress = adress_;
    error_name = error_name_;

    conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    tconf = RdKafka::Conf::create(RdKafka::Conf::CONF_TOPIC);

    conf->set(adress, brokers, errstr);
    conf->set(error_name, &ex_dr_cb, errstr);
}
KafkaController::KafkaController(){};