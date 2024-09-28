int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " filename" << std::endl;
        return 1;
    }

    auto polygons = readPolygonsFromFile(argv[1]);

    std::string command;
    Polygon target;

    while (std::cin >> command) {
        if (command == "LESSAREA" || command == "SAME") {
            int vertexCount;
            std::cin >> vertexCount;
            target.points.resize(vertexCount);

            for (int i = 0; i < vertexCount; i++) {
                std::cin >> target.points[i].x >> target.points[i].y;
            }

            executeCommand(polygons, command, target);
        } else {
            std::cerr << "Unknown command: " << command << std::endl;
        }
    }

    return 0;
}
