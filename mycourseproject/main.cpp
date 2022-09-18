#include <SFML/Graphics.hpp>
#include "Game.h"
#include "menu.h"

using namespace sf;

int main()
{
	// ������� ���� �������� 600 �� 600 � �������� ���������� 60 ������ � �������
	RenderWindow window(VideoMode(600, 600), "15");
	menu(window);
	window.setFramerateLimit(60);

	Font font;
	font.loadFromFile("things/CyrilicOld.ttf");

	// ����� � ������������ ������
	Text text("F3 - New Game / Esc - Exit / Arrow Keys - Move Tile", font, 20);
	text.setFillColor(Color::Green);
	text.setPosition(5.f, 5.f);

	// ������� ������ ����
	game game;
	game.setPosition(50.f, 50.f);

	Event event;
	int move_counter = 0;	// ������� ��������� ����� ��� ������������� �����������

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) window.close();
			if (event.type == Event::KeyPressed)
			{
				// �������� ������� ������� - ��������� ��������������� ��������
				if (event.key.code == Keyboard::Escape)
				{
					menu(window);
				}
				if (event.key.code == Keyboard::Left)
				{
					game.Move(Direction::Left);
				}
				if (event.key.code == Keyboard::Right)
				{
					game.Move(Direction::Right);
				}
				if (event.key.code == Keyboard::Up)
				{
					game.Move(Direction::Up);
				}
				if (event.key.code == Keyboard::Down)
				{
					game.Move(Direction::Down);
				}
				// ����� ����
				if (event.key.code == Keyboard::F3)
				{
					game.Init();
					move_counter = 100;
				}
			}
		}

		// ���� ������� ����� ������ ����, ���������� ������������ �����������
		if (move_counter-- > 0)
		{
			game.Move((Direction)(rand() % 4));
		}

		// ��������� ����������� �������� �� ���������
		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}