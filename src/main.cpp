#include <fstream>

#include "vec3.h"
#include "color.h"

int main() {
    std::ofstream file("image.ppm");

    if (!file) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int image_height = 256;
    int image_width = 256;

    file << "P3\n" << image_height << ' ' << image_width << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; i++) {
            auto pixel_colour = colour((double(i) / (image_width - 1)), double(j) / (image_height - 1), 0.0);
            write_colour(file, pixel_colour);
        }
    }

    file.close();

    std::clog << "\nDone. \n";

    return 0;
}