#include "Vector2.h"
#include <math.h>


Vector2::Vector2()
{
	Vector2::x = 0;
	Vector2::y = 0;

}

Vector2::Vector2(float x, float y)
{
	this->x = x;
	this->y = y;


}

Vector2::~Vector2()
{


}

Vector2 Vector2::operator+(const Vector2& OtherVector)
{

	return Vector2(this->x + OtherVector.x, this->y + OtherVector.y);
}

Vector2 Vector2::operator+=(const Vector2& OtherVector)
{
	// increament the X and Y values by adding values of other vectors 
	this->x += OtherVector.x;
	this->y += OtherVector.y;


	return *this;
}

Vector2 Vector2::operator-(const Vector2& OtherVector)
{


	return Vector2(this->x - OtherVector.x, this->y - OtherVector.y);
}

Vector2 Vector2::operator-=(const Vector2& OtherVector)
{
	// this will decreament the value of vectore X and Y 
	this->x -= OtherVector.x;
	this->y -= OtherVector.y;

	return  *this;
}

Vector2 Vector2::operator*(const float& Scalar)
{


	return Vector2(this->x * Scalar, this->y * Scalar);
}

Vector2 Vector2::operator*=(const float& Scalar)
{
	//multiply the scalar value  

	this->x *= Scalar;
	this->y *= Scalar;


	return *this;
}

Vector2 Vector2::operator/(const float& Scalar)
{

	Vector2 DividedVector = Vector2(this->x, this->y);

	// is the scalar 0 
	if (Scalar != 0 )
	{
		// is the current x value zero 

		if (this->x !=0)
		{
			DividedVector.x /= Scalar;
		}

		// is the current y value zero 
		if (this->y != 0)
		{
			DividedVector.y /= Scalar;
		}
	}


	return Vector2();
}

Vector2 Vector2::operator/=(const float& Scalar)
{
	if (Scalar != 0)
	{
		// is the current x value zero 

		if (this->x != 0)
		{	 
			this->x /= Scalar;
		}

		// is the current y value zero 

		if (this->y != 0)
		{		 
			this->y /= Scalar;

		}
	}


	return *this;
}

bool Vector2::operator==(const Vector2& OtherVector)
{
	bool MatchX = this->x == OtherVector.x;
	bool MatchY = this->y == OtherVector.y;



	return MatchX && MatchY;
}

bool Vector2::operator!=(const Vector2& OtherVector)
{

	bool MatchX = this->x != OtherVector.x;
	bool MatchY = this->y != OtherVector.y;


	return MatchX && MatchY;
}

float Vector2::Length()
{


	return sqrtf(x*x + y*y);

}

void Vector2::Normalise()
{

	if (Length() != 0)
	{
		this->x /= Length();
		this->y /= Length();

	}
	else
	{
		this->x = 0;
		this->y = 0;
	}
}

Vector2 Vector2::Normalised()
{
	Vector2 Result = Vector2(0, 0);

	if (Length() != 0)
	{
		Result.x = this->x / Length();
		Result.y = this->y / Length();

	}
 
	return Result;
}

Vector2 Vector2::Zero()
{
	return Vector2(0,0);
}
