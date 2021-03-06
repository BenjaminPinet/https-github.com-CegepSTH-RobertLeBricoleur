#ifndef PLAYER_H__
#define PLAYER_H__

#include "define.h"
#include "transformation.h"
#include "vector3.h"

class Player
{
private:
	float m_rotX;
	float m_rotY;
	Vector3f m_position;

public:
	Player(const Vector3f& position, float rotX = 0, float rotY = 0);
	void TurnLeftRight(float value);
	void TurnTopBottom(float value);
	void Move(bool front, bool back, bool left, bool right, float elapsedTime);
	void ApplyTransformation(Transformation& transformation) const;

};
#endif
