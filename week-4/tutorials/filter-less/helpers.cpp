#include "helpers.h"
#include <string>
#include <stdio.h>

using namespace std;

// max channle number
const int CAP_VALUE = 255;

// Custom Function for return strut
struct Colour {
    float red;
    float green;
    float blue;
};

// Calculate SpiaColour using SepialColourCombo() method
class SepiaColour{
private:
    int redrgb;
    int bluergb;
    int greenrgb;
public:
    SepiaColour(int red, int green, int blue)
    {
        redrgb = red;
        bluergb = blue;
        greenrgb = green;
    }

    // Return combo of sepal colours 
    Colour SepialColourCombo()
    {
        Colour spiaColour; 

        spiaColour.red = SepiaColourRed();
        spiaColour.green = SepiaColourGreen();
        spiaColour.blue = SepiaColourBlue();

        return spiaColour;
    }   

    float SepiaColourRed()
    {
        return (0.393 * (float)(redrgb)) + (0.769 * (float)(greenrgb)) + (0.189 * (float)(bluergb));
    }

    float SepiaColourGreen()
    {
        return (0.394 * (float)(redrgb)) + (0.686 * (float)(greenrgb)) + (0.168 * (float)(bluergb));
    }

    float SepiaColourBlue()
    {
        return (0.272 * (float)(redrgb)) + (0.534 * (float)(greenrgb)) + (0.131 * (float)(bluergb));;
    }
};

// Prototypes 
int calculateAverage(int red_value, int blue_value, int green_value);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int row = 0; row < height; row++) 
    {
        for(int col = 0; col < width; col++)
        {
            int average_colour = calculateAverage(image[row][col].rgbtRed, image[row][col].rgbtBlue, image[row][col].rgbtGreen);
            
            // Apply Average colour 
            image[row][col].rgbtRed = average_colour; 
            image[row][col].rgbtBlue = average_colour; 
            image[row][col].rgbtGreen = average_colour; 
        }
    }
    return;
}

// Calculate Average GrayScale
int calculateAverage(int red_value, int blue_value, int green_value)
{   
    int average = (red_value +blue_value + green_value) / 3;
    return average;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int row = 0; row < height; row++) 
    {
        for(int col = 0; col < width; col++)
        {
            SepiaColour sepiaColourValues(image[height][width].rgbtRed, image[height][width].rgbtBlue, image[height][width].rgbtGreen);
            Colour spiaColourcombo = sepiaColourValues.SepialColourCombo();

            // Check for overflow 250 in spiaColourcombo strut
            if ((int) spiaColourcombo.red > 250)
            {
                spiaColourcombo.red = 250;
            } else if ((int) spiaColourcombo.green > 250)
            {
                spiaColourcombo.green = 250; 
            } else if((int) spiaColourcombo.blue > 250)
            {
                spiaColourcombo.blue = 250;
            }

            // Apply sepia to images pixel from colour struct
            image[row][col].rgbtRed = (int) spiaColourcombo.red; 
            image[row][col].rgbtBlue = (int) spiaColourcombo.blue; 
            image[row][col].rgbtGreen = (int) spiaColourcombo.green; 
        }
    }
    return;
}

int calculateSepciaChannel(int red, int green, int blue)
{
    // returns a dictionary! Array + linked-list?
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
