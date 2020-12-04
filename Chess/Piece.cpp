#include "Piece.h"

Piece::Piece()
	
{
	m_hasMoved = false;
	m_isAlive = true;
}


string Piece::GetIdentity()
{
	return m_identity;
}



void Piece::SetIdentity(string identity)
{
	//there's gotta be a better way to do this
	
	char pieceType = identity[1];

	if (pieceType == pawn || pieceType == knight || pieceType == bishop || pieceType == rook || pieceType == queen || pieceType == king)
	{
		m_identity = identity;
	}
	else
	{
		cout << "invalid piece" << std::endl;
	}

}


bool Piece::GetHasMoved()
{
	return m_hasMoved;
}

void Piece::HasIndeedMoved()
{
	m_hasMoved = true;
}

void Piece::DrawPiece()
{
	cout << m_identity;
}

bool Piece::GetIsAlive()
{
	return m_isAlive;
}

void Piece::SetEaten()
{
	m_isAlive = false;
}

