//#include "Libraries.h"
//#include "Constants.h"
//
//int find_in_vector(char elem, std::vector<char>& vect, int start, int end) {
//    for (int i = start; i < end; ++i) {
//        if (elem == vect[i]) return i;
//    }
//    return -1;
//}
//
//std::string convTo10(std::string num, int cur_base) {
//    int x = 0;
//    for (int i = 0; i < num.size(); ++i) {
//        x = (x * cur_base) + (num[i] - '0');
//    }
//    return std::to_string(x);
//}
//
//std::string convFrom10(std::string num, int res_base, std::vector<char>& symbols) {
//    long long x = stoi(num);
//    std::vector<char> v;
//    while (x != 0) {
//        v.push_back(symbols[x % res_base]);
//        x = x / res_base;
//    }
//    std::string ans = "";
//    for (int i = v.size() - 1; i >= 0; --i) { ans += v[i]; }
//    return ans;
//}
//
//
//void change_text(sf::Text& text, sf::String& str) {
//    text.setString(str);
//    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height);
//    text.setPosition(width / 2, height / 2);
//}