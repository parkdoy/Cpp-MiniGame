#pragma once
#include "Actor.h"
#include <string>
#include "SDL_mixer.h" //sound

using namespace std;

class ASound :
    public AActor
{
    public :
        ASound(int NewX, int NewY, string Filename, int Newloop = -1);
        virtual ~ASound();
        virtual void BeginPlay() override;
        virtual void Tick() override;

        Mix_Music* Music;
        int Loop;
        int Volume = 10;
};

