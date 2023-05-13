#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
int main()
{
    // �������� ����
    RenderWindow window(VideoMode(800, 600), "Arkanoid");
    window.setFramerateLimit(60);
    // �������� ���������
    RectangleShape platform(Vector2f(100.f, 10.f));
    platform.setFillColor(Color::Green);
    platform.setPosition(350.f, 580.f);
    // �������� ����
    CircleShape ball(10.f);
    ball.setFillColor(Color::Red);
    ball.setPosition(395.f, 550.f);
    float ball_dx = 6.f, ball_dy = -6.f;
    // ������� ���� ����
    while (window.isOpen())
    {
        // ��������� �������
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        // �������� ���������
        if (Keyboard::isKeyPressed(Keyboard::Left) && platform.getPosition().x > 0)
            platform.move(-5.f, 0.f);
        if (Keyboard::isKeyPressed(Keyboard::Right) && platform.getPosition().x < 700)
            platform.move(5.f, 0.f);
        // �������� ����
        ball.move(ball_dx, ball_dy);
        // ������ ���� �� ������
        if (ball.getPosition().x < 0 || ball.getPosition().x > 790)
            ball_dx = -ball_dx;
        if (ball.getPosition().y < 0)
            ball_dy = -ball_dy;
        // ������ ���� �� ���������
        if (ball.getPosition().y > 570 && ball.getPosition().x > platform.getPosition().x && ball.getPosition().x < platform.getPosition().x + 100)
            ball_dy = -ball_dy;
        // �������� �� ���������
        if (ball.getPosition().y > 600)
            window.close();
        // ��������� ��������
        window.clear();
        window.draw(platform);
        window.draw(ball);
        window.display();
    }
    return 0;
}
