#include "graph.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <cmath>
#include <random>


// Remove Duplicates in connected nodes
// Bring force calculations together in their own loop
// Active Adding/Subtracting of Nodes during display
// Variable Force during Display
// Actively Visualizing Djiktra's as the force display is done.
// Generally reorganize code to be better

using namespace std;

struct Node
{
    int identifier;
    double x;
    double y;
    vector<int> connected_nodes;
};

class Graph
{
public:
    vector<Node> adjacency_list;
    Graph() {}

    Node* get_node(int identifier)
    {
        for (Node& node : adjacency_list)
        {
            if (node.identifier == identifier)
            {
                return &node;
            }
        }
        Node new_node;
        new_node.identifier = identifier;
        adjacency_list.push_back(new_node);
        return &adjacency_list.back();
    }

    void add_node(int identifier){
        for (const Node& node : adjacency_list) {
            if (node.identifier == identifier) {
                return;
            }
        }
        Node new_node;
        new_node.identifier = identifier;
        adjacency_list.push_back(new_node);
    }

    void add_edge(int source_identifier, int target_identifier)
    {
        Node* source_node = get_node(source_identifier);
        Node* target_node = get_node(target_identifier);

        source_node->connected_nodes.push_back(target_identifier);
    }

    int get_number_nodes()
    {
        return static_cast<int>(adjacency_list.size());
    }

    void print()
    {
        for (const Node& node : adjacency_list)
        {
            cout << "Node " << node.identifier << " is connected to: ";
            for (int connected_node : node.connected_nodes)
            {
                cout << connected_node << " ";
            }
            cout << endl;
        }
    }

    void display()
    {
        // SFML Force Directed Layout
        // Maybe add functionality to make it change in real time, with buttons for add nodes/edges
        int window_size = 800;
        sf::RenderWindow window(sf::VideoMode(window_size, window_size), "Graph");
        window.setPosition(sf::Vector2i(0, 0));

        // Set initial positions of nodes
        int grid_size = ceil(sqrt(this->get_number_nodes()));
        double grid_spacing = static_cast<double>(window_size) / (grid_size);
        int node_count = 0;

        for (int i = 0; i < grid_size; ++i)
        {
            for (int j = 0; j < grid_size; ++j)
            {
                if (node_count < this->get_number_nodes())
                {
                    // Set the positions of nodes in the adjacency_list
                    adjacency_list[node_count].x = (j*grid_spacing)+grid_spacing/2;
                    adjacency_list[node_count].y = (i*grid_spacing)+grid_spacing/2;
                    node_count++;
                }
            }
        }


        double dt = 0.0001;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                // User input for more nodes/edges
            }


            window.clear();

            // Defining shapes
            double node_size=grid_spacing/6;
            double edge_width=grid_spacing/60;
            sf::CircleShape node_shape(node_size);
            node_shape.setFillColor(sf::Color::White);

            // Force Directed Graph Constants (Spring Systems, Electrical Forces)
            // https://cs.brown.edu/people/rtamassi/gdhandbook/chapters/force-directed.pdf, 12.2
            double c1 = 2;
            double c2= grid_spacing;
            double c3=grid_spacing;
            double c4=1;



            // Drawing Shapes and Calculating forces/moving shapes
            for (const Node &node : adjacency_list) {
                node_shape.setPosition((node.x-node_size), (node.y-node_size));
                window.draw(node_shape);
                for (int connected_node_identifier : adjacency_list[node.identifier].connected_nodes) {
                    if (connected_node_identifier==node.identifier){
                        break;
                    }
                    // Calculate the rotation angle/length
                    double dx = adjacency_list[connected_node_identifier].x - adjacency_list[node.identifier].x;
                    double dy = adjacency_list[connected_node_identifier].y - adjacency_list[node.identifier].y;
                    double angle = atan2(dy, dx) * (180.f / static_cast<float>(M_PI));
                    double length = sqrt(dx * dx + dy * dy);
                    sf::RectangleShape edge_shape(sf::Vector2f(length, edge_width));
                    edge_shape.setFillColor(sf::Color::White);
                    edge_shape.setPosition(adjacency_list[node.identifier].x, adjacency_list[node.identifier].y);
                    edge_shape.setRotation(angle);
                    window.draw(edge_shape);


                    // Adjacent Attraction
                    adjacency_list[node.identifier].x+=c4*c1*log10(sqrt(pow(dx,2)+pow(dy,2))/c2)*dx/(sqrt(pow(dx,2)+pow(dy,2)));
                    adjacency_list[node.identifier].y+=c4*c1*log10(sqrt(pow(dx,2)+pow(dy,2))/c2)*dy/(sqrt(pow(dx,2)+pow(dy,2)));

                    adjacency_list[connected_node_identifier].x-=c4*c1*log10(sqrt(pow(dx,2)+pow(dy,2))/c2)*dx/(sqrt(pow(dx,2)+pow(dy,2)));
                    adjacency_list[connected_node_identifier].y-=c4*c1*log10(sqrt(pow(dx,2)+pow(dy,2))/c2)*dy/(sqrt(pow(dx,2)+pow(dy,2)));
                }
                for (const Node &node2 : adjacency_list) {
                    if (node.identifier != node2.identifier && find(node.connected_nodes.begin(), node.connected_nodes.end(), node2.identifier) == node.connected_nodes.end()) {
                        double dx = adjacency_list[node2.identifier].x - adjacency_list[node.identifier].x;
                        double dy = adjacency_list[node2.identifier].y - adjacency_list[node.identifier].y;

                        // Nonadjacent Repulsion
                        adjacency_list[node.identifier].x+=(-c4*c3/(pow(dx,2)+pow(dy,2)))*dx/(sqrt(pow(dx,2)+pow(dy,2)));
                        adjacency_list[node.identifier].y+=(-c4*c3/(pow(dx,2)+pow(dy,2)))*dy/(sqrt(pow(dx,2)+pow(dy,2)));

                        adjacency_list[node2.identifier].x-=(-c4*c3/(pow(dx,2)+pow(dy,2)))*dx/(sqrt(pow(dx,2)+pow(dy,2)));
                        adjacency_list[node2.identifier].y-=(-c4*c3/(pow(dx,2)+pow(dy,2)))*dy/(sqrt(pow(dx,2)+pow(dy,2)));
                    }
                }
                if (adjacency_list[node.identifier].x < node_size) {
                    adjacency_list[node.identifier].x = node_size;
                } else if (adjacency_list[node.identifier].x > window_size-node_size) {
                    adjacency_list[node.identifier].x = window_size-node_size;
                }

                if (adjacency_list[node.identifier].y < node_size) {
                    adjacency_list[node.identifier].y = node_size;
                } else if (adjacency_list[node.identifier].y > window_size-node_size) {
                    adjacency_list[node.identifier].y = window_size-node_size;
                }


            }


            window.display();

            this_thread::sleep_for(chrono::duration<double>(dt));
        }
    }
};

void testing()
{

    Graph graph;

    graph.add_edge(0,1);
    graph.add_edge(2,1);
    graph.add_edge(0,2);
    graph.add_edge(1,3);
    graph.add_edge(3,3);
    graph.add_edge(6,3);
    graph.add_edge(7,6);
    graph.add_edge(8,5);
    graph.add_edge(9,4);
    graph.add_edge(0,3);
    int n = 20;
    // graph.add_edge(rand()%n,rand()%n);
    // graph.add_edge(rand()%n,rand()%n);
    // graph.add_edge(rand()%n,rand()%n);
    // graph.add_edge(rand()%n,rand()%n);
    // graph.add_edge(rand()%n,rand()%n);
    // graph.add_edge(rand()%n,rand()%n);
    // graph.add_edge(rand()%n,rand()%n);
    // Segmentation Fault

    graph.print();
    graph.display();
}