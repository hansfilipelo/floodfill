#include "Utils.hpp"
#include <iostream>

using namespace std;

void Utils::flood_fill(vector< vector<int> >* map, int start_x, int start_y, int old_color, int new_color)
{
    vector<coord_t> stack;
    int width = map->at(0).size();
    int height = map->size();

    if(old_color == new_color) return;
    stack.clear();

    int curr_x;
    bool traverse_above, traverse_below;
    coord_t current_coord = {start_x, start_y};
    
    // Push the start position on stack
    stack.push_back(current_coord);

    while(!stack.empty())
    {
        current_coord = stack.back();
        stack.pop_back();

        curr_x = current_coord.x;
        
        // Start "from left" in memory so that all writes occour in order
        while(curr_x >= 0 && map->at(current_coord.y).at(curr_x) == old_color) curr_x--;
        
        curr_x++;
        traverse_above = traverse_below = false;
        
        while(curr_x < width && map->at(current_coord.y).at(curr_x) == old_color )
        {
            map->at(current_coord.y).at(curr_x) = new_color;
            
            if(!traverse_above && current_coord.y > 0 && map->at(current_coord.y - 1).at(curr_x) == old_color)
            {
                stack.push_back({curr_x, current_coord.y - 1});
                traverse_above = true;
            }
            else if(traverse_above && current_coord.y > 0 && map->at(current_coord.y - 1).at(curr_x) != old_color)
            {
                traverse_above = false;
            }
            if(!traverse_below && current_coord.y < height - 1 && map->at(current_coord.y + 1).at(curr_x) == old_color)
            {   
                stack.push_back({curr_x, current_coord.y + 1});
                traverse_below = true;
            }
            else if(traverse_below && current_coord.y < height - 1 && map->at(current_coord.y + 1).at(curr_x) != old_color)
            {
                traverse_below = false;
            }
            curr_x++;
        }
    }
}

