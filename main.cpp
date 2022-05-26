#include <iostream>
#include <SFML/Graphics.hpp>


class Tile : public sf::RectangleShape
{
public:
    Tile();
    Tile(sf::Vector2f position, sf::Color color, double size);
    ~Tile();

    void draw(sf::RenderWindow &window);

private:

};

Tile::Tile(){}

Tile::Tile(sf::Vector2f position, sf::Color color, double size)
{
    setPosition(position);
    setFillColor(color);
    setSize(sf::Vector2f(size, size));
}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "TEST");
    //sf::CircleShape shape(400.f);
    //shape.setFillColor(sf::Color::Red);
    ////shape.setOutlineThickness(-10.f);
    //shape.setOutlineColor(sf::Color(250, 150, 100));
    Tile square(sf::Vector2f(300.f, 300.f), sf::Color::Red, 200);

    //sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));

    while (window.isOpen())
    {
        sf::Event e;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        window.draw(square);
        window.display();
    }
    return 0;
}


