//
// Created by mykhailo on 18.05.24.
//

#ifndef LAB4_KAFKACONTROLLER_HPP
#define LAB4_KAFKACONTROLLER_HPP


#include <iostream>
#include <librdkafka/rdkafkacpp.h>
#include <string>

class ProgramDeliveryReportCb : public RdKafka::DeliveryReportCb {
public:
    void dr_cb(RdKafka::Message &message) override {
        std::cout << "Message delivered to topic " << message.topic_name() << " [" << message.partition() << "] at offset " << message.offset() << std::endl;
    }
};


class KafkaController {
private:
    std::string brokers;
    std::string topic_str;
    RdKafka::Conf *conf;
    RdKafka::Conf *tconf;
    std::string errstr;
    std::string adress;
    std::string error_name;
    ProgramDeliveryReportCb ex_dr_cb;
    RdKafka::Producer *producer;
    RdKafka::Topic *topic;

public:
    KafkaController(std::string brokers_, std::string topic_str_, std::string adress_, std::string error_name_);
    KafkaController();
    int initKafka();
    int sendMessage(std::string message_str);
};


#endif//LAB4_KAFKACONTROLLER_HPP
