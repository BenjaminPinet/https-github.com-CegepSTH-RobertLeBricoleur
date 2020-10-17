#include "player.h"

Player::Player(const Vector3f& position, float rotX, float rotY)
{
    m_position = position;
    m_rotX = rotX;
    m_rotY = rotY;
}

void Player::TurnLeftRight(float value)
{
    m_rotX += value;
}

void Player::TurnTopBottom(float value)
{
    
}

void Player::Move(bool front, bool back, bool left, bool right, float elapsedTime)
{
    if (front)
    {
        float xrotrad, yrotrad;
        yrotrad = (m_rotY / 180 * 3.141592654f);
        xrotrad = (m_rotX / 180 * 3.141592654f);
        m_rotX += float(sin(yrotrad));
        m_position – = float(cos(yrotrad));
        m_rotY – = float(sin(xrotrad));
    }

    if (back)
    {
        float xrotrad, yrotrad;
        yrotrad = (m_rotY / 180 * 3.141592654f);
        xrotrad = (m_rotX / 180 * 3.141592654f);
        m_rotX – = float(sin(yrotrad));
        m_position += float(cos(yrotrad));
        m_rotY += float(sin(xrotrad));
    }

    if (right)
    {
        float yrotrad;
        yrotrad = (m_rotY / 180 * 3.141592654f);
        m_rotX += float(cos(yrotrad)) * 0.2;
        m_position += float(sin(yrotrad)) * 0.2;
    }

    if (left)
    {
        float yrotrad;
        yrotrad = (m_rotY / 180 * 3.141592654f);
        m_rotX –= float(cos(yrotrad)) * 0.2;
        m_position –= float(sin(yrotrad)) * 0.2;
    }
}

void Player::ApplyTransformation(Transformation& transformation) const
{
	transformation.ApplyRotation(-m_rotX, 1.f, 0, 0);
	transformation.ApplyRotation(-m_rotY, 0, 1.f, 0);
	transformation.ApplyTranslation(-m_position);
}
