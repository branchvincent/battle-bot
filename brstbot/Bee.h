

ChinaBee bee;


void init_bee() {
  bee.init(48, 49);
}

void update_bee() {
  // This must be called every loop
  bee.update();
  
  for (int i=0; i<bee.get_num_teams(); i++) {
    team_status_t* stat = bee.get_status(i);
    if (stat->haveFound || true) {
      
      
//      Serial.print("(");
//      Serial.print(x_true(stat->x));
//      Serial.print(",");
//      Serial.print(y_true(stat->y));
//      Serial.print(")   ");

      if (i == 3) {
        Point p = Point(x_true(stat->x),y_true(stat->y));
        log("Updating bot 3!  ", p.toString());
        bots[i].setPosition(p);
      }
    }
  }
//  Serial.println();
  
}

