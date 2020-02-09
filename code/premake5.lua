
require('vstudio')

-- reconfigure paths with qt support
premake.path = premake.path .. ";build"
package.path = package.path .. ";../tools/premake/premake-qt/?.lua"

-- use clang instead of msvc on windows
premake.override(premake.vstudio.vc2010, 'platformToolset', function(base, cfg)
    premake.vstudio.vc2010.element("PlatformToolset", nil, "ClangCL")
end)

-- qt short alias 
require('qt')
qt = premake.extensions.qt

workspace "PS4Delta"
    configurations { "Debug", "Release" }
    architecture "x86_64"

    location "../build"
    os.mkdir"../build/symbols"
    characterset "Unicode"
	cppdialect "C++17"

    targetdir '../bin/%{cfg.buildcfg}/'
    
    -- multi threaded compilation
    flags "MultiProcessorCompile"
    cppdialect "C++17"

    symbols "On"
    
    defines { "FXNAME=\"%{wks.name}\"", 
              "FXNAME_WIDE=L\"%{wks.name}\""}

    filter "configurations:Debug"
        defines { "DELTA_DBG" }

    filter "configurations:Release"
        optimize "Speed"
    
    filter {"system:windows"}
         characterset "Unicode"

    filter {"system:windows", "kind:not StaticLib"}
        linkoptions { "/PDB:\"$(SolutionDir)\\symbols\\$(ProjectName)_%{cfg.buildcfg}.pdb\"" }

    filter { "system:windows", "kind:not StaticLib" }
        linkoptions "/manifestdependency:\"type='Win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\""

    filter "system:not windows"
        buildoptions "-fPIC"

    -- Disable deprecation warnings and errors
    filter "action:vs*"
        defines
        {
            "NOMINMAX",
            "WIN32_LEAN_AND_MEAN",
            "_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING",
            "_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING",
            "_CRT_SECURE_NO_WARNINGS",
            "_CRT_SECURE_NO_DEPRECATE",
            "_CRT_NONSTDC_NO_WARNINGS",
            "_CRT_NONSTDC_NO_DEPRECATE",
            "_SCL_SECURE_NO_WARNINGS",
            "_SCL_SECURE_NO_DEPRECATE"
        }
    filter "action:gmake*"
        toolset "clang"
    filter {}

    startproject "host"

    group "app"
    include "./delta"
    include "./delta_qt"
    include "./host"
    include "./core"
    include "./common"
    include "./video_core"

    group "vendor"
    include "vendor/3rdparty.lua"
    
-- Cleanup
if _ACTION == "clean" then
    os.rmdir("../bin");
    os.rmdir("../build");
end
