float getReflection(int portNumber)
{ // Function to get color reflection by sensor
	switch(portNumber)
	{
		case 1:
			return 100*(getColorReflected(CS1)-black1)/white1;
		case 2:
			return 100*(getColorReflected(CS2)-black2)/white2;
		case 3:
			return 100*(getColorReflected(CS3)-black3)/white3;
		case 4:
			return 100*(getColorReflected(CS4)-black4)/white4;
		default:
			return 0;
	}
}

float getTrueReflection(int portNumber)
{
    switch(portNumber)
	{
		case 1:
			return getColorReflected(CS1);
		case 2:
			return getColorReflected(CS2);
		case 3:
			return getColorReflected(CS3);
		case 4:
			return getColorReflected(CS4);
		default:
			return 0;
	}
}

int getTrueColor(int portNumber)
{
	switch(portNumber)
	{
		case 1:
			return getColorName(CS1);
		case 2:
			return getColorName(CS2);
		case 3:
			return getColorName(CS3);
		case 4:
			return getColorName(CS4);
		default:
			return 0;
	}
}

int getColor(int portNumber)
{
	return getTrueColor(portNumber);
}

float getAmbient(int portNumber)
{
	switch(portNumber)
	{
		case 1:
			return getColorAmbient(CS1);
		case 2:
			return getColorAmbient(CS2);
		case 3:
			return getColorAmbient(CS3);
		case 4:
			return getColorAmbient(CS4);
		default:
			return 0;
	}
}

float getHue(int portNumber)
{
	switch(portNumber)
	{
		case 1:
			return getColorHue(CS1);
		case 2:
			return getColorHue(CS2);
		case 3:
			return getColorHue(CS3);
		case 4:
			return getColorHue(CS4);
		default:
			return 0;
	}
}

float getSaturation(int portNumber)
{
	switch(portNumber)
	{
		case 1:
			return getColorSaturation(CS1);
		case 2:
			return getColorSaturation(CS2);
		case 3:
			return getColorSaturation(CS3);
		case 4:
			return getColorSaturation(CS4);
		default:
			return 0;
	}
}

float getRed(int portNumber)
{
	int red;
	int blue;
	int green;
	switch(portNumber)
	{
		case 1:
			getColorRGB(CS1, red, green, blue);
			return red;
		case 2:
			getColorRGB(CS2, red, green, blue);
			return red;
		case 3:
			getColorRGB(CS3, red, green, blue);
			return red;
		case 4:
			getColorRGB(CS4, red, green, blue);
			return red;
		default:
			return 0;
	}
}

float getGreen(int portNumber)
{
	int red;
	int blue;
	int green;
	switch(portNumber)
	{
		case 1:
			getColorRGB(CS1, red, green, blue);
			return green;
		case 2:
			getColorRGB(CS2, red, green, blue);
			return green;
		case 3:
			getColorRGB(CS3, red, green, blue);
			return green;
		case 4:
			getColorRGB(CS4, red, green, blue);
			return green;
		default:
			return 0;
	}
}

float getBlue(int portNumber)
{
	int red;
	int blue;
	int green;
	switch(portNumber)
	{
		case 1:
			getColorRGB(CS1, red, green, blue);
			return blue;
		case 2:
			getColorRGB(CS2, red, green, blue);
			return blue;
		case 3:
			getColorRGB(CS3, red, green, blue);
			return blue;
		case 4:
			getColorRGB(CS4, red, green, blue);
			return blue;
		default:
			return 0;
	}
}

const string getName[8] = {
	"NONE",
	"BLACK",
	"BLUE",
	"GREEN",
	"YELLOW",
	"RED",
	"WHITE",
	"BROWN"
};

float getReflFromTrue(int refl, int portNumber)
{
	switch(portNumber)
	{
		case 1:
			return 100*(refl-black1)/white1;
		case 2:
			return 100*(refl-black2)/white2;
		case 3:
			return 100*(refl-black3)/white3;
		case 4:
			return 100*(refl-black4)/white4;
		default:
			return 0;
	}
}
