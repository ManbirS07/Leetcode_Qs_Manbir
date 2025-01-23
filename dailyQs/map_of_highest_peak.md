Approach
Initialization:
Create a height grid initialized to a large value (R + C, where R and C are the grid's dimensions).
Set water cells (isWater[i][j] == 1) to height 0.

Two-Pass Propagation:
First Pass (Top-Left to Bottom-Right):
Update each cell's height based on its top and left neighbors.
Second Pass (Bottom-Right to Top-Left):
Update each cell's height based on its bottom and right neighbors.

Key Idea:
By sweeping twice through the grid, each cell's height gets the minimum possible value as distances from all directions are considered.

