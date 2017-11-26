// Fill out your copyright notice in the Description page of Project Settings.

#include "UKingTilesLibrary.h"





FVector UKingTilesLibrary::DirectionToCube(int32 Direction)
{
	Direction = Direction % 6;
	switch (Direction)
	{
	case 0:
	{
		return FVector{ 1,0,-1 };
	}
	case 1:
	{
		return FVector{ 1,-1,0 };
	}
	case 2:
	{
		return FVector{ 0,-1,1 };
	}
	case 3:
	{
		return FVector{ -1,0,1 };
	}
	case 4:
	{
		return FVector{ -1,1,0 };
	}
	case 5:
	{
		return FVector{ 0,1,-1 };
	}
	}
	return FVector();
}

FVector UKingTilesLibrary::RoundCube(FVector Cube)
{
	FVector RoundedCube;
	int32 Rx = FMath::RoundToInt(Cube.X);
	int32 Ry = FMath::RoundToInt(Cube.Y);
	int32 Rz = FMath::RoundToInt(Cube.Z);

	float XDiff = FMath::Abs(Rx - Cube.X);
	float YDiff = FMath::Abs(Ry - Cube.Y);
	float ZDiff = FMath::Abs(Rz - Cube.Z);

	if (XDiff > YDiff && XDiff > ZDiff)
	{
		Rx = -Ry - Rz;
	}
	else if (YDiff > ZDiff)
	{
		Ry = -Rx - Rz;
	}
	else
	{
		Rz = -Rx - Ry;
	}

	RoundedCube = FVector{ (float)(Rx), (float)(Ry), (float)(Rz) };
	return RoundedCube;
}

FVector UKingTilesLibrary::OffsetToCube(FVector2D Offset)
{
	FVector Cube;
	Cube.X = Offset.X - (Offset.Y - (FMath::FloorToInt(Offset.Y) % 2)) / 2;
	Cube.Y = -Cube.X - Offset.Y;
	Cube.Z = Offset.Y;
	return Cube;
}

FVector2D UKingTilesLibrary::CubeToOffset(FVector Cube)
{
	int32 CubeZFloored = FMath::FloorToInt(Cube.Z);
	FVector2D OffsetCoords;
	OffsetCoords.X = (FMath::FloorToInt(Cube.X) + ((CubeZFloored - CubeZFloored % 2) / 2));
	OffsetCoords.Y = Cube.Z;
	return OffsetCoords;
}

FVector UKingTilesLibrary::AxialToCube(float Q, float R)
{
	FVector CubeCoords;
	CubeCoords.X = Q;
	CubeCoords.Y = (Q * -1) - R;
	CubeCoords.Z = R;
	return CubeCoords;
}

FVector UKingTilesLibrary::LocationToCube(float HexWidth, float HexHeight, FVector Location)
{
	//Location = Location - FVector{ HexWidth / 2, HexHeight / 2, 0 };

	float Q = (Location.X * FMath::Sqrt(3) / 3 - Location.Y / 3) / (HexHeight / 2);
	float R = Location.Y * 2 / 3 / (HexHeight / 2);

	//LogMsg("Q: " + FString::FromInt(Q) + ", R: " + FString::FromInt(R), 15.0f, FColor::Yellow, 1);

	return RoundCube(AxialToCube(Q, R));
}

FVector UKingTilesLibrary::CubeToLocation(FVector Cube)
{
	float Size = 294 / 2;
	float X = Size * FMath::Sqrt(3) * (Cube.X + Cube.Z / 2);
	float Y = Size * 3 / 2 * Cube.Z;

	//var x = hex.q
	//var z = hex.r
	//var y = -x - z

	//x = size * sqrt(3) * (hex.q + hex.r / 2)
	//y = size * 3 / 2 * hex.r
	//return Point(x, y)

	return FVector(X, Y, 0);
}