#include <opencv2/imgcodecs.hpp>
#include "InstaEditor.h"

int main() {
	cv::Mat image = cv::imread("image.jpg");
	InstaEditor edtr(image);
	edtr.execute();
	return 0;
}