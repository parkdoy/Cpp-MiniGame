#include "Engine.h"

#include <iostream>

using namespace std;



using namespace std;

//int main()
//{
//	//Engine* MyEngine = new Engine();
//	//MyEngine->Load("Level01.map");
//
//	//MyEngine->Run();
//
//	//delete MyEngine;
//	//MyEngine = nullptr;
//
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	Engine* MyEngine = new Engine();
	MyEngine->Load("Level01.map");

	MyEngine->Run();

	delete MyEngine;
	MyEngine = nullptr;


	/*unsigned int Pawn = 1; ///0000 0001
	unsigned int StaticMesh = 2; ///0000 0010
	unsigned int DynamicMesh = 4; ///0000 0100
	unsigned int PhysicsBody = 8; ///0000 1000*/

	//0001 | 0001 = 0001  Or 둘중에 하나가 참이면 참
	//0000 | 0001 = 0001
	//0001 | 0000 = 0001

	//0001 & 0001 = 0001  And 둘중에 하나가 참이면 참
	//0000 & 0001 = 0000
	//0001 & 0000 = 0000

	//unsigned char Player = Pawn | DynamicMesh | PhysicsBody;
	//Player & Red;		//0000 1110 & 0000 0001 => 0000 0000
	//Player & Blue;		//0000 1111 & 0000 0010 => 0000 0010
	//Player & Green;		//0000 1111 & 0000 0100 => 0000 0100
	//Player & White;		//0000 1111 & 0000 1000 => 0000 1000

	//Player& (StaticMesh);  // 0000 1101 & 0000 0010 => 0000 0000 //false
	//bitmasking

	//Xor
	//0001 ^ 0001 => 0000
	//0001 ^ 0000 => 0001
	//0000 ^ 0001 => 0001
	//0000 ^ 0000 => 0000

	//0111 ^ 0010 => 0101
	//0101 ^ 0010 => 0111

	//unsigned char A = 1;  // 0001
	//A = A << 1;			  // 0010
	//A = A << 1;			  // 0100
	//A = A << 1;			  // 1000
	//A = A >> 1;			  // 0100
	//A = A >> 1;			  // 0010
	//A = A >> 1;			  // 0001
	//A = A >> 1;			  // 0000

	//A = A << 1;			  // 0000 0000
	//A = 0b10000000;			// 0000 0001
	//printf("%d", (unsigned char)(A >> 8));

	return 0;
}
