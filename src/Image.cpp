#include "Image.hpp"

Image::Image(uint width, uint height) : m_imgWidth(width), m_imgHeight(height)
{
  // Initialise an array of Color*
  image = new Color *[m_imgHeight];

  for (uint i = 0; i < m_imgHeight; i++)
    image[i] = new Color[m_imgWidth];
}

Image::~Image()
{
  for (uint i = 0; i < m_imgHeight; i++)
  {
    delete[] image[i];
  }
  delete[] image;
}

void Image::generateImage(const std::string &filename) const
{
  std::ofstream imgFile(filename);
  imgFile << "P3\n# Generated by Ava\n";
  imgFile << m_imgWidth << " " << m_imgHeight << "\n255\n";

  // Y axis is inverted so that negative y could point downwards
  for (uint y = m_imgHeight; y > 0; y--)
  {

    for (uint x = 0; x < m_imgWidth; x++)
    {

      Color color = image[y - 1][x];

      imgFile << int(color.red * 255) << " " << int(color.green * 255) << " " << int(color.blue * 255) << "\n";
    }
    imgFile << "\n#-----------------------------\n";
  }
}