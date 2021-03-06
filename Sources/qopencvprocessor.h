/*------------------------------------------------------------------------------------------------------
Taranov Alex, 2014									     HEADER FILE
Class that wraps opencv functions into Qt SIGNAL/SLOT interface
The simplest way to use it - rewrite appropriate section in QOpencvProcessor::customProcess(...) slot
------------------------------------------------------------------------------------------------------*/

#ifndef QOPENCVPROCESSOR_H
#define QOPENCVPROCESSOR_H
//------------------------------------------------------------------------------------------------------

#include <QObject>
#include <opencv2/opencv.hpp>

//------------------------------------------------------------------------------------------------------

class QOpencvProcessor : public QObject
{
    Q_OBJECT
public:
    explicit QOpencvProcessor(QObject *parent = 0);

signals:
    void frameProcessed(const cv::Mat& value, double frame_period); //should be emited in the end of each frame processing
    void dataCollected(unsigned long red, unsigned long green, unsigned long blue, unsigned long area, double period);
    void selectRegion(const char * string);     // emit it if no objects has been detected or no regions are selected
    void mapCellProcessed(unsigned long red, unsigned long green, unsigned long blue, unsigned long area, double period);
    void mapRegionUpdated(const cv::Rect& rect);

public slots:
    void customProcess(const cv::Mat &input);   // just a template of how a program logic should work
    void updateTime();                          // use it in the beginning of any time-measurement operations
    void setRect(const cv::Rect &input_rect);   // sets m_cvrect
    void faceProcess(const cv::Mat &input);     // an algorithm that evaluates PPG from skin region, region evaluates by means of opencv's cascadeclassifier functions
    void rectProcess(const cv::Mat &input);     // an algorithm that evaluates PPG from skin region defined by user
    bool loadClassifier(const std::string& filename); // an interface to CascadeClassifier::load(...) function
    void setFullFaceFlag(bool value);           // interface to define if algorithm will process full rectangle region returned by detectmultiscale(...) or parts them
    void mapProcess(const cv::Mat &input);

    cv::Rect getRect(); // returns current m_cvRect
    void setMapRegion(const cv::Rect &input_rect); // sets up map region, see m_mapRect
    void setMapCellSize(quint16 sizeX, quint16 sizeY);
    void setSkinSearchingFlag(bool value);

private:
    bool m_fullFaceFlag;
    bool m_skinFlag;
    int64 m_timeCounter;    // stores time of application/computer start
    double m_framePeriod;   // stores time of frame processing
    cv::Rect m_cvRect;      // this rect is used by process_rectregion_pulse slot
    cv::CascadeClassifier m_classifier; //object that manages opencv's image recognition functions

    quint16 m_mapCellSizeX;
    quint16 m_mapCellSizeY;
    cv::Rect m_mapRect;
    unsigned char **v_pixelSet; // memory should be allocated in setMapCellSize() call

    bool isSkinColor(unsigned char valueRed, unsigned char valueGreen, unsigned char valueBlue);
};

inline bool QOpencvProcessor::isSkinColor(unsigned char valueRed, unsigned char valueGreen, unsigned char valueBlue)
{
    //from Ghazali Osman Muhammad, Suzuri Hitam and Mohd Nasir Ismail
    //"ENHANCED SKIN COLOUR CLASSIFIER USING RGB RATIO MODEL" International Journal on Soft Computing (IJSC) Vol.3, No.4, November 2012
    //Swift’s rule
    /*if( (valueBlue > valueRed)    &&
        (valueGreen < valueBlue)    &&
        (valueGreen > valueRed)     &&
        ( (valueBlue < (valueRed >> 2))  || (valueBlue > 200) ) ) {
        return false;
    } else return true;*/

    //Kovac's rule
    /*if( (valueRed > 95) && (valueRed > valueGreen)    &&
        (valueGreen > 40) && (valueBlue > 20)           &&
        ((valueRed - qMin(valueGreen,valueBlue)) > 15)  &&
        ((valueRed - valueGreen) > 15 ) ) {
        return true;
    } else return false;*/

    //Modified Kovac's rule
    if( (valueRed > 115) &&
        (valueRed > valueGreen) && (valueBlue > 45)     &&
        ((valueRed - qMin(valueGreen,valueBlue)) > 35)  &&
        ((valueRed - valueGreen) > 25 ) ) {
        return true;
    } else return false;
}


//------------------------------------------------------------------------------------------------------
#endif // QOPENCVPROCESSOR_H
