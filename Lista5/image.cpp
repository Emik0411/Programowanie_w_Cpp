#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::load(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    std::ifstream in(filename, std::ios::binary);
    if (!in) throw std::invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;
    if (magic != MAGIC) throw std::logic_error("unknown magic naumber " + magic);

    in >> my_width >> my_height >> color_depth;

    if (!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw std::logic_error("invalid image parameter(s): " + std::to_string(my_width) + " " +
                               std::to_string(my_height) + " " + std::to_string(color_depth));
    in.ignore(1);
    pixels.resize(my_height);
    for (auto& line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
        if (!in) throw std::logic_error("failed to read binary pixel data from file " + filename);
    }
}

void Image::save_as(const std::string& filename)
{
    std::ofstream out(filename, std::ios::binary);
    if (!out) throw std::invalid_argument("failed to open \"" + filename + "\" for writing");

    out << magic << "\n" << my_width << " " << my_height << "\n" << color_depth << "\n";
    for (const auto& line : pixels)
    {
        out.write(reinterpret_cast<const char*>(&line[0]), my_width * sizeof(RGB));
    }
}

void Image::add_watermark()
{
    const RGB color = {236, 30, 33};

    for (int i = 0; i < my_height; i++)
    {
        pixels[i][i * my_width / my_height] = color;
        pixels[i][my_width - i * my_width / my_height-1] = color;
    }
}

void Image::blurr()
{
    std::vector<std::vector<RGB>> new_pixels = pixels;

    for(int h = 1; h < my_height - 1; h++)
    {
        for(int w = 1; w < my_width - 1; w++)
        {
            int red_sum = 0;
            int green_sum = 0;
            int blue_sum = 0;
            for(int y = -1; y <= 1; y++)
            {
                for(int x = -1; x <= 1; x++)
                {
                    red_sum += pixels[h+y][w+x].red;
                    green_sum += pixels[h+y][w+x].green;
                    blue_sum += pixels[h+y][w+x].blue;
                }
            }
            new_pixels[h][w].red = static_cast<unsigned char>(red_sum/9);
            new_pixels[h][w].green = static_cast<unsigned char>(green_sum/9);
            new_pixels[h][w].blue = static_cast<unsigned char>(blue_sum/9);
        }
    }
    pixels = new_pixels;

}

void Image::extract_layer(ColorLayer color_layer)
{
    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            if (color_layer == ColorLayer::Red)
            {
                pixels[h][w].green = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Green)
            {
                pixels[h][w].red = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Blue)
            {
                pixels[h][w].red = 0;
                pixels[h][w].green = 0;
            }
        }
    }
}

void Image::filter()
{
    std::vector<std::vector<RGB>> new_pixels = pixels;

    for(int h = 0; h < my_height -1; h++)
    {
        for(int w = 0; w < my_width -1; w++)
        {
            new_pixels[h][w].red = std::abs(pixels[h][w].red - pixels[h + 1][w + 1].red);
            new_pixels[h][w].green = std::abs(pixels[h][w].green - pixels[h + 1][w + 1].green);
            new_pixels[h][w].blue = std::abs(pixels[h][w].blue - pixels[h + 1][w + 1].blue);
        }
    }
    pixels = new_pixels;
}

void Image::flip_horizontally()
{
    std::vector<std::vector<RGB>> schowek = pixels;

    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            pixels[h][w] = schowek[h][my_width - w - 1];

        }
    }
}

void Image::flip_vertically()
{
    std::vector<std::vector<RGB>> schowek = pixels;

    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            pixels[h][w] = schowek[my_height - h - 1][w];

        }
    }
}

void Image::inflate()
{
    std::vector<std::vector<RGB>> new_pixels(my_height * 2, std::vector<RGB>(my_width * 2));

    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            new_pixels[2 * h][2 * w] = pixels[h][w];
            new_pixels[2 * h + 1][2 * w] = pixels[h][w];
            new_pixels[2 * h][2 * w + 1] = pixels[h][w];
            new_pixels[2 * h + 1][2 * w + 1] = pixels[h][w];
        }
    }

    pixels = new_pixels;
    my_height = my_height * 2;
    my_width = my_width * 2;
}

void Image::negative()
{
    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            pixels[h][w].red = 255 - pixels[h][w].red;
            pixels[h][w].green = 255 - pixels[h][w].green;
            pixels[h][w].blue = 255 - pixels[h][w].blue;
        }
    }
}

void Image::rotate_clockwise_90()
{
    int new_height = my_width;
    int new_width = my_height;
    std::vector<std::vector<RGB>> new_pixels(new_height, std::vector<RGB>(new_width));

    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            new_pixels[w][my_height - h - 1] = pixels[h][w];
        }
    }

    pixels = new_pixels;
    my_height = new_height;
    my_width = new_width;
}

void Image::sepia()
{
    to_grayscale();

    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            unsigned char new_red = static_cast<unsigned char>(std::min(255, int(pixels[h][w].red * 0.393 + pixels[h][w].green * 0.769 + pixels[h][w].blue * 0.189)));
            unsigned char new_green = static_cast<unsigned char>(std::min(255, int(pixels[h][w].red * 0.349 + pixels[h][w].green * 0.686 + pixels[h][w].blue * 0.168)));
            unsigned char new_blue = static_cast<unsigned char>(std::min(255, int(pixels[h][w].red * 0.272 + pixels[h][w].green * 0.534 + pixels[h][w].blue * 0.131)));
            pixels[h][w] = {new_red, new_green, new_blue};
        }
    }
}

void Image::shrink()
{
    std::vector<std::vector<RGB>> new_pixels(my_height / 2, std::vector<RGB>(my_width / 2));

    for(int h = 0; h < my_height / 2; h++)
    {
        for(int w = 0; w < my_width / 2; w++)
        {
            unsigned char new_red = static_cast<unsigned char>((pixels[2 * h][2 * w].red + pixels[2 * h + 1][2 * w].red + pixels[2 * h][2 * w + 1].red + pixels[2 * h + 1][2 * w + 1].red)/4);
            unsigned char new_green = static_cast<unsigned char>((pixels[2 * h][2 * w].green + pixels[2 * h + 1][2 * w].green + pixels[2 * h][2 * w + 1].green + pixels[2 * h + 1][2 * w + 1].green)/4);
            unsigned char new_blue = static_cast<unsigned char>((pixels[2 * h][2 * w].blue + pixels[2 * h + 1][2 * w].blue + pixels[2 * h][2 * w + 1].blue + pixels[2 * h + 1][2 * w + 1].blue)/4);
            new_pixels[h][w] = {new_red, new_green, new_blue};
        }
    }

    pixels = new_pixels;
    my_height = my_height / 2;
    my_width = my_width / 2;
}

void Image::to_grayscale()
{
    for(int h = 0; h < my_height; h++)
    {
        for(int w = 0; w < my_width; w++)
        {
            unsigned char gray = static_cast<unsigned char>((pixels[h][w].red + pixels[h][w].green + pixels[h][w].blue)/3);
            pixels[h][w] = {gray, gray, gray};
        }
    }
}

int Image::height() const
{
    return my_height;
}

int Image::width() const
{
    return my_width;
}





