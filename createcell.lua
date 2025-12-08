local inventory = {};
local current_slots = 0;
local wanted_slots = 0;
local read_input = -1;

while (read_input ~= 0) do
print("There are currently ".. current_slots .. " slots in your inventoy");
io.write("Create how many slots: ");
read_input = tonumber(io.read());
wanted_slots = read_input + current_slots; --because yes
for i = (current_slots+1), wanted_slots do
    inventory[i] = {};
    current_slots = i;

end
print("Total slots: "..current_slots)
print("Wanted slots: "..read_input);
wanted_slots = 0;
for k, v in ipairs(inventory) do
    print(k, v);
end
end

--[[function getItemAndCount()
    
end
function create_cell()
    
end
]]--