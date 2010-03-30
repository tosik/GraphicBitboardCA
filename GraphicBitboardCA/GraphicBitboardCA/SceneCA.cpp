
#include "SceneCA.h"

#include "debug/Debug.h"
#include "basic/GlobalInstance.h"
#include "graphics/Renderer.h"
#include "graphics/Camera.h"
#include "graphics/Light.h"
#include "utility/Common.h"
#include "utility/KeyManager.h"
#include "utility/Type.h"


SceneCA::SceneCA(BlueCarrot::SceneID scene_id)
	: SceneRendering(scene_id)
{
}

void SceneCA::Initialize()
{
	SceneRendering::Initialize();

	BlueCarrot::graphics::Renderer * renderer = BlueCarrot::GetGlobalInstance()->GetRenderer();

	m_CA.Randomize();
	AddSceneEntity(&m_CA);
}

void SceneCA::Finalize()
{
	SceneRendering::Finalize();
}

void SceneCA::Update(unsigned int elapsed_time)
{
	SceneRendering::Update(elapsed_time);

	m_CA.Step();
}

