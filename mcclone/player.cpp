#include "player.h"

Player::Player(const Vector3f& position, float rotX, float rotY)
{
}

void Player::TurnLeftRight(float value)
{
    glRotatef(value, 1.0, 0.0, 0.0);
}

void Player::TurnTopBottom(float value)
{
    glRotatef(value, 0.0, 1.0, 0.0);
}

void Player::Move(bool front, bool back, bool left, bool right, float elapsedTime)
{

}

void Player::ApplyTransformation(Transformation& transformation) const
{
	transformation.ApplyRotation(-m_rotX, 1.f, 0, 0);
	transformation.ApplyRotation(-m_rotY, 0, 1.f, 0);
	transformation.ApplyTranslation(-m_position);
}
