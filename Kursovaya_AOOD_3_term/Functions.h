#pragma once
#include "Libraries.h"
#include "Constants.h"

int find_in_vector(char elem, std::vector<char>& vect, int start, int end) {
    for (int i = start; i < end; ++i) {
        if (elem == vect[i]) return i;
    }
    return -1;
}

std::string convTo10(std::string num) {
    long long x = 0;
    for (int i = 0; i < num.size(); ++i) {
        if (isdigit(num[i]))
            x = (x * from) + (num[i] - '0');
        else
            x = (x * from) + ((num[i] - 'A') + 10);
    }
    return std::to_string(x);
}

std::string convFrom10(std::string num) {
    long long x = stoi(num);
    std::vector<char> v;
    while (x != 0) {
        v.push_back(symbols[x % to]);
        x = x / to;
    }
    std::string ans = "";
    for (int i = v.size() - 1; i >= 0; --i) { ans += v[i]; }
    return ans;
}


void change_text(sf::Text& text, sf::String& str) {
    text.setString(str);
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height);
    text.setPosition(width / 2, height / 2);
}

void update_text(sf::Text& text, int offset) {
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height);
    text.setPosition(width / 2, height / 2 + offset);
}

bool check_system(std::string syst) {
    int syst_int = std::stoi(syst);
    if (syst_int >= 2 && syst_int <= 16)
        return true;
    return false;
}