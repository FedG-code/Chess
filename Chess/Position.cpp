#include "Position.h"

void Position::SetPosition(string coordinates)
{
	m_Notation = coordinates;
	m_Xpos = TranslateXFromNotation(coordinates[0]);
	m_Ypos = TranslateYFromNotation(coordinates[1]);
}

void Position::SetJustNotation(string notation)
{
	m_Notation = notation;
}

string Position::GetCoordinatesNotation()
{
	/*std::string coordinates;  
	int translatedY = m_Ypos+1;
	coordinates.push_back(Translate(m_Xpos));
	coordinates.push_back((translatedY));
	return coordinates;*/
	return m_Notation;
}

string Position::CompareNotation(string finalpos)
{
	//This code should output whether a final position is on any linear path away from the intial position
	string UpOrDown = isUpOrDown(finalpos);
	string LeftOrRight = isLeftOrRight(finalpos);
	bool UpRight = isUpRight(finalpos);
	bool DownRight = isDownRight(finalpos);
	bool DownLeft = isDownLeft(finalpos);
	bool UpLeft = isUpLeft(finalpos);

	if (UpOrDown != "No")
	{
		return UpOrDown;
	}
	else if (LeftOrRight != "No")
	{
		return LeftOrRight;
	}
	else if (UpRight)
	{
		return "UpRight";
	}
	else if (DownRight)
	{
		return "DownRight";
	}
	else if (DownLeft)
	{
		return "DownLeft";
	}
	else if (UpLeft)
	{
		return "UpLeft";
	}
		return "No";
}

string Position::isUpOrDown(string finalpos)
{
	int startX = m_Xpos;
	int startY = m_Ypos;
	int finalX = TranslateXFromNotation(finalpos[0]);
	int finalY = TranslateYFromNotation(finalpos[1]);
	
	if (startX == finalX && startY != finalY)
	{
		if (startY < finalY)
		{
			return "Up";
		}
		else if (startY > finalY)
		{
			return "Down";
		}
	}
	else if (startX == finalX && startY == finalY)
	{
		cout << "same tile error" << endl;

		return "No";
	}
		return "No";
}

bool Position::isUpRight(string finalpos)
{
	int startX = m_Xpos;
	int startY = m_Ypos;
	int finalX = TranslateXFromNotation(finalpos[0]);
	int finalY = TranslateYFromNotation(finalpos[1]);

	if (startX > finalX || startY > finalY)
	{
		return false;
	}
	else
	{
		for (startX; startX <= finalX; startX++, startY++)
		{
			if (startX == finalX && startY == finalY)
			{
				return true;
			}
		}
	}

	return false;
}

bool Position::isDownRight(string finalpos)
{
	int startX = m_Xpos;
	int startY = m_Ypos;
	int finalX = TranslateXFromNotation(finalpos[0]);
	int finalY = TranslateYFromNotation(finalpos[1]);

	if (startX > finalX || startY < finalY)
	{
		return false;
	}
	else
	{
		for (startX; startX <= finalX; startX++, startY--)
		{
			if (startX == finalX && startY == finalY)
			{
				return true;
			}
		}
	}

	return false;
}

bool Position::isDownLeft(string finalpos)
{
	int startX = m_Xpos;
	int startY = m_Ypos;
	int finalX = TranslateXFromNotation(finalpos[0]);
	int finalY = TranslateYFromNotation(finalpos[1]);

	if (startX < finalX || startY < finalY)
	{
		return false;
	}
	else
	{
		for (startX; startX >= finalX; startX--, startY--)
		{
			if (startX == finalX && startY == finalY)
			{
				return true;
			}
		}
	}

	return false;
}

string Position::isLeftOrRight(string finalpos)
{
	int startX = m_Xpos;
	int startY = m_Ypos;
	int finalX = TranslateXFromNotation(finalpos[0]);
	int finalY = TranslateYFromNotation(finalpos[1]);

	if (startY == finalY && startX != finalX)
	{
		if (startX < finalX)
		{
			return "Right";
		}
		else if (startX > finalX)
		{
			return "Left";
		}
	}
	else if (startX == finalX && startY == finalY)
	{
		cout << "same tile error" << endl;

		return "No";
	}
		return "No";
}

bool Position::isUpLeft(string finalpos)
{
	int startX = m_Xpos;
	int startY = m_Ypos;
	int finalX = TranslateXFromNotation(finalpos[0]);
	int finalY = TranslateYFromNotation(finalpos[1]);

	if (startX < finalX || startY > finalY)
	{
		return false;
	}
	else
	{
		for (startX; startX <= finalX; startX++, startY++)
		{
			if (startX == finalX && startY == finalY)
			{
				return true;
			}
		}
	}

	return false;
}

int Position::GetX()
{
	return m_Xpos;
}

int Position::GetY()
{
	return m_Ypos;
}



bool Position::Bump(Direction dir)
{
	switch (dir)
	{
	case Up:
		return BumpYUp();
	case Down:
		return BumpYDown();
	case Left:
		return BumpXDown();
	case Right:
		return BumpXUp();
	}
}

bool Position::BumpYUp()
{
	if (m_Ypos < 7)
	{
		m_Ypos++;

		string newNotation;
		
		newNotation.push_back(TranslateXToNotation(m_Xpos));
		newNotation.push_back(TranslateYToNotation(m_Ypos));
		SetPosition(newNotation);
		return true;
	}
	else
	{
		cout << "you're exceeding the array limit son" << endl;
		return false;
	}
}

bool Position::BumpXUp()
{
	if (m_Xpos < 7)
	{
		m_Xpos++;

		string newNotation;
		newNotation.push_back(TranslateXToNotation(m_Xpos));
		newNotation.push_back(TranslateYToNotation(m_Ypos));
		SetPosition(newNotation);
		return true;
	}
	else
	{
		cout << "you're exceeding the array limit son" << endl;
		return false;
	}
}

bool Position::BumpYDown()
{

	if (m_Ypos > 0)
	{
		m_Ypos--;

		string newNotation;
		newNotation.push_back(TranslateXToNotation(m_Xpos));
		newNotation.push_back(TranslateYToNotation(m_Ypos));
		SetPosition(newNotation);
		return true;
	}
	else
	{
		cout << "you're exceeding the array limit son" << endl;
		return false;
	}
}

bool Position::BumpXDown()
{
	if (m_Xpos > 0)
	{
		m_Xpos--;

		string newNotation;
		newNotation.push_back(TranslateXToNotation(m_Xpos));
		newNotation.push_back(TranslateYToNotation(m_Ypos));
		SetPosition(newNotation);
		return true;
	}
	else
	{
		cout << "you're exceeding the array limit son" << endl;
		return false;
	}
}
