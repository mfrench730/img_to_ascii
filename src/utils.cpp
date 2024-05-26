#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "opencv2/opencv.hpp"

using std::cout;
using std::endl;
using std::stringstream;
using std::string;
using namespace cv;


const string ascii = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\" ^ `'. ";
double ascii_mod = (ascii.size() - 1) / 255.0;


void print_ascii(Mat& I, int pixels) {
	// check if image has 3 channels 
	if (I.channels() != 3) {
		cout << "Must have 3 channels." << endl;
		return;
	}

	std::ofstream of("output.txt");

	int c_pixels = pixels;
	int r_pixels = pixels * 2;

	Vec3b pixel;
	int intensity;

	for (int i = 0; i < I.rows - r_pixels; i += r_pixels) {
		for (int j = 0; j < I.cols - c_pixels; j += c_pixels) {
			intensity = 0;
			for (int k = 0; k < r_pixels; k++) {
				for (int l = 0; l < c_pixels; l++) {
					pixel = I.at<Vec3b>(i + k, j + l);

					// combine each channel, accounting for difference in weight of each color
					intensity += ((pixel[0] * 0.2126) + (pixel[1] * 0.7153) + (pixel[2] * 0.0722));
				}
			}
			intensity /= (r_pixels * c_pixels);
			intensity *= ascii_mod;
			
			try {
				if (intensity >= ascii.size()) {
					throw (intensity);
				}
				of << ascii.at(intensity);
			}
			catch (int error) {
				std::cerr << "Out of range: " << error << endl;
			}
			

		}
		of << endl;
	}
}