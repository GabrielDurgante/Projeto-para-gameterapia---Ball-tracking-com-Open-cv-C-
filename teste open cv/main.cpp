#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {

    int respforma;


    cout << "Qual movimento você deseja? \n 1- Quadrado \n 2- Elevação lateral \n";
    cin >> respforma;

    if (respforma == 1)
    {
        VideoCapture cap(0);
        if (!cap.isOpened())
        {
            cout << "alterar o número da porta da câmera";
            return -1;
        }
        while (true)
        {
            Mat frame;
            cap.read(frame);

            // Checa se a imagem foi criada
            // successfully or not
            if (!frame.data) {
                std::cout << "Não foi possível abrir ou "
                    << "encontre a imagem\n";

                return 0;
            }

           
            Mat hsvFrame;
            cvtColor(frame, hsvFrame, CV_RGB2HSV);

            blur(hsvFrame, hsvFrame, cv::Size(1, 1));

            //Threshold 
            Scalar lowerBound = cv::Scalar(55, 100, 50);
            Scalar upperBound = cv::Scalar(90, 255, 255);
            Mat threshFrame;
            inRange(hsvFrame, lowerBound, upperBound, threshFrame);

            //Calculate X,Y centroid      
            Moments m = moments(threshFrame, false);
            Point com(m.m10 / m.m00, m.m01 / m.m00);

            //Draw crosshair
            Scalar color = cv::Scalar(0, 0, 255);
            drawMarker(frame, com, color, cv::MARKER_CROSS, 20, 2);

            cvNamedWindow("Detector de bola verde", CV_WINDOW_NORMAL);
            cvSetWindowProperty("Detector de bola verde", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);

            cv::Mat dst;
            cv::flip(frame, dst, 1);
            imshow("Detector de bola verde", dst);

            //imshow("Detector de bola verde", frame);
            //imshow("Thresholded Tennis Ball", threshFrame);


            // Show our image inside a window
            waitKey(30) == 27;

            if (cv::waitKey(30) >= 10)
                break;


        }
    }

    if (respforma == 2)
    {
        VideoCapture cap(0);
        if (!cap.isOpened())
        {
            cout << "alterar o número da porta da câmera";
            return -1;
        }
        while (true)
        {
            Mat frame;
            cap.read(frame);

            // Checa se a imagem foi criada
            // successfully or not
            if (!frame.data) {
                std::cout << "Não foi possível abrir ou "
                    << "encontre a imagem\n";

                return 0;
            }

            /* // Top Left Corner
            Point p1(90, 90);
            // Bottom Right Corner
            Point p2(255, 255);
            // Desenha o retangulo
            rectangle(frame, p1, p2,
                Scalar(0, 0, 255),
                thickness, LINE_8); */

            int contador = 1;

            while (contador < 2)
            {
                int thickness = -1;

                Point center(100, 74);//declara o ponto central
                int radius = 25; //Declara o raio
                Scalar line_Color(25, 25, 112);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2)
            {
                int thickness = -1;

                Point center(225, 225);//declara o ponto central
                int radius = 25; //Declara o raio
                Scalar line_Color(25, 25, 112);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2)
            {
                int thickness = -1;

                Point center(500, 74);//declara o ponto central
                int radius = 25; //Declara o raio
                Scalar line_Color(25, 25, 112);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            contador = 1;

            while (contador < 2)
            {
                int thickness = -1;

                Point center(375, 225);//declara o ponto central
                int radius = 25; //Declara o raio
                Scalar line_Color(25, 25, 112);//Cor do bgl

                circle(frame, center, radius, line_Color, thickness);//Usa circle()function para desenhar a linha

                contador++;
            }

            Point p1(500, 74), p2(375, 225);
            int thickness = 2;

            line(frame, p1, p2, Scalar(25, 25, 112),
                thickness, LINE_8);

            Point p3(100, 74), p4(225, 225);

            line(frame, p3, p4, Scalar(25, 25, 112),
                thickness, LINE_8);

            Mat hsvFrame;
            cvtColor(frame, hsvFrame, CV_RGB2HSV);

            blur(hsvFrame, hsvFrame, cv::Size(1, 1));

            //Threshold 
            Scalar lowerBound = cv::Scalar(55, 100, 50);
            Scalar upperBound = cv::Scalar(90, 255, 255);
            Mat threshFrame;
            inRange(hsvFrame, lowerBound, upperBound, threshFrame);

            //Calculate X,Y centroid      
            Moments m = moments(threshFrame, false);
            Point com(m.m10 / m.m00, m.m01 / m.m00);

            //Draw crosshair
            Scalar color = cv::Scalar(0, 0, 255);
            drawMarker(frame, com, color, cv::MARKER_CROSS, 20, 2);

            cvNamedWindow("Detector de bola verde", CV_WINDOW_NORMAL);
            cvSetWindowProperty("Detector de bola verde", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);

            cv::Mat dst;
            cv::flip(frame, dst, 1);
            imshow("Detector de bola verde", dst);

            //imshow("Detector de bola verde", frame);
            //imshow("Thresholded Tennis Ball", threshFrame);


            // Show our image inside a window
            waitKey(30) == 27;

            if (cv::waitKey(30) >= 10)
                break;


        }
    }

    else
    {
        cout << "Aapenas 1 ou 2 eh aceito";
    }

}
