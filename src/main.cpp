#include <librdkafka/rdkafkacpp.h>  // Основной заголовок C++
#include <iostream>
#include <string>

int main() {
    // Конфигурация продюсера
    RdKafka::Conf* conf = RdKafka::Conf::create(RdKafka::Conf::CONF_GLOBAL);
    std::string err_str;

    // Настройка брокеров Kafka
    if (conf->set("bootstrap.servers", "localhost:9092", err_str) != RdKafka::Conf::CONF_OK) {
        std::cerr << "Error: " << err_str << std::endl;
        return 1;
    }

    // Создание продюсера
    RdKafka::Producer* producer = RdKafka::Producer::create(conf, err_str);
    if (!producer) {
        std::cerr << "Failed to create producer: " << err_str << std::endl;
        return 1;
    }

    // Отправка сообщения
    std::string topic_name = "test-topic";
    std::string message = "Hellosas!";

    // Создание сообщения
    RdKafka::ErrorCode resp = producer->produce(
        topic_name,
        RdKafka::Topic::PARTITION_UA, // Автовыбор партиции
        RdKafka::Producer::RK_MSG_COPY,
        const_cast<char*>(message.c_str()), message.size(),
        nullptr, 0, 0, nullptr
    );

    if (resp != RdKafka::ERR_NO_ERROR) {
        std::cerr << "Produce failed: " << RdKafka::err2str(resp) << std::endl;
    }
    else {
        std::cout << "Message sent successfully!" << std::endl;
    }

    // Ожидание отправки
    producer->flush(5000); // 5 секунд

    // Освобождение ресурсов
    delete producer;
    delete conf;

    return 0;
}