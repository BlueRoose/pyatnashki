#pragma once
#include <SFML/Graphics.hpp>

void menu(RenderWindow& window)
{
	Texture namegame, menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	namegame.loadFromFile("things/name.png");
	menuTexture1.loadFromFile("things/newgame.png");
	menuTexture2.loadFromFile("things/aboutthegame.png");
	menuTexture3.loadFromFile("things/exit.png");
	aboutTexture.loadFromFile("things/rules.png");
	menuBackground.loadFromFile("things/fon.png");
	Sprite name(namegame), menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;
	name.setPosition(0, -20);
	menu1.setPosition(150, 200);
	menu2.setPosition(75, 300);
	menu3.setPosition(225, 400);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		window.clear(Color(129, 181, 221));

		if (IntRect(150, 200, 300, 75).contains(Mouse::getPosition(window)))
		{
			menu1.setColor(Color::Blue);
			menuNum = 1;
		}
		if (IntRect(75, 300, 450, 75).contains(Mouse::getPosition(window)))
		{
			menu2.setColor(Color::Blue);
			menuNum = 2;
		}
		if (IntRect(225, 400, 150, 75).contains(Mouse::getPosition(window)))
		{
			menu3.setColor(Color::Blue);
			menuNum = 3;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1)
			{
				isMenu = false; //если нажали первую кнопку, то выходим из меню 
			}
			if (menuNum == 2) {
				window.draw(about);
				window.display();
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}
			if (menuNum == 3)
			{
				window.close();
				isMenu = false;
			}

		}

		window.draw(menuBg);
		window.draw(name);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}