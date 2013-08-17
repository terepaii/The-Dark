#include "Player.h"
#include <string>




	Player::Player(std::string desc)
	{
		desc = desc;
	}

	short Player::getHealth()
	{
		return health ;
	}

	void Player::setSteps()
	{
		steps++ ;
	}

	bool Player::hasKey()
	{
		return false ;
	}
	