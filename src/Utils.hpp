#include <vector>

class Utils 
{
    public:
        
        static void flood_fill(std::vector< std::vector<int> >* map, int start_x, int start_y, int old_color, int new_color);
    private:
            typedef struct {
                int x;
                int y;
            } coord_t;

};
