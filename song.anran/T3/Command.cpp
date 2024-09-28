void executeCommand(const std::vector<Polygon>& polygons, const std::string& command, const Polygon& target) {
    if (command == "LESSAREA") {
        double targetArea = calculateArea(target);
        int count = 0;
        for (const auto& polygon : polygons) {
            if (calculateArea(polygon) < targetArea) {
                count++;
            }
        }
        std::cout << count << std::endl;
    } else if (command == "SAME") {
        int count = 0;
        for (const auto& polygon : polygons) {
            if (polygon.vertexCount() == target.vertexCount()) {
                bool same = true;
                for (int i = 0; i < polygon.vertexCount(); i++) {
                    if (polygon.points[i].x != target.points[i].x || polygon.points[i].y != target.points[i].y) {
                        same = false;
                        break;
                    }
                }
                if (same) {
                    count++;
                }
            }
        }
        std::cout << count << std::endl;
    }
}
