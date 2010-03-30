
#include "basic/Main.h"
#include "for/win/MainFunction.h"
#include "scene/SceneID.h"
#include "SceneCA.h"
#include "SceneID.h"

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	// Windows �p�̃A�v���P�[�V�����̏ꍇ�́A���̊֐��Ɉ��������̂܂܎󂯓n��
	return BlueCarrot::WindowsEntryPoint(hThisInst, hPrevInst, lpszArgs, nWinMode);
}



BlueCarrot::SceneBase * BlueCarrot::callback::CreateScene(BlueCarrot::SceneID scene_id)
{
	switch ( scene_id )
	{
	case SCENE_ID_CA:
		return new SceneCA(scene_id);
		break;
	default:
		assert(false);
		return NULL;
	}
	return NULL;
}

BlueCarrot::SceneID BlueCarrot::callback::GetStartupSceneID()
{
	return SCENE_ID_CA;
}

BlueCarrot::utility::Size<int> BlueCarrot::callback::GetScreenSize()
{
	return BlueCarrot::utility::Size<int>(640, 480);
}
