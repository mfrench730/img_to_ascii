#include "utils.cpp"
#include "opencv2/opencv.hpp"

using std::cout;
using std::endl;
using std::string;
using namespace cv;

const string image_path = "../../../src/mona_lisa.jpg";

int main() {
	
	Mat img = imread(image_path, IMREAD_COLOR);

	if (img.empty()) {
		std::cerr << "Failed to load image." << endl;
		return 1;
	}

	/*imshow("Display window", img);
	int k = waitKey(0);*/
	print_ascii(img, 4);	

	return 0;
}