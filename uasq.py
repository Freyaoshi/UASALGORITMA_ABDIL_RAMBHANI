import matplotlib.pyplot as plt
import random

def sierpinski_triangle(iterations):
    # Define the vertices of the triangle
    vertices = [(0, 0), (1, 0), (0.5, 0.866)]  # Equilateral triangle
    
    # Start with an initial point
    x, y = 0.5, 0.5
    
    # Lists to store the points
    x_vals = [x]
    y_vals = [y]

    for _ in range(iterations):
        # Randomly choose a vertex
        vx, vy = random.choice(vertices)
        
        # Move halfway towards the chosen vertex
        x = (x + vx) / 2
        y = (y + vy) / 2
        
        # Append the new point to the lists
        x_vals.append(x)
        y_vals.append(y)

    # Plot the points
    plt.figure(figsize=(6, 6))
    plt.scatter(x_vals, y_vals, s=0.1, color='blue')
    plt.axis('off')  # Hide axes for a cleaner look
    plt.title("Sierpinski Triangle", fontsize=14)
    plt.show()

# Generate the fractal with 50,000 points
sierpinski_triangle(50000)
