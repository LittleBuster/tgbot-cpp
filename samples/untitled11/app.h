#ifndef APP_H
#define APP_H

#include <memory>
#include <tgbot/tgbot.h>

using namespace std;


class App
{
private:
    shared_ptr<TgBot::IBot> m_bot;
    shared_ptr<TgBot::ITgLongPool> m_longPool;
    void on_msg();
    void on_any();

public:
    App(shared_ptr<TgBot::IBot> bot, shared_ptr<TgBot::ITgLongPool> longPool);

    int start();
};

#endif // APP_H
