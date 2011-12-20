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
require( globalincludes.."/profilecreator" )
require( globalincludes.."/json" )
require( globalincludes.."/hook" )

function mainloop()
--	stdin = io.input( io.stdin, "r" )
--	input = stdin:read()
--	while(input ~= "exit" ) do
--		input = stdin:read()
--	end
end
