#ifndef QHARMONICPROCESSOR_H
#define QHARMONICPROCESSOR_H

#include <QObject>
#include "fftw3.h"

#define BOTTOM_LIMIT 0.7 // in s^-1, it is 42 bpm
#define TOP_LIMIT 4.5 // in s^-1, it is 270 bpm
#define SNR_TRESHOLD 2.0 // in most cases this value is suitable when (bufferlength == 256)
#define HALF_INTERVAL 2 // defines the number of averaging indexes when frequency is evaluated, this value should be >= 1
#define DIGITAL_FILTER_LENGTH 5 // in counts

class QHarmonicProcessor : public QObject
{
    Q_OBJECT
public:
    explicit QHarmonicProcessor(QObject *parent = 0, quint16 length_of_data = 256, quint16 length_of_buffer = 256 );
    ~QHarmonicProcessor();
    enum color_channel { Red, Green, Blue };
    enum XMLparserError { NoError, FileOpenError, FileExistanceError, ReadError, ParseFailure };
    enum SexID { Male, Female };
    enum TwoSideAlpha { FiftyPercents, TwentyPercents, TenPercents, FivePercents, TwoPercents };

signals:
    void CNSignalWasUpdated(const qreal * pointer_to_vector, quint16 length_of_vector);
    void SpectrumWasUpdated(const qreal * pointer_to_vector, quint16 length_of_vector);
    void ptTimeWasUpdated(const qreal * pointer_to_vector, quint16 length_of_vector);
    void HRfrequencyWasUpdated(qreal freq_value, qreal snr_value, bool reliable_data_flag);
    void PCAProjectionWasUpdated(const qreal * ppointer_to_vector, quint16 length_of_vector);
    void pt_YoutputWasUpdated(const qreal *pointer_to_vector, quint16 length_of_vector);
    void SignalActualValues(qreal signalValue, qreal meanRed, qreal meanGreen, qreal meanBlue, qreal freqValue, qreal snrValue);
    void TooNoisy(qreal snr_value);
    void SlowPPGWasUpdated(const qreal *pointer, quint16 legth);

public slots:
    void WriteToDataOneColor(unsigned long red, unsigned long green, unsigned long blue, unsigned long area, double time);
    void ComputeFrequency();
    void switch_to_channel(color_channel value);
    qreal CountFrequency(); // inertion of a result depends on how frequently this function is called, if with period of 1 sec result is averaged frequency on 1 sec, if 1 min then averaged on 1 min etc.
    void set_zerocrossingCounter(quint16 value);
    int loadThresholds(const char *fileName, SexID sex, int age, TwoSideAlpha alpha);

private:
    qreal *ptCNSignal;  //a pointer to centered and normalized data (typedefinition from fftw3.h, a single precision complex float number type)
    fftw_complex *ptSpectrum;  // a pointer to an array for FFT-spectrum
    qreal SNRE; // a variable for signal-to-noise ratio estimation storing
    qreal *ptData_ch1; //a pointer to spattialy averaged data (you should use it to write data to an instance of a class)
    qreal *ptData_ch2; //a pointer to spattialy averaged data (you should use it to write data to an instance of a class)
    qreal *ptDataForFFT; //a pointer to data prepared for FFT
    qreal *ptAmplitudeSpectrum;
    qreal ch1_mean;   //a variable for mean value in channel1 storing
    qreal ch2_mean;   //a variable for mean value in channel2 storing
    qreal *ptTime; //a pointer to an array for frame periods storing (values in milliseconds thus unsigned int)
    qreal HRfrequency; //a variable for storing a last evaluated frequency of the 'strongest' harmonic
    unsigned int curpos; //a current position I meant
    unsigned int datalength; //a length of data array
    unsigned int bufferlength; //a lenght of sub data array for FFT (bufferlength should be <= datalength)
    qreal *ptX; // a pointer to input counts history, for digital filtration
    quint16 loop(qint16) const; //a function that return a loop-index
    quint16 loop_for_ptX(qint16) const; //a function that return a loop-index
    fftw_plan m_plan;
    color_channel m_channel; // determines which color channel is enrolled by WriteToDataOneColor(...) method
    qreal *pt_Youtput; // a pointer to a vector of digital filter output
    qreal *pt_Xoutput; // for intermediate result storage
    qreal pt_Tempoutput[2]; // to store two close counts from digital derivative
    quint8 m_zerocrossing;
    qreal m_output; // will store value that will be written in pt_Youtput[i]
    quint8 loop_on_two(qint16 difference) const;
    qint16 m_zerocrossingCounter; // will store the number of pulse waves for averaging HRfrequency estimation
    double m_leftThreshold; // a bottom threshold for warning about high pulse value
    double m_rightTreshold; // a top threshold for warning aboul low pulse value
};

// inline, for speed, must therefore reside in header file
inline quint16 QHarmonicProcessor::loop(qint16 difference) const
{
    return ((datalength + (difference % datalength)) % datalength); // have finded it on wikipedia ), it always returns positive result
}
//---------------------------------------------------------------------------
inline quint16 QHarmonicProcessor::loop_for_ptX(qint16 difference) const
{
    return ((DIGITAL_FILTER_LENGTH + (difference % DIGITAL_FILTER_LENGTH)) % DIGITAL_FILTER_LENGTH);
}
//---------------------------------------------------------------------------
inline quint8 QHarmonicProcessor::loop_on_two(qint16 difference) const
{
    return ((2 + (difference % 2)) % 2);
}
//---------------------------------------------------------------------------


#endif // QHARMONICPROCESSOR_H
