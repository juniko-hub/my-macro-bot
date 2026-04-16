#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(MyBotLayer, LevelInfoLayer) {
    bool init(GJGameLevel* level, bool p1) {
        // Вызываем оригинальный init, чтобы уровень вообще загрузился
        if (!LevelInfoLayer::init(level, p1)) return false;

        // Проверка: ID > 0 означает, что это онлайн-уровень или созданный тобой
        // Официальные уровни имеют ID 0 или отрицательные в некоторых случаях
        if (level->m_levelID <= 0) return true;

        // 1. Создаем саму кнопку (используем стандартный спрайт настройки)
        auto sprite = CCSprite::createWithSpriteFrameName("GJ_optionsBtn_001.png");
        
        auto myButton = CCMenuItemSpriteExtra::create(
            sprite,
            this,
            menu_selector(MyBotLayer::onMyButtonClick)
        );

        // 2. Ищем левое меню (там, где обычно кнопка лидерборда)
        auto leftMenu = this->getChildByID("left-side-menu");
        
        if (leftMenu) {
            // Присваиваем ID нашей кнопке, чтобы другие моды могли с ней дружить
            myButton->setID("record-bot-button");
            leftMenu->addChild(myButton);
            
            // Магия Geode: эта команда сама пересчитает позиции всех кнопок в столбце
            leftMenu->updateLayout();
        }

        return true;
    }

    void onMyButtonClick(CCObject* sender) {
        // Тестовое уведомление, чтобы понять, что кнопка живая
        FLAlertLayer::create(
            "Macro Bot", 
            "Recording Logic Coming Soon...", 
            "OK"
        )->show();
    }
};