
#include "pch.h"
#include "UserInterface.h"
#include "libusbcpp.h"
#include "ODrive.h"

class BatteryApp : public Battery::Application {

	std::shared_ptr<UserInterface> ui;
	std::thread backendUpdateThread;
	std::atomic<bool> shouldClose = false;

public:
	BatteryApp();

	bool OnStartup() override;
	void OnUpdate() override;
	void OnRender() override;
	void OnShutdown() override;
	void OnEvent(Battery::Event* e) override;

};
