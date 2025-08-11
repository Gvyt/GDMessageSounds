#include <Geode/modify/FAlertLayer.hpp>
#include <Geode/Geode.hpp>
#include <regex>

using namespace geode::prelude;

class $modify(PopupSoundModHook,FAlertLayer) {
    bool init(FAlertLayer*self, gd::string title, gd::string message, gd::string button, gd::string button2, bool button2Visible, bool useSmallFont) {
        if (! FAlertLayer::init(self, title, message, button, button2, button2Visible, useSmallFont)) {
            return false;
        }

        const std::string fullText = title + " " + message;

        std::regex error_pattern("- \\d+");

        if (std::regex_search(fullText, error_patter)) {
            geode::audio::playSound("resources/GJ_Error.ogg"_spr);
               } else {
                geode::audio::playSound("resources/GJ_Popup.ogg"_spr);
               }
    }
        return true;
    }