//------------------------------------------------------------------------------
//Copyright Robert Pelloni.
//All Rights Reserved.
//------------------------------------------------------------------------------


#pragma once
#include "bobtypes.h"

class Logger;


#include "./state/State.h"
#include "src/Utility/Console.h"
#include "src/Utility/ConsoleText.h"
//#include "src/Utility/ControlsManager.h"
//#include "src/Utility/audio/AudioManager.h"

class ControlsManager;
class AudioManager;
class BGClientEngine;
class Cameraman;
class SpriteManager;
class ActionManager;
class CinematicsManager;
class TextManager;
class EventManager;
class MapManager;
class Map;
class Wallet;
class Clock;
class GameSave;
class GUIManager;
class StuffMenu;
class GameStore;
class PlayerEditMenu;
class Player;
class ND;
class FriendManager;
class StatusBar;
class NotificationManager;
class ServerObject;
class Event;

class Engine : public State
{
private:
	typedef State super;
public:
	

	static Logger log;


	AudioManager* audioManager = nullptr;
	Cameraman* cameraman = nullptr;
	SpriteManager* spriteManager = nullptr;
	ActionManager* actionManager = nullptr;
	MapManager* mapManager = nullptr;
	CinematicsManager* cinematicsManager = nullptr;
	CaptionManager* captionManager = nullptr;
	TextManager* textManager = nullptr;
	EventManager* eventManager = nullptr;


private:
	ControlsManager* controlsManager = nullptr;

	//static BGClientEngine* clientGameEngine;
	//ArrayDeque<Cameraman*> *cameramanStack = new ArrayDeque<Cameraman*>();


public:

	bool hitLayerEnabled = true;
	bool underLayerEnabled = true;
	bool overLayerEnabled = true;
	bool entityLayerEnabled = true;
	bool lightsLayerEnabled = true;
	bool debugLayerEnabled = false;


	//DebugText cameraSpeedText = DebugConsole.add("cameraSpeedText");
	ConsoleText* zoomText = Console::debug("zoomText");

	ConsoleText* mapCamText = Console::debug("mapCamText");
	ConsoleText* mapScreenText = Console::debug("mapScreenText");

	ConsoleText* mapSizeText = Console::debug("mapSizeText");
	ConsoleText* resolutionText = Console::debug("resolutionText");

	ConsoleText* textText = Console::debug("textText");
	ConsoleText* textOptionText = Console::debug("textOptionText");

	Engine();
	virtual ~Engine() override;
	virtual void init() override;

	virtual void update() override;
	virtual void render() override;
	virtual void updateDebugText();
	void* getGameObjectByTYPEIDName(const string& typeIDName);


	Cameraman* getCameraman();
	MapManager* getMapManager();
	SpriteManager* getSpriteManager();
	ActionManager* getActionManager();
	TextManager* getTextManager();
	AudioManager* getAudioManager();
	CaptionManager* getCaptionManager();
	EventManager* getEventManager();

	CinematicsManager* getCinematicsManager();
	Map* getCurrentMap();

public:
	//static void setClientGameEngine(BGClientEngine* clientGameEngine);
	//void setControlsManager(ControlsManager* controlsManager);
	//static BGClientEngine* getClientGameEngine();

	float getWidthRelativeToZoom();
	float getHeightRelativeToZoom();







	virtual bool serverMessageReceived(string e) override;

	//====================================================
	//SPRITE
	//====================================================
public:
	void sendSpriteDataRequestByName(string spriteAssetName);
	void sendSpriteDataRequestByID(int id);

private:
	void incomingSpriteData(string s);

	//====================================================
	//MAP
	//====================================================
public:
	void sendMapDataRequestByName(string mapName);
	void sendMapDataRequestByID(int id);

private:
	void incomingMapData(string s);

	//====================================================
public:
	void sendServerObjectRequest(ServerObject* serverObject);

	//====================================================
	//DIALOGUE
	//====================================================
	void sendDialogueRequest(int id);

private:
	void incomingDialogue(string s);

	//====================================================
	//EVENT
	//====================================================

public:
	void sendEventRequest(int id);

private:
	void incomingEvent(string s);

	//====================================================
	//GAMESTRING
	//====================================================
public:
	void sendGameStringRequest(int id);

private:
	void incomingGameString(string s);

	//====================================================
	//FLAG
	//====================================================
public:
	void sendFlagRequest(int id);

private:
	void incomingFlag(string s);

	//====================================================
	//SKILL
	//====================================================
public:
	void sendSkillRequest(int id);

private:
	void incomingSkill(string s);
	//====================================================
	//MUSIC
	//====================================================
public:
	void sendMusicRequest(int id);

private:
	void incomingMusic(string s);

	//====================================================
	//SOUND
	//====================================================
public:
	void sendSoundRequest(int id);

private:
	void incomingSound(string s);
};

