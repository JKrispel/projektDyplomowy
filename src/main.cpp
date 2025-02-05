#include "raylib.h"
#include <iostream>

#pragma region imgui
#include "imgui.h"
#include "rlImGui.h"
#include "imguiThemes.h"
#pragma endregion

#include "player.h"
#include "npc.h"
#include "enemy.h"
#include "decisions/action_manager/action.h"
// TODO
// AI dla NPC
// co musi sie wykonywac w kazdej klatce?
// Redesign:
// unordered_map możliwych Akcji
// FinalDecision będzie posiadać identyfikator Enum.
// Logika decyzji zostanie oddzielona od wykonywania akcji.
// (m.in. nie będzie też potrzeby przekazywania pozycji gracza i celu dla akcji w odmętach implementacji logiki decyzyjnej)
// W ten sposób design logiki decyzyjnej, dostępnych akcji i ich dostępu do stanu gry powinien przyjąć bardziej ortogonalny charakter.
// Będzie to wymagało drobnych zmian w bibliotece (przede wszystkim klasa FinalDecision).



int main(void)
{
	const int screen_width = 1280;
	const int screen_height = 800;

	Rectangle map_bounds{};
	map_bounds.height = float(screen_height) - 20.0f;
	map_bounds.width = float(screen_width) - 20.0f;
	map_bounds.x = 10.0f;
	map_bounds.y = 10.0f;

	//SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(screen_width, screen_height, "Test Drzew Decyzyjnych");
	SetTargetFPS(60);

#pragma region imgui
	rlImGuiSetup(true);

	//you can use whatever imgui theme you like!
	//ImGui::StyleColorsDark();
	//imguiThemes::yellow();
	//imguiThemes::gray();
	imguiThemes::green();
	//imguiThemes::red();
	//imguiThemes::embraceTheDarkness();


	ImGuiIO &io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io.FontGlobalScale = 2;

	ImGuiStyle &style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		//style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 0.5f;
		//style.Colors[ImGuiCol_DockingEmptyBg].w = 0.f;
	}

#pragma endregion

	Player player;

	player.position.x = screen_width / 2;
	player.position.y = screen_height / 2;
	player.radius = 20;
	player.speed = 7;
	player.area = map_bounds;

	// w finalnej implementacji NPC bedzie posiadal ActionManager
	// Npc(Podążający) otrzymuje jako target gracza

	Npc npc = Npc(player);
	npc.position.x = 50.f;
	npc.position.y = 50.f;
	npc.radius = 20;
	npc.speed = 4;

	Enemy enemy = Enemy(player);
	enemy.position.x = 50.f;
	enemy.position.y = 100.f;
	enemy.radius = 20;
	enemy.speed = 4;


	while (!WindowShouldClose()) {
	

		// Updating
		player.update();
		npc.update();	// w środku zawarta logika AI
		enemy.update();

		// Drawing
		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangleRec(map_bounds, DARKPURPLE);
		player.draw();
		npc.draw();
		enemy.draw();

	#pragma region imgui
		rlImGuiBegin();

		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);
	#pragma endregion


	#pragma region imgui
		rlImGuiEnd();

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}
	#pragma endregion

		EndDrawing();
	}


#pragma region imgui
	rlImGuiShutdown();
#pragma endregion



	CloseWindow();

	return 0;
}