-- This is the engine basics file.
-- It should contain ALL engine related functions, INCLUDING BUT NOT LIMITED TO:
-- hooks
-- functions
-- global variables
--
-- Below is a list of the engine-created compiled-in variables, and their content.
-- Their content, can NOT be changed.
--
-- global variables {{
--  globalinclude	'data/lua/include'
-- }}

-- Includes:
include( globalinclude.."/profilecreator.lua" )
include( globalinclude.."/json.lua" )
include( globalinclude.."/hook.lua" )

function mainloop()
--	stdin = io.input( io.stdin, "r" )
--	input = stdin:read()
--	while(input ~= "exit" ) do
--		input = stdin:read()
--	end
end
