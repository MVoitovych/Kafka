//
// Created by mykhailo on 18.05.24.
//

#ifndef LAB4_CONFIG_HPP
#define LAB4_CONFIG_HPP

// 'C' - console; 'K' - Kafka
#define OUTPUT_TYPE 'C'

#define BROKERS "localhost:9092"
#define TOPIC "test"
#define ADDRESS "bootstrap.servers"
#define ERROR_ADDRESS "dr_cb"
#endif//LAB4_CONFIG_HPP

// docker run -p 9092:9092 apache/kafka:3.7.0
// docker exec -it <container-name> /bin/bash
// docker ps -a
// docker exec -it pedantic_payne /bin/bash
// /opt/kafka/bin/kafka-console-consumer.sh --bootstrap-server localhost:9092 --topic test --from-beginning