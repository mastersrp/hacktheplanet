-- This is the engine basics file.
-- It should contain ALL engine related functions, INCLUDING BUT NOT LIMITED TO:
-- hooks
-- functions
-- global variables

-- Includes:
dofile( globalinclude.."/profilecreator.lua" )
dofile( globalinclude.."/json.lua" )

function onInit()
	print( "[LUA] Initiating..." )
end

function onExit()
	print( "[LUA] Exiting..." )
end

function onProfileNotFound()
	print( "[LUA] Could not find your profile" )
	print( "[LUA] Creating a new one! (not yet, but this'll come eventually." )
end
