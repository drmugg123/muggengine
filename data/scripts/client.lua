device = Device.new()

window = device:create_window()
window:open(800, 600, "Client")

client = Client.new()
client:initialize(2, 0, 0)

renderer = device:create_renderer()
renderer:initialize()

packet = StringPacket.new()

local input

print("Enter address to connect to:")
input = io.read()

client:connect(input, 2300, 5000)

keyboard = Keyboard.new()

if client:is_connected() then
    renderer:set_background_color(Color.new(0, 1, 0, 1))
    
    while window:is_open() do
        if keyboard:is_key_down("Escape") then
            window:close()
        elseif keyboard:is_key_down("Return") then
            print("Enter message to send:")
            input = io.read()
   
            if not input == "" then
                packet:set_data(input, "Reliable")
                client:send_string_packet(packet, 0)
            end
        elseif keyboard:is_key_down("Insert") and not window:get_clipboard() == "" then
            packet:set_data(window:get_clipboard(), "Reliable")
            client:send_string_packet(packet, 0)
        end

        client:poll(0)
    
        renderer:draw()
        window:swap_buffers()
    end

    client:disconnect(3000)
else
    print("Failed to connect to " .. input .. ":" .. 2300)
end
