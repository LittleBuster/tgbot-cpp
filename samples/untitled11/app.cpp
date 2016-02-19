#include "app.h"
#include <iostream>
#include<boost/bind.hpp>


App::App(shared_ptr<TgBot::IBot> bot, shared_ptr<TgBot::ITgLongPool> longPool)
{
    m_bot = bot;
    m_longPool = longPool;
}

void App::on_msg()
{
    auto usrs = m_bot->getApi().getUpdates();
    auto usr = usrs[usrs.size()-1];

    cout << usr->message->from->id << endl;
    m_bot->getApi().sendMessage(usr->message->from->id, "Yes! I'am started.");
}

void App::on_any()
{
    auto usrs = m_bot->getApi().getUpdates();
    auto usr = usrs[usrs.size()-1];
    m_bot->getApi().sendMessage(usr->message->from->id, "What are you " + usr->message->from->firstName + " doing?: " + usr->message->text);
}

int App::start()
{
    m_bot->getEvents().onCommand("start", boost::bind(&App::on_msg, this));
    m_bot->getEvents().onAnyMessage(boost::bind(&App::on_any, this));

    cout << "Bot username: " << m_bot->getApi().getMe()->username.c_str() << endl;

    while (true) {
        cout << "Long poll started" << endl;
        m_longPool->start();
    }
}
