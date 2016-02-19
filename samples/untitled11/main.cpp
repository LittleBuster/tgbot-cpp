#include <tgbot/tgbot.h>
#include "app.h"
#include <memory>

using namespace std;


int main(void)
{
    auto bot = make_shared<TgBot::Bot>("TOKEN");
    auto longPool = make_shared<TgBot::TgLongPoll>(bot);

    auto app = make_shared<App>(bot, longPool);
    return app->start();
}
