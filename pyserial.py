import serial
import matplotlib.pyplot as plt
import math

# Specify the serial port and baud rate (adjust COM port as needed)
serial_port = 'COM3'  # Replace with the correct port (e.g., 'COM3' on Windows, '/dev/ttyUSB0' on Linux)
baud_rate = 115200

# Initialize lists to store Cartesian coordinates
x_coords = []
y_coords = []

try:
    # Open the serial connection
    with serial.Serial(serial_port, baud_rate, timeout=1) as ser:
        print("Reading data from Arduino...")

        prev_angle = None
        first_point = None
        while True:
            line = ser.readline().decode('utf-8').strip()
            if not line:
                continue

            # Parse the angle and distance from the serial data
            if "Angle:" in line and "Distance:" in line:
                try:
                    parts = line.split(", ")
                    angle = int(parts[0].split(": ")[1].replace("\u00b0", ""))
                    distance = int(parts[1].split(": ")[1].replace(" mm", ""))

                    # Convert polar coordinates to Cartesian coordinates
                    x = distance * math.cos(math.radians(angle))
                    y = distance * math.sin(math.radians(angle))
                    x_coords.append(x)
                    y_coords.append(y)

                    # Store the first point (at 0 degrees) for later connection
                    if angle == 0 and first_point is None:
                        first_point = (x, y)

                    print(f"Angle: {angle}, Distance: {distance}, X: {x:.2f}, Y: {y:.2f}")

                    # Check for a complete 360-degree scan
                    if prev_angle is not None and angle == 0 and prev_angle == 359:
                        break

                    prev_angle = angle
                except ValueError:
                    print("Invalid data format received:", line)

except serial.SerialException as e:
    print(f"Serial error: {e}")
except KeyboardInterrupt:
    print("Data reading interrupted.")

# Connect the last point at 315 degrees to the first point at 0 degrees
if first_point is not None:
    x_coords.append(first_point[0])
    y_coords.append(first_point[1])

# Plot the data as a closed path
plt.figure(figsize=(8, 8))
plt.plot(x_coords, y_coords, marker='o', linestyle='-', color='b')
plt.title("2D Map (Closed Path)")
plt.xlabel("X (mm)")
plt.ylabel("Y (mm)")
plt.grid(True)
plt.axis('equal')  # Ensure equal scaling for x and y axes
plt.show()
