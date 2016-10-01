
const int bot_position_buffer_size = 5;

class Bot {
  private:
    Point position;
    Point lastPosition;
    int visualHeading;
    Point position_buffer[bot_position_buffer_size];
    int position_kickout_index = 0;

  public:

    Point getLastPosition() {
      return lastPosition;
    }
  
    Point getPosition() {
       return position;
    }

    void setPosition(Point p) {

      if ((p.x != lastPosition.x) || (p.y != lastPosition.y)) {

        Point displacementVector((int)(p.x - lastPosition.x), (int)(p.y - lastPosition.y));
  
        // Update estimated heading.
        float headingRadians = atan2(displacementVector.y, displacementVector.x);
        float headingDegrees = headingRadians * 180/M_PI; ;
        visualHeading = headingDegrees;
        
        lastPosition = position;
        position = p;

        log("New Position for Bot: ", p.toString());
        log("New Heading for Bot: ", headingDegrees);
        
      }
    }

    int getVisualHeading() {
      return visualHeading;
    }
};

