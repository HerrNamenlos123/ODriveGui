
-- Retrieve the project name
newoption { trigger = "projectname", description = "Name of the generated project" }
local projectName = _OPTIONS["projectname"]
if projectName == nil then print("The project name was not specified! --projectname=YourApplication") os.exit(1) end
if projectName == "BatteryEngine" then print("The project cannot be named 'BatteryEngine'!") os.exit(1) end




-- Main Solution
workspace (projectName)
    configurations { "Debug", "Release", "Deploy" }

    platforms { "x64" }
    defaultplatform "x64"
    startproject (projectName)



-- Dependencies (git submodules)
include "modules/BatteryEngine"
include "modules/libusbcpp"



-- Actual application project
project (projectName)
    language "C++"
	cppdialect "C++17"
	staticruntime "on"
    location "build"
    targetname (projectName)
    targetdir "bin/%{cfg.buildcfg}"
    targetname "%{prj.name}"

    system "Windows"
    entrypoint "mainCRTStartup"
    architecture "x86_64"

    pchheader "pch.h"
    pchsource "src/pch.cpp"




    -- Configuration filters are active up to the next filter statement
    -- Indentation is purely visual
    filter "configurations:Debug"
        defines { "DEBUG", "_DEBUG", "NDEPLOY", "ALLEGRO_STATICLINK" }
        kind "ConsoleApp"
        runtime "Debug"
        symbols "On"
        linkoptions { '/NODEFAULTLIB:libcmt.lib', '/NODEFAULTLIB:msvcrt.lib', '/NODEFAULTLIB:msvcrtd.lib' }

    filter "configurations:Release"
        defines { "NDEBUG", "NDEPLOY", "ALLEGRO_STATICLINK" }
        kind "ConsoleApp"
        runtime "Release"
        optimize "On"
        linkoptions { '/NODEFAULTLIB:libcmtd.lib', '/NODEFAULTLIB:msvcrt.lib', '/NODEFAULTLIB:msvcrtd.lib' }

    filter "configurations:Deploy"
        defines { "NDEBUG", "DEPLOY", "ALLEGRO_STATICLINK" }
        kind "WindowedApp"
        runtime "Release"
        optimize "On"
        linkoptions { '/NODEFAULTLIB:libcmtd.lib', '/NODEFAULTLIB:msvcrt.lib', '/NODEFAULTLIB:msvcrtd.lib' }

    filter {}



    -- Include directories for the compiler
    includedirs { "include" }
 


    -- Main source files (all files in the project view)
    files { "include/**", "src/**" }



    -- BatteryEngine dependency
    dependson "BatteryEngine"
    includedirs (BATTERYENGINE_INCLUDE_DIRS)
    libdirs (BATTERYENGINE_LINK_DIRS)
    links (BATTERYENGINE_LINKS)
    
    
    -- libusbcpp dependency
    dependson "libusbcpp"
    includedirs (LIBUSBCPP_INCLUDE_DIRS)
    libdirs (LIBUSBCPP_LINK_DIRS)
    links (LIBUSBCPP_LINKS)



    linkoptions { "/IGNORE:4099" }  -- Ignore warning that no .pdb file is found for debugging
