
project "delta-qt"
    language "C++"
    kind "SharedLib"

    -- win/project resource description
    defines { "rsc_company=\"Dev-Force/Alpin-Dev\"",
              "rsc_copyright=\"(C) Force67 2019-2020. All rights reserved\"",
              "rsc_fileversion=\"1.0.0.0\"", 
              "rsc_productversion=\"1.0.0.0\"",
              "rsc_internalname=\"%{prj.name}\"",
              "rsc_productname=\"PS4Delta\"",
              "rsc_originalname=\"%{prj.name}%{prj.targetextension}\"",
              "rsc_description=\"PS4Delta core - with qt\"" }

    includedirs {
        ".",
        "../common",
        "../common/utl",
        "../core",
        "../core/orbis",
        "../video_core",

        -- 3rd party
        "../vendor/fmtlib/include",
        "../vendor/capstone/include",
        "../vendor/zlib",
        "../vendor/xbyak/xbyak"
    }

    links {
        "common",
        "core",
        "video_core",

        "capstone",
        "zlib",
        "fmtlib"
    }

    files {
        "premake5.lua",
        "_res/core.rc",
        "**.ui",
        "**.inl",
        "**.h",
        "**.hpp",
        "**.cpp",
        "**.c",
        "*.def",
    }
    
    -- enable qt for this project
    qt.enable()
    
    qtmodules {
        "core",
        "gui",
        "widgets",
        "opengl"
    }

    -- workaround for CI
    local qtd = os.getenv("Qt5_Dir")
    if qtd then
        qtpath(qtd)
    end

    filter "system:windows"
        qtmodules {
            "winextras",
            "qml"
        }

        local qtinclude, qtlib, qtbin = qt.getPaths(qt)

        -- yet another CI workaround
        if qtd then
            qtbin = qtd .. "\\bin"
        end
            
        -- auto-deploy qt dlls
        postbuildcommands(
            qtbin .. "\\windeployqt --no-angle --no-opengl-sw --no-svg --no-translations --no-quick --plugindir \"$(TargetDir)qt\" \"$(TargetPath)\""
        )
    filter "system:not windows"
        removefiles "**.rc"
        local qti = os.getenv("QT_INCLUDE")
        if qti then
            qtincludepath(qti)
        end
    filter {}

    qtprefix "Qt5"
    qtgenerateddir "qtgen"

    -- use debug versions of qt
    -- libs in debug builds
    configuration { "Debug" }
            qtsuffix "d"
    configuration {}