#include "pch.h"

#define FILENAME "THERE.sav"

void SaveFile(SAV** sav)
{
	FILE* fp = NULL;
	fopen_s(&fp, FILENAME, "wb");
	if (fp == NULL)
	{
		return;
	}

	fwrite(&sav, sizeof(SAV), 1, fp);

	//저장 완료..
	fclose(fp);
}

bool LoadFile(SAV** sav)
{
	FILE* fp = NULL;
	fopen_s(&fp, FILENAME, "rb");
	if (fp == NULL)
	{
		return false;
	}

	SAV* save = NULL;
	save = new SAV;

	if (save == NULL)
	{
		sav = NULL;

		fclose(fp);
		return false;
	}

	fread(save, sizeof(SAV), 1, fp);
	*sav = save;
	fclose(fp);

	return true;
}