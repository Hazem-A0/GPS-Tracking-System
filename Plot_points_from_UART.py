import serial


# Open serial port for UART communication
ser = serial.Serial("COM10", 9600, timeout=1)  # Change 'COM3' to your UART port

# Open file to save GPS data
file_name = "Coordinates.txt"
open("coordinates.txt", "w").close()  # clearing the file
# Main loop
char_to_send = input("Enter U to receive the date ")

# Send the character
ser.write(char_to_send.encode())

with open(file_name, "a") as file:
    while True:
        # Prompt user to send character

        # Read data from serial port
        data = ser.readline().decode("utf-8").strip()

        # Check if data is "logdone", if so, break out of the loop
        if data == "logdone":
            print("Received 'logdone'. Stopping writing to file.")
            break

        # Write data to file
        file.write(data + "\n")

        # Print received data
        print("Data received:", data)
file.close()
# %%
import folium

# Read locations from text file
locations = []
latitude = []
longitude = []
with open("coordinates.txt", "r") as file:
    latitudes_done = False
    for line in file:
        line = line.strip()  # Remove leading/trailing whitespaces
        if not line:  # Skip empty lines
            continue
        if line == "latdone":
            latitudes_done = True
            continue
        if not latitudes_done:
            latitude.append(int(line[:-8]) + (float(line[-8:])) / 60)

        else:
            longitude.append(int(line[:-8]) + (float(line[-8:])) / 60)

    for loc in range(len(longitude)):
        locations.append([latitude[loc], longitude[loc]])


m = folium.Map(location=locations[0], zoom_start=19)  # Start Point
for loc in locations:
    folium.Marker(location=loc).add_to(m)
print(locations)

# display
m
