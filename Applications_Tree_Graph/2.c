#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // Added for strcpy
#define INT_MAX 1000

// Structure to represent a station
typedef struct Station
{
    int id;
    char name[100];
    // Add other station information fields as needed
} Station;

// Structure to represent a train route
typedef struct Route
{
    int source;
    int destination;
    int distance;
    // Add other route information fields as needed
} Route;

// Graph data structure
typedef struct Graph
{
    int numStations;
    int numRoutes;
    Station *stations;
    Route *routes;
} Graph;

// Function to create a new station
Station createStation(int id, const char *name)
{
    Station station;
    station.id = id;
    strcpy(station.name, name);
    return station;
}

// Function to create a new route
Route createRoute(int source, int destination, int distance)
{
    Route route;
    route.source = source;
    route.destination = destination;
    route.distance = distance;
    return route;
}

// Function to add a station to the graph
void addStation(Graph *graph, Station station)
{
    graph->stations[graph->numStations++] = station;
}

// Function to add a route to the graph
void addRoute(Graph *graph, Route route)
{
    graph->routes[graph->numRoutes++] = route;
}

// Function to find the index of a station in the graph given its ID
int findStationIndex(Graph *graph, int stationId)
{
    for (int i = 0; i < graph->numStations; i++)
    {
        if (graph->stations[i].id == stationId)
        {
            return i;
        }
    }
    return -1; // Station not found
}

// Function to find the index of a route in the graph given its source and destination
int findRouteIndex(Graph *graph, int source, int destination)
{
    for (int i = 0; i < graph->numRoutes; i++)
    {
        if (graph->routes[i].source == source && graph->routes[i].destination == destination)
        {
            return i;
        }
    }
    return -1; // Route not found
}

// Function to find the shortest path using Dijkstra's algorithm
void findShortestPath(Graph *graph, int source, int destination)
{
    int numVertices = graph->numStations;
    int *distances = (int *)malloc(numVertices * sizeof(int));
    int *previous = (int *)malloc(numVertices * sizeof(int));
    bool *visited = (bool *)malloc(numVertices * sizeof(bool));

    // Initialize distances and previous array
    for (int i = 0; i < numVertices; i++)
    {
        distances[i] = INT_MAX;
        previous[i] = -1;
        visited[i] = false;
    }

    // Distance from source to itself is 0
    distances[source] = 0;

    // Dijkstra's algorithm
    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = -1;
        int minDistance = INT_MAX;

        // Find the vertex with the minimum distance
        for (int v = 0; v < numVertices; v++)
        {
            if (!visited[v] && distances[v] < minDistance)
            {
                minDistance = distances[v];
                u = v;
            }
        }

        if (u == -1)
        {
            break; // No more reachable vertices
        }

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < numVertices; v++)
        {
            int routeIndex = findRouteIndex(graph, u, v);
            if (routeIndex != -1)
            {
                int altDistance = distances[u] + graph->routes[routeIndex].distance;
                if (altDistance < distances[v])
                {
                    distances[v] = altDistance;
                    previous[v] = u;
                }
            }
        }
    }

    // Print the shortest path
    printf("Shortest path from %s to %s: ", graph->stations[source].name, graph->stations[destination].name);
    int current = destination;
    while (current != source)
    {
        printf("%s -> ", graph->stations[current].name);
        current = previous[current];
    }
    printf("%s\n", graph->stations[source].name);

    free(distances);
    free(previous);
    free(visited);
}

int main()
{
    // Create the graph
    Graph graph;
    graph.numStations = 0;
    graph.numRoutes = 0;
    graph.stations = (Station *)malloc(100 * sizeof(Station));
    graph.routes = (Route *)malloc(100 * sizeof(Route));

    // Add stations
    addStation(&graph, createStation(0, "Station A"));
    addStation(&graph, createStation(1, "Station B"));
    addStation(&graph, createStation(2, "Station C"));
    // Add more stations...

    // Add routes
    addRoute(&graph, createRoute(0, 1, 10));
    addRoute(&graph, createRoute(1, 2, 5));
    // Add more routes...

    // Find shortest path
    int source = findStationIndex(&graph, 0);
    int destination = findStationIndex(&graph, 2);
    findShortestPath(&graph, source, destination);

    // Clean up
    free(graph.stations);
    free(graph.routes);

    return 0;
}
