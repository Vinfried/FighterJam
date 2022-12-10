#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	// operators that will allow us to perform math functions on the vector 

	Vector2 operator+(const Vector2 &OtherVector);
	Vector2 operator+=(const Vector2& OtherVector);


	Vector2 operator-(const Vector2& OtherVector);
	Vector2 operator-=(const Vector2& OtherVector);


	Vector2 operator*(const float& Scalar);
	Vector2 operator*=(const float& Scalar);


	Vector2 operator/(const float& Scalar);
	Vector2 operator/=(const float& Scalar);


	// bool operators 
	bool operator == (const Vector2& OtherVector);
	bool operator != (const Vector2& OtherVector);

	// what is the length of x and y vectors 
	float Length();


	void Normalise();
	Vector2 Normalised();


	Vector2 Zero();


	// coordinates stored in the vector 

	float x;
	float y;





};

