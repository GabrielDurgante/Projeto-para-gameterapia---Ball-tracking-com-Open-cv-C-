#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){

	cout << "pica dura 123\n";

	auto filename = "C:\\opencv\\opencv\\sources\\samples\\data\\cards.png";
	auto imagem = imread(filename);

	imshow("imagem foda", imagem);

	waitKey();




}