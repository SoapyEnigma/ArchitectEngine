#include <Engine.h>

class ExampleLayer : public AE::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{

	}

	void OnUpdate() override
	{

	}

	void OnEvent(AE::Event& e) override
	{
		//AE_APP_TRACE("{0}", e);
	}
};

class Editor : public AE::Application
{
public:
	Editor()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new AE::ImGuiLayer());
	}
	~Editor()
	{

	}
};

AE::Application* AE::CreateApplication()
{
	return new Editor();
}