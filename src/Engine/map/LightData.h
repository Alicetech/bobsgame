//------------------------------------------------------------------------------
//Copyright Robert Pelloni.
//All Rights Reserved.
//------------------------------------------------------------------------------


#pragma once
#include "bobtypes.h"
class Logger;




class LightData : public EntityData
{

private:
	typedef EntityData super;


private:
	
	int widthPixels1X = 2;
	
	int heightPixels1X = 2;


	
	u8 redColorByte = 0;
	
	u8 greenColorByte = 0;
	
	u8 blueColorByte = 0;
	
	u8 alphaColorByte = 0;

	
	int radiusPixels1X = 2;

	
	float blendFalloff = 2.0f;

	
	float decayExponent = 1.0f;
	int focusRadius1X = 0;
	
	bool isDayLight = true;
	
	bool isNightLight = false;

	
	bool flickers = false;
	
	bool changesColor = false;
	
	bool toggleable = false;
	
	int toggleXPixels1X = -1;
	
	int toggleYPixels1X = -1;
	
	int flickerOnTicks = 0;
	
	int flickerOffTicks = 0;
	
	bool flickerRandomUpToOnTicks = false;
	
	bool flickerRandomUpToOffTicks = false;


public:
	LightData();


	LightData(int id, const string& mapName, const string& stateName, const string& name, int spawnXPixels1X, int spawnYPixels1X, int widthPixels1X, int heightPixels1X, int redColorByte, int greenColorByte, int blueColorByte, int alphaColorByte, int radiusPixels1X, float blendFalloff, float decayExponent, int focusRadius1X, bool isDayLight, bool isNightLight, bool flickers, bool changesColor, bool toggleable, int toggleXPixels1X, int toggleYPixels1X, int flickerOnTicks, int flickerOffTicks, bool flickerRandomUpToOnTicks, bool flickerRandomUpToOffTicks);


	LightData(int id, const string& name);


	//static LightData* fromBase64ZippedJSON(const string& b64);


	//static LightData* fromJSON(const string& json);

	string& initFromString(string& t);


	virtual string getTYPEIDString() override;


	virtual int getWidthPixels1X();
	virtual int getHeightPixels1X();
	virtual int getWidthPixelsHQ();
	virtual int getHeightPixelsHQ();

	virtual int getRadiusPixels1X();
	virtual int getRadiusPixelsHQ();

	virtual int getFocusRadiusPixels1X();
	virtual int getFocusRadiusPixelsHQ();


	virtual int getToggleXPixels1X();
	virtual int getToggleYPixels1X();
	virtual int getToggleXPixelsHQ();
	virtual int getToggleYPixelsHQ();

	virtual u8 getRedColorByte();
	virtual u8 getGreenColorByte();
	virtual u8 getBlueColorByte();
	virtual u8 getAlphaColorByte();

	virtual u8 r();
	virtual u8 g();
	virtual u8 b();
	virtual u8 a();


	virtual float getBlendFalloff();
	virtual float getDecayExponent();
	virtual bool getIsDayLight();
	virtual bool getIsNightLight();
	virtual bool getFlickers();
	virtual bool getChangesColor();
	virtual bool getToggleable();
	virtual int getFlickerOnTicks();
	virtual int getFlickerOffTicks();
	virtual bool getFlickerRandomUpToOnTicks();
	virtual bool getFlickerRandomUpToOffTicks();


	//set

	virtual void setWidthPixels1X(int s);
	virtual void setHeightPixels1X(int s);

	virtual void setRadiusPixels1X(int s);

	virtual void setFocusRadiusPixels1X(int s);

	virtual void setToggleXPixels1X(int s);
	virtual void setToggleYPixels1X(int s);

	virtual void setRedColorByte(u8 s);
	virtual void setGreenColorByte(u8 s);
	virtual void setBlueColorByte(u8 s);
	virtual void setAlphaColorByte(u8 s);

	virtual void setBlendFalloff(float s);
	virtual void setDecayExponent(float s);
	virtual void setIsDayLight(bool s);
	virtual void setIsNightLight(bool s);
	virtual void setFlickers(bool s);
	virtual void setChangesColor(bool s);
	virtual void setToggleable(bool s);
	virtual void setFlickerOnTicks(int s);
	virtual void setFlickerOffTicks(int s);
	virtual void setFlickerRandomUpToOnTicks(bool s);
	virtual void setFlickerRandomUpToOffTicks(bool s);
};

