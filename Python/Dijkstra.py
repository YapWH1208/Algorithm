import heapq

def dijkstra(graph, start):
    # Priority queue to store vertices and their tentative distances
    priority_queue = [(0, start)]  # (distance, vertex)
    distances = {vertex: float('infinity') for vertex in graph}
    distances[start] = 0

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        # Skip if the current distance is greater than the known distance
        if current_distance > distances[current_vertex]:
            continue

        # Update distances for neighbors
        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            # If a shorter path is found, update the distance
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances

# Example usage:
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

start_vertex = 'A'
shortest_distances = dijkstra(graph, start_vertex)

print(f"Shortest distances from vertex {start_vertex}:")
for vertex, distance in shortest_distances.items():
    print(f"To {vertex}: {distance}")
