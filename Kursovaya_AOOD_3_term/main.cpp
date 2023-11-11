#include "Functions.h"

int main() {

    setlocale(LC_ALL, "Russian");

    sf::RenderWindow window(sf::VideoMode(width, height), "Number System Translator");
   /* sf::Texture background_texture;
    background_texture.loadFromFile("back1.jpg");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);
    background_sprite.setPosition(0, -50);*/

    sf::Font font;
    font.loadFromFile("font.ttf");

    sf::Text text(L"Введите число от 2 до 16 - начальную систему счисления", font, 30), cur_num("", font, 30), escape(L"Нажмите Escape, чтобы выйти", font, 20);
    sf::Text text_screen5(L"Нажмите Enter, чтобы начать заново", font, 25);
    /*text.setFillColor(sf::Color::Red); escape.setFillColor(sf::Color::Red); cur_num.setFillColor(sf::Color::Red); text_screen5.setFillColor(sf::Color::Red);
    text.setOutlineThickness(1.3); escape.setOutlineThickness(1.3); cur_num.setOutlineThickness(1.3); text_screen5.setOutlineThickness(1.3);
    text.setOutlineColor(sf::Color::Black); escape.setOutlineColor(sf::Color::Black); cur_num.setOutlineColor(sf::Color::Black); text_screen5.setOutlineColor(sf::Color::Black);*/
    text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height);
    text.setPosition(width / 2, height / 2 - 50);
    escape.setPosition(width - escape.getGlobalBounds().width - 20, height - escape.getGlobalBounds().height - 20);
    update_text(text_screen5, 50);
    sf::String cur_str = "";

    int screen = 1;
    

    while (window.isOpen()) {
        // std::cout << screen << '\n';
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
                break;
            }
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                    /*Sleep(0.3);
                    char ch = static_cast<char>(event.text.unicode);
                    std::cout << ch << std::endl;
                    if (isdigit(ch)) {
                        cur_s += ch;
                        std::cout << 1;
                    }*/
                if (event.text.unicode == '\r' && cur_str.getSize() != 0) {
                    //std::cout << "enter\n";
                    if (screen == 5 || screen == 4) {
                        screen = 1;
                        text.setString(L"Введите число от 2 до 16 - начальную систему счисления");
                        cur_str = "";
                        cur_num.setString("");
                    }
                    else {
                        if (screen == 1)
                            text.setString(L"Введите число от 2 до 16 - конечную систему счисления");
                        else if (screen == 2)
                            text.setString(L"Введите число для конвертации");
                        else if (screen == 3) {
                            text.setString(L"Результат перевода:");
                        }
                        std::string cur_num_str = cur_str;
                        // std::cout << "cur_num_str " << cur_num_str << '\n';
                        if ((screen == 1 || screen == 2) && check_system(cur_num_str)) {
                            if (screen == 1) {
                                from = std::stoi(cur_num_str);
                                // std::cout << from << '\n';
                            }
                            else if (screen == 2) {
                                to = std::stoi(cur_num_str);
                                // std::cout << to << '\n';
                            }
                            cur_str = "";
                            cur_num.setString(cur_str);
                            screen++;
                        }
                        else if (screen == 1 || screen == 2) {
                            screen = 5;
                            text.setString(L"Введенно неверное число");
                        }
                        else {
                            // std::cout << "before disaster " << static_cast<std::string>(cur_str) << '\n';
                            std::string to10 = convTo10(static_cast<std::string>(cur_str));
                            // std::cout << "to " << to10 << '\n';
                            std::string from10 = convFrom10(to10);
                            // std::cout << "from " << from10 << '\n';
                            cur_str = convFrom10(convTo10(static_cast<std::string>(cur_str)));
                            // std::cout << static_cast<std::string>(cur_str) << '\n';
                            cur_num.setString(cur_str);
                            screen++;
                        }
                    }
                }
                else if (event.text.unicode == '\b' && screen <= 3) {
                    // std::cout << "backspace\n";
                    if (cur_str.getSize() > 0) {
                        cur_str.erase(cur_str.getSize() - 1, 1);
                        cur_num.setString(cur_str);
                    }
                }
                else if (event.text.unicode < 128 && screen <= 3) {
                    int symb_pos = -1;
                    char ch = static_cast<char> (event.text.unicode);
                    // std::cout << ch << '\n';
                    if (screen == 1 || screen == 2) {
                        symb_pos = find_in_vector(ch, symbols, 0, 10);
                    }
                    else {
                        symb_pos = find_in_vector(ch, symbols, 0, from);
                    }
                    if (symb_pos != -1) {
                        cur_str += ch;
                        cur_num.setString(cur_str);
                    }
                }
            }
        }
        
        window.clear();
        // window.draw(background_sprite);

        if (screen < 5) {
            update_text(cur_num, num_offset);
            window.draw(cur_num);
        }
        if (screen == 4 || screen == 5) 
            window.draw(text_screen5);
        update_text(text, text_offset);
        window.draw(text);
        window.draw(escape);
        
        window.display();
    }

    return 0;
}
