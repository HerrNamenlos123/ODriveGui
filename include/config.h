#pragma once

#define CONTROL_PANEL_WIDTH 700
#define STATUS_BAR_HEIGHT 45
#define STATUS_BAR_ELEMENTS_WIDTH 270
#define ODRIVE_POPUP_HEIGHT 370
#define ENDPOINT_SELECTOR_WIDTH 400

#define RED			IMGUI_COLOR(255, 0, 0, 255)
#define GREEN		IMGUI_COLOR(0, 255, 0, 255)
#define BLUE		IMGUI_COLOR(0, 0, 255, 255)
#define BROWN		IMGUI_COLOR(211, 84, 0, 255)
#define LIGHT_BLUE	IMGUI_COLOR(46, 134, 193, 255)
#define LIGHT_GREEN	IMGUI_COLOR(46, 204, 113, 255)
#define YELLOW		IMGUI_COLOR(244, 208, 63, 255)

#define COLOR_FLOAT		BROWN
#define COLOR_BOOL		LIGHT_BLUE
#define COLOR_UINT		LIGHT_GREEN
#define COLOR_FUNCTION	YELLOW

#define IMGUI_COLOR(r, g, b, a) ImVec4({ r / 255.f, g / 255.f, b / 255.f, a / 155.f })
#define IMGUI_BUFFER_SIZE 16

// Flags for the Text input fields
#define IMGUI_FLAGS_FLOAT ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_CharsScientific
#define IMGUI_FLAGS_INT ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_AutoSelectAll | ImGuiInputTextFlags_CharsDecimal

