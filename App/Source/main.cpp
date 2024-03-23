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
		
	}
};

class Editor : public AE::Application
{
public:
	Editor()
	{
		PushLayer(new ExampleLayer());
	}
	~Editor()
	{

	}
};

AE::Application* AE::CreateApplication()
{
	return new Editor();
}