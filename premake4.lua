solution "BreadBoard Simulation"

	language "C++"
	buildoptions "-std=c++11"
    configurations { "debug - windows","debug - linux", "release - windows", "release - linux" }

    project "BreadBoard"

        kind "ConsoleApp"
        files { "src/**.*" }
		includedirs { "src", "engine/undicht/core/include","engine/undicht/engine/src", "engine/undicht/vendor", "engine/undicht/vendor/glm" }
		
		libdirs {"engine/undicht/core", "engine/undicht/engine" }
		links { "core", "engine" }
		
		configuration "debug - windows"
		
		configuration "debug - linux"
			links { "dl" }
			
			
		configuration "release - linux"
			links { "dl" }
			
	include "engine/undicht"
			

        
