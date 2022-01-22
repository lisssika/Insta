
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>
#include "InstagramEditor.h"
int main() {
	cv::Mat image = cv::imread("image.jpg");
	InstagramEditor instagram_editor(image);
	instagram_editor.execute();
	//InstaEditor edtr(image);
	//edtr.execute();
	return 0;
}