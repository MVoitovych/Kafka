#include "../config.hpp"
#include "../include/CSVReader.hpp"
#include "../include/ConsoleSender.hpp"
#include "../include/KafkaController.hpp"
#include "../include/KafkaSender.hpp"



int main() {

    char output_type = OUTPUT_TYPE;
    Sender *sender;

    if (output_type == 'C') {
        sender = (Sender *) new ConsoleSender();
    } else {
        sender = (Sender *) new KafkaSender();
    }

    CSVReader reader("../data.csv");
    std::string row;

    for (int i = 0; !(row = reader.readRow()).empty() && i < 1000; ++i) {
        sender->sendData(row);
        sender->sendData("\n");
    }


    return 0;
}
